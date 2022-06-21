/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:27:23 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/21 15:54:05 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fd_management(t_ast *ast, t_exec *exec, int flag)
{
	printf("{%d}\n", exec->i);
	if (flag == 2)
	{
		ast->data.command->in = exec->pipe[exec->i][0];
		if (exec->i + 1 < exec->n_pipe)
			ast->data.command->out = exec->pipe[exec->i + 1][1];
		else
			ast->data.command->out = 1;
	}
	else if (flag == 1)
	{
		if (exec->first)
		{
			ast->data.command->in = 0;
			exec->first = 0;
		}
		else
			ast->data.command->in = exec->pipe[exec->i - 1][0];
		ast->data.command->out = exec->pipe[exec->i][1];
	}
	else
	{
		ast->data.command->out = 1;
		ast->data.command->in = 0;
	}
}

void	exec_ast(t_ast *ast, t_exec *exec, int flag)
{
	pid_t	pid;

	if (ast->e_type == AST_PIPE || ast->e_type == AST_OR
		|| ast->e_type == AST_AND)
	{
		exec->i++;
		if (ast->data.tree->left->e_type != AST_COMMAND)
			exec->i--;
		flag = 1;
		exec_ast(ast->data.tree->left, exec, flag);
		if (ast->data.tree->left->e_type != AST_COMMAND)
			exec->i++;
		flag = 2;
		exec_ast(ast->data.tree->right, exec, flag);
		return ;
	}
	if (ast->e_type == AST_COMMAND)
		fd_management(ast, exec, flag);
	pid = fork();
	if (pid == 0)
		execute(ast->data.command, exec->env);
	if (ast->data.command->out != 1)
		close(ast->data.command->out);
	if (ast->data.command->in != 0)
		close(ast->data.command->in);
	wait(NULL);
}
