/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:27:34 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/17 14:25:44 by akjoerse         ###   ########.fr       */
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
	debug_print(*stack, "BEFORE ROTATE");
	t_stack	*second;
	t_stack	*bottom;
	t_stack	*top;

	top = find_top(*stack);
	bottom = find_bottom(top);
	second = top->next;
	second->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
	debug("ok");
	DEFTXT;
	debug_print(*stack, "AFTER ROTATE");
}

//	LAST TO FIRST
void reverse_rotate(t_stack **stack)
{
	debug_print(*stack, "BEFORE RR");
	debug("inside reverse_rotate");
	t_stack	*top;
	t_stack	*penult;
	t_stack	*bottom;
	top = find_top(*stack);
	penult = find_penultimate(*stack);
	bottom = find_bottom(*stack);
//	debug <
	printf("top = %p\n", top);
	printf("penult = %p\n", penult);
	printf("bottom = %p\n", bottom);
//	debug >
	top->prev = bottom;
	bottom->next = top;
	penult->next = NULL;
	bottom->prev = NULL;
}
/* 
	temporary_stack = find_top(*stack);//save the top
	penultimate = find_penultimate(*stack);//find second to last (next bottom)
	bottom = find_bottom(*stack);//find the bottom to retrieve (next top)
	bottom->next = temporary_stack;//set new top
	bottom->prev = NULL;
	penultimate->next = NULL;
	debug("done with reverse_rotate");
	debug_print(*stack, "AFTER RR"); */