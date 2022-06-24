/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:25:05 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/24 18:38:01 by abelqasm         ###   ########.fr       */
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

int	execute_tree(t_ast *ast, t_exec *exec, int flag)
{
	int	exit_value;

	if (ast->e_type != AST_COMMAND && ast->data.tree->left->e_type != AST_COMMAND)
	{
		if (ast->e_type == AST_PIPE)
			exec->pipe_parenth = 1;
		exit_value = execute_tree(ast->data.tree->left, exec, 0);
		if (ast->e_type == AST_PIPE)
		{
			exec->i++;
			execute_tree(ast->data.tree->right, exec, 2);
		}
		if (exit_value != 0 && ast->e_type == AST_OR)
			execute_tree(ast->data.tree->right, exec, flag);
		if (exit_value == 0 && ast->e_type == AST_AND)
			execute_tree(ast->data.tree->right, exec, flag);
		return (0);
	}
	if (execute_ast(ast, exec, flag) == 1)
		return (1);
	return (0);
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
	if (!parser->syntax_error)
		execute_tree(ast, exec, 0);
	else
		printf("syntax error\n");
	free_shell(&ast, &parser, &exec, pipe);
}
