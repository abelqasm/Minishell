/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:01:50 by abelqasm          #+#    #+#             */
/*   Updated: 2022/08/02 15:05:14 by abelqasm         ###   ########.fr       */
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
	if (parser->token->e_type != TOKEN_ID
		&& parser->token->e_type != TOKEN_DOLLAR)
	{
		g_env.error++;
		return ;
	}
	args_push(&command->redir, parser->token->value, INPUT);
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
	if (parser->token->e_type != TOKEN_ID
		&& parser->token->e_type != TOKEN_DOLLAR)
	{
		g_env.error++;
		return ;
	}
	args_push(&command->redir, parser->token->value, OUTPUT);
	*start = parser;
}
