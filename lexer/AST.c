/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:06:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/20 13:56:13 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ast	*init_ast(int type)
{
	t_ast	*ast;

	ast = malloc(sizeof(t_ast));
	ast->e_type = type;
	ast->data = NULL;
	return (ast);
}
