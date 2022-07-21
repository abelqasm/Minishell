/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:49:33 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/21 09:56:21 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	char	*c;
	int		i;

	i = 0;
	c = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			c[i] = str[i] + 32;
		else
			c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
