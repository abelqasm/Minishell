/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:07:54 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/27 19:32:27 by abelqasm         ###   ########.fr       */
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

void	export_value(char ***exp, char *value)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = g_env.exp;
	(void)exp;
	g_env.exp = malloc(sizeof(char *) * (line_count(tmp) + 2));
	while (tmp[i])
	{
		g_env.exp[i] = ft_strdup(tmp[i]);
		i++;
	}
	g_env.exp[i] = ft_strdup(value);
	i++;
	g_env.exp[i] = 0;
}

void	export(t_cmd_data *data)
{
	if (!data->args->next)
		print_export(&g_env.exp);
	else
		export_value(&g_env.exp, data->args->next->str);
}
