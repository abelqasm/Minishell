/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:38:33 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/02 16:54:52 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_existing(char *src, char *dst)
{
	char	**str1;
	char	**str2;
	int		value;
	int		i;

	str1 = ft_split(src, '=');
	str2 = ft_split(dst, '=');
	value = 1;
	if (ft_strlen(str1[0]) == ft_strlen(str2[0]))
		value = ft_strncmp(str1[0], str2[0], ft_strlen(str1[0]));
	i = -1;
	while (str1[++i])
		free(str1[i]);
	free(str1);
	i = -1;
	while (str2[++i])
		free(str2[i]);
	free(str2);
	if (!value)
		return (1);
	return (0);
}

int	check_value(char **src, char *value)
{
	int	i;

	i = -1;
	while (src[++i])
	{
		if (check_existing(src[i], value))
			return (1);
	}
	return (0);
}
