/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parenth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:42:02 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/11 17:33:56 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ast	*parse_parenth(t_parser **start)
{
	t_parser	*parser;
	t_ast		*tree;

	parser = *start;
	if (parser->token->e_type == TOKEN_LPARENTH)
	{
		parser->token = lexer_next_token(&parser);
		tree = parser_parse(&parser);
		if (parser->token->e_type == TOKEN_RPARENTH)
		{
			parser->token = lexer_next_token(&parser);
			return (tree);
		}
	}
	*start = parser;
	return (parse_command(&parser));
}
