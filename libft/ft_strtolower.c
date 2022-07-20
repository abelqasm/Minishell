/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:49:33 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/20 22:53:49 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	int		i;
	char	*value;

	i = -1;
	value = malloc(sizeof(char) * (ft_strlen(str) + 1))
	while (str[++i])
		value[i] = ft_tolower(str[i]);
	value[i] = 0;
	return (value);
}
