/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:02:45 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/31 13:39:18 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	*rotate_a(int *a)
{
	int	i;
	int	s;
	int	m;
	int	n;

	s = a[0];
	i = s;
	m = a[s];
	a[s] = a[1];
	while (i-- > 1)
	{
		n = a[i];
		a[i] = m;
		m = n;
	}
	return (a);
}

int	*rotate_b(int *b)
{
	int	i;
	int	s;
	int	m;
	int	n;

	s = b[0];
	i = s;
	m = b[s];
	b[s] = b[1];
	while (i-- > 1)
	{
		n = b[i];
		b[i] = m;
		m = n;
	}
	return (b);
}

t_stack	*rotate_s(t_stack *a)
{
	a->a = rotate_a(a->a);
	a->b = rotate_b(a->b);
	return (a);
}