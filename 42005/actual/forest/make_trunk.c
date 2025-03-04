/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_trunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:43:23 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/04 18:44:31 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		trunk_init(t_stack **stack_a, t_tree **tree)
{
	int		i;
	int		j;
	int		size;
	t_stack	*s;
	t_stack	*t;

	i = 0;
	s = (*(*stack_a)->head);
	size = s->size;
	while (i != size)
	{
		j = 0;
		while (j != 215)
		{
			if (i == 0)
				(*tree)->trunk[j][0] = size;
			else
				(*tree)->trunk[j][i] = s->pos;
			j++;
		}
		if (i > 0)
			s = s->next;
		i++;
	}
	(*tree)->trunk[j][i] = -1;
}

