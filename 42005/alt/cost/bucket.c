/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:07:22 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/17 16:14:07 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* buckets
a concept from radix sorting, but adapted for triplet search

dependent on position, not index
for pos = 1-3 bucket is 1 etc.
*/

void		set_bucket(t_stack *stack)
{
	t_stack	*mem;
	int		bucket;

	mem = stack;
	bucket = 1;
	while (stack->next != NULL)
	{
		if (stack->bucket == 0)
		{
//divide by 3? i mean, the i = 1,2,3 are bucket 1.
			if (mem->index == bucket)
		}
	}
}