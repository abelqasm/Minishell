/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:18:42 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/28 15:08:05 by abelqasm         ###   ########.fr       */
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

	i = -1;
	tmp = g_env.env;
	g_env.env = malloc(sizeof(char *) * (line_count(tmp) + 2));
	while (tmp[++i])
	{
		g_env.env[i] = ft_strdup(tmp[i]);
		free(tmp[i]);
	}
	g_env.env[i] = ft_strdup(value);
	g_env.env[++i] = 0;
	free(tmp);
}

void	replace_env_value(char *value)
{
	char	*str;
	char	**split;
	int		i;

	i = -1;
	split = ft_split(value, '=');
	while (g_env.env[++i])
	{
		if (!ft_strncmp(g_env.env[i], split[0], ft_strlen(split[0])))
		{
			str = g_env.env[i];
			g_env.env[i] = ft_strdup(value);
			free(str);
		}
	}
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	ft_env(t_cmd_data *data)
{
	int		i;

	i = -1;
	(void)data;
	while (g_env.env[++i])
		printf("%s\n", g_env.env[i]);
}
