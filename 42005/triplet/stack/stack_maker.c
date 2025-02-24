/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:09:40 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/24 13:35:56 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_maker(int argc, char **argv, int argn)
{
	t_stack	*stack;
	t_stack	*head;
	int		*array;

	head = NULL;
	array = arg_array(argc, argv, argn, array);
	if (!array)
		error_handling(NULL, NULL);
	stack = stacker(array, argn, &head);
	ouroboros(stack->head, argn);
	positioner(stack->head, argn);
	stack_inspector(stack->head);
	return (*stack->head);
}

//provision for last

t_stack	*stacker(int *array, int argn, t_stack **head)
{
	int			index;
	t_stack		*stack;
	t_stack		*prev;
	
	index = 0;
	stack = NULL;
	prev = NULL;
	while (index < argn)
	{
		stack = create_node(array[index], stack, index, argn);
		if (stack == NULL)
			error_handling(head, NULL);
		if (index == 0)
			*head = stack;
		if (prev)
			prev->next = stack;
		stack->head = head;
		prev = stack;
		index++;
	}
	// stack = *stack->head;
	return (stack);
}

t_stack	*create_node(int value, t_stack *prev, int index, int argn)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		error_handling(&new, &prev);
	new->value = value;
	new->index = index + 1;
	new->pos = 0;
	new->size = argn;
	new->clue = '0';
	new->cost_a = 0;
	new->cost_b = 0;
	new->prev = prev;
	new->next = NULL;
	return (new);
}

void		positioner(t_stack **stack, int argn)
{
	t_stack	*alias;
	t_stack	*highest;
	int		curr;

	curr = argn;
	alias = (*stack);
	highest = NULL;
	while (1)
	{
		highest = highlow_value(alias, argn + 1);
		if (highest == NULL)
			break;
		else
			highest->pos = curr--;
	}
}

t_stack	*highlow_value(t_stack *stack, int argn)
{
	t_stack *highest;
	t_stack *curr;
	int	high;
	
	highest = NULL;
	high = INT_MIN;
	curr = stack;
	while (argn--)
	{
		if (curr->pos == 0 && curr->value > high)
		{
			high = curr->value;
			highest = curr;
		}
		curr = curr->next;
	}
	return (highest);
}


