/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AST.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:18:21 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/17 15:00:35 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef struct s_ast
{
	void			*data;
	struct s_ast	*left;
	struct s_ast	*right;
	enum
	{
		ASR_ID,
		ASR_SLQUOTE,
		ASR_SRQUOTE,
		ASR_DLQUOTE, 
		ASR_DRQUOTE,
		ASR_DOLLAR,
		ASR_RDIN,
		ASR_RDOUT,
		ASR_APPEND,
		ASR_DELIM,
		ASR_PIPE,
		ASR_OR,
		ASR_AND,
		ASR_EOF,
	} e_type;
}	t_ast;

t_ast	*init_ast(void *data, int type);
#endif