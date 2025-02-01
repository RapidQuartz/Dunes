/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:08 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/01 18:17:15 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_checker(t_stack *stack)
{
	debug("in sort_checker()");
	t_stack	*temp;
	
	if (!stack)
		error_handling(NULL, NULL);
	temp = stack;
	while (temp->next != NULL)
	{
		debug("in _sc_ loop");
		if (temp->value < temp->next->value)
			temp = temp->next;
		else
			return (0);
	}
	debug("sorted");
	return (1);
}