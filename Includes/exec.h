/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:40:51 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/28 12:13:38 by abelqasm         ###   ########.fr       */
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
	int		n_pipe;
}	t_exec;

typedef struct s_global
{
	char	**env;
	int		error;
	int		npipe;
	int		heredoc;
	int		exit_status;
}	t_global;

t_exec	*init_exec(int n_pipe);
void	execute(t_cmd_data *data, char **env, t_exec *exec);
void	open_io(t_cmd_data *data);
void	ft_close_pipes(t_exec *exec);
void	set_exit_value(int exit_status, int type);
void	execute_node(t_ast *ast, t_exec *exec, int flag);
void	execute_ast(t_ast *ast, t_exec *exec, int flag);
char	*ft_find_cmd(char **paths, char *cmd);
char	**join_args(t_args *args);
char	**split_args(char	**args);
char	*ft_getenv(char *env);
#endif