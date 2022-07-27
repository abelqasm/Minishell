/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:46:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/26 14:54:04 by abelqasm         ###   ########.fr       */
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

char	**split_args(char	**args)
{
	t_args	*strings;
	char	**str;
	int		i;
	int		j;

	i = -1;
	strings = NULL;
	while (args[++i])
	{
		j = -1;
		str = ft_split(args[i], ' ');
		while (str[++j])
			args_push(&strings, str[j]);
	}
	return (join_args(strings));
}

int	count_args_alloc(t_args *args)
{
	t_args	*ptr;
	int		i;

	i = 0;
	ptr = args;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

char	**join_args(t_args *args)
{
	char	**str;
	int		i;

	i = 0;
	if (!args)
		return (NULL);
	str = malloc(sizeof(char *) * (count_args_alloc(args) + 1));
	while (args)
	{
		str[i] = ft_strdup(args->str);
		args = args->next;
		i++;
	}
	str[i] = 0;
	return (str);
}
