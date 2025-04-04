/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:22:40 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/04 17:08:55 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///	KEEPERS:
bool		arrays_in_sequence(t_stack *s);
//? easier to have a simple one like this:: ?
bool		array_sorted(int *a, int mode);
//then do a special check for tops
//then i can use that one function 3 times::
//initially before "sorting"
//to check A
//to check B

/*		check_rotation
0.	can i push straight a->b?
1.	should i rotate a/b/both?
*/

/*	array_unsorted
TRUE 	if		::
the i = 1 value is not 1
any value from i = 1 to i = size is not in sequence
the i = size value is not size
FALSE	if		::
every value is in sequence
*/

/*	stacks_unsorted
TRUE	if		::
some values are in B
some values are NOT in sequence

FALSE	if		::
every value is in A
every value in A is in sequence

*/
bool		unsorted(t_stack *s)
{
	if ((((s->a != NULL && s->b != NULL) \
	&& (s->a[0] >= 1 && s->b[0] >= 1))) \
	&& (s->a[1] == s->b[1] + 1)
	&& ((array_sorted(s->a, 1)) \
	&& (array_sorted(s->b, -1))))
		return (false);
	else
	return (true);
}

bool		array_sorted(int *a, int mode)
{
	int	i;
	int	num;

	i = 0;
	if (a == NULL || (a != NULL && a[0] <= 1))
		return (true);
	else
		num = a[++i];
	while (a != NULL && a[0] > i++)
	{
		if (a[i] != num + mode)
			return (false);
		num = a[i];
	}
	return (true);
}
/*	array_in_sequence*/
bool		arrays_in_sequence(t_stack *s)
{
	int	i;
	int	j;
	int	a_num;
	int	b_num;

	i = 0;
	j = 0;
	if (s->a != NULL && s->a[0] > 1)
		a_num = s->a[1];
	if (s->b != NULL && s->b[0] > 1)
		b_num = s->b[1];
	if (((s->a != NULL && s->b != NULL) && (s->a[0] >= 1 && s->b[0] >= 1)) \
	&& (s->a[1] - 1 != s->b[1]))
		return (false);
	while (s != NULL && (i++ < s->a[0] || j++ < s->b[0]))
	{
		if ((s->a != NULL && i < s->a[0] && (s->a[i] - 1 != a_num)) \
		|| (s->b != NULL && j < s->b[0] && (s->b[j] + 1 != b_num)))
			return (false);
		if (s->a != NULL && s->a[0] > i)
			a_num = s->a[i];
		if (s->b != NULL && s->b[0] > j)
			b_num = s->b[j];
	}
	return (true);
}
/*	top_adjacent
bool	top_adjacent(int top_a, int top_b)
{
	if (top_a + 1 == top_b)
		return (true);
	else
		return (false);
}
*/
/*	stacks_in_sequence
TRUE	if		::
every value in A is in sequence
the top of A is in sequence with the top of B
every value in B is in sequence

FALSE	if		::
some values are NOT in sequence
the top of A is NOT in sequence with the top of B

*/
/* 
bool		in_sequence(t_stack *s)
{
	int	i;

	if ((array_in_sequence(s->a)) && (array_in_sequence(s->b)))
		return (true);
	else
		return (false);
} */


t_stack	*check_rotation(int *a, int *b, t_stack *c)
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
		while (a[0] > i && b[0] >= j)
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
