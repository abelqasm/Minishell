/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:24:49 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/23 11:52:20 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parser	*init_parser(t_lexer *lexer)
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser));
	parser->lexer = lexer;
	parser->token = lexer_next_token(parser->lexer);
	return (parser);
}

t_ast	*parse_command(t_parser **parser)
{
	t_ast			*tree;

	tree = init_ast(AST_COMMAND);
	tree->data = fill_struct(parser);
	return (tree);
}

t_ast	*parser_parse(t_parser **start) 
{
	t_parser	*parser;
	t_ast		*tree;
	t_ast		*tree2;

	parser = *start;
	tree = parse_command(&parser);
	if (parser->token->e_type == TOKEN_PIPE)
	{
		parser->token = lexer_next_token(parser->lexer);
		tree2 = parser_parse(&parser);
		return (init_pipe_node(tree, tree2));
	}
	*start = parser;
	return (tree);
}