/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:06:04 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/26 17:47:20 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_args	*init_args(char *item)
{
	t_args	*list;

	list = malloc(sizeof(t_args));
	list->str = item;
	list->next = NULL;
	return (list);
}

void	args_push(t_args **args, char *item)
{
	t_args	*push;

	push = *args;
	if (!push)
	{
		push = init_args(item);
		*args = push;
		return ;
	}
	while (push->next)
		push = push->next;
	push->next = init_args(item);
}
