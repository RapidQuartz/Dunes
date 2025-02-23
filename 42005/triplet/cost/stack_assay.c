/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_assay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:06:02 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/23 19:57:12 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		stack_assay(t_stack **st, t_stack **ts)
{
	t_stack	*subject;
	int		motive;
	int		clue;

	subject = (*st);
	motive = subject->pos;
	while (1)
	{
		clue = is_triplet(st);
		if (clue != 0)
			sort_trip(st, ts, clue);
	}
}

int		is_triplet(t_stack **st)
{
	t_stack	*ts;
	int	trip;
	int	a;
	int	b;
	int	c;

	ts = (*st)->head;
	trip = 0;
	a = ts->prev->pos;
	b = ts->pos;
	c = ts->next->pos;
	if (ts->prev->pos == (ts->pos - 1))//abc+1/acb+1/bca+1
		trip += 1;
	if (ts->next->pos == (ts->pos - 1))//abc+1*2=2/
		trip += 2;//
	if (ts->next->pos == (ts->pos + 1))//acb+1*3=3/bca+1*3=3/
		trip += 4;//
	if (ts->prev->pos == (ts->pos + 1))//bac-1/cab-1/cba-1
		trip -= 1;
	if (ts->next->pos == (ts->pos - 1) && trip <= 0)//bac-1*2=-2/cab-1*2=-2
		trip -= 2;//
	if (ts->next->pos == (ts->pos + 1) && trip <= 0)//cba-1*3=-3
		trip -= 4;//
	return (trip);
}
void		sort_trip(t_stack **st, t_stack **ts, int cl)
{
	
	return ;
}