/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 02:05:32 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/01 12:16:05 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**error_handel(char *c, char **old)
{
	DIR		*dir;
	char	**temp;

	dir = opendir(c);
	if (dir == NULL)
	{
		write(2, "minishell: cd: ", 15);
		if (c)
			write(2, c, ft_strlen(c));
		else
			write(2, "HOME", 4);
		write(2, ": No such file or directory\n", 28);
		g_env.exit_status = 1;
		return (NULL);
	}
	closedir(dir);
	temp = (char **)malloc(sizeof(char *) * 3);
	temp[2] = NULL;
	*old = ft_strdup("OLDPWD=");
	temp[0] = ft_strdup("export");
	return (temp);
}

int	move_to_dir(char *c, t_cmd_data *cmd)
{
	char	cwd[256];
	char	*old;
	char	**temp;

	temp = error_handel(c, &old);
	if (temp == NULL)
		return (1);
	getcwd(cwd, sizeof(cwd));
	old = ft_ftjoin(old, cwd);
	temp[1] = ft_strdup(old);
	export(temp, 0, cmd);
	free(old);
	free(temp[1]);
	chdir(c);
	old = ft_strdup("PWD=");
	getcwd(cwd, sizeof(cwd));
	old = ft_ftjoin(old, cwd);
	temp[1] = ft_strdup(old);
	export(temp, 0, cmd);
	free_table(temp);
	temp = NULL;
	free(old);
	old = NULL;
	return (0);
}

void	cd(char **c, int false, t_cmd_data *cmd)
{
	int		error;
	char	*home;

	error = 0;
	if (open_built_io(cmd))
		return ;
	if (c[1] != NULL)
		error = move_to_dir(c[1], cmd);
	else if (c[1] == NULL)
	{
		home = ft_getenv("HOME");
		error = move_to_dir(home, cmd);
		free(home);
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
