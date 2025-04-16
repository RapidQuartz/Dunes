/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:07:53 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/16 12:53:11 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stk *s, int *a, int *b)
{
	int	i;

	i = 0;
	while (i++ < a[0])
	{
		s->sm[i] = find_next_smaller(b, a[i]);
		s->bg[i] = find_next_bigger(b, a[i]);
		set_cost(s->sm[i], s->bg[i], s, i);
	}
	s->c_cost = get_collective_cost(s->a_cost, s->b_cost, s->c_cost, s);
	return ;
}

void	set_cost(int smaller, int bigger, t_stk *s, int i)
{
	int	cost_s;
	int	cost_b;

	cost_s = 0;
	cost_b = 0;
	if (i <= s->a_mid)
		s->a_cost[i] = i - 1;
	else if (i > s->a_mid)
		s->a_cost[i] = i - s->a[0] -1;
	if (smaller != 0 && smaller <= s->b_mid)
		cost_s = (smaller - 1);
	else if (smaller != 0 && smaller > s->b_mid)
		cost_s = (smaller - s->b[0] - 1);
	if (bigger != 0 && bigger <= s->b_mid)
		cost_b = (bigger - 2);
	else if (bigger != 0 && bigger > s->b_mid)
		cost_b = (bigger - s->b[0]);
	if ((bigger == 0 && smaller != 0) \
	|| (get_abs(cost_s) <= get_abs(cost_b)))
		set_target(s, i, smaller, cost_s);
	else if ((bigger != 0 && smaller == 0) \
	|| (get_abs(cost_s) > get_abs(cost_b)))
		set_target(s, i, bigger, cost_b);
}

void	set_target(t_stk *s, int i, int target, int cost)
{
	s->b_tgt[i] = target;
	s->b_cost[i] = cost;
}

int	*get_collective_cost(int *a, int *b, int *c, t_stk *s)
{
	int	i;
	int	bargain;
	int	offer;

	i = 0;
	bargain = INT_MAX;
	while (i++ < s->a[0])
	{
		c[i] = get_abs(a[i]) + get_abs(b[i]);
		if (c[i] < bargain || i == 1)
		{
			bargain = c[i];
			offer = i;
		}
	}
	s->a_tgt[0] = offer;
	s->b_tgt[0] = s->b_tgt[offer];
	s->a_cost[0] = a[offer];
	s->b_cost[0] = b[offer];
	c[0] = bargain;
	return (c);
}
