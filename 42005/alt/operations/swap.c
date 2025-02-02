/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:26:19 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/02 12:13:44 by akjoerse         ###   ########.fr       */
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
}
