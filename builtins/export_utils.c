/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:35:54 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/27 19:53:11 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_it(char **exp)
{
	int	i;

	i = -1;
	while (exp && exp[++i])
		printf("declare -x %s\n", exp[i]);
}

void	print_export(char ***exp)
{
	char	*tmp;
	char	**str;
	int		i;
	int		j;

	i = -1;
	str = *exp;
	while (str[++i])
	{
		j = -1;
		while (str[++j + 1])
		{
			if (ft_strncmp(str[j], str[j + 1], ft_strlen(str[j])))
			{
				tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = tmp;
			}
		}
	}
	print_it(str);
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
