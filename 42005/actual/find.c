/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:37:59 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/01 13:46:38 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_highest_index(int *stk, int tgt)
{
	int		i;
	int		j;
	int		h;

	i = 0;
	j = 0;
	h = tgt;
	while (stk[0] > i)
	{
		if (stk[i] > h)
		{
			h = stk[i];
			j = i;
		}
		i++;
	}
	if (j > 0)
		return (j);
	return (0);
}

int			find_lowest_index(int *stk, int tgt)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = tgt;
	while (stk[0] > i)
	{
		if (stk[i] < l)
		{
			l = stk[i];
			j = i;
		}
		i++;
	}
	if (j > 0)
		return (j);
	return (0);
}

int			find_higher_index(int *stk, int tgt)
{
	int		i;

	i = 0;
	while (stk[0] > i)
	{
		if (stk[i] == tgt + 1)
			return (i);
		i++;
	}
	return (0);
}

int			find_lower_index(int *stk, int tgt)
{
	int		i;

	i = 0;
	while (stk[0] > i)
	{
		if (stk[i] == tgt - 1)
			return (i);
		i++;
	}
	return (0);
}
