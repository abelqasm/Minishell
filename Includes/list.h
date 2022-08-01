/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:59:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/08/01 12:57:19 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_args
{
	char			*str;
	enum
	{
		INPUT,
		OUTPUT,
	} e_type;
	struct s_args	*next;
}	t_args;

typedef struct s_cmd_data
{
	t_args	*args;
	t_args	*redir;
	int		in;
	int		out;
	int		delim;
	int		append;
}	t_cmd_data;

t_cmd_data	*init_command(void);
t_args		*init_args(char *item, int type);
void		args_push(t_args **args, char *item, int type);
void		fill_wildcards(char *str, t_cmd_data **cmd);

#endif