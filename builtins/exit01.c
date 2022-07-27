/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:56:46 by brmohamm          #+#    #+#             */
/*   Updated: 2022/07/25 17:36:49 by abelqasm         ###   ########.fr       */
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

void	exit_with_status(int check, int nbr, int res)
{
	if (check == 0 && res == 1)
	{
		printf("exit\n");
		exit(nbr);
	}
	else if (check == 0 && res >= 2)
	{
		printf("exit: too many arguments\n");
		g_env.exit_status = 1;
	}
	else if (check == 1 && res >= 1)
	{
		printf("exit: numeric argument required\n");
		exit(255);
	}
}

void	exitm(char **data)
{
	int	nbr;
	int	res;
	int	check;

	res = count_args(data);
	nbr = 0;
	check = 0;
	if (res == 0)
	{
		printf("exit\n");
		exit(0);
	}
	if (data[1])
	{
		nbr = ft_atoi(data[1]);
		check = ft_isd(data[1]);
	}
	exit_with_status(check, nbr, res);
}
