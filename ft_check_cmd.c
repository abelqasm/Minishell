/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:33:13 by abelqasm          #+#    #+#             */
/*   Updated: 2022/04/03 02:33:33 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_check_cmd(char *cmd)
{
	char	**paths;
	char	*cmd_path;
	char	*tmp;

	paths = ft_split(getenv("PATH"), ':');
	while (paths && *paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		paths++;
	}
	return (NULL);
}
