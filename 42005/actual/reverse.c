/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:42 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/13 17:26:34 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_stk *s, int post)
{
	int	i;
	int	size;
	int	m;
	int	n;

	i = 0;
	size = s->a[0];
	m = s->a[size];
	while (i++ < size)
	{
		n = s->a[i];
		s->a[i] = m;
		m = n;
	}
	if (s->a_cost[0] < 0)
		s->a_cost[0]++;
	if (post == 1)
		write (1, "rra\n", 4);
	// ft_keep_op("rra", s);
		
}

void	reverse_b(t_stk *s, int post)
{
	int	i;
	int	size;
	int	m;
	int	n;

	i = 0;
	size = s->b[0];
	m = s->b[size];
	while (i++ < size)
	{
		n = s->b[i];
		s->b[i] = m;
		m = n;
	}
	if (s->b_cost[0] < 0)
		s->b_cost[0]++;
	if (post == 1)
		write (1, "rrb\n", 4);
	// ft_keep_op("rrb", s);
}

void	reverse_s(t_stk *s)
{
	reverse_a(s, 0);
	reverse_b(s, 0);
	// ft_keep_op("rrr", s);
	write (1, "rrr\n", 4);
}
