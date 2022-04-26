/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:57:57 by abelqasm          #+#    #+#             */
/*   Updated: 2022/04/25 08:30:51 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef struct s_token
{
	char	*value;
	enum
	{
		TOKEN_ID,
		TOKEN_SLQUOTE,
		TOKEN_SRQUOTE,
		TOKEN_DLQUOTE,
		TOKEN_DRQUOTE,
		TOKEN_DOLLAR,
		TOKEN_RDIN,
		TOKEN_RDOUT,
		TOKEN_APPEND,
		TOKEN_DELIM,
		TOKEN_PIPE,
		TOKEN_OR,
		TOKEN_AND,
		TOKEN_EOF,
	} e_type;
}	t_token;
t_token	*init_token(char *str, int type);
void	ft_tokenize(char *str);
#endif