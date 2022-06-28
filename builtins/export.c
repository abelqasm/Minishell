/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:07:54 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/28 12:00:35 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_value(char *value)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = g_env.exp;
	g_env.exp = malloc(sizeof(char *) * (line_count(tmp) + 2));
	while (tmp[++i])
	{
		g_env.exp[i] = ft_strdup(tmp[i]);
		free(tmp[i]);
	}
	g_env.exp[i] = ft_strdup(value);
	g_env.exp[++i] = 0;
	free(tmp);
}

void	replace_value(char *value)
{
	char	*str;
	char	**split;
	int		i;

	i = -1;
	split = ft_split(value, '=');
	while (g_env.exp[++i])
	{
		if (!ft_strncmp(g_env.exp[i], split[0], ft_strlen(split[0])))
		{
			str = g_env.exp[i];
			g_env.exp[i] = ft_strdup(value);
			free(str);
		}
	}
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	export(t_cmd_data *data)
{
	if (!data->args->next)
		print_export();
	else
	{
		if (data->args->next->str && data->args->next->str[0] != '=')
		{
			data->args = data->args->next;
			while (data->args)
			{
				if (!check_value(g_env.exp, data->args->str))
				{
					export_value(data->args->str);
					if (check_char(data->args->str, '='))
						add_to_env(data->args->str);
				}
				else
				{
					if (check_char(data->args->str, '='))
					{
						replace_value(data->args->str);
						replace_env_value(data->args->str);
					}
				}
				data->args = data->args->next;
			}
		}
	}
}
