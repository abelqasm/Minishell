/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:18:42 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/27 20:13:28 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getenv(char *env)
{
	int	i;

	i = -1;
	while (g_env.env[++i])
	{
		if (!ft_strncmp(g_env.env[i], env, ft_strlen(env)))
			return (g_env.env[i]);
	}
	return (NULL);
}

void	add_to_env(char *value)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = g_env.env;
	g_env.env = malloc(sizeof(char *) * (line_count(tmp) + 2));
	while (tmp[i])
	{
		g_env.env[i] = ft_strdup(tmp[i]);
		i++;
	}
	g_env.env[i] = ft_strdup(value);
	i++;
	g_env.env[i] = 0;
}

void	ft_env(t_cmd_data *data)
{
	int		i;

	i = -1;
	(void)data;
	while (g_env.env[++i])
		printf("%s\n", g_env.env[i]);
}
