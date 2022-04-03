/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:05:29 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/01 15:57:02 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[len]);
	while (len--)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
	}
	return (NULL);
}
