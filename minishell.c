/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:21:18 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/13 19:54:05 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_ast(t_ast *ast, int n)
{
	if (ast->e_type == AST_PIPE || ast->e_type == AST_OR || ast->e_type == AST_AND || ast->e_type == AST_PARENTH)
	{
		printf("%*s(\n", n*4,"");
		print_ast(ast->data.tree->left, n + 1);
		printf("%*s|\n", n*4,"");
		print_ast(ast->data.tree->right, n + 1);
		printf("%*s)\n", n*4,"");
		return ;
	}
	while (ast->data.command->args)
	{
		printf("%*sthis is the value :%s\n", n*4, "",ast->data.command->args->str);
		ast->data.command->args = ast->data.command->args->next;
	}
}

void	ft_tokenize(char *str)
{
	t_parser	*parser;
	t_lexer		*lexer;
	t_ast		*ast;
	
	lexer = init_lexer(str);
	parser = init_parser(lexer);
	ast = parser_parse(&parser);
	print_ast(ast, 0);
	free_tree(&ast, &parser);
}

static void sigintHandler(int sig)
{
	printf("%d\n", sig);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	char	*str;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		str = readline("myshell >");
		ft_tokenize(str);
	}
}

// ls -la | wc -l || cat Makefile