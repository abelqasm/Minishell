/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:34:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/01 15:56:33 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	if (!dst && !src)
		return (0);
	dest = dst;
	source = src;
	if (dest < source)
	{
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		dest = dst + (len - 1);
		source = src + (len -1);
		while (len--)
			*dest-- = *source--;
	}
	return (dst);
}
