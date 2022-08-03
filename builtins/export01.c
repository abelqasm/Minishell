/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 02:44:39 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/02 10:28:13 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copie_table(char **cp)
{
	int	i;

	i = 0;
	while (cp[i])
		i++;
	g_env.env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (cp[i])
	{
		g_env.env[i] = ft_strdup(cp[i]);
		i++;
	}
	g_env.env[i] = NULL;
}

void	print_error_of_equal(char *c, int *error)
{
	if (c[0] == '=')
	{
		*error = 1;
		write(2, "minishell: export: `", 20);
		write(2, c, ft_strlen(c));
		write(2, "': not a valid identifier\n", 26);
		g_env.exit_status = 1;
	}
}

/*error if input take 1 all the comm in the next dont export*/
int	errorin_args(char *c, int error, int i)
{
	char	*befor_equal;
	int		j;

	if (c)
	{
		j = 0;
		befor_equal = malloc(i + 1);
		if (!befor_equal)
			return (0);
		befor_equal[i] = '\0';
		while (c[j] && j < i)
		{
			befor_equal[j] = c[j];
			j++;
		}
		error = input_error(befor_equal);
		print_error_of_equal(c, &error);
		if (error == 1)
		{
			free(befor_equal);
			return (1);
		}
		free(befor_equal);
	}
	return (0);
}

int	replace(int i, char *c)
{
	char	*cr;
	int		x;
	int		j;

	x = i;
	i = 0;
	while (g_env.env[i] && ft_strncmp(g_env.env[i], c, x) != 0)
		i++;
	if (g_env.env[i] != '\0')
	{
		cr = malloc(sizeof(char *) * ft_strlen(c) + 1);
		cr[ft_strlen(c)] = '\0';
		j = 0;
		while (c[j])
		{
			cr[j] = c[j];
			j++;
		}
		free(g_env.env[i]);
		g_env.env[i] = ft_strdup(cr);
		free(cr);
		return (1);
	}
	return (0);
}

void	print_export(char *c, int out)
{
	int	equal_exist;
	int	y;

	equal_exist = 0;
	y = 0;
	while (c[y])
	{
		if (y == 0)
			write(out, "declare -x ", 11);
		write(out, &c[y], 1);
		if (c[y] == '=' && equal_exist != 1)
		{
			write(out, "\"", 1);
			equal_exist = 1;
		}
		y++;
		if (c[y] == '\0' && equal_exist == 1)
		{
			write(out, "\"", 1);
			equal_exist = 0;
		}
		if (c[y] == '\0')
			write(out, "\n", 1);
	}
}
