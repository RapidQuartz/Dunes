/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:10:07 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/17 13:10:28 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//maybe include provision for other stacks?
t_snap	*get_delta(t_snap *snap)
{
	unsigned short	cost;//collective
	short	delta;//difference between index and pos
	unsigned short	size;//size of stack in question
	int			i;//iterator
	
	i = 1;//set to 1 to avoid size-info
	cost = 0;
	delta = 0;
	size = snap->size;
	if (snap->a != NULL)
	{
		snap->ar = get_acost(snap);
		delta += snap->ar[0];
	}
	if (snap->b != NULL)
	{
		snap->br = get_bcost(snap);
		delta += snap->br[0];
	}
	snap->delta = delta;
	return (snap);
}

///	CHANGES:NEEDED:	provide for midpoint 
/*
[what about a[0]/2 + a[0]%2]
[so for a[0] == 3]
[3/2 = 1]
[3%2 = 1]
but thats fine; unless assuming... that the first extra num is swappable?
[if (i<(a[0] / 2 + a[0] % 2))] catches 1, 2
[if (i>(a[0] / 2 + a[0] % 2))] catches 3
[]
[]
[]
(if i<a[0]/2) in first half
(if i>a[0]/2) in second half

*/
short	*get_acost(t_snap *snap)
{
	short			delta;//difference between index and pos
	short			mid;//difference between index and pos
	int			i;//iterator
	
	i = 0;
	delta = 0;
	if (snap->a[0] != 0)
	{
		mid = (snap->a[0] / 2 + snap->a[0] % 2);
		while (i++ < snap->a[0])
		{
			//(IS AND belongs first half);;delta = size - index - pos == 5 - 1 - 5 == -1'
			if (i <= mid && snap->a[i] <= mid)
				snap->ar[i] = snap->a[0] - i - snap->a[i];
			//(IS NOT BUT belongs second half);;delta = pos - index == 3 - 2 == 1'
			if (i <= mid && snap->a[i] > mid)
				snap->ar[i] = snap->a[i] - i;
			//(IS NOT BUT belongs first half);;delta = size - index + pos == 5 - 5 + 2 == 2'
			if (i >= mid && snap->a[i] <= mid)
				snap->ar[i] = snap->a[0] - i + snap->a[i];
			//(IS AND belongs second half);;delta = pos - index == 4 - 4 == 0'
			if (i >= mid && snap->a[i] > mid)
				snap->ar[i] = snap->a[i] - i;
			if (snap->ar[i] < 0)
				delta += (snap->ar[i] * -1);
			else
				delta += snap->ar[i];
		}
	}
	snap->ar[0] = delta;
	return (snap->ar);
}

/* backup (that works, even)
short	*get_acost(t_snap *snap)
{
	unsigned	cost;//collective
	unsigned	delta;//difference between index and pos
	int			i;//iterator
	
	i = 0;
	delta = 0;
	if (snap->a[0] != 0)
	{
		while (i++ < snap->a[0])
		{
			cost = snap->a[i];
			if (cost < i)
				snap->ac[i] = i - cost;
			else if (cost > i)
				snap->ac[i] = cost - i;
			else if (cost == i)
				snap->ac[i] = 0;
			delta += snap->ac[i];
		}
	}
	snap->ac[0] = delta;
	return (snap->ac);
} */

short	*get_bcost(t_snap *snap)
{
	short			delta;//difference between index and pos
	short			mid;//difference between index and pos
	int			i;//iterator
	
	i = 0;
	delta = 0;
	if (snap->b[0] != 0)
	{
		mid = (snap->b[0] / 2 + snap->b[0] % 2);
		while (i++ < snap->b[0])
		{
			//(IS AND belongs first half);;delta = size - index - pos == 5 - 1 - 5 == -1'
			if (i <= mid && snap->b[i] <= mid)
				snap->br[i] = snap->b[0] - i - snap->b[i];
			//(IS NOT BUT belongs second half);;delta = pos - index == 3 - 2 == 1'
			if (i <= mid && snap->b[i] > mid)
				snap->br[i] = snap->b[i] - i;
			//(IS NOT BUT belongs first half);;delta = size - index + pos == 5 - 5 + 2 == 2'
			if (i > mid && snap->b[i] <= mid)
				snap->br[i] = snap->b[0] - i + snap->b[i];
			//(IS AND belongs second half);;delta = pos - index == 4 - 4 == 0'
			if (i > mid && snap->b[i] > mid)
				snap->br[i] = snap->b[i] - i;
			if (snap->br[i] < 0)
				delta += (snap->br[i] * -1);
			else
				delta += snap->br[i];
		}
	}
	snap->br[0] = delta;
	return (snap->br);
}
