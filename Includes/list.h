/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:59:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/22 13:30:35 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_args
{
	char			*str;
	struct s_args	*next;
}	t_args;

typedef struct s_cmd_data
{
	t_args	*args;
	char	*intput;
	char	*output;
	int		pipe;
}	t_cmd_data;

typedef struct s_list
{
	t_cmd_data		*item;
	struct s_list	*next;
}	t_list;
t_args	*init_args(char *item);
void	args_push(t_args **list, char *item);
#endif