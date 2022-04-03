/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:30:19 by abelqasm          #+#    #+#             */
/*   Updated: 2022/04/03 18:04:25 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const	*str, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str[0] != sep)
		count++;
	while (str[i])
	{
		if (str[i] == sep && str[i + 1])
		{
			while (str[i] == sep)
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*ft_split_word(char *src, char c)
{
	int		i;
	char	*word;
	int		len;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(*src));
	if (!word)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		word[i] = src[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*skip_next(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	while (str[i] && str[i] == c)
		i++;
	return (&str[i]);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!split)
		return (NULL);
	while (*str == c && *str)
		str++;
	while (*str)
	{
		split[j] = ft_split_word(str, c);
		j++;
		str = skip_next(str, c);
	}
	split[j] = 0;
	return (split);
}
