/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:21:23 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/01 15:56:24 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_range(int nb)
{
	int				i;
	unsigned int	num;

	num = nb;
	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i = 1;
		num = nb * -1;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*number;
	int				len;
	unsigned int	nbr;

	nbr = n;
	if (n == 0)
		return (ft_strdup("0"));
	len = calc_range(n);
	number = (char *)malloc(sizeof(*number) * len + 1);
	if (!number)
		return (NULL);
	if (n < 0)
	{
		number[0] = '-';
		nbr = n * -1;
	}
	number[len] = '\0';
	len--;
	while (len >= 0 && number[len] != '-')
	{
		number[len] = nbr % 10 + '0';
		len--;
		nbr = nbr / 10;
	}
	return (number);
}
