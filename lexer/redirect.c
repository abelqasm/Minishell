/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:01:50 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/02 17:07:21 by abelqasm         ###   ########.fr       */
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
		parser->lexer->error++;
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
		parser->lexer->error++;
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
	signal(SIGQUIT, SIG_DFL);
	while (1)
	{
		str = readline("> ");
		if (!str)
			exit(0);
		if (!ft_strncmp(str, delim, ft_strlen(delim)) || !str)
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
	int			exit_status;

	parser = *start;
	parser->token = lexer_next_token(&parser);
	if (parser->token->e_type != TOKEN_ID
		&& parser->token->e_type != TOKEN_DOLLAR)
	{
		parser->lexer->error++;
		return ;
	}
	pipe(fd);
	pid = fork();
	if (pid == 0)
		fill_heredoc(parser, fd);
	wait(&exit_status);
	g_env.exit_status = WEXITSTATUS(exit_status);
	free(parser->token->value);
	close(fd[1]);
	(*cmd)->delim = fd[0];
	*start = parser;
}
