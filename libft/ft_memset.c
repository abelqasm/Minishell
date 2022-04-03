/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:41:43 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/01 15:56:36 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	unsigned char	*set;
	size_t			i;

	i = 0;
	set = src;
	while (i < len)
	{
		set[i] = c;
		i++;
	}
	return (set);
}
