/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:58:38 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/08 00:32:50 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*lexer_parse_token(t_lexer *lexer)
{
	char	*str;

	str = ft_calloc(1, sizeof(char));
	if (lexer->c == 34 || lexer->c == 22)
		lexer_advance(lexer);
	while (ft_isalnum(lexer->c))
	{
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
	}
	return (init_token(str, TOKEN_ID));
}

t_token	*lexer_set_token_value(t_lexer *lexer, int type)
{
	t_token	*token;
	char	*value;

	value = malloc(2 * sizeof(char));
	value[0] = lexer->c;
	value[1] = '\0';
	token = init_token(value, type);
	lexer_advance(lexer);
	if (type == TOKEN_OR || type == TOKEN_AND
		|| type == TOKEN_APPEND || type == TOKEN_DELIM)
		lexer_advance(lexer);
	return (token);
}

t_token	*lexer_next_token(t_lexer *lexer)
{
	lexer_skip_whitespace(lexer);
	if (ft_isalnum(lexer->c) || lexer->c == 34 || lexer->c == 22)
		return (lexer_parse_token(lexer));
	if (lexer->c == '|' && lexer->cp == '|')
		return (lexer_set_token_value(lexer, TOKEN_OR));
	if (lexer->c == '&' && lexer->cp == '&')
		return (lexer_set_token_value(lexer, TOKEN_AND));
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
