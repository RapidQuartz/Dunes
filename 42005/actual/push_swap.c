/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:46 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/28 11:35:19 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_n	*new_st(t_n *s, t_n *n);
void	push_b(t_n **a, t_n **b);

// void	push_swap(t_n **stack_a, t_n **stack_b)
void	push_swap(t_stack **stack)
{
	int	i;
	t_stack	*stk;
	
	i = 0;
	stk = (*stack);
debug("checking if n > 3");
	if (stk->st_a[0] == 2)
	;
		// swap(&sta);
	if (stk->st_a[0] == 3)
	;
		// sort_three(stack_a);
// debug("n > 3: print stack before sort stack");
// d_print_stack((*stack_a)->h);
	if (stk->st_a[0] > 3)
		exec_turk(stack);
		// sort_stack(&sta, &stb);
	return ;
}

