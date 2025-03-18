/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:37:32 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/18 17:05:39 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_n	*make_st(int *arr)
{
	int	i;
	t_n	*st;
	t_n	*ts;

	i = 1;
	while (i++ < arr[0])
	{
		st = malloc(sizeof(*st));
		if (!st)
			return (NULL);
		if (1 == i)
		{
			st->siz = arr[0];
			st->asz = st->siz;
			st->bsz = 0;
		}
		st->a = arr[i];
		if (1 < i)
			ts->n = st;
		ts = st;
	}
	ts->n = NULL;
	return (ts);
}
