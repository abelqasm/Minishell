/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:06:04 by abelqasm          #+#    #+#             */
/*   Updated: 2022/08/01 12:57:13 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_args	*init_args(char *item, int type)
{
	t_args	*list;

	list = malloc(sizeof(t_args));
	list->str = item;
	list->next = NULL;
	list->e_type = type;
	return (list);
}

void	args_push(t_args **args, char *item, int type)
{
	t_args	*push;

	push = *args;
	if (!push)
	{
		push = init_args(item, type);
		*args = push;
		return ;
	}
	while (push->next)
		push = push->next;
	push->next = init_args(item, type);
}
