/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:27:34 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/02 13:19:17 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_ra(t_stack **stack)
{
	write(1, "ra\n", 3);
	rotate(stack);
}

//	FIRST TO LAST
void rotate(t_stack **stack)
{
	debug(GRNTXT"rotating..");
	t_stack	*temporary_stack;
	t_stack	*previous;
	t_stack	*bottom;

	bottom = find_bottom(*stack);
	YLWTXT;
	debug("ok");
	temporary_stack = (*stack);
	debug("ok");
	temporary_stack->prev = bottom->prev;
	debug("ok");
	bottom->next = temporary_stack;
	debug("ok");
	temporary_stack->next = NULL;
	debug("ok");
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	debug("ok");
	debug("ok");
	DEFTXT;
}

//	LAST TO FIRST
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