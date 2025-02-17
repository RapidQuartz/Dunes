/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:20:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/17 15:31:20 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//sets 'cost' variables for number sets greater than 3
int		adjacent_triplet(t_stack *stack);
int		find_triplet(t_stack *stack);

void		set_cost(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	trip;

	trip = find_triplet(*stack_a);
}

int		adjacent_triplet(t_stack *stack)
{
	int	i;
	int	x;
	int	y;
	int	z;	

	i = 0;
	x = stack->pos;
	y = stack->next->pos;
	z = stack->next->next->pos;
	if (x == (y + 1) || (x == (y - 1)) || (x == (z + 1) || (x == (z - 1))))
	{
		debug("first condition");
		i++;
	}
	if (y == (z + 1) || (y == (z - 1)))
	{
		debug("second condition");
		i++;
	}
	return (i);
}
int		find_triplet(t_stack *stack)
{
	int	trip;
	
	trip = 0;
	while (stack->next->next != NULL)
	{
		debug("inside loop in tripletfinder");
		if (adjacent_triplet(stack))
			trip++;
		stack = stack->next;
	}
	printf(BLUTXT"\nTRIP = %d\n"DEFTXT, trip);
}
