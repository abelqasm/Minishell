/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:57:57 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/25 15:28:25 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef struct s_parser	t_parser;
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
struct s_parser
{
	t_token	*token;
	t_lexer	*lexer;
	int		syntax_error;
};
t_parser	*init_parser(t_lexer *lexer);
t_token		*init_token(char *str, int type);
t_token		*lexer_next_token(t_parser **parser);
t_token		*lexer_set_token_value(t_lexer *lexer, int type);
t_token		*lexer_help_set_token(t_lexer *lexer);
t_token		*lexer_parse_token(t_lexer *lexe, int type);
t_token		*lexer_parse_dollard(t_lexer *lexer);
t_token		*lexer_parse_expand(t_lexer *lexer);
t_token		*lexer_parse_single_quote(t_lexer *lexer, int type);
t_token		*lexer_parse_double_quote(t_lexer *lexer, int type);
t_token		*lexer_tokenize(t_lexer *lexer);
void		fill_rdin(t_parser **start, t_cmd_data **cmd);
void		fill_rdout(t_parser **start, t_cmd_data **cmd);
void		ft_tokenize(char *str, char **env);
#endif
