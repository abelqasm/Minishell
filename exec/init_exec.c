/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:46:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/17 21:28:08 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exec	*init_exec(char **env)
{
	t_exec	*exec;

	exec = malloc(sizeof(t_exec));
	exec->env = env;
	exec->first = 1;
	pipe(exec->pipe);
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
