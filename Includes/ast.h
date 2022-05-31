/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AST.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:18:21 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/31 18:39:11 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef struct s_ast	t_ast;
typedef struct s_node
{
	t_ast	*left;
	t_ast	*right;
}	t_node;
typedef union s_data_type
{
	t_node		*tree;
	t_cmd_data	*command;
}	t_data_type;
struct s_ast
{
	enum
	{
		AST_PIPE,
		AST_OR,
		AST_AND,
		AST_COMMAND,
		AST_ID,
		AST_SQUOTE,
		AST_DQUOTE,
		AST_DOLLAR,
		AST_RDIN,
		AST_RDOUT,
		AST_APPEND,
		AST_DELIM,
		AST_EOF,
	} e_type;
	t_data_type	data;
};
t_ast		*init_ast(int type);
t_ast		*parser_parse(t_parser **parser);
t_ast		*parse_command(t_parser **parser);
t_ast		*init_node(t_ast *left, t_ast *right, int type);
t_ast		*parse_and_cmd(t_parser **parser);
t_ast		*parse_parenth(t_parser **start);
t_ast		*parse_or_cmd(t_parser **parser);
t_data_type	fill_struct(t_parser **start);
void		free_ast(t_ast **ast);
#endif