/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:05:27 by brmohamm          #+#    #+#             */
/*   Updated: 2022/07/30 14:38:07 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stralnum(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if ((c[i] < 'a' && c[i] > 'z') || (c[i] < 'A' && c[i] > 'Z')
			|| (c[i] < '0' && c[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_space(char *c)
{
	int	i;

	i = -1;
	while (c[++i])
	{
		if (c[i] == ' ' || c[i] == '\f' || c[i] == '\v'
			|| c[i] == '\t' || c[i] == '\r' || c[i] == '\n')
			return (0);
	}
	return (1);
}
