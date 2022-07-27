/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_io_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:37:46 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/27 12:38:53 by abelqasm         ###   ########.fr       */
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

void	open_input(t_cmd_data *data, char **input)
{
	int	i;

	i = -1;
	while (input && input[++i])
	{
		data->in = open(input[i], O_RDWR, 0644);
		if (data->in < 0)
		{
			printf("no such file or directory: %s\n", input[i]);
			g_env.exit_status = 1;
		}
	}
}

void	open_output(t_cmd_data *data, char **output)
{
	int	i;

	i = -1;
	while (output && output[++i])
	{
		if (data->append)
			data->out = open(output[i], O_RDWR | O_CREAT | O_APPEND, 0644);
		else
			data->out = open(output[i], O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
}

void	open_built_io(t_cmd_data *data)
{
	char	**input;
	char	**output;

	input = join_args(data->intput);
	output = join_args(data->output);
	open_input(data, input);
	open_output(data, output);
	if (input)
		free_table(input);
	if (output)
		free_table(output);
}
