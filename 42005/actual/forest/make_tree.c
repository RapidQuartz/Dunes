/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:38:37 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/04 17:43:14 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//	purpose:	initialize tree with empty values
t_tree	*make_tree(t_tree **tree, t_stack **stack)
{
	t_stack	*tower;
	t_tree	**roots;
	t_tree	*trunk;
	t_tree	*stump;
	int		i;

	i = 0;
	tower = *((*stack)->head);
	trunk = NULL;
	roots = NULL;
	while (i < 16)
	{
		trunk = plant_tree(&trunk, roots);
		if (!trunk || trunk == NULL)
			tree_error(tree, roots, stack, NULL);
		roots = trunk->roots;
	}
	return (trunk);
}

t_tree	*plant_tree(t_tree **trunk, t_tree **roots)
{
	t_tree	*tree;

	tree = malloc(sizeof(*tree));
	if (!trunk || trunk == NULL)
		return (NULL);
	tree->rings = 0;
	tree->trunk = NULL;
	tree->branch = NULL;
	tree->leaf = NULL;
	tree->seed = NULL;
	tree = *plant_roots(&tree, roots);
	if (tree == NULL)
		return (NULL);
	if (trunk != NULL && (*trunk) != NULL)
		(*trunk)->next = tree;
	return (tree);
}

t_tree	**plant_roots(t_tree **tree, t_tree **roots)
{
	t_tree	**new_roots;
	
	if (roots == NULL)
	{
		new_roots = malloc(sizeof(t_tree *));
		if (!new_roots)
			return (NULL);
		else
			(*new_roots) = *tree;
	}
	else
		new_roots = roots;
	(*tree)->roots = new_roots;
	return (tree);
}
