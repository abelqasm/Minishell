/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parenth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:42:02 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/31 21:21:15 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ast	*parse_parenth(t_parser **start)
{
	t_parser	*parser;
	t_ast		*tree;
	t_ast		*tree2;
	int			type;
	
	parser = *start;
	type = parser->token->e_type;
	printf("test here %d\n", type);
	tree = parse_command(&parser);
	if (type == TOKEN_LPARENTH)
	{
		printf("hi\n");
		free(parser->token->value);
		parser->token = lexer_next_token(parser->lexer);
		tree2 = parser_parse(&parser);
		if (parser->token->e_type == TOKEN_LPARENTH)
		{
			printf("test here\n");
			return (init_node(tree, tree2, parser->token->e_type));
		}
	}
	*start = parser;
	return (tree);
}
