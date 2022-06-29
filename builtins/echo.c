/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:20:13 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/29 19:42:50 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_arg(t_args *args)
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

int	check_n(char *str)
{
	int	i;
	int	dush;
	int	n;

	i = 0;
	dush = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '-')
			dush++;
		if (str[i] != '-' && str[i] != 'n')
			n++;
		i++;
	}
	if (dush != 1 || n)
		return (1);
	return (0);
}

void	echo(t_cmd_data *data)
{
	int	count;
	int	n;

	count = count_arg(data->args);
	n = 0;
	if (count == 0)
		printf("\n");
	if (count >= 1)
	{
		data->args = data->args->next;
		while (data->args && !check_n(data->args->str))
		{
			data->args = data->args->next;
			n++;
		}
		while (data->args)
		{
			printf("%s", data->args->str);
			if (data->args->next || !n)
				printf(" ");
			data->args = data->args->next;
		}
	}
	if (!n)
		printf("\n");
}
