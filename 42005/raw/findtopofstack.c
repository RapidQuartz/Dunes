/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findtopofstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:21:58 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/28 17:52:41 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_stack_top(t_stack *stack)
{
	debug("inside find stack top");
	
	while (stack && stack->prev != NULL)
	{
		debug("broke backwards");
		stack = stack->prev;
	}
	debug("made it out");
	return (stack);
}