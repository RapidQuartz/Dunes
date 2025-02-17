/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:09:40 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/17 17:49:14 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_maker(int count, char **arg, int members)
{
	t_stack		*stack;
	t_stack		*lowest;

	stack = stack_filler(count, arg, members);
	stack_inspector(&stack);
	stack_positioner(&stack, members + 1);
	stack_hilofinder(&stack, members);
	lowest = find_lowest(stack);
	// stack_finisher(&stack, &lowest, members);
	return (stack);
}

t_stack	*stack_filler(int count, char **arg, int members)
{
	t_stack		*stack;
	int			i;
	int			n;
	long int		value;

	i = 1;
	stack = NULL;
	while (i < count)
	{
		n = 0;
		while (n != arg_counter(arg[i]))
		{
			n++;
			value = get_number(arg[i], n);
			check_minmax(value, &stack);
			if (stack == NULL)
				stack = arg_stacker((int)value, stack);
			else
				make_bottom(&stack, arg_stacker((int)value, stack));
		}
		i++;
	}
	return (stack);
}
	
t_stack	*arg_stacker(int value, t_stack *prev)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	if (prev == NULL)
		new->index = 1;
	if (prev != NULL)
	{
		while (prev->next != NULL)
		{
			prev = prev->next;
		}
		new->index = prev->index + 1;
		new->prev = prev;
	}
	new->pos = 0;
	new->bucket = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->hi = NULL;
	new->lo = NULL;
	new->next = NULL;
	return (new);
}
	/* new->higher = NULL;
	new->lower = NULL; */

void	stack_positioner(t_stack **stack, int members)
{
	debug("in stack positioner");
	t_stack	*mem;
	t_stack	*highest;
	int		high;

	while (--members > 0)
	{
		mem = (*stack);
		highest = NULL;
		high = INT_MIN;
		while (mem)
		{
			if (mem->value == INT_MIN && mem->pos == 0)
				mem->pos = 1;
			if (mem->value > high && mem->pos == 0)
			{
				high = mem->value;
				highest = mem;
				mem = *stack;
			}
			else
				mem = mem->next;
		}
		if (highest != NULL)
			highest->pos = members;
	}
	debug("leaving stack positioner");
}

void	stack_hilofinder(t_stack **stack, int size)
{
	debug("in hlf");
	t_stack	*mem;
	t_stack	*nxt;
	int		count;
	int		i = 0;

	mem = (*stack);
	count	= 0;
	while (count < size /*&& i < 20 */)//works randomly but no provision for starting/stopping
	{
		if (mem->next != NULL)
			nxt = mem->next;
		else
			nxt = (*stack);
		debug("in hlf loop");
		while (nxt->next =! NULL)
		{
			count += stack_hilosetter(mem, nxt, size);
			if (nxt->next != NULL)
			{
				debug(".1");
				nxt = nxt->next;
			}
			else if (nxt->next == NULL)
			{
				debug(".2");
				break ;
			}
			debug("swooping");
			printf("nxt:%p\n", nxt);
		}
		debug("pooping");
		if (*stack)
		{
			debug("in blooping");
			nxt = (*stack);
		}
		debug("in looping");
		if (mem->next == NULL)
			mem = (*stack);
		else
			mem = mem->next;
		debug("looping");
	}
}

int	stack_hilosetter(t_stack *stack, t_stack *next, int size)
{
	debug("in hls");
	if (stack->pos == next->pos + 1)
	{
		debug("returning +1");
		if (stack->pos < size)
			stack->hi = next;
		if (next->pos > 1)
			next->lo = stack;
		return (1);
	}
	else if (stack->pos == next->pos - 1)
	{
		debug("returning -1");
		stack->lo = next;
		next->hi = stack;
		return (1);
	}
	debug("returning 0");
	return (0);
}

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
