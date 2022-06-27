/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:49:33 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/27 19:47:14 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_builtin(char *str)
{
	if (!ft_strncmp(str, "export", ft_strlen(str)))
		return (0);
	if (!ft_strncmp(str, "unset", ft_strlen(str)))
		return (1);
	if (!ft_strncmp(str, "env", ft_strlen(str)))
		return (2);
	if (!ft_strncmp(str, "cd", ft_strlen(str)))
		return (3);
	if (!ft_strncmp(str, "pwd", ft_strlen(str)))
		return (4);
	if (!ft_strncmp(str, "echo", ft_strlen(str)))
		return (5);
	if (!ft_strncmp(str, "exit", ft_strlen(str)))
		return (6);
	return (-1);
}
