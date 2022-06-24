/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:06:04 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/24 19:06:32 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_args	*init_args(char *item)
{
	t_args	*list;

	list = malloc(sizeof(t_args));
	list->str = item;
	list->next = NULL;
	return (list);
}

void	args_push(t_args **args, char *item)
{
	t_args	*push;

	push = *args;
	if (!push)
	{
		push = init_args(item);
		*args = push;
		return ;
	}
	while (push->next)
		push = push->next;
	push->next = init_args(item);
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
	if (parser->token->e_type == TOKEN_RDOUT)
		fill_rdout(start, cmd);
}

t_data_type	fill_struct(t_parser **start)
{
	t_parser	*parser;
	t_cmd_data	*command;
	t_data_type	data;

	command = malloc(sizeof(t_cmd_data));
	parser = *start;
	command->args = NULL;
	command->intput = NULL;
	command->output = NULL;
	command->in = 0;
	command->out = 1;
	while (command_type(parser->token->e_type))
	{
		if (parser->token->e_type == TOKEN_ID
			|| parser->token->e_type == TOKEN_DOLLAR)
			args_push(&command->args, parser->token->value);
		if (parser->token->e_type == TOKEN_RDIN
			|| parser->token->e_type == TOKEN_RDOUT)
			fill_redirect(&parser, &command);
		parser->token = lexer_next_token(&parser);
	}
	*start = parser;
	data.command = command;
	return (data);
}
