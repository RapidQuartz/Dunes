/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:26:19 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/02 20:38:56 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		do_sa(t_stack **stack)
{
	write(1, "sa\n", 3);
	do_swap(stack);
}

void		do_sb(t_stack **stack)
{
	write(1, "sb\n", 3);
	do_swap(stack);
}

void		do_swap(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*old;
	
	old = *((*stack)->head);
	new_head = old->next;
	new_head->prev = old->prev;
	old->prev->next = new_head;
	old->next = new_head->next;
	new_head->next->prev = old;
	new_head->next = old;
	update_head(old->head, new_head);
	(*stack) = new_head;
}

void		update_head(t_stack **old_head, t_stack *new_head)
{
	*old_head = new_head;
}