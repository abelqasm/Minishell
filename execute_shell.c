/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:25:05 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/23 16:32:58 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_ast **ast, t_parser **parser, t_exec **exec, int n_pipe)
{
	free_tree(ast, parser);
	if (n_pipe)
	{
		(*exec)->i = -1;
		while (++(*exec)->i < n_pipe)
			free((*exec)->pipe[(*exec)->i]);
		free((*exec)->pipe);
	}
	free((*exec));
}

void	execute_tree(t_ast *ast, t_exec *exec)
{
	int	exit_value;

	if (ast->e_type == AST_COMMAND
		|| ast->data.tree->left->e_type == AST_COMMAND)
		exec_ast(ast, exec, 0);
	else
	{
		if (ast->e_type == AST_PIPE)
			exec->pipe_parenth = 1;
		exit_value = exec_ast(ast->data.tree->left, exec, 0);
		if (ast->e_type != AST_PIPE)
			exec->first = 1;
		if (ast->e_type == AST_PIPE)
		{
			exec->i++;
			exec->pipe_parenth = 0;
			exec_ast(ast->data.tree->right, exec, 2);
		}
		if (exit_value != 0 && ast->e_type == AST_OR)
			exec_ast(ast->data.tree->right, exec, 0);
		if (exit_value == 0 && ast->e_type == AST_AND)
			exec_ast(ast->data.tree->right, exec, 0);
	}
}

void	execute_shell(char *str, char **env)
{
	t_parser	*parser;
	t_lexer		*lexer;
	t_exec		*exec;
	t_ast		*ast;
	int			pipe;

	pipe = 0;
	lexer = init_lexer(str);
	parser = init_parser(lexer);
	ast = parser_parse(&parser, &pipe);
	exec = init_exec(env, pipe);
	execute_tree(ast, exec);
	free_shell(&ast, &parser, &exec, pipe);
}
