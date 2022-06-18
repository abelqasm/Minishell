/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:40:51 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/18 19:10:28 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

typedef struct s_exec
{
	char	**env;
	int		pipe[2];
	int		fd;
	int		first;
}	t_exec;
t_exec	*init_exec(char **env);
char	*ft_find_cmd(char **paths, char *cmd);
char	*join_args(t_args *args);
void	execute(t_cmd_data *data, char **env);
void	open_io(t_cmd_data *data);
void	exec_ast(t_ast *ast, t_exec *exec, int flag);
#endif