/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AST.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:18:21 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/20 14:04:38 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef struct s_pipe
{
	t_ast	*left;
	t_ast	*right;
}	t_pipe;
typedef union s_data_type
{
	t_pipe	*tree;
	t_list	*list;
}	t_data_type;
typedef struct s_ast
{
	enum
	{
		AST_ID,
		AST_SLQUOTE,
		AST_SRQUOTE,
		AST_DLQUOTE,
		AST_DRQUOTE,
		AST_DOLLAR,
		AST_RDIN,
		AST_RDOUT,
		AST_APPEND,
		AST_DELIM,
		AST_PIPE,
		AST_OR,
		AST_AND,
		AST_EOF,
	} e_type;
	t_data_type	*data;
}	t_ast;
t_ast	*init_ast(int type);
#endif