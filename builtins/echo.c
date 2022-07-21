/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 02:30:46 by brmohamm          #+#    #+#             */
/*   Updated: 2022/07/21 23:39:33 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	nl_not_exist(int *nl_exist, char *c, int *i)
{
	int	y;

	if (c[0] == '-')
	{
		y = 1;
		while (c[y] && c[y] == 'n')
			y++;
		if (c[y] == '\0')
		{
			*nl_exist = 0;
			*i = *i + 1;
			return (0);
		}
	}
	return (1);
}

void	redir_or_pipe(int pipe_exist, int out)
{
	if (pipe_exist == 1 && out != 0)
	{
		dup2(out, 1);
		out = 1;
	}
	else if (out == 0)
		out = 1;
	else if (pipe_exist == 1)
		dup2(out, 1);
}

void	while_on_newlin(char **c, int *nl_exist, int *i)
{
	while (c[*i + 1])
	{
		if (nl_not_exist(nl_exist, c[*i + 1], i) == 1)
			break ;
	}
}

void	echo(char **c, int pipe_exist, int out)
{
	int	i;
	int	nl_exist;

	i = 0;
	nl_exist = 1;
	redir_or_pipe(pipe_exist, out);
	while_on_newlin(c, &nl_exist, &i);
	while (c[i + 1])
	{
		if (c[i + 1] != NULL)
			write(out, c[i + 1], ft_strlen(c[i + 1]));
		i++;
		if (c[i + 1])
			write(out, " ", 1);
	}
	if (nl_exist == 1)
		write(out, "\n", 1);
	if (pipe_exist == 1)
	{
		g_env.exit_status = 0;
		exit(0);
	}
	else
		g_env.exit_status = 0;
}
