/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:34 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/13 17:27:13 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*push_a(int *a, int *b, t_stk *c)
{
	int	i;
	int	s;
	int	m;
	int	n;

	i = 0;
	a[0]++;
	s = a[0];
	m = b[1];
	while (i++ < s)
	{
		n = a[i];
		a[i] = m;
		m = n;
	}
	b = realign_stack(b);
		write (1, "pa\n", 3);
	// ft_keep_op("pa", c);
	return (c);
}

t_stk	*push_b(int *a, int *b, t_stk *c)
{
	int	i;
	int	s;
	int	m;
	int	n;

	i = 0;
	b[0]++;
	s = b[0];
	m = a[1];
	while (i++ < s)
	{
		n = b[i];
		b[i] = m;
		m = n;
	}
	a = realign_stack(a);
		write (1, "pb\n", 3);
	// ft_keep_op("pb", c);
	return (c);
}

t_stk	*swap_a(t_stk *s)
{
	int	n;

	n = s->a[1];
	s->a[1] = s->a[2];
	s->a[2] = n;
	write (1, "sa\n", 3);
	// write (1, "\1", 3);
	return (s);
}

t_stk	*swap_b(t_stk *s)
{
	int	n;

	n = s->b[1];
	s->b[1] = s->b[2];
	s->b[2] = n;
	// write (1, "\1", 3);
	write (1, "sa\n", 3);
	return (s);
}

t_stk	*swap_s(t_stk *s)
{
	int	n;
	int	m;

	n = s->a[1];
	s->a[1] = s->a[2];
	s->a[2] = n;
	m = s->b[1];
	s->b[1] = s->b[2];
	s->b[2] = m;
	write (1, "ss\n", 3);
	return (s);
}
