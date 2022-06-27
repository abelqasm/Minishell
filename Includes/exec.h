/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:40:51 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/27 20:10:26 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

typedef struct s_exec
{
	pid_t	*pid;
	int		pid_i;
	int		**pipe;
	int		i;
	int		first;
	int		pipe_parenth;
	int		n_pipe;
}	t_exec;

typedef struct s_global
{
	char	**env;
	char	**exp;	
}	t_global;

t_exec	*init_exec(int n_pipe);
void	execute(t_cmd_data *data, char **env);
void	open_io(t_cmd_data *data);
void	execute_node(t_ast *ast, t_exec *exec, int flag);
void	execute_ast(t_ast *ast, t_exec *exec, int flag);
char	*ft_find_cmd(char **paths, char *cmd);
char	*join_args(t_args *args);
char	*ft_getenv(char *env);
#endif