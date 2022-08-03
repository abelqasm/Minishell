/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:46:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/08/01 19:27:15 by abelqasm         ###   ########.fr       */
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
	char	cwd[256];
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
	if (!ft_strcmp(str[0], "./minishell"))
	{
		free(str[0]);
		getcwd(cwd, sizeof(cwd));
		str[0] = ft_strjoin(cwd, "/minishell");
	}
	return (str);
}
