/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:54:06 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/20 23:00:40 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	all_builtins01(char **c, int pipe_exist, int fd, int out)
{
	if (ft_strcmp(c[0], "export") == 0)
	{
		export(c, fd, pipe_exist, out);
		return (1);
	}
	if (ft_strcmp(c[0], "unset") == 0)
	{
		unset(c, pipe_exist);
		return (1);
    }
	if (ft_strcmp(c[0], "exit") == 0)
	{
		exitm(c);
		return (1);
	}
	if (ft_strcmp(c[0], "env") == 0)
	{
		envm(c, fd, pipe_exist, out);
		return (1);
	}
	return (0);
}

int	all_builtins(char **c, int pipe_exist, int fd, int out)
{
	char	*temp;

	if (all_builtins01(c, pipe_exist, fd, out) == 1)
		return (1);
		temp = ft_strtolower(c[0]);
	if (ft_strcmp(temp, "pwd") == 0)
	{
		pwd (c, fd, pipe_exist, out);
		free(temp);
		return (1);
	}
	if (ft_strcmp(temp, "echo") == 0)
	{
		echo(c, fd, pipe_exist, out);
		free(temp);
		return (1);
	}
	if (ft_strcmp(c[0], "cd") == 0)
	{
		cd(c, pipe_exist, out);
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}