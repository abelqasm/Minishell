/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 02:00:06 by abelqasm          #+#    #+#             */
/*   Updated: 2021/11/19 21:41:19 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	len_sub(char const *s, unsigned int start, size_t lenght)
{
	unsigned int	i;
	size_t			len;

	i = 0;
	while (s[i] && i != start)
		i++;
	len = ft_strlen(&s[i]);
	if (len > lenght)
		return (lenght + 1);
	return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * len_sub(s, start, len));
	if (!str)
		return (NULL);
	while (i != start && s[i])
		i++;
	while (s[i] && j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
