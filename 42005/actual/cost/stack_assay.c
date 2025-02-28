/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_assay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:06:02 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/28 12:42:18 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		stack_assay(t_stack **st, t_stack **ts, int size)
{
	t_stack	*subject;
	int		*motive;
	int		i;

	subject = (*st);
	i = 0;
	while (size--)
	{
		is_adjacent(&subject);
		subject = subject->next;
	}
	subject = nav_ptr_set(&subject, subject->size);
	motive = ft_nzero(motive, subject->size);
	if (!motive)
		error_handling(st, ts);
	cost_get(&subject, subject->size + 1, motive);
	debug_cost_print(motive, subject->size);
	free (motive);
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
//	helpers for this: cost set?
//	check value of num array first
void		cost_set(t_stack **ss, t_stack *st, t_stack *ts, int *num);

void		cost_get(t_stack **st, int size, int *num)
{
	t_stack *ss;
	t_stack *tt;
	int	itr;
	int	pos;
	int	ind;

	ss = (*st);
	while (ss->high != NULL)
		ss = ss->high;
	while (1)
	{
		(*st) = ss;
		tt = ss;
		if ((*st)->pos == 1 || (*st)->low == NULL)
			break ;
		else
			cost_set(st, ss, tt, num);
		ss = (*st)->low;
	}
	return ;
}

void		cost_set(t_stack **ss, t_stack *st, t_stack *ts, int *num)
{
	int	itr;
	int	ind;
	
	itr = 1;
	ind = (*ss)->index;
	while (st->next != (*ss)->low && ts->prev != (*ss)->low)
	{
		st = st->next;
		ts = ts->prev;
		itr++;
	}
	if (st->next == (*ss)->low && itr > 0)
		itr *= -1;
	num[ind] = itr;
	(*ss)->cost_a = -num[ind];
	(*ss)->low->cost_b = num[ind];
	return ;
}

/* 
void		cost_get(t_stack **st, t_stack **ts, int size, int **num)
{
	while (size-- && (*st)->high != NULL)
	{
		(*ts) = (*st)->next;
		while (1 + (*st)->pos != (*ts)->pos && num[(*st)->index - 1][0]++)
			(*ts) = (*ts)->next;
		while (1 + (*st)->pos != (*ts)->pos && num[(*st)->index - 1][1]++)
			(*ts) = (*ts)->prev;
		if ((*st)->pos != 1)
		{
			if (num[(*st)->index - 1][0] < num[(*st)->index - 1][1])
				(*ts)->cost_a = &num[(*st)->index - 1][0];
			else
				(*ts)->cost_a = &num[(*st)->index - 1][1];
		}
		if ((*st)->pos != (*st)->size)
		{
			if (num[(*st)->index - 1][0] < num[(*st)->index - 1][1])
			{
				(*st)->cost_b = &num[(*st)->index - 1][0];
				debug(REDTXT"OPTION 1"DEFTXT);
			}
			else
			{
				(*st)->cost_b = &num[(*st)->index - 1][1];
				debug(GRNTXT"OPTION 2"DEFTXT);
			}
		}
		if ((*st)->high == NULL)
			break ;
		(*st) = (*st)->high;
	}
}
 */