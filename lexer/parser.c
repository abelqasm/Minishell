/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:24:49 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/20 13:55:00 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parser	*init_parser(t_lexer *lexer)
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser));
	parser->lexer = lexer;
	parser->token = lexer_next_token(lexer);
	return (parser);
}

// s_token get_piped_command(t_parser **start_ptr) // sum
// {
// 	t_parser *start = *start_ptr;
// 	s_token t1 = get_somethingelse_command(&start) // start has changed to the end
// 	if (start.type == pipe)
// 	{
// 		// start = next(start);
// 		t_parser t2 = get_piped_command(start);
// 		command3 = piped(t1, t2);
// 		return command3;
		
// 	}
// 	*start_ptr = start;
// 	return command1
// }

// // t_ast	*parser_parse(t_parser **parser)
// // {
// // 	t_parser	*start;
// // 	t_ast		*tree;
	
// // 	tree = init_ast();
// // }

// typedef struct token s_token;
// typedef enum{
// 	PIPE,
// 	COMMAND
// } e_token_type;

// typedef struct {
// 	s_token *left;
// 	s_token *right
// } pipe_data;

// typedef struct 
// {
// 	char *cmd;
// 	char **arg;
	
// } command_data;


// typedef union 
// {
// 	pipe_data 		*tree;
// 	command_data	*command;
	
// } u_type_of_token;

// struct token {
// 	e_token_type		type;
// 	u_type_of_token		data;
// };


// s_token *get_command(t_parser **start_ptr)
// {
// 	t_parser *start = *start_ptr;
// 	s_token *t = malloc(sizeof(s_token));
// 	t->type = COMMAND;
// 	command_data *cmd = malloc(  sizeof(command_data));
// 	t->data.command = cmd;
// 	while (start->token->e_type != TOKEN_PIPE)
// 	{
// 		// start = next(start);
// 		// fill cmd struct

// 	}
// 	*start_ptr = start;
// 	return t;
// }


// // a arg < file | b ; c arg


// s_token get_piped_command(t_parser **start_ptr) // sum
// {
// 	t_parser *start = *start_ptr;
// 	s_token t1 = get_somethingelse_command(&start) // start has changed to the end
// 	if (start.type == pipe)
// 	{
// 		// start = next(start);
// 		t_parser t2 = get_piped_command(start);
// 		command3 = piped(t1, t2);
// 		return command3;
		
// 	}
// 	*start_ptr = start;
// 	return command1
// }


// s_token get_somethingelse_command(t_parser **start_ptr) // mlti
// {
// 	t_parser *start = *start_ptr;
// 	s_token t1 = get_command(&start) // start has changed to the end
// 	if (start.type == SOMETHINGELSE)
// 	{
// 		// start = next(start);
// 		t_parser t2 = get_piped_command(start);
// 		command3 = somethingelse(t1, t2);
// 		return command3;
		
// 	}
// 	*start_ptr = start;
// 	return command1
// }




// s_token* piped(s_token *t1, s_token *t2)
// {

// 	s_token *t = malloc(sizeof(s_token));
// 	t->type = COMMAND;
// 	t->data.tree->left = t1;
// 	t->data.tree->right = t2;
// 	return t;
// }