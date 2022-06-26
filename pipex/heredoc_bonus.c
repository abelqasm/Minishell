/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:46:33 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/29 19:16:29 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_infile_child_heredoc(t_heredoc *heredoc, char **argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv[3], ' ');
	path = ft_find_cmd(heredoc->paths, cmd[0]);
	dup2(heredoc->pipe[1], 1);
	close(heredoc->pipe[0]);
	dup2(heredoc->tmp_file, 0);
	if (!path)
		ft_error();
	execve(path, cmd, env);
	exit(1);
}

void	ft_outfile_child_heredoc(t_heredoc *heredoc, char **argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv[4], ' ');
	path = ft_find_cmd(heredoc->paths, cmd[0]);
	dup2(heredoc->pipe[0], 0);
	close(heredoc->pipe[1]);
	dup2(heredoc->file, 1);
	if (!path)
		ft_error();
	execve(path, cmd, env);
	exit(1);
}

void	ft_heredoc_mngmt(t_heredoc *heredoc, char **argv, char **env)
{
	heredoc->child1 = fork();
	if (heredoc->child1 == -1)
		ft_error();
	if (heredoc->child1 == 0)
		ft_infile_child_heredoc(heredoc, argv, env);
	heredoc->child2 = fork();
	if (heredoc->child2 == -1)
		ft_error();
	if (heredoc->child2 == 0)
		ft_outfile_child_heredoc(heredoc, argv, env);
	close(heredoc->pipe[1]);
	close(heredoc->pipe[0]);
	waitpid(heredoc->child1, NULL, 0);
	waitpid(heredoc->child2, NULL, 0);
}

void	ft_heredoc(int argc, char **argv, char **env)
{
	t_heredoc	heredoc;

	if (argc != 6)
		ft_argmt_error();
	heredoc.paths = ft_split(ft_path(env), ':');
	heredoc.file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	heredoc.tmp_file = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (heredoc.file == -1 || heredoc.tmp_file == -1)
		ft_error();
	if (pipe(heredoc.pipe) == -1)
		ft_error();
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		heredoc.str = get_next_line(0);
		if (!ft_strcmp(heredoc.str, argv[2]))
			break ;
		write(heredoc.tmp_file, heredoc.str, ft_strlen(heredoc.str));
		free(heredoc.str);
	}
	close(heredoc.tmp_file);
	heredoc.tmp_file = open(argv[1], O_RDONLY);
	ft_heredoc_mngmt(&heredoc, argv, env);
	unlink(argv[1]);
	exit(0);
}
