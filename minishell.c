/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:21:18 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/23 16:10:34 by abelqasm         ###   ########.fr       */
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

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	char	*str;

	while (1)
	{
		str = readline("myshell >");
		if (!str)
		{
			printf("exit\n");
			exit(1);
		}
		add_history(str);
		execute_shell(str, env);
	}
}

// ls -la | wc -l || cat Makefile