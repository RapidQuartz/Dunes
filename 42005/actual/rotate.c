/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:44 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/16 12:37:19 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stk *s, int post)
{
	int	i;
	int	size;
	int	m;
	int	n;

	size = s->a[0];
	i = size;
	m = s->a[size];
	s->a[size] = s->a[1];
	while (i-- > 1)
	{
		n = s->a[i];
		s->a[i] = m;
		m = n;
	}
	if (s->a_cost[0] > 0)
		s->a_cost[0]--;
	if (post == 1)
		ft_put("ra");
}

void	rotate_b(t_stk *s, int post)
{
	int	i;
	int	size;
	int	m;
	int	n;

	size = s->b[0];
	i = size;
	m = s->b[size];
	s->b[size] = s->b[1];
	while (i-- > 1)
	{
		n = s->b[i];
		s->b[i] = m;
		m = n;
	}
	if (s->b_cost[0] > 0)
		s->b_cost[0]--;
	if (post == 1)
		ft_put("rb");
}

void	rotate_s(t_stk *s)
{
	rotate_a(s, 0);
	rotate_b(s, 0);
	ft_put("rr");
}
