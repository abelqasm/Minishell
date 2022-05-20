/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:21:18 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/19 18:15:58 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	main(void)
{
	char	*str;

	while (1)
	{
		str = readline("myshell >");
		ft_tokenize(str);
		free(str);
	}
}
