/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:27:34 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/01 19:02:13 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_ra(t_stack **stack)
{
	write(1, "ra\n", 3);
	rotate(stack);
}

void rotate(t_stack **stack)
{
	t_stack	*temporary_stack;
	t_stack	*bottom;

	temporary_stack = *stack;
	*stack = (*stack)->next;
	bottom = find_bottom(*stack);
	temporary_stack->next = NULL;
	bottom->next = temporary_stack;
}

void reverse_rotate(t_stack **stack)
{
	t_stack	*temporary_stack;
	t_stack	*penultimate;
	t_stack	*bottom;

	temporary_stack = *stack;
	bottom = find_bottom(*stack);
	*stack = bottom;
	(*stack)->next = temporary_stack;
	penultimate = get_penultimate(*stack);
	penultimate->next = NULL;
}