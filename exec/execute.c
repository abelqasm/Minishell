/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:55:03 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/17 19:21:47 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_find_cmd(char **paths, char *cmd)
{
	char	*cmd_path;
	char	*tmp;

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

	envp = getenv("PATH");
	path = ft_split(envp, ':');
	cmd_path = ft_find_cmd(path, data->args->str);
	open_io(data);
	printf("[%d] [%d]\n", data->in, data->out);
	dup2(data->in, STDIN_FILENO);
	dup2(data->out, STDOUT_FILENO);
	execve(cmd_path, &data->args->str, env);
}
