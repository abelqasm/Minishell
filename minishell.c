/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:21:18 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/21 10:39:29 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	ft_putchar_fd('\n', 1);
	rl_on_new_line();
	rl_redisplay();
	return ;
}

void	catch_signal(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

char	**env_exp(char **env)
{
	char	**str;
	int		i;

	str = malloc(sizeof(char *) * (line_count(env) + 1));
	i = -1;
	while (env[++i])
		str[i] = ft_strdup(env[i]);
	str[i] = 0;
	return (str);
}

int	main(int argc, char **argv, char **env)
{
	char	*str;

	(void)argc;
	(void)argv;
	g_env.env = env_exp(env);
	while (1)
	{
		g_env.error = 0;
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		str = readline("myshell >");
		if (!str)
		{
			printf("exit");
			exit(0);
		}
		add_history(str);
		execute_shell(str);
	}
}

// ls -la | wc -l || cat Makefile