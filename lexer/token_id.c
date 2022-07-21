/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:51:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/21 18:24:35 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*parse_return_value(char *str, char **tmp)
{
	char	*value;
	int		i;

	i = -1;
	value = ft_itoa(g_env.exit_status);
	while (str[++i] && str[i] != '?')
		i++;
	while (str[++i])
	{
		value = ft_realloc(value, (ft_strlen(value + 2) * sizeof(char)));
		ft_strlcat(value, (char []){str[i], 0}, ft_strlen(value) + 2);
	}
	free(*tmp);
	return (value);
}

t_token	*lexer_parse_dollard(t_lexer *lexer)
{
	char	*str;
	char	*tmp;

	str = ft_calloc(1, sizeof(char));
	tmp = NULL;
	lexer_advance(lexer);
	while ((ft_isalnum(lexer->c) && lexer->c != '"'
			&& lexer->c != '\'') || lexer->c == '?')
	{
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
	}
	if (lexer->delim)
		free(lexer->delim);
	lexer->delim = ft_strjoin("$", str);
	tmp = ft_getenv(str);
	if (check_double(str, '?'))
		tmp = parse_return_value(str, &tmp);
	free(str);
	if (!tmp)
		tmp = ft_strdup("\n");
	return (init_token(tmp, TOKEN_DOLLAR));
}

t_token	*lexer_parse_token(t_lexer *lexer, int type)
{
	char	*str;

	str = ft_calloc(1, sizeof(char));
	while (lexer_args_char(lexer->c))
	{
		if (lexer->c == '*')
			type = TOKEN_WILDCARDS;
		if (lexer->c == '"' || lexer->c == '\'')
			lexer_advance(lexer);
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
	}
	return (init_token(str, type));
}
