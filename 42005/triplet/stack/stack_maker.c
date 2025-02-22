/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:09:40 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/22 14:59:49 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void		ouroboros(t_stack **snek, int argn);
t_stack	*highlow_value(t_stack *stack, int argn);
void		pos_set(t_stack *stack, int argn, t_stack *high, t_stack *low);

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
	ouroboros(&stack, argn);
	// stack_inspector(&stack);//temporarily disabled
	positioner(stack->head, argn);
	return (stack);
}
//provision for last
void		ouroboros(t_stack **snek, int argn)
{
	t_stack	*bottom;
	if (snek != (*snek)->head && (*snek)->next == NULL)
		bottom = (*snek);
	snek = (*snek)->head;
	(*snek)->prev = bottom;
	bottom->next = (*snek);
	return ;
}
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
	new->cost_a = 0;
	new->cost_b = 0;
	new->prev = prev;
	new->next = NULL;
	return (new);
}

void		positioner(t_stack **stack, int argn)
{
	t_stack		*highest;
	t_stack		*lowest;
	int		mem;
	int		sec;

	highest = highlow_value(*stack, argn + 1, INT_MIN);
	while (argn-- > 1)
	{
		pos_set(highest->next, argn + 1, highest, lowest);
	}
	printf("positions set? wtf?");
}

void		pos_set(t_stack *stack, int argn, t_stack *high, t_stack *low)
{
	int		mem;
	int		bound;
	t_stack	*keep;

	mem = INT_MIN;
	bound = stack->size;
	keep = low;
	while (stack->pos != argn && stack->pos != 1 && low->pos != argn)
	{
		bound--;
		if (stack->pos == 0 && stack->value > keep->value)
			keep = stack;
		else if (stack)
			stack = stack->next;
		if (!bound)
			keep->pos = argn;
	}
}

t_stack	*highlow_value(t_stack *stack, int argn)
{
	t_stack	*modus;
	int		mode;

	modus = stack->head;
	while (argn--)
	{
		mode = modus->value;
		if (stack->value >= mode)
			modus = stack->value;
		modus = modus->next;
	}
	modus->pos = modus->size;
	return (modus);
}

/* void		stack_positioner(t_stack **stack, int argn, int i)
{
	t_stack	*mem;
	t_stack	*highest;
	int		high;

	while (--argn > 0)
	{
		mem = (*stack)->head;
		highest = NULL;
		high = INT_MIN;
		while (i < mem->size && mem->next != mem->head)
		{
			if (mem->value == INT_MIN && mem->pos == 0)
				mem->pos = 1;
			if (mem->value > high && mem->pos == 0)
			{
				high = mem->value;
				highest = mem;
				mem = (*stack)->head;
			}
			else
				mem = mem->next;
		}
		if (highest != NULL)
			highest->pos = argn;
	}
} */



/* 
void	stack_finisher(t_stack **stack, t_stack **lowest, int members)
{
	int		i;
	t_stack	*mem;
	t_stack	*prev;
	
	mem = *lowest;
	prev = *lowest;
	while (mem->position < members)
	{
		i = 0;
		while (i < members && mem->position != (prev->position + 1))
		{
			if (mem->next == NULL)
				mem = *stack;
			else
				mem = mem->next;
			i++;
		}
		if (prev->position == (mem->position) - 1)
		{
			prev->higher = mem;
			mem->lower = prev;
		}
		prev = mem;
	}
	return ;
} */
