/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:48:35 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/27 20:13:47 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_the_unset(char *value)
{
	char	**tmp;
	int		i;
	int		j;

	i = -1;
	j = -1;
	tmp = g_env.env;
	g_env.env = malloc(sizeof(char *) * (line_count(tmp)));
	while (tmp[++i])
	{
		if (ft_strncmp(tmp[i], value, ft_strlen(value)))
			g_env.env[++j] = ft_strdup(tmp[i]);
	}
	g_env.env[j] = 0;
}

void	unset(t_cmd_data *data)
{
	if (data->args->next)
		do_the_unset(data->args->next->str);
}
