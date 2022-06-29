/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:17:26 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/29 11:47:14 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_args(t_args *args)
{
	t_args	*ptr;
	int		i;

	i = 0;
	ptr = args;
	while (ptr->next)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
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

void	ft_exit(t_cmd_data *data)
{
	int	nbr;
	int	res;
	int	check;

	res = count_args(data->args);
	if (res == 0)
	{
		printf("exit\n");
		exit(0);
	}
	nbr = ft_atoi(data->args->next->str);
	check = ft_isd(data->args->next->str);
	exit_with_status(check, nbr, res);
}
