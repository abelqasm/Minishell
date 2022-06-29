/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:42:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/29 10:18:13 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd_data	*init_command(void)
{
	t_cmd_data	*command;

	command = malloc(sizeof(t_cmd_data));
	command->args = NULL;
	command->intput = NULL;
	command->output = NULL;
	command->in = 0;
	command->out = 1;
	command->delim = 0;
	command->append = 0;
	return (command);
}

int	command_type(int type)
{
	if (type != TOKEN_EOF && type != TOKEN_PIPE && type != TOKEN_OR
		&& type != TOKEN_AND && type != TOKEN_RPARENTH)
		return (1);
	return (0);
}

void	fill_redirect(t_parser **start, t_cmd_data **cmd)
{
	t_parser	*parser;

	parser = *start;
	if (parser->token->e_type == TOKEN_RDIN)
		fill_rdin(start, cmd);
	if (parser->token->e_type == TOKEN_RDOUT
		|| parser->token->e_type == TOKEN_APPEND)
		fill_rdout(start, cmd);
	if (parser->token->e_type == TOKEN_DELIM)
		fill_delim(start, cmd);
}

t_data_type	fill_struct(t_parser **start)
{
	t_parser	*parser;
	t_cmd_data	*command;
	t_data_type	data;

	parser = *start;
	command = init_command();
	while (command_type(parser->token->e_type))
	{
		if (parser->token->e_type == TOKEN_ID
			|| parser->token->e_type == TOKEN_DOLLAR)
			args_push(&command->args, parser->token->value);
		if (parser->token->e_type == TOKEN_RDIN
			|| parser->token->e_type == TOKEN_RDOUT
			|| parser->token->e_type == TOKEN_DELIM
			|| parser->token->e_type == TOKEN_APPEND)
			fill_redirect(&parser, &command);
		parser->token = lexer_next_token(&parser);
	}
	*start = parser;
	data.command = command;
	return (data);
}
