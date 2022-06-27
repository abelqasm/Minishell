/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:39:51 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/27 19:55:58 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef void	(*t_builtins_function)(t_cmd_data *data);
int		check_builtin(char *str);
void	execute_builtin(t_cmd_data *data);
void	export_value(char *value);
void	print_it(char **exp);
void	print_export(char ***exp);
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

#endif