/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:14:22 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/28 15:51:30 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack_entry(int value, t_stack *prev)
{
	// debug("");
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	if (prev == NULL)
		new->index = 1;
	if (prev != NULL)
	{
		debug("'prev (stack provided) is NOT NULL'");
		while (prev->next != NULL)
		{
			debug("iterating through 'prev->next");
			prev = prev->next;
		}
		new->index = prev->index + 1;
		new->prev = prev;
	}
	new->position = 0;
	new->adjacency = 0;
	new-> higher = NULL;
	new-> lower = NULL;
	new->next = NULL;
	return (new);
}
// 3 debug lines

t_stack	*stack_maker(int ac, char **av)
{
	t_stack	*stack;
	long int	num;
	int		i;
	int		count;
	int		an;

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		count = 0;
		an = arg_counter(av[i]);
		while (count != an)
		{
			count++;
			num = get_number(av[i], count);
			if (i == 1 && count == 1)
				stack = new_stack_entry(num, NULL);
			else
				add_to_bottom(&stack, new_stack_entry(num, stack));
		}
		i++;
	}
	return (stack);
}


void	add_to_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bottom = find_stack_bottom(*stack);
	bottom->next = new;
}

void	give_stack_position(t_stack *stack, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (size > 0)
	{
		ptr = stack;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->position == 0)
				ptr->position = 1;
			if (ptr->value > value && ptr->position == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->position = size--;
	}
}
