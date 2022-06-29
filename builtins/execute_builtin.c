/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:54:06 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/29 09:48:21 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_builtin(t_cmd_data *data)
{
	t_builtins_function	built[7];

	built[0] = export;
	built[1] = unset;
	built[2] = ft_env;
	built[3] = cd;
	built[4] = pwd;
	// built[5] = echo;
	built[6] = ft_exit;
	built[check_builtin(data->args->str)](data);
}
