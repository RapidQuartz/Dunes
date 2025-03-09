/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:27:34 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/02 20:27:09 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		do_rotate(t_stack **stack_a, t_stack **stack_b, char stk, int dir)
{
	if (dir > 0)
		write(1, "r", 1);
	else if (dir < 0)
		write(1, "rr", 2);
	if (stack_a != NULL && stk == 'a')
		write(1, "a\n", 3);
	else if (stack_b != NULL && stk == 'b')
		write(1, "b\n", 3);
	else if (stk == 'c')
		write(1, "r\n", 3);
	if (stack_b == NULL || stk == 'a' && (dir > 0 || dir < 0))
		rotate_head(stack_a, NULL, stk, dir);
	if (stack_a == NULL || stk == 'b' && (dir > 0 || dir < 0))
		rotate_head(stack_b, NULL, stk, dir);
	if (stack_b != NULL && stack_a != NULL && stk == 'c' && \
		(dir > 0 || dir < 0))
		rotate_head(stack_a, stack_b, stk, dir);
}

void		rotate_head(t_stack **old, t_stack **new, char stk, int dir)
{
	if ((!new || new == NULL) && dir > 0)
		new = &(*old)->next;
	if ((!new || new == NULL) && dir < 0)
		new = &(*old)->prev;
	if ((stk == 'a' || stk == 'b') && dir == 1)
		*((*old)->head) = (*new)->next;
	if ((stk == 'a' || stk == 'b') && dir == -1)
		*((*old)->head) = (*new)->prev;
	if (stk == 'c' && dir == 1)
	{
		*((*old)->head) = (*old)->next;
		// *((*new)->head) = (*new)->next;
	}
	if (stk == 'c' && dir == -1)
	{
		*((*old)->head) = (*old)->prev;
		// *((*new)->head) = (*new)->prev;
	}
}
