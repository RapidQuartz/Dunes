/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:43:28 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/18 20:00:42 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_maker(int argc, char **argv)
{
	t_stack		*stack;
	int			argn;
	int			index;
	int			pos;
	long int		value;

	index = 1;
	stack = NULL;
	argn = set_argn(argc, argv);
	while (index < argc)
	{
		pos = 0;
		while (pos != argn)
		{
			value = get_number(arg[index], argn);
			check_minmax(value, &stack);
			if (stack == NULL)
				stack = stack_generator((int)value, stack);
			else
				stack_orienter(&stack, stack_generator((int)value, stack));
			pos++;
		}
		index++;
	}
	return (stack);
}

int		set_argn(int argc, char **argv);

t_stack	*set_head(int value, t_stack *last, t_stack *head)
{
	t_stack	
}
t_stack	*stack_generator(t_stack *head)
t_stack	*stack_generator(t_stack *head)
{
	t_stack	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->value = value;
	new->pos = 0;
	new->bucket = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->hed = head;
	new->hii = NULL;
	new->low = NULL;
	new->next = NULL;
	return (new);
}
/* 	if (prev == NULL)
		new->index = 1;
	if (prev != NULL)
	{
		while (prev->next != NULL)
		{
			prev = prev->next;
		}
		new->index = prev->index + 1;
		new->prev = prev;
	} */