/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:46 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/28 11:01:16 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_n	*new_st(t_n *s, t_n *n);
void	push_b(t_n **a, t_n **b);

void	push_swap(t_n **stack_a, t_n **stack_b)
{
	int	i;
	t_n	*sta;
	t_n	*stb;
	
	i = 0;
	sta = (*stack_a);
	stb = (*stack_b);
debug("checking if n > 3");
	if (sta->i->v == 2)
		swap(&sta);
	if (sta->i->v == 3)
		sort_three(stack_a);
debug("n > 3: print stack before sort stack");
d_print_stack((*stack_a)->h);
	if (sta->i->v > 3)
		exec_turk(stack_a, stack_b);
		// sort_stack(&sta, &stb);
	return ;
}

