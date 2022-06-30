/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:39:51 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/30 16:37:09 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef void	(*t_builtins_function)(t_cmd_data *data);
int		check_builtin(char *str);
void	execute_builtin(t_cmd_data *data);
void	add_export_value(char *value);
void	print_it(void);
void	print_export(void);
void	export(t_cmd_data *data);
void	unset(t_cmd_data *data);
void	ft_env(t_cmd_data *data);
void	pwd(t_cmd_data *data);
void	cd(t_cmd_data *data);
void	echo(t_cmd_data *data);
void	ft_exit(t_cmd_data *data);
void	add_to_env(char *value);
int		line_count(char **str);
int		check_char(char *str, char c);
int		check_value(char **src, char *value);
int		check_existing(char *src, char *dst);
void	replace_env_value(char *value);
void	replace_value(char *value);
void	free_node(t_args *args);

#endif