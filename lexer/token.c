/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:51:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/12 16:17:39 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lexer_advance_quotes(t_lexer *lexer)
{
	if (lexer->c == '"' || lexer->c == '\'')
		lexer_advance(lexer);
}

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

t_token	*lexer_parse_quote(t_lexer *lexer, int type)
{
	char	*str;
	t_token	*env;

	str = ft_calloc(1, sizeof(char));
	lexer_advance(lexer);
	while (lexer_args_char(lexer->c)
		|| (lexer->c == ' ' || lexer->c == '\f' || lexer->c == '\v'
			|| lexer->c == '\t' || lexer->c == '\r' || lexer->c == '\n'))
	{
		lexer_advance_quotes(lexer);
		if (lexer->c == '$' && type == TOKEN_DQUOTE)
		{
			env = lexer_parse_dollard(lexer);
			str = ft_realloc(str, (ft_strlen(str)
						+ ft_strlen(env->value) + 1) * sizeof(char));
			ft_strlcat(str, env->value, ft_strlen(str)
				+ ft_strlen(env->value) + 1);
			free(env);
		}
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
	}
	lexer_advance_quotes(lexer);
	return (init_token(str, type));
}
