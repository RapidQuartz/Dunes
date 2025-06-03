/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:09:40 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/02 18:50:53 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_maker(int argc, char **argv, int argn)
{
	t_stack	*stack;
	int		*array;
	int		index;
	t_stack	**head;

	index = 0;
	array = arg_array(argc, argv, argn, array);
	if (!array)
		error_handling(NULL, NULL);
	head = malloc(sizeof(t_stack *));
	if (!head)
		error_handling(NULL, NULL);
	stack = stacker(array, argn, index, head);
	if (!stack)
		error_handling(&stack, head);
	positioner(stack->head, argn);
	stack_inspector(stack->head);
	free(array);
	return (stack);
}

//provision for last

t_stack	*stacker(int *array, int argn, int index, t_stack **head)
{
	t_stack		*stack;
	t_stack		*prev;
	
	prev = NULL;
	while (index < argn)
	{
		stack = create_node(array[index], prev, index, argn);
		if (stack == NULL)
			error_handling(head, NULL);
		if (index == 0)
			*head = stack;
		if (prev)
			prev->next = stack;
		stack->head = head;
		prev = stack;
		index++;
		if (index == argn)
		{
			stack = *stack->head;
			stack->prev = prev;
			prev->next = stack;
		}
	}
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
	new->cost_r = 0;
	new->cost_a = 0;
	new->cost_s = 0;
	new->cost_m = 0;
	new->low = NULL;
	new->high = NULL;
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


