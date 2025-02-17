/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:27:34 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/17 11:25:14 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_ra(t_stack **stack)
{
	write(1, "ra\n", 3);
	rotate(stack);
}

void	do_rra(t_stack **stack)
{
	write(1, "rra\n", 3);
	reverse_rotate(stack);
}

//	FIRST TO LAST
void rotate(t_stack **stack)
{
	debug(GRNTXT"rotating.."DEFTXT);
	t_stack	*temporary_stack;
	t_stack	*previous;
	t_stack	*bottom;

	bottom = find_bottom(*stack);
	YLWTXT;
	debug("temporary_stack = (*stack);");
	temporary_stack = (*stack);
	debug("temporary_stack->prev = bottom->prev;");
	temporary_stack->prev = bottom->prev;
	debug("bottom->next = temporary_stack;");
	bottom->next = temporary_stack;
	debug("temporary_stack->next = NULL;");
	temporary_stack->next = NULL;
	debug("(*stack) = (*stack)->next;");
	(*stack) = (*stack)->next;
	debug(REDTXT"ok here is closer to the error"DEFTXT);
	// printf(GRNTXT"[3] pointer for stack: %p\t next: %p\n"DEFTXT, (*stack)->prev, (*stack)->next);
	// (*stack)->prev = NULL;
	debug("ok");
	DEFTXT;
}

//	LAST TO FIRST
void reverse_rotate(t_stack **stack)
{
	debug("inside reverse_rotate");
	t_stack	*temporary_stack;
	t_stack	*penultimate;
	t_stack	*bottom;
	
	debug(BLUTXT"1 ok"DEFTXT);
	temporary_stack = *stack;//save the top
	penultimate = get_penultimate(*stack);
	debug(BLUTXT"2 ok"DEFTXT);
	bottom = find_bottom(*stack);//find the bottom to retrieve
	debug(BLUTXT"3 ok"DEFTXT);
	*stack = bottom;//stack top is bottom
	debug(BLUTXT"4 ok"DEFTXT);
	debug(GRNTXT"HERE IT DIES"DEFTXT);
	(*stack)->next = temporary_stack;//next after top is previous top
	/* `bottom->next = top` */
	debug(BLUTXT"5 ok"DEFTXT);
	debug(BLUTXT"6 ok"DEFTXT);
	penultimate->next = NULL;
}