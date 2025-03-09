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

#include "push_swap.h"

// void		sort_negativecost(t_stack **stack_a);


void	push_swap(t_stack **stack_a, t_stack **stack_b, int members)
{
	debug("inside push_swap");
	if (members == 2)
	{
		debug("doing sa inside ps");
		write (1, "sa\n", 3);
		// do_twoswap(*stack_a);
	}
	if (members == 3)
		debug("default");
	// sort_three(stack_a, stack_b, members);
	// if (members > 2 && members < 6)
	if (members > 3)
		debug("default");
	// set_cost(stack_a, stack_b, members);
}
