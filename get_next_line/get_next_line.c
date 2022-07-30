/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:40 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/30 12:55:36 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_separate(char **str)
{
	char	*line;
	char	*fre;

	fre = *str;
	if (ft_srch_n(*str) == -1)
	{
		if (*str != NULL && **str != '\0')
			line = ft_strdup(*str);
		else
			line = NULL;
		free(fre);
		*str = NULL;
	}
	else
	{
		line = ft_substr(*str, 0, ft_srch_n(*str) + 1);
		*str = ft_substr(*str, ft_srch_n(*str) + 1,
				ft_strlen(*str) - ft_srch_n(*str));
		free(fre);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			i;
	char		*line;

	line = malloc(1 + 1);
	if (!line)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	while (ft_srch_n(str) == -1)
	{
		i = read(fd, line, 1);
		if (i == 0 || i == -1)
			break ;
		line[i] = 0;
		str = ft_strjoin_gnl(str, line);
	}
	free(line);
	return (ft_separate(&str));
}
