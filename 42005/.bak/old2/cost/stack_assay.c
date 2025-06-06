/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_assay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:06:02 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/02 17:33:03 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		stack_assay(t_stack **st, t_stack **ts, int size)
{
	int		sum;
	int		i;

	i = size;
	sum = 0;
	while (i--)
	{
		check_adjacency(st);
		(*st) = (*st)->next;
	}
	(*st) = nav_ptr_set(st, (*st)->size);
	while (size-- && (*st))
	{
		(*st)->cost_r = ft_cost((*st), 'r');
		(*st)->cost_a = ft_cost((*st), 'a');
		if ((*st)->high)
			(*st) = (*st)->high;
		else
			break ;
	}
	st = (*st)->head;
	i = ft_cost((*st), 's');
}

void		check_adjacency(t_stack **st)
{
	int	a;
	int	b;
	int	c;

	a = (*st)->prev->pos;
	b = (*st)->pos;
	c = (*st)->next->pos;
	if (a == b - 1 && b == c - 1 && c == a + 2)//abc
		((*st)->clue = 'a');
	else if (a == b + 1 && b == c - 2 && c == a + 1)//bac
		((*st)->clue = 'b');
	else if (a == b - 2 && b == c + 1 && c == a + 1)//acb
		((*st)->clue = 'c');
	else if (a == b - 1 && b == c + 2 && c == a - 1)//bca
		((*st)->clue = 'd');
	else if (a == b + 2 && b == c - 1 && c == a - 1)//cab
		((*st)->clue = 'e');
	else if (a == b + 1 && b == c + 1 && c == a - 2)//cba
		((*st)->clue = 'f');
	else if (a == b - 1)
		((*st)->clue = 'g');
	else if (a == b + 1)
		((*st)->clue = 'h');
	else
		((*st)->clue = 'i');
}

t_stack	*nav_ptr_set(t_stack **st, int size)
{
	t_stack	*ts;
	t_stack	*lo;
	t_stack	*keep;

	while ((*st)->pos != 1)
		(*st) = (*st)->next;
	keep = (*st);
	lo = keep;
	while (lo->pos != size)
	{
		ts = lo->next;
		while (lo->pos + 1 != ts->pos)
			ts = ts->next;
		lo->high = ts;
		ts->low = lo;
		lo = ts;
	}
	return (keep);
}
