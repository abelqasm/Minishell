/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:01:50 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/24 19:11:14 by abelqasm         ###   ########.fr       */
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
		parser->syntax_error++;
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
	parser->token = lexer_next_token(&parser);
	if (parser->token->e_type != TOKEN_ID)
	{
		parser->syntax_error++;
		return ;
	}
	args_push(&command->output, parser->token->value);
	*start = parser;
}
