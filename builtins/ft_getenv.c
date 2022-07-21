/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:57:26 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/21 18:29:42 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	line_count(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_getenv(char *env)
{
	int		i;
	char	**split;
	char	*value;

	i = -1;
	while (g_env.env[++i])
	{
		split = ft_split(g_env.env[i], '=');
		if (!ft_strcmp(split[0], env))
		{
			value = ft_strdup(split[1]);
			free_table(split);
			return (value);
		}
		free_table(split);
	}
	return (NULL);
}
