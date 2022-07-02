/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:49:33 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/02 17:09:33 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_builtin(char *str)
{
	if (!ft_strncmp(str, "export", 6))
		return (0);
	if (!ft_strncmp(str, "unset", 5))
		return (1);
	if (!ft_strncmp(str, "env", 3))
		return (2);
	if (!ft_strncmp(str, "cd", 2))
		return (3);
	if (!ft_strncmp(str, "pwd", 3))
		return (4);
	if (!ft_strncmp(str, "echo", 4))
		return (5);
	if (!ft_strncmp(str, "exit", 4))
		return (6);
	return (-1);
}
