/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_assay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:06:02 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/24 15:25:32 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		stack_assay(t_stack **st, t_stack **ts, int size)
{
	t_stack	*subject;
	int		motive;
	char		clue;

	subject = (*st);
	motive = 0;
	while (size--)
	{
		motive = is_adjacent(&subject);
		clue = subject->clue;
		if (motive == 3 && (clue >= 'a' && clue <= 'f'))
			;//trip_sort
		else if (motive == 2 && (clue >= 'g' && clue <= 'h'))
			;//doub_sort
		else if (motive == 1)
			sing_cost_set(&subject, clue);
		else if (motive == 2)
			doub_cost_set(&subject, clue);
		else if (motive == 3)
			trip_cost_set(&subject, clue);
		subject = subject->next;
	}
	if (clue != 'n')
}

int		is_adjacent(t_stack **st)
{
	int		n;
	t_stack	*subject;
	
	n = 0;
	subject = (*st);
	is_triplet(&subject, subject->size);
	if (subject->clue >= 'a' && subject->clue <= 'f')
		return (3);
	else
		is_doublet(&subject, subject->size);
	if (subject->clue >= 'g' && subject->clue <= 'h')
		return (2);
	is_singlet(&subject, subject->size);
	else if (subject->clue == '2')
		return (2);
	else if (subject->clue != '0' && subject->clue != '1')
		return (3);
}
// check for triplet
// (if st->prev->pos, st->pos, st->next->pos are all within 1)
// // if triplet >> `cost_a/cost_b` and `clue' for all is set
// // else if not triplet >>
// check for doublet
// (if st->prev->pos, st->pos are both within 1)
// // if doublet >> `cost_a/cost_b` and `clue' for both is set
// // else if not doublet
// check for singlet
// (how far to next adjacent -/+)
// // always >> `cost_a/cost_b` and `clue` set

void		is_triplet(t_stack **st, int size)
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
	else
		((*st)->clue = '1');
}

void		is_doublet(t_stack **st, int size)
{
	int	a;
	int	b;
	
	a = (*st)->pos;
	b = (*st)->next->pos;
	if (a == b - 1)
		((*st)->clue = 'g');
	else if (a == b + 1)
		((*st)->clue = 'h');
	else
		((*st)->clue = '2');
}

void		is_singlet(t_stack **st)
{
	t_stack	**ts;

	(*ts) = (*st)->next;
	while ((*st)->next != (*ts)->next && (*st)->clue == '2')
	{
		if ((*ts)->pos == (*st)->pos + 1)
		{
			(*st)->clue = 'i';
			(*st)->cost_b = (*st)->index - (*ts)->index;
		}
		else if ((*ts)->pos == (*st)->pos - 1)
		{
			(*st)->clue = 'j';
			(*st)->cost_b = (*ts)->index - (*st)->index;
		}
		else
			(*ts) = (*ts)->next;
	}
}

void		cost_set(t_stack **st, char clue)
{
	t_stack	**ts;
	int		dist;

	(*ts) = (*st)->next;
	if (clue >= 'a' && clue <= 'f')
	{
		(*st)->prev->cost_b = (*st)->prev->index - (*st)->index;
		(*st)->cost_a = (*st)->prev->index - (*st)->index;
		(*st)->cost_b = (*st)->index - (*st)->next->index;
		(*st)->next->cost_a = (*st)->index - (*st)->next->index;
	}
	else if (clue >= 'g' && clue <= 'h')
	{
		(*st)->prev->cost_b = (*st)->prev->index - (*st)->index;
		(*st)->cost_a = (*st)->prev->index - (*st)->index;
	}
	else if ((*st)->clue >= 'i' && (*st)->clue <= 'j')
	
}

void		sort_trip(t_stack **st, t_stack **ts, char cl)
{
	
	return ;
}

void		sort_doub(t_stack **st, t_stack **ts, char cl)


/* triplet arrangements
	/abc = a
	/acb = b
	/bac = c
	/bca = d
	/cab = e
	/cba = f
*/

/* on variables 'char clue', 'int cost_a', 'int cost_b'

*/