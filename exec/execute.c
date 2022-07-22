/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:55:03 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/22 12:19:01 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_close_pipes(t_exec *exec)
{
	int	i;

	i = -1;
	while (++i < exec->n_pipe)
	{
		close(exec->pipe[i][0]);
		close(exec->pipe[i][1]);
	}
}

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
	return (cmd);
}

void	execute(t_cmd_data *data, char **env, t_exec *exec)
{
	char	**path;
	char	*cmd_path;
	char	*envp;
	char	**args;

	envp = ft_getenv("PATH");
	path = ft_split(envp, ':');
	cmd_path = ft_find_cmd(path, data->args->str);
	args = ft_split(join_args(data->args), ' ');
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (data->in != 0)
		dup2(data->in, STDIN_FILENO);
	if (data->out != 1)
		dup2(data->out, STDOUT_FILENO);
	ft_close_pipes(exec);
	execve(cmd_path, args, env);
	printf("command not found: %s\n", cmd_path);
	exit(127);
}
