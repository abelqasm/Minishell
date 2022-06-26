/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:48:48 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/26 16:52:08 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_double(char *str, int c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int	check_parenth(char *str)
{
	int	i;
	int	left;
	int	right;

	i = -1;
	left = 0;
	right = 0;
	while (str[++i])
	{
		if (str[i] == '(')
			left++;
		if (str[i] == ')')
			right++;
	}
	if (left == right)
		return (1);
	return (0);
}

int	advance_quotes(t_lexer *lexer)
{
	lexer_advance(lexer);
	return (1);
}
