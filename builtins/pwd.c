/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 02:36:03 by brmohamm          #+#    #+#             */
/*   Updated: 2022/07/30 10:11:01 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	args_error(char *c, int false, char *name)
{
	if (c[0] == '-')
	{
		write(2, name, ft_strlen(name));
		write(2, ": `", 3);
		write(2, &c[0], 1);
		write(2, &c[1], 1);
		write(2, "': put commend without option\n", 30);
		g_env.exit_status = 1;
		return (1);
	}
	else if (false == 1)
	{
		write(2, name, ft_strlen(name));
		write(2, ": `", 3);
		write(2, c, ft_strlen(c));
		write(2, "': put commend without args \n", 29);
		g_env.exit_status = 1;
		return (1);
	}
	return (0);
}

/*************** --  pwd -- ******************/

void	shearch_and_print(int out)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (g_env.env[y] != NULL)
	{
		if (ft_strncmp(g_env.env[y], "PWD", 3) == 0)
			break ;
		y++;
	}
	if (g_env.env[y] != NULL)
	{
		while ((g_env.env[y][i] != '='))
			i++;
		if (g_env.env[y][i] == '=')
		{
			while (g_env.env[y][i + 1])
			{
				write(out, &g_env.env[y][i + 1], 1);
				i++;
			}
		}
		write(out, "\n", 1);
	}
}

void	pwd(char **c, int pipe_exist, t_cmd_data *cmd)
{
	int	error;

	error = 0;
	if (!open_built_io(cmd))
		return ;
	if (c[1])
		error = args_error(c[1], 0, "pwd");
	if (error == 0)
	{
		redir_or_pipe(pipe_exist, cmd->out);
		shearch_and_print(cmd->out);
	}
	if (pipe_exist == 1)
	{
		if (error == 0)
			g_env.exit_status = 0;
		exit(g_env.exit_status);
	}
	if (error == 0)
			g_env.exit_status = 0;
}
