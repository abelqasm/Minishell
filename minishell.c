/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:21:18 by abelqasm          #+#    #+#             */
/*   Updated: 2022/08/01 17:22:54 by abelqasm         ###   ########.fr       */
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
	g_env.exit_status = 1;
	return ;
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

void	add_to_history(char *str)
{
	int	out;

	out = open("/Users/abelqasm/history", O_RDWR | O_CREAT | O_APPEND, 0644);
	if (ft_isprint(str[0]))
	{
		add_history(str);
		write(out, str, ft_strlen(str));
		write(out, "\n", 1);
	}
}

void	read_from_history(void)
{
	char	*str;
	int		fd;

	fd = open("/Users/abelqasm/history", O_RDONLY);
	if (fd < 0)
		return ;
	str = get_next_line(fd);
	while (str)
	{
		add_history(str);
		free(str);
		str = get_next_line(fd);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*str;

	(void)argc;
	(void)argv;
	g_env.env = env_exp(env);
	g_env.exit_status = 0;
	read_from_history();
	while (1)
	{
		g_env.heredoc = 0;
		g_env.error = 0;
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		str = readline("myshell$ ");
		if (!str)
		{
			printf("exit");
			exit(g_env.exit_status);
		}
		if (ft_isprint(str[0]))
			add_history(str);
		add_to_history(str);
		execute_shell(str);
	}
}
