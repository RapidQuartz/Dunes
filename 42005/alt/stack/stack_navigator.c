/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_navigator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:49:41 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/17 14:52:15 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//	locates bottom of stack and returns pointer
t_stack *find_bottom(t_stack *stack)
{
	debug("ok then");
	if (stack)
	{
		while (stack && stack->next != NULL)
			stack = stack->next;
	}
	debug("done with find bottom");//SEGFAULT
	return (stack);	
}


t_stack	*find_lowest(t_stack *stack)
{
	t_stack	*lowest;
	
	lowest = stack;
	while (lowest->next != NULL)
	{
		if (lowest->pos == 1)
			break;
		else if (lowest->pos != 1)
			lowest = lowest->next;
	}
	return (lowest);
}


//	makes parameter "new" the new bottom of the stack
void	make_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;
	
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bottom = find_bottom(*stack);
	bottom->next = new;
	new->prev = bottom;
}
/* 
int		arg_navigator(int count, char **args);
int		arg_navigator(int count, char **args)
{
	
} */