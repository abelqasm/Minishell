/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:25:05 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/01 01:12:54 by abelqasm         ###   ########.fr       */
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
	free((*exec)->pid);
	free((*exec));
}

void	execute_shell(char *str)
{
	t_parser	*parser;
	t_lexer		*lexer;
	t_exec		*exec;
	t_ast		*ast;
	int			exit_value;
	int			pipe;

	pipe = 0;
	lexer = init_lexer(str);
	parser = init_parser(lexer);
	ast = parser_parse(&parser, &pipe);
	exec = init_exec(pipe);
	if (!parser->lexer->error)
	{
		execute_ast(ast, exec, 0);
		while (waitpid(-1, &exit_value, 0) > 0)
			g_env.exit_status = WEXITSTATUS(exit_value);
	}
	else
		printf("syntax error\n");
	free_shell(&ast, &parser, &exec, pipe);
}
