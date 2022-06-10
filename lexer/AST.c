/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:06:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/10 21:12:51 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ast	*init_ast(int type)
{
	t_ast	*ast;

	ast = malloc(sizeof(t_ast));
	if (type == AST_PIPE || type == AST_AND || type == AST_OR)
		ast->data.tree = malloc(sizeof(t_node));
	ast->e_type = type;
	return (ast);
}

t_ast	*init_node(t_ast *left, t_ast *right, int type)
{
	t_ast	*node;

	if (type == TOKEN_PIPE)
		node = init_ast(AST_PIPE);
	if (type == TOKEN_OR)
		node = init_ast(AST_OR);
	if (type == TOKEN_AND)
		node = init_ast(AST_AND);
	if ( type == AST_PARENTH)
		node = init_ast(AST_PARENTH);
	node->data.tree->left = left;
	node->data.tree->right = right;
	return (node);
}

void	free_ast(t_ast **tree)
{
	t_args *tmp;
	t_ast	*ast;
	
	ast = *tree;
	if (ast->e_type == AST_PIPE || ast->e_type == AST_OR || ast->e_type == AST_AND)
	{
		free_ast(&ast->data.tree->left);
		free(ast->data.tree->left);
		free_ast(&ast->data.tree->right);
		free(ast->data.tree->right);
		free(ast->data.tree);
		return ; 
	}
	while (ast->data.command->args)
	{
		tmp = ast->data.command->args;
		free(ast->data.command->args->str);
		ast->data.command->args = ast->data.command->args->next;
		free(tmp);
	}
	free(ast->data.command);
}
