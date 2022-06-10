/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:06:04 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/10 18:58:34 by abelqasm         ###   ########.fr       */
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

t_data_type	fill_struct(t_parser **start)
{
	t_parser	*parser;
	t_cmd_data	*command;
	t_data_type	data;

	command = malloc(sizeof(t_cmd_data));
	parser = *start;
	command->args = NULL;
	while (parser->token->e_type != TOKEN_EOF && parser->token->e_type != TOKEN_PIPE
			&& parser->token->e_type != TOKEN_OR && parser->token->e_type != TOKEN_AND 
			&& parser->token->e_type != TOKEN_RPARENTH)
	{
		if (parser->token->e_type == TOKEN_ID || parser->token->e_type == TOKEN_DOLLAR
				|| parser->token->e_type == TOKEN_SQUOTE || parser->token->e_type == TOKEN_DQUOTE)
			args_push(&command->args, parser->token->value);
		if (parser->token->e_type == TOKEN_RDIN)
		{
			free(parser->token);
			parser->token = lexer_next_token(parser->lexer);
			args_push(&command->intput, parser->token->value);
		}
		if (parser->token->e_type == TOKEN_RDOUT)
		{
			free(parser->token);
			parser->token = lexer_next_token(parser->lexer);
			args_push(&command->output, parser->token->value);
		}
		free(parser->token);
		parser->token = lexer_next_token(parser->lexer);
	}
	// free(parser->token);
	*start = parser;
	data.command = command;
	return (data);
}
