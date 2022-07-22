/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:06:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/07/22 16:21:55 by abelqasm         ###   ########.fr       */
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

t_ast	*init_node(t_ast *left, t_ast *right)
{
	t_ast	*node;

	node = init_ast(AST_PIPE);
	node->data.tree->left = left;
	node->data.tree->right = right;
	return (node);
}

void	free_args(t_args **args)
{
	t_args	*tmp;

	while ((*args))
	{
		tmp = *args;
		free((*args)->str);
		(*args) = (*args)->next;
		free(tmp);
	}
}

void	free_ast(t_ast **ast)
{
	if ((*ast)->e_type == AST_PIPE || (*ast)->e_type == AST_OR
		|| (*ast)->e_type == AST_AND)
	{
		free_ast(&(*ast)->data.tree->left);
		free((*ast)->data.tree->left);
		free_ast(&(*ast)->data.tree->right);
		free((*ast)->data.tree->right);
		free((*ast)->data.tree);
		return ;
	}
	free_args(&(*ast)->data.command->args);
	free_args(&(*ast)->data.command->intput);
	free_args(&(*ast)->data.command->output);
	free((*ast)->data.command);
}

void	free_tree(t_ast **ast, t_parser **parser)
{
	free_ast(ast);
	free(*ast);
	if ((*parser)->lexer->delim)
		free((*parser)->lexer->delim);
	free((*parser)->lexer->str);
	free((*parser)->lexer);
	free((*parser)->token->value);
	free((*parser)->token);
	free((*parser));
}
