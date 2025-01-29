/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:16:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/29 16:43:33 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		analyzer(t_stack **stack)
{
	int		pp;
	int		cp;
	int		np;
	
	if ((*stack)->prev == NULL || (*stack)->next == NULL)
		return (0);
	cp = (*stack)->position;
	np = (*stack)->next->position;
	pp = (*stack)->prev->position;
	if (pp < cp && cp < np && pp < np)
		return (25);
	if (pp < cp && cp > np && pp < np)
		return (21);
	if (pp > cp && cp < np && pp < np)
		return (26);
	if (pp < cp && cp > np && pp > np)
		return (37);
	if (pp > cp && cp < np && pp > np)
		return (42);
	if (pp > cp && cp > np && pp > np)
		return (38);
	return (0);
}

void		sorter(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	t_stack	*stack;
	while (!is_sorted((*stack_a)))
	{
		i = analyzer(stack_a);
		if ((i == 25) || (i == 21) || (i == 26))
			dosort_abc(stack_a, stack_b, i);
		if ((i == 37) || (i == 42) || (i == 38))
			dosort_def(stack_a, stack_b, i);
		if (i == 0)
			return ;
	}
}

void		dosort_abc(t_stack **stack, t_stack **kcats, int flag)
{
	if (flag == 25)
	{
		dd(do_pb, &(*stack), &(*kcats));
		do_pb((stack), (kcats));
	}
	if (flag == 21)
	{
		do_pb(&(*stack), &(*kcats));
		do_sa(&(*stack));
		dd(do_pb, &(*stack), &(*kcats));
	}
	if (flag == 26)
	{
		do_sa(&(*stack));
		dd(do_pb, &(*stack), &(*kcats));
		do_pb(&(*stack), &(*kcats));
	}
}

void		dosort_def(t_stack **stack, t_stack **kcats, int flag)
{
	if (flag == 37)
	{
		do_ra(&(*stack));
		do_sa(&(*stack));
		do_pb(&(*stack), &(*kcats));
		do_rra(&(*stack));
		dd(do_pb, &(*stack), &(*kcats));
	}
	if (flag == 42)
	{
		do_sa(&(*stack));
		do_pb(&(*stack), &(*kcats));
		do_sa(&(*stack));
		dd(do_pb, &(*stack), &(*kcats));
	}
	if (flag == 38)
	{
		do_double(rotate, &(*stack));
		do_ra(&(*stack));
		do_pb(&(*stack), &(*kcats));
		do_rra(&(*stack));
		do_pb(&(*stack), &(*kcats));
		do_rra(&(*stack));
		do_pb(&(*stack), &(*kcats));
	}
}
