/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:25:05 by abelqasm          #+#    #+#             */
/*   Updated: 2022/08/01 15:56:42 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_ast **ast, t_parser **parser, t_exec **exec, int n_pipe)
{
	if (n_pipe)
	{
		(*exec)->i = -1;
		while (++(*exec)->i < n_pipe)
			free((*exec)->pipe[(*exec)->i]);
		free((*exec)->pipe);
	}
	free_tree(ast, parser);
	free((*exec)->pid);
	free((*exec));
}

void	set_exit_value(int exit_status, int type)
{
	g_env.exit_status = WEXITSTATUS(exit_status);
	if (WIFSIGNALED(exit_status))
	{
		if (type)
		{
			g_env.exit_status = 1;
			g_env.heredoc = 1;
		}
		else
			g_env.exit_status = WTERMSIG(exit_status) + 128;
	}
}

void	execute_shell(char *str)
{
	t_parser	*parser;
	t_lexer		*lexer;
	t_exec		*exec;
	t_ast		*ast;

	lexer = init_lexer(str);
	parser = init_parser(lexer);
	ast = parser_parse(&parser, &lexer->pipe);
	exec = init_exec(lexer->pipe);
	if (g_env.pipe)
		g_env.npipe = 1;
	if (!g_env.error && !g_env.heredoc)
	{
		execute_ast(ast, exec, 0);
		ft_close_pipes(exec);
		while (waitpid(-1, &g_env.exit_status, 0) > 0)
			set_exit_value(g_env.exit_status, 0);
	}
	else if (g_env.error && !g_env.heredoc)
	{
		ft_close_pipes(exec);
		printf("syntax error\n");
		g_env.exit_status = 258;
	}
	free_shell(&ast, &parser, &exec, lexer->pipe);
}
