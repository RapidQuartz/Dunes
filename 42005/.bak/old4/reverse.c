/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:02:33 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/31 13:33:23 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*reverse_a(int *a)
{
	int	i;
	int	s;
	int	m;
	int	n;

	i = 0;
	s = a[0];
	m = a[s];
	while (i++ < s)
	{
		n = a[i];
		a[i] = m;
		m = n;
	}
	return (a);
}

int	*reverse_b(int *b)
{
	int	i;
	int	s;
	int	m;
	int	n;

	i = 0;
	s = b[0];
	m = b[s];
	while (i++ < s)
	{
		n = b[i];
		b[i] = m;
		m = n;
	}
	return (b);
}

t_stack	*reverse_s(t_stack *a)
{
	a->a = reverse_a(a->a);
	a->b = reverse_b(a->b);
	return (a);
}