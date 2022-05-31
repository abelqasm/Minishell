/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opperators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:42:02 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/27 17:03:35 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ast	*parse_or_cmd(t_parser **start)
{
	t_parser	*parser;
	t_ast		*tree;
	t_ast		*tree2;
	
	parser = *start;
	tree = parse_and_cmd(&parser);
	if (parser->token->e_type == TOKEN_OR)
	{
		parser->token = lexer_next_token(parser->lexer);
		tree2 = parser_parse(&parser);
		return (init_node(tree, tree2, parser->token->e_type));
	}
	*start = parser;
	return (tree);
}

t_ast	*parse_and_cmd(t_parser **start)
{
	t_parser	*parser;
	t_ast		*tree;
	t_ast		*tree2;
	
	parser = *start;
	tree = parse_command(&parser);
	if (parser->token->e_type == TOKEN_AND)
	{
		parser->token = lexer_next_token(parser->lexer);
		tree2 = parser_parse(&parser);
		return (init_node(tree, tree2, parser->token->e_type));
	}
	*start = parser;
	return (tree);
}

t_ast	*parse_parenth(t_parser **start)
{
	t_parser	*parser;
	t_ast		*tree;
	t_ast		*tree2;
	
	parser = *start;
	tree = parse_command(&parser);
	if (parser->token->e_type == TOKEN_AND)
	{
		parser->token = lexer_next_token(parser->lexer);
		tree2 = parser_parse(&parser);
		return (init_node(tree, tree2, parser->token->e_type));
	}
	*start = parser;
	return (tree);
}
