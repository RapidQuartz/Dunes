/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:26:19 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/31 17:41:58 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void		do_swap(t_stack *stack);
void		do_sa(t_stack **stack);
void		do_sb(t_stack **stack);


void		do_sa(t_stack **stack)
{
	printf("sa");
	do_swap(*stack);
}

void		do_sb(t_stack **stack)
{
	printf("sb");
	do_swap(*stack);
}

void		do_swap(t_stack *stack)
{
	t_stack	*swap;
	int		val;
	
	if (stack == NULL || stack->next == NULL)
		return ;
	val = stack->value;
	stack->value = stack->next->value;
	stack->next->value = val;
	val = stack->position;
	stack->position = stack->next->position;
	stack->next->position = val;
	val = stack->index;
	stack->index= stack->next->index;
	stack->next->index = val;
	val = stack->bucket;
	stack->bucket= stack->next->bucket;
	stack->next->bucket = val;
	swap = stack->lower;
	stack->lower = stack->next->lower;
	stack->next->lower = swap;
	swap = stack->higher;
	stack->higher = stack->next->higher;
	stack->next->higher = swap;
	stack->higher->
	stack->prev;
}
