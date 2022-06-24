/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:27:23 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/24 18:52:08 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fd_management(t_ast *ast, t_exec *exec, int flag)
{
	if (flag == 2)
	{
		ast->data.command->in = exec->pipe[exec->i][0];
		if (exec->pipe_parenth > 0)
		{
			ast->data.command->out = exec->pipe[exec->i + 1][1];
			exec->pipe_parenth--;
		}
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
}

int	execute_node(t_ast *ast, t_exec *exec, int flag)
{
	int	exit_value;

	exec->i++;
	if (ast->e_type == AST_PIPE)
		flag = 1;
	exit_value = execute_ast(ast->data.tree->left, exec, flag);
	if (ast->e_type == AST_PIPE)
		flag = 2;
	if (exit_value != 0 && ast->e_type == AST_OR)
		exit_value = execute_ast(ast->data.tree->right, exec, flag);
	if (exit_value == 0 && ast->e_type == AST_AND)
		exit_value = execute_ast(ast->data.tree->right, exec, flag);
	if (ast->e_type == AST_PIPE)
		exit_value = execute_ast(ast->data.tree->right, exec, flag);
	return (exit_value);
}

int	execute_ast(t_ast *ast, t_exec *exec, int flag)
{
	pid_t	pid;
	int		exit_value;

	if (ast->e_type == AST_PIPE || ast->e_type == AST_OR
		|| ast->e_type == AST_AND)
	{
		exit_value = execute_node(ast, exec, flag);
		if (exit_value == 0)
			return (0);
		return (1);
	}
	if (ast->e_type == AST_COMMAND)
		fd_management(ast, exec, flag);
	pid = fork();
	if (pid == 0)
		execute(ast->data.command, exec->env);
	if (ast->data.command->out != 1)
		close(ast->data.command->out);
	wait(&exit_value);
	if (WEXITSTATUS(exit_value) == 0)
		return (0);
	return (1);
}
