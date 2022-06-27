/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:24:29 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/27 14:36:42 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	do_the_unset(char ***export, char value)
{
	char	**str;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = *export;
	str = malloc(sizeof(char *) * (line_count(tmp)));
	while (tmp[i])
	{
		if (strcmp(tmp[i], value))
		{
		str[j] = strdup(tmp[i]);
		j++;
		}
		i++;
	}
	str[j] = 0;
	(*export) = str;
}

