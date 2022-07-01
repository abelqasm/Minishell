/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:27:23 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/01 01:13:39 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fd_management(t_ast *ast, t_exec *exec, int flag)
{
	if (flag == 2)
	{
		ast->data.command->in = exec->pipe[exec->i][0];
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

void	execute_node(t_ast *ast, t_exec *exec, int flag)
{
	exec->i++;
	flag = 1;
	execute_ast(ast->data.tree->left, exec, flag);
	flag = 2;
	execute_ast(ast->data.tree->right, exec, flag);
}

void	execute_ast(t_ast *ast, t_exec *exec, int flag)
{
	if (!ast->data.command->args)
		return ;
	if (ast->e_type == AST_PIPE || ast->e_type == AST_OR
		|| ast->e_type == AST_AND)
	{
		execute_node(ast, exec, flag);
		return ;
	}
	if (ast->e_type == AST_COMMAND)
		fd_management(ast, exec, flag);
	exec->pid_i++;
	if (check_builtin(ast->data.command->args->str) != -1)
	{
		execute_builtin(ast->data.command);
		return ;
	}
	exec->pid[exec->pid_i] = fork();
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (exec->pid[exec->pid_i] == 0)
		execute(ast->data.command, g_env.env);
	if (ast->data.command->out != 1)
		close(ast->data.command->out);
}
