/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:06:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/23 14:23:34 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ast	*init_ast(int type)
{
	t_ast	*ast;

	ast = malloc(sizeof(t_ast));
	if (type == AST_PIPE)
		ast->data.tree = malloc(sizeof(t_node));
	ast->e_type = type;
	return (ast);
}

t_ast	*init_node(t_ast *left, t_ast *right)
{
	t_ast	*node;

	node = init_ast(AST_PIPE);
	node->data.tree->left = left;
	node->data.tree->right = right;
	return (node);
}
