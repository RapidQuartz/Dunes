/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:10:07 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/10 12:26:32 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//maybe include provision for other stacks?
t_snap	*get_delta(t_snap *snap)
{
	unsigned short	cost;//collective
	unsigned short	delta;//difference between index and pos
	unsigned short	size;//size of stack in question
	int			i;//iterator
	
	i = 1;//set to 1 to avoid size-info
	cost = 0;
	delta = 0;
	size = snap->size;
	snap->ac = get_acost(snap);
	snap->bc = get_bcost(snap);
	delta = snap->ac[0] + snap->ac[0]; 
	return (snap);
}

short	*get_acost(t_snap *snap)
{
	unsigned short	cost;//collective
	unsigned short	delta;//difference between index and pos
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
}

short	*get_bcost(t_snap *snap)
{
	unsigned short	cost;//collective
	unsigned short	delta;//difference between index and pos
	int			i;//iterator
	
	i = 0;
	delta = 0;
	if (snap->b[0] != 0)
	{
		while (i++ < snap->b[0])
		{
			cost = snap->b[i];
			if (cost < i)
				snap->bc[i] = i - cost;
			else if (cost > i)
				snap->bc[i] = cost - i;
			else if (cost == i)
				snap->bc[i] = 0;
			delta += snap->bc[i];
		}
	}
	snap->bc[0] = delta;
	return (snap->bc);
}
