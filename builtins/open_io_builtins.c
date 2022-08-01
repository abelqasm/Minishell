/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_io_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:37:46 by abelqasm          #+#    #+#             */
/*   Updated: 2022/08/01 12:04:13 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**sort_export(void)
{
	char	*tmp;
	char	**export;
	int		i;
	int		j;

	i = -1;
	export = env_exp(g_env.env);
	while (export[++i])
	{
		j = -1;
		while (export[++j + 1])
		{
			if (ft_strncmp(export[j], export[j + 1],
					ft_strlen(export[j])) > 0)
			{
				tmp = export[j];
				export[j] = export[j + 1];
				export[j + 1] = tmp;
			}
		}
	}
	return (export);
}

int	error_exit(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, ": No such file or directory", 27);
	write(2, "\n", 1);
	g_env.exit_status = 1;
	return (1);
}

int	open_built_io(t_cmd_data *data)
{
	t_args	*args;
	int		value;

	args = data->redir;
	value = 0;
	while (args && !value)
	{
		if (args->e_type == INPUT)
		{
			data->in = open(args->str, O_RDWR, 0644);
			if (data->in < 0)
				value = error_exit(args->str);
		}
		else if (args->e_type == OUTPUT)
		{
			if (data->append)
				data->out = open(args->str, O_RDWR | O_CREAT | O_APPEND, 0644);
			else
				data->out = open(args->str, O_RDWR | O_CREAT | O_TRUNC, 0644);
		}
		args = args->next;
	}
	return (value);
}
