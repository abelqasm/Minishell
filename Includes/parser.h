/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:22:47 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/15 22:25:21 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../minishell.h"

typedef struct s_parser
{
	t_token	*token;
	t_lexer	*lexer;
}	t_parser;
t_parser *init_parser(t_lexer *lexer);
#endif