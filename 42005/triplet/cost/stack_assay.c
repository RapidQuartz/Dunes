/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_assay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:06:02 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/25 14:09:31 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		stack_assay(t_stack **st, t_stack **ts, int size)
{
	t_stack	*subject;
	int		**motive;
	int		i;

	subject = (*st);
	i = 0;
	while (size--)
	{
		is_adjacent(&subject);
		subject = subject->next;
	}
	subject = nav_ptr_set(&subject, subject->size);
	motive = ft_nzero(motive, 2, 2);
	if (!motive)
		error_handling(st, ts);
	cost_set(&subject, &subject->prev, subject->size + 1, motive);
}

void		is_adjacent(t_stack **st)
{
	int		n;
	t_stack	*subject;
	
	n = 0;
	subject = (*st);
	check_adjacency(&subject);
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
	else if (a == b - 2 && b == c + 1 && c == a + 1)//acb
		((*st)->clue = 'b');
	else if (a == b + 1 && b == c - 2 && c == a + 1)//bac
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

void		cost_set(t_stack **st, t_stack **ts, int size, int **num)
{
	int	ct;
	int	vl;
	
	ct = (*st)->index;
	vl = 0;
	while (size--)
	{
		while ((*ts)->pos - 1 != (*st)->pos)
		{
			(*ts) = (*ts)->next;
			num[ct][0]++;
		}
		(*ts) = (*st)->prev;
		while ((*ts)->pos - 1 != (*st)->pos)
		{
			(*ts) = (*ts)->prev;
			num[ct][1]++;
		}
		if (num[ct][0] < num[ct][1])
			vl = num[ct][0];
		else
			vl = num[ct][1];
		(*st)->cost_b = vl;
		(*ts)->cost_a = vl;
	}
}
