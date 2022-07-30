/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:39:51 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/30 10:13:12 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	free_node(t_args *args);
void	export(char **c, int pipe_exist, t_cmd_data *cmd);
void	envm(char **c, int pipe_exist, t_cmd_data *cmd);
void	echo(char **c, int pipe_exist, t_cmd_data *cmd);
void	redir_or_pipe(int pipe_exist, int out);
void	pwd(char **c, int pipe_exist, t_cmd_data *cmd);
void	cd(char **c, int false, t_cmd_data *cmd);
void	print_export(char *c, int out);
void	unset(char **c, int false, t_cmd_data *cm);
void	copie_table(char **cp);
void	exitm(char **c, t_cmd_data *cmd);
void	free_table(char **c);
int		all_builtins01(char **c, int pipe_exist, t_cmd_data *cmd);
int		all_builtins(char **c, int pipe_exist, t_cmd_data *cmd);
int		args_error(char *c, int false, char *name);
int		errorin_args(char *c, int error, int i);
int		open_built_io(t_cmd_data *data);
int		check_bultins(t_ast *ast);
int		replace(int i, char *c);
int		line_count(char **str);
int		input_error(char *c);
int		line_count(char **str);
char	*ft_getenv(char *env);
char	**sort_export(void);

#endif