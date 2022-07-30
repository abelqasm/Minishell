/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 02:31:14 by brmohamm          #+#    #+#             */
/*   Updated: 2022/07/30 10:11:51 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	if_equal_exist(int equal_exist, int out, int i)
{
	if (equal_exist == 1)
	{
		write(out, g_env.env[i],
			ft_strlen(g_env.env[i]));
		write(out, "\n", 1);
	}
}

void	print_env(int out)
{
	int	i;
	int	y;
	int	equal_exist;

	i = 0;
	equal_exist = 0;
	while (g_env.env[i])
	{
		y = 0;
		equal_exist = 0;
		while (g_env.env[i][y])
		{
			if (g_env.env[i][y] == '=' && g_env.env[i][y + 1])
			{
				equal_exist = 1;
				break ;
			}
			y++;
		}
		if_equal_exist(equal_exist, out, i);
		i++;
	}
}

void	envm(char **c, int pipe_exist, t_cmd_data *cmd)
{
	int	error;

	error = 0;
	if (!open_built_io(cmd))
		return ;
	if (c[1])
		error = args_error(c[1], 1, "env");
	if (error == 0)
	{
		redir_or_pipe(pipe_exist, cmd->out);
		print_env(cmd->out);
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
