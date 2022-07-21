/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:10:37 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/21 19:43:19 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer_args_quotes(int c)
{
	if (ft_isprint(c) || c == ' ' || c == '\f' || c == '\v'
		|| c == '\t' || c == '\r')
		return (1);
	return (0);
}

void	set_expand_value(t_lexer *lexer, char **str)
{
	t_token	*env;

	env = lexer_parse_dollard(lexer);
	if (env->value)
	{
		*str = ft_realloc(*str, (ft_strlen(*str)
					+ ft_strlen(env->value) + 1) * sizeof(char));
		ft_strlcat(*str, env->value, ft_strlen(*str)
			+ ft_strlen(env->value) + 1);
	}
	if (lexer->c == '"')
		lexer_advance(lexer);
	free(env->value);
	free(env);
}

char	*more_value(t_lexer *lexer, char **str)
{
	while (lexer_args_quotes(lexer->c))
	{
		if (lexer->c == '$')
			set_expand_value(lexer, str);
		*str = ft_realloc(*str, (ft_strlen(*str) + 2) * sizeof(char));
		ft_strlcat(*str, (char []){lexer->c, 0}, ft_strlen(*str) + 2);
		lexer_advance(lexer);
	}
	return (*str);
}

t_token	*lexer_parse_double_quote(t_lexer *lexer, int type)
{
	char	*str;

	str = ft_calloc(1, sizeof(char));
	lexer_advance(lexer);
	if (!check_double(lexer->str + lexer->i, '"'))
		g_env.error++;
	while (lexer_args_quotes(lexer->c) && lexer->c != '"')
	{
		if (lexer->c == '$')
			set_expand_value(lexer, &str);
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
	}
	if (lexer->c == '"')
		lexer_advance(lexer);
	str = more_value(lexer, &str);
	return (init_token(str, type));
}

t_token	*lexer_parse_single_quote(t_lexer *lexer, int type)
{
	char	*str;

	str = ft_calloc(1, sizeof(char));
	lexer_advance(lexer);
	if (!check_double(lexer->str + lexer->i, '\''))
		g_env.error++;
	while (lexer_args_quotes(lexer->c) && lexer->c != '\'')
	{
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
	}
	if (lexer->c == '\'')
		lexer_advance(lexer);
	str = more_value(lexer, &str);
	return (init_token(str, type));
}
