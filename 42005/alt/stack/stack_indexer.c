/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_indexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:52:15 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/31 16:46:39 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_indexer(t_stack **stk)
{
	t_stack	*high;
	int		low;
	
	low = INT_MIN;
	high = (*stk);
	while ((*stk))
	{
		if ((*stk)->value > low)
			high = (*stk);
	}
}
//(*stk)

/* 
t_stack	*stack_indexer(int value, t_stack *prev)
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
	new->adjacency = -1;
	new->higher = NULL;
	new->lower = NULL;
	new->next = NULL;
	return (new);
} */