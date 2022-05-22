/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:21:18 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/22 17:09:21 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokenize(char *str)
{
	t_parser	*parser;
	t_lexer		*lexer;
	t_ast		*ast;
	
	lexer = init_lexer(str);
	parser = init_parser(lexer);
	ast = parser_parse(&parser);
	// while (parser->token->e_type != TOKEN_EOF)
	// {
	// 	printf("this is the token %s\nand this is its type %u\n", parser->token->value, parser->token->e_type);
	// 	parser->token = lexer_next_token(lexer);
	// }
	// free(lexer);
	// free(token);
	while (ast->data->command->args)
	{
		printf("this is the value :%s\n", ast->data->command->args->str);
		ast->data->command->args = ast->data->command->args->next;
	}
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
