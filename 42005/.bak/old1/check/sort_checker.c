/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:08 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/20 17:47:19 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_checker(t_stack *stack)
{
	int		flag;
	
	if (!stack)
		error_handling(&stack, NULL);
	while (stack->next != *stack->head)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
