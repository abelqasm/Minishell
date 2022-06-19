/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:55:03 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/19 18:59:48 by abelqasm         ###   ########.fr       */
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
		data->in = open(data->intput->str, O_RDWR | O_CREAT, 0644);
		data->intput = data->intput->next;
	}
	while (data->output)
	{
		data->out = open(data->output->str, O_RDWR | O_CREAT | O_TRUNC, 0644);
		data->output = data->output->next;
	}
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
	printf("[%d] [%d]   %s\n", data->in, data->out, args[0]);
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
	exit(1);
}
