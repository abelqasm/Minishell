/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:01:50 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/29 11:20:41 by abelqasm         ###   ########.fr       */
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

	while (1)
	{
		str = readline("> ");
		if (!ft_strncmp(str, parser->token->value,
				ft_strlen(parser->token->value)) || !str)
			break ;
		write(fd[1], str, ft_strlen(str) + 1);
		write(fd[1], "\n", 1);
		free(str);
	}
	if (str)
		free(str);
}

void	fill_delim(t_parser **start, t_cmd_data **cmd)
{
	t_parser	*parser;
	int			fd[2];

	parser = *start;
	parser->token = lexer_next_token(&parser);
	if (parser->token->e_type != TOKEN_ID)
	{
		parser->lexer->error++;
		return ;
	}
	pipe(fd);
	fill_heredoc(parser, fd);
	free(parser->token->value);
	close(fd[1]);
	(*cmd)->delim = fd[0];
	*start = parser;
}
