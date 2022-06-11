/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:06:36 by abelqasm          #+#    #+#             */
/*   Updated: 2022/06/11 16:34:34 by abelqasm         ###   ########.fr       */
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
	node->data.tree->left = left;
	node->data.tree->right = right;
	return (node);
}

void	free_ast(t_ast **ast)
{
	t_args	*tmp;

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
	while ((*ast)->data.command->args)
	{
		if ((*ast)->data.command->intput)
			free((*ast)->data.command->intput);
		if ((*ast)->data.command->output)
			free((*ast)->data.command->output);
		tmp = (*ast)->data.command->args;
		free((*ast)->data.command->args->str);
		(*ast)->data.command->args = (*ast)->data.command->args->next;
		free(tmp);
	}
	free((*ast)->data.command);
}

void	free_tree(t_ast **ast, t_parser **parser)
{
	free_ast(ast);
	free((*parser)->lexer->str);
	free((*parser)->lexer);
	free((*parser)->token->value);
	free((*parser)->token);
	free((*parser));
	free(*ast);
}
