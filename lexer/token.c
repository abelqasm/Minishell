/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:22:11 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/28 17:01:16 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*lexer_set_token_value(t_lexer *lexer, int type)
{
	char	*value;

	value = malloc(sizeof(char) * 2);
	value[0] = lexer->c;
	value[1] = '\0';
	lexer_advance(lexer);
	if (type == TOKEN_APPEND || type == TOKEN_DELIM)
	{
		value = ft_realloc(value, sizeof(char) * 3);
		ft_strlcat(value, (char []){lexer->c, 0}, 3);
		lexer_advance(lexer);
	}
	return (init_token(value, type));
}

t_token	*lexer_help_set_token(t_lexer *lexer)
{
	if (lexer->c == '<' && lexer->cp == '<')
		return (lexer_set_token_value(lexer, TOKEN_DELIM));
	if (lexer->c == '>' && lexer->cp == '>')
		return (lexer_set_token_value(lexer, TOKEN_APPEND));
	if (lexer->c == '|')
		return (lexer_set_token_value(lexer, TOKEN_PIPE));
	if (lexer->c == '<')
		return (lexer_set_token_value(lexer, TOKEN_RDIN));
	if (lexer->c == '>')
		return (lexer_set_token_value(lexer, TOKEN_RDOUT));
	return (lexer_set_token_value(lexer, TOKEN_EOF));
}

t_token	*lexer_tokenize(t_lexer *lexer)
{
	if (lexer->c == '|' || lexer->c == '>' || lexer->c == '<')
		return (lexer_help_set_token(lexer));
	if (lexer->c == '$')
		return (lexer_parse_token(lexer, TOKEN_DOLLAR));
	if (lexer_args_char(lexer->c) && lexer->c != '\'' && lexer->c != '"')
		return (lexer_parse_token(lexer, TOKEN_ID));
	if (lexer->c == '\'')
		return (lexer_parse_single_quote(lexer, TOKEN_ID));
	if (lexer->c == '"')
		return (lexer_parse_double_quote(lexer, TOKEN_ID));
	return (lexer_set_token_value(lexer, TOKEN_EOF));
}

t_token	*lexer_next_token(t_parser **parser)
{
	lexer_skip_whitespace((*parser)->lexer);
	if ((*parser)->token)
	{
		if ((*parser)->token->e_type == TOKEN_PIPE
			|| (*parser)->token->e_type == TOKEN_EOF
			|| (*parser)->token->e_type == TOKEN_RDIN
			|| (*parser)->token->e_type == TOKEN_APPEND
			|| (*parser)->token->e_type == TOKEN_RDOUT
			|| (*parser)->token->e_type == TOKEN_DELIM
			|| (*parser)->token->e_type == TOKEN_WILDCARDS)
			free((*parser)->token->value);
		free((*parser)->token);
	}
	return (lexer_tokenize((*parser)->lexer));
}
