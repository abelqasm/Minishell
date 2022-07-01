/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:46:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/01 00:19:40 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exec	*init_exec(int n_pipe)
{
	t_exec	*exec;

	exec = malloc(sizeof(t_exec));
	exec->pid = malloc(sizeof(int) * (n_pipe + 1));
	exec->pid_i = -1;
	exec->first = 1;
	exec->i = -1;
	if (n_pipe)
	{
		exec->pipe = malloc(sizeof(int *) * n_pipe);
		while (++exec->i < n_pipe)
		{
			exec->pipe[exec->i] = malloc(sizeof(int) * 2);
			pipe(exec->pipe[exec->i]);
		}
	}
	exec->i = -1;
	exec->n_pipe = n_pipe;
	return (exec);
}

char	*join_args(t_args *args)
{
	char	*str;

	str = ft_strdup(args->str);
	while (args->next)
	{
		args = args->next;
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, args->str);
	}
	return (str);
}
