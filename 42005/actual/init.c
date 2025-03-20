/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:37:32 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/20 13:00:30 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_n	*make_st(int *arr)
{
	int	i;
	t_n	*st;
	t_n	*ts;
	t_n	*top;

	i = 0;
	while (i++ < arr[0])
	{
		st = malloc(sizeof(*st));
		if (!st)
			return (NULL);
		st->ssz = arr[0];
		st->siz = st->siz;
		st->val = arr[i];
		if (1 < i)
			ts->n = st;
		else
			top = st;
		ts = st;
	}
	ts->n = NULL;
	return (top);
}
t_n	*new_st(t_n *n)
{	
	n = malloc(sizeof(*n));
	if (!n || n == NULL)
		d_end();
	return (n);
}
