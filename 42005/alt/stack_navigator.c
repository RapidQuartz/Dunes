/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_navigator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:49:41 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/30 16:55:23 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	locates bottom of stack and returns pointer
t_stack *find_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);	
}

//	makes parameter "new" the new bottom of the stack
void	make_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;
	
	bottom = find_bottom(stack);
}