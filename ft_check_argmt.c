/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:36:16 by abelqasm          #+#    #+#             */
/*   Updated: 2022/04/03 18:31:25 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_argmt(char *line)
{
	char	**check;

	check = ft_pipe_mngmt(line);
	if (!check)
		printf("command not found: \n");
	return (0);
}
