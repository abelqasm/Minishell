/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:22:03 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/23 15:59:47 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./Includes/lexer.h"
# include "./Includes/token.h"
# include "./Includes/ast.h"
# include "./Includes/list.h"
# include "./Includes/exec.h"

void	execute_shell(char *str, char **env);
void	execute_tree(t_ast *ast, t_exec *exec);
void	free_shell(t_ast **ast, t_parser **parser, t_exec **exec, int n_pipe);

#endif
