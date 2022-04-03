/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:00:19 by abelqasm          #+#    #+#             */
/*   Updated: 2021/11/19 21:09:06 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *check, char c)
{
	int	i;

	i = 0;
	while (check[i])
	{
		if (check[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_start(const char *str, const char *check)
{
	int	i;

	i = 0;
	while (str[i] && ft_check(check, str[i]))
		i++;
	return (i);
}

static int	ft_check_end(const char *str, const char *check)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (len - i > 0 && ft_check(check, str[len - i - 1]))
		i++;
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = ft_check_start(s1, set);
	end = ft_check_end(s1, set);
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (start >= end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
