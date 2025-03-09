/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:49:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/09 19:50:26 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ree		*make_tree(t_snap **stack, t_ree *tree);

t_snap *push_swap(t_snap **stack)
{
	short		size;
	t_ree		*tree;

	size = (*stack)->a[0];
	tree = NULL;
	tree = make_tree(stack, tree);
	return (0);
}

t_ree		*make_tree(t_snap **stack, t_ree *tree)
{
	int	i;

	i = 0;
	if (tree == NULL)
	{
		tree = malloc(sizeof(*tree));
		if (!tree)
			return (NULL);
		tree->order = (*stack);
		while (i < 12)
		{
			tree->moves[i] = malloc(sizeof(t_snap));
			if (!tree->moves[i])
				return (NULL);
			tree->moves[i] = NULL;
			i++;
		}
	}
		
}