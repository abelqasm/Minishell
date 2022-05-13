/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:22:03 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/13 14:00:02 by abelqasm         ###   ########.fr       */
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
# include "./Includes/token.h"
# include "./Includes/lexer.h"

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
	int		fd;
	int		pipe;
}	t_line;

typedef struct s_list
{
	t_line			*line;
	struct s_list	*next;
}	t_list;

int		ft_check_argmt(char *line);
char	*ft_check_cmd(char *cmd);
char	**ft_pipe_mngmt(char *argmt);
#endif
