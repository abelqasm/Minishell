/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:51:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/04/25 07:17:31 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*init_token(char *value, int type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = value;
	token->e_type = type;
	free(value);
	return (token);
}

void	ft_tokenize(char *str)
{
	t_token	*token;
	t_lexer	*lexer;

	lexer = init_lexer(str);
	token = lexer_next_token(lexer);
	while (token->e_type != TOKEN_EOF)
	{
		printf("this is the token %s\nand this is its type %u\n", token->value, token->e_type);
		free(token);
		token = lexer_next_token(lexer);
	}
	free(lexer);
	free(token);
}
