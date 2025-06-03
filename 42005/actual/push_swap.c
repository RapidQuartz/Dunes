/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:34 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/16 12:32:34 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*push_a(int *a, int *b, t_stk *c)
{
	int	i;
	int	m;
	int	n;

	i = 0;
	a[0]++;
	m = b[1];
	while (i++ < a[0])
	{
		n = a[i];
		a[i] = m;
		m = n;
	}
	i = b[0];
	b[0]--;
	m = b[i];
	b[i] = 0;
	while (--i > 0)
	{
		n = b[i];
		b[i] = m;
		m = n;
	}
	ft_put("pa");
	return (c);
}

t_stk	*push_b(int *a, int *b, t_stk *c)
{
	int	i;
	int	m;
	int	n;

	i = 0;
	b[0]++;
	m = a[1];
	while (i++ < b[0])
	{
		n = b[i];
		b[i] = m;
		m = n;
	}
	i = a[0];
	m = a[i];
	a[0]--;
	a[i] = 0;
	while (--i > 0)
	{
		n = a[i];
		a[i] = m;
		m = n;
	}
	ft_put("pb");
	return (c);
}

t_stk	*swap_a(t_stk *s)
{
	int	n;

	n = s->a[1];
	s->a[1] = s->a[2];
	s->a[2] = n;
	ft_put("sa");
	return (s);
}

t_stk	*swap_b(t_stk *s)
{
	int	n;

	n = s->b[1];
	s->b[1] = s->b[2];
	s->b[2] = n;
	ft_put("sb");
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
	ft_put("ss");
	return (s);
}
