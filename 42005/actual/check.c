/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:22:40 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/01 14:51:16 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*check_rotation(int *a, int *b, int *c)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = find_highest_index(b, a[1]);//what is the highest member of b?
	//[0] = a[1] is biggest
	//[i] = index of highest member
	k = find_higher_index(b, a[1]);//
	//[0] = a[1] is biggest
	//[k] = index of +1 higher member
	j = find_lowest_index(b, a[1]);//
	//[0] = a[1] is smallest
	//[j] = index of lowest member
	l = find_lower_index(b, a[1]);//
	//[0] = a[1] is smallest
	//[l] = index of -1 lower member
	if (a[1] > b[1])
	if (a[1] < b[1])
}

int	*check_a_rotation
/*	check rotation
if (a[1] > b[1])
is a[1] bigger than all of b?
	YES - cost to rotate b so a[1] is 'below' highest
		find_highest_index
	NO	- cost to rotate b so a[1] is 'below' higher and 'above' smaller
		find_higher_index
		find_smaller_index
if (a[1] < b[1])
is a[1] smaller than all of b?
	YES	- cost to rotate b so a[1] is 'above' smallest
		find_smallest_index
	NO	- cost to rotate b so a[1] is 'above' smaller and 'below' higher
		find_smaller_index
		find_higher_index
*/



//issue::if :a[2,4]b[3,1] -> returns 0;
//should:: ensure: a[3, 4]b[2, 1] to return 0 -> then pushback if b[0] > 0
int	stack_is_sorted(t_stack *stk)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (stk->a[0] > i || stk->b[0] > i)
	{
		if (stk->a[0] > i && stk->a[i] > stk->a[i + 1])
			f++;
		if (stk->b[0] > i && stk->b[i] < stk->b[i + 1])
			f++;
		if (f > 0)
			return (0);
		i++;
	}
	if (stack_is_sequential(stk))
		return (1);
	else
		return (0);
}

int	stack_is_sequential(t_stack *stk)
{
	int		i;
	int		s;

	i = 1;
	if ((stk->a[0] > i) || (stk->b[0] > i))
	{
		while (stk->a[0] > i)
		{
			s = stk->a[i++];
			if (stk->a[i] != s + 1)
				return (0);
		}
//this is meant to check that the top of b[] is the next in line to push to a[]
		if (stk->a[0] == i && stk->b[0] != 0 && stk->b[1] != stk->a[1] - 1)
			return (0);
		i = 1;
		while (stk->b[0] > i)
		{
			s = stk->b[i++];
			if (stk->b[i] != s - 1)
				return (0);
		}
	}
	return (1);
}
/* 
int	stack_is_sorted(t_n *sta)
{
	sta = (*sta->h);
	while (sta != sta->i->p)
	{
		if (sta->v > sta->n->v)
			return (0);
		sta = sta->n;
	}
	return (1);
} */
