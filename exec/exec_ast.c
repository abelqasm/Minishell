/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:27:23 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/17 19:58:07 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fd_management(t_ast *ast, t_exec *exec, int fd)
{
	if (fd == 2)
	{
		ast->data.command->in = exec->pipe[0];
		ast->data.command->out = 1;
	}
	else if (fd == 1)
	{
		if (exec->first)
		{
			ast->data.command->in = 0;
			exec->first = 0;
		}
		else
			ast->data.command->in = exec->pipe[0];
		ast->data.command->out = exec->pipe[1];
	}
}

void	exec_ast(t_ast *ast, t_exec *exec, int fd)
{
	pid_t	pid;

	if (ast->e_type == AST_PIPE || ast->e_type == AST_OR
		|| ast->e_type == AST_AND || ast->e_type == AST_PARENTH)
	{
		fd = 1;
		exec_ast(ast->data.tree->left, exec, fd);
		fd = 2;
		exec_ast(ast->data.tree->right, exec, fd);
		return ;
	}
	else
		fd_management(ast, exec, fd);
	pid = fork();
	if (pid == 0)
		execute(ast->data.command, exec->env);
	else
		wait(NULL);
}
