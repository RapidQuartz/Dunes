/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:46 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/04 15:47:33 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_swap(t_n **stack_a, t_n **stack_b)
void	push_swap(t_stack **stack)
{
	int	i;
	t_stack	*stk;
	
	i = 0;
	stk = (*stack);
	if (stack_is_sorted(stk))
		return ;
	if (stk->a[0] == 2)
		swap_a(stk->a);
	else if (stk->a[0] == 3)
		sort_three(stack);
	else if (stk->a[0] > 3)
		exec_turk(stack, 0);
	return ;
}

