/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:51:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/10 19:01:33 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*lexer_parse_dollard(t_lexer *lexer)
{
	char	*str;
	char	*tmp;

	str = ft_calloc(1, sizeof(char));
	tmp = NULL;
	lexer_advance(lexer);
	while (ft_isalnum(lexer->c) && lexer->c != '"' && lexer->c != '\'')
	{
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
	}
	tmp = getenv(str);
	free(str);
	return (init_token(tmp, TOKEN_DOLLAR));
}

t_token	*lexer_parse_token(t_lexer *lexer, int type)
{
	char	*str;

	str = ft_calloc(1, sizeof(char));
	while (lexer_args_char(lexer->c))
	{
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
	}
	return (init_token(str, type));
}

t_token	*lexer_set_token_value(t_lexer *lexer, int type)
{
	char	*value;

	value = malloc(sizeof(char) * 2);
	value[0] = lexer->c;
	value[1] = '\0';
	lexer_advance(lexer);
	if (type == TOKEN_OR || type == TOKEN_AND
		|| type == TOKEN_APPEND || type == TOKEN_DELIM)
	{
		value = ft_realloc(value, sizeof(char) * 3);
		ft_strlcat(value, (char []){lexer->c, 0}, 3);
		lexer_advance(lexer);
	}
	return (init_token(value, type));
}

t_token	*lexer_parse_quote(t_lexer *lexer, int type)
{
	char	*str;
	t_token	*env;

	str = ft_calloc(1, sizeof(char));
	lexer_advance(lexer);
	while ((ft_isprint(lexer->c) && lexer->c != '"' && lexer->c != '\'')
		|| (lexer->c == ' ' || lexer->c == '\f' || lexer->c == '\v'
			|| lexer->c == '\t' || lexer->c == '\r' || lexer->c == '\n'))
	{
		if (lexer->c == '$' && type == TOKEN_DQUOTE)
		{
			env = lexer_parse_dollard(lexer);
			str = ft_realloc(str, (ft_strlen(str) + ft_strlen(env->value) +1) * sizeof(char));
			ft_strlcat(str, env->value, ft_strlen(str) + ft_strlen(env->value) +1);
			free(env);
		}
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
	}
	if (lexer->c == '"' || lexer->c == '\'')
		lexer_advance(lexer);
	return (init_token(str, type));
}

t_token	*lexer_next_token(t_lexer *lexer)
{
	lexer_skip_whitespace(lexer);
	if (lexer->c == '$')
		return (lexer_parse_dollard(lexer));
	if (lexer->c == '(')
		return (lexer_set_token_value(lexer, TOKEN_LPARENTH));
	if (lexer->c == ')')
		return (lexer_set_token_value(lexer, TOKEN_RPARENTH));
	if (lexer_args_char(lexer->c) && lexer->c != '\'' && lexer->c != '"')
		return (lexer_parse_token(lexer, TOKEN_ID));
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
	if (lexer->c == '\'')
		return (lexer_parse_quote(lexer, TOKEN_SQUOTE));
	if (lexer->c == '"')
		return (lexer_parse_quote(lexer, TOKEN_DQUOTE));
	return (lexer_set_token_value(lexer, TOKEN_EOF));
}
