/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:57:57 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/11 15:46:26 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef struct s_token
{
	char	*value;
	enum
	{
		TOKEN_PIPE,
		TOKEN_OR,
		TOKEN_AND,
		TOKEN_ID,
		TOKEN_SQUOTE,
		TOKEN_DQUOTE,
		TOKEN_LPARENTH,
		TOKEN_RPARENTH,
		TOKEN_DOLLAR,
		TOKEN_RDIN,
		TOKEN_RDOUT,
		TOKEN_APPEND,
		TOKEN_DELIM,
		TOKEN_EOF,
	} e_type;
}	t_token;
t_token	*init_token(char *str, int type);
t_token	*lexer_next_token(t_lexer *lexer);
t_token	*lexer_set_token_value(t_lexer *lexer, int type);
t_token	*lexer_help_set_token(t_lexer *lexer);
t_token	*lexer_parse_token(t_lexer *lexe, int type);
t_token	*lexer_parse_dollard(t_lexer *lexer);
t_token	*lexer_parse_expand(t_lexer *lexer);
t_token	*lexer_parse_quote(t_lexer *lexer, int type);
void	ft_tokenize(char *str);
#endif

// void	fill_redirect(t_parser **start, t_cmd_data **cmd)
// {
// 	t_parser	*parser;
// 	t_cmd_data	*command;

// 	parser = *start;
// 	command = *cmd;
// 	if (parser->token->e_type == TOKEN_RDIN)
// 	{
// 		free(parser->token);
// 		parser->token = lexer_next_token(parser->lexer);
// 		args_push(&command->intput, parser->token->value);
// 	}
// 	if (parser->token->e_type == TOKEN_RDOUT)
// 	{
// 		free(parser->token);
// 		parser->token = lexer_next_token(parser->lexer);
// 		args_push(&command->output, parser->token->value);
// 	}
// 	*start = parser;
// }

// t_data_type	fill_struct(t_parser **start)
// {
// 	t_parser	*parser;
// 	t_cmd_data	*command;
// 	t_data_type	data;

// 	command = malloc(sizeof(t_cmd_data));
// 	parser = *start;
// 	command->args = NULL;
// 	while (command_type(parser->token->e_type))
// 	{
// 		if (parser->token->e_type == TOKEN_ID
// 			|| parser->token->e_type == TOKEN_DOLLAR
// 			|| parser->token->e_type == TOKEN_SQUOTE
// 			|| parser->token->e_type == TOKEN_DQUOTE)
// 			args_push(&command->args, parser->token->value);
// 		if (parser->token->e_type == TOKEN_RDIN
// 			|| parser->token->e_type == TOKEN_RDOUT)
// 			fill_redirect(&parser, &command);
// 		free(parser->token);
// 		parser->token = lexer_next_token(parser->lexer);
// 	}
// 	*start = parser;
// 	data.command = command;
// 	return (data);
// }
