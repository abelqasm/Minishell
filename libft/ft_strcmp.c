/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:56:55 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/21 12:25:27 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp( const char *s1, const char *s2)
{
	size_t	m;

	m = 0;
	if (s1 == s2)
		return (0);
	while (s1[m] != '\0' && s2[m] != '\0')
	{
		if (s1[m] != s2[m])
		{
			return (((unsigned char *)s1)[m] - ((unsigned char *)s2)[m]);
		}
		m++;
	}
	if ((s1[m] == '\0' && s2[m] != '0')
		|| (s2[m] == '\0' && s1[m] != '\0'))
		return (((unsigned char *)s1)[m] - ((unsigned char *)s2)[m]);
	return (0);
}
