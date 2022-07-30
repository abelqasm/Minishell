/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:07:51 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/30 23:14:50 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_lexer
{
	char	*str;
	char	*delim;
	char	c;
	char	cp;
	int		pipe;
	size_t	i;
	size_t	size;
}	t_lexer;
t_lexer	*init_lexer(char *str);
void	lexer_advance(t_lexer *lexer);
void	lexer_advance_quotes(t_lexer *lexer, int type);
void	lexer_skip_whitespace(t_lexer *lexer);
void	set_expand_value(t_lexer *lexer, char **str);
void	lexer_add_value(t_lexer *lexer, char **str, int type);
int		lexer_args_char(int c);
int		lexer_args_quotes(int c);

#endif