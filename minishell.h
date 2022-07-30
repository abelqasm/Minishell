/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:22:03 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/30 12:48:18 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "./Includes/boolean.h"
# include "./libft/libft.h"
# include "./Includes/lexer.h"
# include "./Includes/token.h"
# include "./Includes/ast.h"
# include "./Includes/list.h"
# include "./Includes/exec.h"
# include "./Includes/builtins.h"
# include "./get_next_line/get_next_line.h"

void	execute_shell(char *str);
void	free_shell(t_ast **ast, t_parser **parser, t_exec **exec, int n_pipe);
void	print_ast(t_ast *ast, int n);
int		check_parenth(char *str);
int		check_double(char *str, int c);
int		advance_quotes(t_lexer *lexer);
char	**env_exp(char **env);
void	rl_replace_line(const char *text, int clear_undo);

t_global	g_env;

#endif
