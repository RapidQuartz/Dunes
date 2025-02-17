/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:26:19 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/17 15:04:11 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		do_sa(t_stack **stack)
{
	write(1, "sa\n", 3);
	do_swap(*stack);
}

void		do_sb(t_stack **stack)
{
	write(1, "sb\n", 3);
	do_swap(*stack);
}
/* broken as fff */
void		do_twoswap(t_stack *stack)
{
	debug(GRNTXT"inside 2swap"DEFTXT);
	debug_print(stack, "BEFORE 2SWAP");
	t_stack	*first;//becomes second
	t_stack	*second;//becomes first
	if (stack == NULL || stack->next == NULL)
		return ;
	if (stack->prev != NULL)
		first = find_top(stack);
	else
		first = stack;
	second = first->next;
	first->prev = second;
	first->next = NULL;
	second->next = first;
	second->prev = NULL;
	debug(BLUTXT"leaving 2swap"DEFTXT);
	debug_print(stack, "AFTER 2SWAP");
}
void		do_swap(t_stack *stack)
{
	debug(GRNTXT"inside swap"DEFTXT);
	debug_print(stack, "BEFORE SWAP");
	t_stack	*first;//becomes second
	t_stack	*second;//becomes first
	t_stack	*third;//->prev becomes first
	if (stack == NULL || stack->next == NULL)
		return ;
	if (stack->prev != NULL)
		first = find_top(stack);
	else
		first = stack;
	second = first->next;
	third = second->next;
	first->prev = second;
	first->next = third;
	second->next = first;
	second->prev = NULL;
	third->prev = first;
	debug(BLUTXT"leaving swap"DEFTXT);
	debug_print(stack, "AFTER SWAP");
}
/* old version: doesnt work on pointers
void		do_swap(t_stack *stack)
{
	int		val;
	
	if (stack == NULL || stack->next == NULL)
		return ;
	val = stack->value;
	stack->value = stack->next->value;
	stack->next->value = val;
	val = stack->pos;
	stack->pos = stack->next->pos;
	stack->next->pos = val;
	val = stack->bucket;
	stack->bucket= stack->next->bucket;
	stack->next->bucket = val;
} */