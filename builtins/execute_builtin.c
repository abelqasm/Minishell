/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:54:06 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/28 15:58:48 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	all_builtins01(char **c, int pipe_exist, t_cmd_data *cmd)
{
	if (ft_strcmp(c[0], "export") == 0)
	{
		export(c, pipe_exist, cmd);
		return (1);
	}
	if (ft_strcmp(c[0], "unset") == 0)
	{
		unset(c, pipe_exist, cmd);
		return (1);
	}
	if (ft_strcmp(c[0], "exit") == 0)
	{
		exitm(c, cmd);
		return (1);
	}
	if (ft_strcmp(c[0], "env") == 0)
	{
		envm(c, pipe_exist, cmd);
		return (1);
	}
	return (0);
}

int	all_builtins(char **c, int pipe_exist, t_cmd_data *cmd)
{
	char	*temp;

	if (all_builtins01(c, pipe_exist, cmd) == 1)
		return (1);
	temp = ft_strtolower(c[0]);
	if (ft_strcmp(temp, "pwd") == 0)
	{
		pwd (c, pipe_exist, cmd);
		free(temp);
		return (1);
	}
	if (ft_strcmp(temp, "echo") == 0)
	{
		echo(c, pipe_exist, cmd);
		free(temp);
		return (1);
	}
	if (ft_strcmp(c[0], "cd") == 0)
	{
		cd(c, pipe_exist, cmd);
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}

int	check_bultins(t_ast *ast)
{
	char	**args;
	int		value;
	int		i;

	i = -1;
	args = join_args(ast->data.command->args);
	value = all_builtins(args, g_env.npipe, ast->data.command);
	while (args[++i])
		free(args[i]);
	free(args);
	return (value);
}
