/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:21:18 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/22 19:24:51 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_ast(t_ast *ast, int n)
{
	if (ast->e_type == AST_PIPE || ast->e_type == AST_OR || ast->e_type == AST_AND)
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
	int			pipe;

	pipe = 0;
	lexer = init_lexer(str);
	parser = init_parser(lexer);
	ast = parser_parse(&parser, &pipe);
	exec = init_exec(env, pipe);
	// print_ast(ast, 0);
	if (ast->e_type != AST_COMMAND && ast->data.tree->left->e_type != AST_COMMAND)
	{
		exec_ast(ast->data.tree->left, exec, 0);
		exec_ast(ast->data.tree->right, exec, 0);
	}
	else
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