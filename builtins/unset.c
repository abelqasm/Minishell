/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:48:35 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/30 16:52:39 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_the_unset(char ***src, char *value)
{
	char	**tmp;
	int		i;
	int		j;

	i = -1;
	j = -1;
	tmp = (*src);
	(*src) = malloc(sizeof(char *) * (line_count(tmp)));
	while (tmp[++i])
	{
		if (!check_existing(tmp[i], value))
			(*src)[++j] = ft_strdup(tmp[i]);
		free(tmp[i]);
	}
	(*src)[++j] = 0;
	free(tmp);
}

void	unset(t_cmd_data *data)
{
	t_args	*tmp;

	if (data->args->next)
	{
		tmp = data->args;
		data->args = data->args->next;
		free_node(tmp);
		while (data->args)
		{
			if (check_value(g_env.env, data->args->str))
				do_the_unset(&g_env.env, data->args->str);
			if (check_value(g_env.exp, data->args->str))
				do_the_unset(&g_env.exp, data->args->str);
			tmp = data->args;
			data->args = data->args->next;
			free_node(tmp);
		}
	}
}
