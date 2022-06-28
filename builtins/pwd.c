/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:14:44 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/28 14:43:08 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(t_cmd_data *data)
{
	char	*str;

	(void)data;
	str = getcwd(NULL, 0);
	printf("%s\n", str);
	free(str);
}
