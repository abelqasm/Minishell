/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_cards.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:09 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/02 16:39:10 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

BOOL	**alloc_bool(char *pattern, size_t s, size_t p)
{
	BOOL	**tab;
	size_t	i;

	i = 0;
	tab = ft_calloc(sizeof(BOOL *), (s + 1));
	while (i < s + 1)
	{
		tab[i] = ft_calloc(sizeof(int), (p + 1));
		i++;
	}
	i = 0;
	tab[0][0] = TRUE;
	while (++i <= p)
	{
		if (pattern[i - 1] == '*')
			tab[0][i] = tab[0][i - 1];
	}
	return (tab);
}

BOOL	free_bool(BOOL **tab, size_t s, size_t p)
{
	size_t	i;
	int		res;

	res = tab[s][p];
	i = 0;
	while (i <= s)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (res);
}

BOOL	is_match(char *str, char *pattern, size_t s, size_t p)
{
	BOOL		**tab;
	size_t		i;
	size_t		j;

	tab = alloc_bool(pattern, s, p);
	i = 0;
	while (++i <= s)
	{
		j = 0;
		while (++j <= p)
		{
			if (str[i - 1] == pattern[j - 1])
				tab[i][j] = tab[i - 1][j - 1];
			else if (pattern[j - 1] == '*')
				tab[i][j] = tab[i - 1][j] || tab[i][j - 1];
			else
				tab[i][j] = FALSE;
		}
	}
	return (free_bool(tab, s, p));
}

void	fill_wildcards(char *str, t_cmd_data **cmd)
{
	struct dirent	*dirent;
	DIR				*dir;
	char			*dir_name;

	dir = opendir("./");
	dirent = readdir(dir);
	while (dirent)
	{
		if (is_match(dirent->d_name, str,
				ft_strlen(dirent->d_name), ft_strlen(str)))
		{
			dir_name = ft_strdup(dirent->d_name);
			args_push(&(*cmd)->args, dir_name);
		}
		dirent = readdir(dir);
	}
	closedir(dir);
}
