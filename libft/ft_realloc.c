/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 05:01:11 by abelqasm          #+#    #+#             */
/*   Updated: 2022/04/25 07:43:06 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t size)
{
	char	*dst;

	dst = malloc(size * sizeof(char));
	dst = ft_memcpy(dst, src, ft_strlen((const char *)src) + 1);
	free(src);
	return (dst);
}
