/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:55:58 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/25 22:39:44 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_close_pipes(t_exec *exec)
{
	int	i;

	i = -1;
	while (++i < exec->n_pipe)
	{
		close(exec->pipe[i][0]);
		close(exec->pipe[i][1]);
	}
}
