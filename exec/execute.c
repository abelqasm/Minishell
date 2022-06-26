/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:55:03 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/26 18:32:25 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_find_cmd(char **paths, char *cmd)
{
	char	*cmd_path;
	char	*tmp;

	if (cmd[0] != '/')
	{
		while (paths && *paths)
		{
			tmp = ft_strjoin(*paths, "/");
			cmd_path = ft_strjoin(tmp, cmd);
			free(tmp);
			if (access(cmd_path, F_OK) == 0)
				return (cmd_path);
			free(cmd_path);
			paths++;
		}
	}
	while (paths && *paths)
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
		paths++;
	}
	printf("command not found: %s\n", cmd);
	return (NULL);
}

void	open_io(t_cmd_data *data)
{
	while (data->intput)
	{
		data->in = open(data->intput->str, O_RDWR, 0644);
		if (data->in < 0)
		{
			printf("wttf???\n");
			exit(0);
		}
		data->intput = data->intput->next;
	}
	while (data->output)
	{
		if (data->append)
			data->out = open(data->output->str, O_RDWR
					| O_CREAT | O_APPEND, 0644);
		else
			data->out = open(data->output->str, O_RDWR
					| O_CREAT | O_TRUNC, 0644);
		data->output = data->output->next;
	}
	if (data->delim)
		data->in = data->delim;
}

void	execute(t_cmd_data *data, char **env)
{
	char	**path;
	char	*cmd_path;
	char	*envp;
	char	**args;

	envp = getenv("PATH");
	path = ft_split(envp, ':');
	cmd_path = ft_find_cmd(path, data->args->str);
	args = ft_split(join_args(data->args), ' ');
	open_io(data);
	if (data->in != 0)
	{
		dup2(data->in, STDIN_FILENO);
		close(data->in);
	}
	if (data->out != 1)
	{
		dup2(data->out, STDOUT_FILENO);
		close(data->out);
	}
	execve(cmd_path, args, env);
	exit(127);
}
