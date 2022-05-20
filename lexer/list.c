/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:06:04 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/20 13:55:37 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*init_list(void *item)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->item = item;
	list->next = NULL;
	return (list);
}

void	list_push(t_list *list, void *item)
{
	t_list	*push;

	push = ft_lstlast(list);
	push->next = init_list(item);
}
