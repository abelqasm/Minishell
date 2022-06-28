/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:14:11 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/28 17:08:46 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getenv_home(char *str)
{
	char	**split;
	char	*home;
	int		i;

	i = -1;
	if (!str)
		return (NULL);
	split = ft_split(ft_getenv(str), '=');
	home = ft_strdup(split[1]);
	while (split[++i])
		free(split[i]);
	free(split);
	return (home);
}

void	add_pwd(char *str, int type)
{
	char	*pwd;

	if (type == 1)
	{
		pwd = ft_strjoin("OLDPWD=", str);
		if (!check_value(g_env.env, "OLDPWD"))
			add_to_env(pwd);
		else
			replace_env_value(pwd);
		free(pwd);
	}
	if (type == 2)
	{
		pwd = ft_strjoin("PWD=", str);
		if (!check_value(g_env.env, "PWD"))
			add_to_env(pwd);
		else
			replace_env_value(pwd);
		free(pwd);
	}
}

void	cd_home(void)
{
	char	*old;
	char	*new;

	old = getcwd(NULL, 0);
	add_pwd(old, 1);
	chdir(ft_getenv_home("HOME"));
	new = getcwd(NULL, 0);
	add_pwd(new, 2);
	free(old);
	free(new);
}

void	cd(t_cmd_data *data)
{
	char	*old;
	char	*new;
	DIR		*dir;

	if (!data->args->next)
		cd_home();
	else
	{
		dir = opendir(data->args->next->str);
		if (!dir)
		{
			printf("%s: No such file or directory\n", data->args->next->str);
			closedir(dir);
			return ;
		}
		closedir(dir);
		old = getcwd(NULL, 0);
		add_pwd(old, 1);
		chdir(data->args->next->str);
		new = getcwd(NULL, 0);
		add_pwd(new, 2);
		free(old);
		free(new);
	}
}
