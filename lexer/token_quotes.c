/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:10:37 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/26 16:52:03 by abelqasm         ###   ########.fr       */
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
	free(env);
}

t_token	*lexer_parse_double_quote(t_lexer *lexer, int type)
{
	char	*str;
	int		quotes;

	str = ft_calloc(1, sizeof(char));
	quotes = 0;
	lexer_advance(lexer);
	if (!check_double(lexer->str + lexer->i, '"'))
		lexer->error++;
	while (lexer_args_quotes(lexer->c) && lexer->c != '"')
	{
		if (quotes == 1 && lexer->c == '\'')
			break ;
		if (lexer->c == '$')
			set_expand_value(lexer, &str);
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
		if (lexer->c == '"' && ft_isalnum(lexer->cp) && !quotes)
			quotes = advance_quotes(lexer);
	}
	if (lexer->c == '"' && !quotes)
		lexer_advance(lexer);
	return (init_token(str, type));
}

t_token	*lexer_parse_single_quote(t_lexer *lexer, int type)
{
	char	*str;
	int		quotes;

	str = ft_calloc(1, sizeof(char));
	quotes = 0;
	lexer_advance(lexer);
	if (!check_double(lexer->str + lexer->i, '\''))
		lexer->error++;
	while (lexer_args_quotes(lexer->c) && lexer->c != '\'')
	{
		if (quotes == 1 && lexer->c == '"')
			break ;
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
		if (lexer->c == '\'' && ft_isalnum(lexer->cp) && !quotes)
			quotes = advance_quotes(lexer);
	}
	if (lexer->c == '\'' && !quotes)
		lexer_advance(lexer);
	return (init_token(str, type));
}
