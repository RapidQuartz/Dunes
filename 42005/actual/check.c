/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:22:40 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/03 12:21:25 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*		check_rotation
0.	can i push straight a->b?
1.	should i rotate a/b/both?
*/
t_stack		*check_rotation(int *a, int *b, t_stack *c)
{
	// c->c = ;
	// c->d = ;
	// c->e = ;
	// c->f = ;
	return (NULL);
}
/* checks:	:
///if:	:stack A & B have only sequential values
//return (-1) if stack A is NOT sequential
//return (-2) if stack B is NOT sequential
//return (-3) if both stacks are NOT sequential
///if:	:rotating stack A or B helps
//return (1) if BOTH stacks ARE sequential AND aligned
//return (2) if rotating A makes BOTH sequential AND aligned
//return (3) if rotating B makes BOTH sequential AND aligned
//return (4) if rotating BOTH makes BOTH sequential AND aligned */
int		pushback_solve_check(t_stack *stk)
{
	int	s;
	int	a;

	s = not_sequential(stk->a, stk->b);
	a = not_aligned(stk->a, stk->b);
	if (a == 0)
		return (s);
	else if (a > 0)
		return (a);
	return (0);
}

/* checks:	:	
//if:		:	values in A grow at +1 increments
//if:		:	values in B shrink at -1 increments
//
//return (0)  if both stacks ARE sequential
//return (-1) if stack A is NOT sequential
//return (-2) if stack B is NOT sequential
//return (-3) if both stacks are NOT sequential */
int	not_sequential(int *a, int *b)
{
	int	i;
	int	k;
	int	l;

	i = 0;
	k = 0;
	l = 0;
	while ((a[0] > i || b[0] > i) && (k >= 0 || l >= 0))
	{
		i++;
		if (a[0] >= i && (i == 1 || a[i] == k + 1) && (k >= 0))
			k = a[i];
		else if (a[0] >= i && a[i] != k + 1)
			k = -1;
		if (b[0] >= i && (i == 1 || b[i] == l - 1) && (l >= 0))
			l = b[i];
		else if (b[0] >= i && b[i] != l - 1)
			l = -2;
		if (a[0] == i && k >= 0)
			k = 0;
		if (b[0] == i && l >= 0)
			l = 0;
	}
	return (k + l);
}
/* return (-1);
return (-2);
return (-3);
return (1);
return (0); */

/* checks:	:
//if:		:	stacks are aligned (the top of a fits into the top of b)
//return (1) if BOTH stacks ARE sequential AND aligned
//return (2) if rotating A makes BOTH sequential AND aligned
//return (3) if rotating B makes BOTH sequential AND aligned
//return (4) if rotating BOTH makes BOTH sequential AND aligned*/
int	not_aligned(int *a, int *b)
{
	int	i;
	int	j;

	i = 1;
	while (a[0] > i)
	{
		j = 1;
		while (a[0] > i && b[0] > j)
		{
			if (a[i] == b[j] + 1 || a[i] == b[j] - 1)
			{
				if (i == 1 && j == 1)
					return (1);
				if (i > 1 && j == 1)
					return (2);
				if (i == 1 && j > 1)
					return (3);	
				if (i > 1 && j > 1)
					return (4);
			}
			j++;
		}
		i++;
	}
	return (0);
}


// int	*check_a_rotation
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
	/* if (stack_is_sequential(stk))
		return (1);
	else */
		return (0);
}
/* 
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
} */
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
