/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 02:47:35 by brmohamm          #+#    #+#             */
/*   Updated: 2022/07/24 22:57:59 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_table(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
	c = NULL;
}

int	input_error(char *c)
{
	if (c[0] == '-')
	{
		write(2, "minishell: export: `", 20);
		write(2, ": `", 3);
		write(2, &c[0], 1);
		write(2, &c[1], 1);
		write(2, "': invalid option\n", 18);
		g_env.exit_status = 1;
		return (1);
	}
	if ((ft_stralnum(c) == 1 && ft_strdigit(c) == 0)
		|| (c[0] >= '0' && c[0] <= '9'))
	{
		write(2, "minishell: export: `", 20);
		write(2, ": `", 3);
		write(2, c, ft_strlen(c));
		write(2, "': not a valid identifier\n", 28);
		g_env.exit_status = 1;
		return (1);
	}
	return (0);
}

void	unset_exist(int br)
{
	int		y;
	char	**cr;
	int		comp;

	y = 0;
	while (g_env.env[y])
		y++;
	y--;
	cr = (char **)malloc(sizeof(char *) * (y + 1));
	cr[y] = NULL;
	comp = 0;
	y = 0;
	while (g_env.env[comp])
	{
		if (br != comp)
		{
			cr[y] = ft_strdup(g_env.env[comp]);
			y++;
		}
		comp++;
	}
	free_table(g_env.env);
	copie_table(cr);
	free_table(cr);
}

void	delete(int *error, int *error_out, char *c)
{
	int	y;
	int	br;

	if (*error == 1)
		*error_out = 1;
	if (*error_out == 0)
	{
		y = 0;
		br = 0;
		while (g_env.env[y] != NULL)
		{
			if (ft_strncmp(g_env.env[y], c, ft_strlen(c)) == 0
				&& (g_env.env[y][ft_strlen(c)] == '\0'
				||g_env.env[y][ft_strlen(c)] == '='))
			{
				br = y;
				break ;
			}
			y++;
		}
		if (g_env.env[y] != NULL)
			unset_exist(br);
	}
}

/*error if input take 1 all the comm in the next dont export*/
void	unset(char **c, int false)
{
	int	i;
	int	error;
	int	error_out;

	i = 0;
	error_out = 0;
	while (c[i + 1] != NULL)
	{
		error = input_error(c[i + 1]);
		delete(&error, &error_out, c[i + 1]);
		i++;
	}
	if (false == 1)
	{
		if (error == 0)
			g_env.exit_status = 0;
		exit(g_env.exit_status);
	}
	if (error == 0)
		g_env.exit_status = 0;
}
