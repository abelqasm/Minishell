/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:21:18 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/18 18:41:36 by abelqasm         ###   ########.fr       */
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

void	ft_tokenize(char *str, char **env)
{
	t_parser	*parser;
	t_lexer		*lexer;
	t_ast		*ast;
	t_exec		*exec;
	
	lexer = init_lexer(str);
	parser = init_parser(lexer);
	ast = parser_parse(&parser);
	exec = init_exec(env);
	// print_ast(ast, 0);
	exec_ast(ast, exec, 0);
	free_tree(&ast, &parser);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	char	*str;

	while (1)
	{
		str = readline("myshell >");
		add_history(str);
		ft_tokenize(str, env);
	}
}

// ls -la | wc -l || cat Makefile