/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:03:05 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/31 13:30:49 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*swap_a(int *a)
{
	int	s;

	s = a[1];
	a[1] = a[2];
	a[2] = s;
	return (a);
}

int	*swap_b(int *b)
{
	int	s;

	s = b[1];
	b[1] = b[2];
	b[2] = s;
	return (b);
}

t_stack	*swap_s(t_stack *a)
{
	a->a = swap_a(a->a);
	a->b = swap_b(a->b);
	return (a);
}
