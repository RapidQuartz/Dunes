/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:09:40 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/30 17:01:18 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	takes: arguments and their count
//	returns: a stack
t_stack	*stack_maker(int count, char **arg, int members)
{
	t_stack		*stack;
	int			i;
	int			n;
	int			m;
	long int	value;

	i = 1;
	stack = NULL;
	while (members && i < count)
	{
		n = arg_counter(arg[i]);
		m = 1;
		while (m != n)
		{
			value = get_number(arg[i], m);
			if (stack == NULL)
				stack = arg_stacker(value, stack);
			else
				make_bottom(&stack, arg_stacker(value, stack));
			m++;
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
	new->position = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->higher = NULL;
	new->lower = NULL;
	new->next = NULL;
	return (new);
}

int		arg_navigator(int count, char **args);
int		arg_navigator(int count, char **args)
{
	
}


