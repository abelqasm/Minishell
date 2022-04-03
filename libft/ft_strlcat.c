/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:20:02 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/01 15:56:51 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;
	size_t	lend;
	size_t	lens;

	i = 0;
	lens = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (lens);
	lend = ft_strlen(dst);
	l = lend;
	if (dstsize == 0 || dstsize <= lend)
		return (lens + dstsize);
	while (src[i] && i < dstsize - lend - 1)
	{
		dst[l] = src[i];
		i++;
		l++;
	}
	dst[l] = '\0';
	return (lens + lend);
}
