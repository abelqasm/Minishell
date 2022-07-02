/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:35:54 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/02 20:37:45 by abelqasm         ###   ########.fr       */
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

void	print_it(void)
{
	int		i;
	int		j;
	char	**split;

	i = -1;
	while (g_env.exp && g_env.exp[++i])
	{
		j = -1;
		split = ft_split(g_env.exp[i], '=');
		printf("declare -x %s=\"%s\"\n", split[0], split[1]);
		while (split[++j])
			free(split[j]);
		free(split);
	}
}

void	print_export(void)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (g_env.exp[++i])
	{
		j = -1;
		while (g_env.exp[++j + 1])
		{
			if (ft_strncmp(g_env.exp[j], g_env.exp[j + 1],
					ft_strlen(g_env.exp[j])) > 0)
			{
				tmp = g_env.exp[j];
				g_env.exp[j] = g_env.exp[j + 1];
				g_env.exp[j + 1] = tmp;
			}
		}
	}
	print_it();
}

int	check_char(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

void	free_node(t_args *args)
{
	free(args->str);
	free(args);
}
