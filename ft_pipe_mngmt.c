/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_mngmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:08:16 by abelqasm          #+#    #+#             */
/*   Updated: 2022/04/03 18:29:31 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_pipe_mngmt(char *argmt)
{
	char	**pipe_argmt;
	char	**check_cmd;
	int		pipes;

	pipe_argmt = ft_split(argmt, '|');
	pipes = word_count(argmt, '|');
	while (pipe_argmt && *pipe_argmt)
	{
		check_cmd = ft_split(*pipe_argmt, ' ');
		if (!ft_check_cmd(check_cmd[0]))
			return (NULL);
		free(check_cmd);
		pipe_argmt++;
	}
	return (pipe_argmt);
}
