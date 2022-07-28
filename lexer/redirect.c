/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:01:50 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/28 12:50:26 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_rdin(t_parser **start, t_cmd_data **cmd)
{
	t_parser	*parser;
	t_cmd_data	*command;

	parser = *start;
	command = *cmd;
	parser->token = lexer_next_token(&parser);
	if (parser->token->e_type != TOKEN_ID)
	{
		g_env.error++;
		return ;
	}
	args_push(&command->intput, parser->token->value);
	*start = parser;
}

void	fill_rdout(t_parser **start, t_cmd_data **cmd)
{
	t_parser	*parser;
	t_cmd_data	*command;

	parser = *start;
	command = *cmd;
	if (parser->token->e_type == TOKEN_APPEND)
		command->append = 1;
	parser->token = lexer_next_token(&parser);
	if (parser->token->e_type != TOKEN_ID)
	{
		g_env.error++;
		return ;
	}
	args_push(&command->output, parser->token->value);
	*start = parser;
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
