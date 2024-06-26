/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:55:03 by abelqasm          #+#    #+#             */
/*   Updated: 2022/08/02 12:55:25 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_find_cmd(char **paths, char *cmd)
{
	char	*cmd_path;
	char	*tmp;

	if (!cmd)
		return (NULL);
	if (cmd[0] && cmd[0] != '/' && cmd[0] != '.')
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
	else if (cmd[0] == '/')
		return (cmd);
	write(2, "command not found: ", 19);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	exit(127);
}

void	exit_error(char *str)
{
	if (errno == EACCES)
	{
		perror(str);
		exit(1);
	}
	write(2, str, ft_strlen(str));
	write(2, ": No such file or directory", 27);
	write(2, "\n", 1);
	exit(1);
}

void	open_io(t_cmd_data *data)
{
	t_args	*args;

	args = data->redir;
	while (args)
	{
		if (args->e_type == INPUT)
		{
			data->in = open(args->str, O_RDWR, 0644);
			if (data->in < 0)
				exit_error(args->str);
		}
		else if (args->e_type == OUTPUT)
		{
			if (data->append)
				data->out = open(args->str, O_RDWR | O_CREAT | O_APPEND, 0644);
			else
				data->out = open(args->str, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (data->out < 0)
				exit_error(args->str);
		}
		args = args->next;
	}
	if (data->delim)
		data->in = data->delim;
}

void	errno_exit(char *cmd_path)
{
	if (errno == ENOENT)
	{
		write(2, "command not found: ", 19);
		write(2, cmd_path, ft_strlen(cmd_path));
		write(2, "\n", 1);
		exit(127);
	}
	else if (errno == EACCES)
	{
		perror(cmd_path);
		exit(126);
	}
	exit(1);
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
	if (!args)
		exit(0);
	cmd_path = ft_find_cmd(path, args[0]);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (data->in != 0)
		dup2(data->in, STDIN_FILENO);
	if (data->out != 1)
		dup2(data->out, STDOUT_FILENO);
	ft_close_pipes(exec);
	execve(cmd_path, args, env);
	errno_exit(cmd_path);
}
