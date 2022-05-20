/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:22:03 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/20 14:01:08 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./Includes/lexer.h"
# include "./Includes/token.h"
# include "./Includes/parser.h"
# include "./Includes/ast.h"
# include "./Includes/list.h"

typedef struct s_args
{
	char			*str;
	int				is_main;
	struct s_args	*next;
}	t_args;

typedef struct s_line
{
	t_args	*cmd;
	char	*intput;
	char	*output;
	int		pipe;
}	t_line;

int		ft_check_argmt(char *line);
char	*ft_check_cmd(char *cmd);
char	**ft_pipe_mngmt(char *argmt);
#endif
