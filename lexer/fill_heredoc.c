/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:05:16 by abelqasm          #+#    #+#             */
/*   Updated: 2022/08/02 15:32:04 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*parse_herd(char *src)
{
	char	*str;
	t_lexer	*lexer;

	lexer = init_lexer(src);
	str = ft_calloc(1, sizeof(char));
	while (lexer->c)
	{
		while (lexer->c == '$')
			set_expand_value(lexer, &str);
		str = ft_realloc(str, (ft_strlen(str) + 2) * sizeof(char));
		ft_strlcat(str, (char []){lexer->c, 0}, ft_strlen(str) + 2);
		lexer_advance(lexer);
	}
	free(lexer);
	return (str);
}

void	fill_heredoc(t_parser *parser, int *fd)
{
	char	*str;
	char	*delim;

	if (parser->token->e_type == TOKEN_ID)
		delim = parser->token->value;
	else
		delim = parser->lexer->delim;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		str = readline("> ");
		if (!str)
			exit(0);
		if (!ft_strcmp(str, delim) || !str)
			break ;
		str = parse_herd(str);
		write(fd[1], str, ft_strlen(str) + 1);
		write(fd[1], "\n", 1);
		free(str);
	}
	if (str)
		free(str);
	exit(0);
}

void	fill_delim(t_parser **start, t_cmd_data **cmd)
{
	t_parser	*parser;
	int			fd[2];
	pid_t		pid;

	parser = *start;
	parser->token = lexer_next_token(&parser);
	if (parser->token->e_type != TOKEN_ID
		&& parser->token->e_type != TOKEN_DOLLAR)
	{
		g_env.error++;
		return ;
	}
	pipe(fd);
	pid = fork();
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (pid == 0)
		fill_heredoc(parser, fd);
	wait(&g_env.exit_status);
	set_exit_value(g_env.exit_status, 1);
	free(parser->token->value);
	close(fd[1]);
	(*cmd)->delim = fd[0];
	*start = parser;
}
