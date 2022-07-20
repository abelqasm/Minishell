/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:18:21 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/19 12:32:52 by abelqasm         ###   ########.fr       */
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
		AST_PARENTH,
		AST_EOF,
	} e_type;
	t_data_type	data;
};
t_ast		*init_ast(int type);
t_ast		*parser_parse(t_parser **parser, int *pipe);
t_ast		*parse_command(t_parser **parser);
t_ast		*init_node(t_ast *left, t_ast *right);
t_ast		*parse_and_cmd(t_parser **parser);
t_ast		*parse_parenth(t_parser **start, int *pipe);
t_ast		*parse_or_cmd(t_parser **parser);
void		free_args(t_args **args);
void		free_ast(t_ast **ast);
void		free_tree(t_ast **ast, t_parser **parser);
t_data_type	fill_struct(t_parser **start);
#endif