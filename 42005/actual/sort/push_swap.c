// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:21:49 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/02 10:13:09 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void		sort_negativecost(t_stack **stack_a);


void		push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	t_tree	**tree;

	tree = NULL;
	size = (*stack_a)->size;
	if (size == 2)
		do_sa(stack_a);
	else if (size == 3)
		clue_find(stack_a, (*stack_a)->size);
	else if (size > 3)
	{
		tree  = tree_planter(stack_a, stack_b, tree);
		forest(stack_a, stack_b, tree);
	}
}
