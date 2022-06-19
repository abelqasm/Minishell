/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:46:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/19 17:05:40 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exec	*init_exec(char **env, int n_pipe)
{
	t_exec	*exec;

	exec = malloc(sizeof(t_exec));
	exec->env = env;
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
