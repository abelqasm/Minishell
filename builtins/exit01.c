/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:56:46 by brmohamm          #+#    #+#             */
/*   Updated: 2022/07/31 23:18:04 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i - 1);
}

int	ft_isd(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	exit_with_status(int check, int nbr, int res, int out)
{
	if (check == 0 && res == 1)
	{
		if (!g_env.pipe)
			write(out, "exit\n", 5);
		exit(nbr);
	}
	else if (check == 0 && res >= 2)
	{
		write(2, "exit: too many arguments\n", 25);
		g_env.exit_status = 1;
	}
	else if (check == 1 && res >= 1)
	{
		write(2, "exit: numeric argument required\n", 32);
		exit(255);
	}
}

void	exitm(char **data, t_cmd_data *cmd)
{
	int	nbr;
	int	res;
	int	check;

	res = count_args(data);
	nbr = 0;
	check = 0;
	if (!open_built_io(cmd))
		return ;
	if (res == 0)
	{
		if (!g_env.pipe)
			write(cmd->out, "exit\n", 5);
		exit(g_env.exit_status);
	}
	if (data[1])
	{
		nbr = ft_atoi(data[1]);
		check = ft_isd(data[1]);
	}
	exit_with_status(check, nbr, res, cmd->out);
}
