/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:55:03 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/28 12:23:07 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_find_cmd(char **paths, char *cmd)
{
	char	*cmd_path;
	char	*tmp;

	if (!cmd)
		return (NULL);
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

void	open_io(t_cmd_data *data)
{
	t_args	*args;

	args = data->intput;
	while (args)
	{
		data->in = open(args->str, O_RDWR, 0644);
		if (data->in < 0)
		{
			printf("no such file or directory: %s\n", args->str);
			exit(1);
		}
		args = args->next;
	}
	args = data->output;
	while (args)
	{
		if (data->append)
			data->out = open(args->str, O_RDWR | O_CREAT | O_APPEND, 0644);
		else
			data->out = open(args->str, O_RDWR | O_CREAT | O_TRUNC, 0644);
		args = args->next;
	}
	if (data->delim)
		data->in = data->delim;
}

void	errno_exit(char *cmd_path)
{
	if (errno == ENOENT)
	{
		printf("command not found: %s\n", cmd_path);
		exit(127);
	}
	else if (errno == EACCES)
	{
		perror(cmd_path);
		exit(126);
	}
}

void	execute(t_cmd_data *data, char **env, t_exec *exec)
{
	char	**path;
	char	*cmd_path;
	char	*envp;
	char	**args;

	open_io(data);
	envp = ft_getenv("PATH");
	path = ft_split(envp, ':');
	args = join_args(data->args);
	args = split_args(args);
	cmd_path = ft_find_cmd(path, args[0]);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!args)
		exit(0);
	if (data->in != 0)
		dup2(data->in, STDIN_FILENO);
	if (data->out != 1)
		dup2(data->out, STDOUT_FILENO);
	ft_close_pipes(exec);
	execve(cmd_path, args, env);
	errno_exit(cmd_path);
	exit(1);
}
