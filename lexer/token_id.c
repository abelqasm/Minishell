/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:51:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/29 12:25:31 by abelqasm         ###   ########.fr       */
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
	tmp = ft_getenv(str);
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
		if (lexer->c == '"' || lexer->c == '\'')
			lexer_advance(lexer);
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
	}
	return (init_token(str, type));
}
