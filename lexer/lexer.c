/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:49:55 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/30 18:52:53 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lexer	*init_lexer(char *str)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->str = str;
	lexer->i = 0;
	lexer->c = str[lexer->i];
	if (lexer->c != '\0')
		lexer->cp = str[lexer->i + 1];
	lexer->size = ft_strlen(str);
	lexer->delim = NULL;
	lexer->pipe = 0;
	return (lexer);
}

t_token	*init_token(char *value, int type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = value;
	token->e_type = type;
	return (token);
}

void	lexer_advance(t_lexer *lexer)
{
	if (lexer->i < lexer->size && lexer->c != '\0')
	{
		lexer->i++;
		lexer->c = lexer->str[lexer->i];
		if (lexer->c == '\0')
			lexer->cp = 0;
		else
			lexer->cp = lexer->str[lexer->i + 1];
	}
}

void	lexer_skip_whitespace(t_lexer *lexer)
{
	while (lexer->c == ' ' || lexer->c == '\f' || lexer->c == '\v'
		|| lexer->c == '\t' || lexer->c == '\r' || lexer->c == '\n')
		lexer_advance(lexer);
}

int	lexer_args_char(int c)
{
	if (ft_isprint(c) && c != '<' && c != '>' && c != '|' && c != '&'
		&& !(c == ' ' || c == '\f' || c == '\v'
			|| c == '\t' || c == '\r' || c == '\n'))
		return (1);
	return (0);
}
