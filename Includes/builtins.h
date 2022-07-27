/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:39:51 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/27 12:36:43 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	free_node(t_args *args);
void	export(char **c, int pipe_exist, int out);
void	envm(char **c, int pipe_exist, int out);
void	echo(char **c, int pipe_exist, int out);
void	redir_or_pipe(int pipe_exist, int out);
void	pwd(char **c, int pipe_exist, int out);
void	cd(char **c, int false, int out);
void	open_built_io(t_cmd_data *data);
void	print_export(char *c, int out);
void	unset(char **c, int false);
void	copie_table(char **cp);
void	exitm(char **c);
void	free_table(char **c);
int		all_builtins01(char **c, int pipe_exist, int out);
int		all_builtins(char **c, int pipe_exist, int out);
int		args_error(char *c, int false, char *name);
int		errorin_args(char *c, int error, int i);
int		check_bultins(t_ast *ast);
int		replace(int i, char *c);
int		line_count(char **str);
int		input_error(char *c);
int		line_count(char **str);
char	*ft_getenv(char *env);
char	**sort_export(void);

#endif