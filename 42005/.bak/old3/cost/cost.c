/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:10:07 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/18 14:18:51 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
short		*xa_delta(unsigned short *n, short *dif, int i);
short		*xb_delta(unsigned short *b, short *dif, int i);
/*	SUMMARY DUCKTALES


TWO PART ALGO

MOVERS
	shift the stack without changing order
ORDERS
	rearrange the stack

how many MOVES before it makes sense to ORDER
	stored for each MOVE
		`int *rot[] = {-1, 5}`
		== STACK A -1 STACK B +5

evaluate each number for relative order

eg:

a	b

1
5
4
3
2

\\ creates "more order" by removing a disordered element
a	b

5	1
4
3
2

\0\	evaluate DELTA
how disordered is stack?
int *rot[]
how much rotation necessary to make ORDERS viable

\1\	evaluate ORDERS:
PA PB SA SB SS

\2\	evaluate MOVERS:
RA RB RR RRA RRB RRR


*/


/*

go thru stack of `n` nums

all nums normalized

iterate thru list

sum dif between adjacent nums

an ordered stack, no matter rotation, sum will be `n`
a disordered stack, no matter rotation, sum will be `>n`

pos	what

	prev	next
1	1	2	
3	2	1
2	1	1

n = 3


{edge case of abutting numbers}
if (a[0] > 1 && i == 1 && a[i] == a[0] && a[i + 1] == i)
	arc[i] = 1;
if (a[0] > 1 && i == a[0])
	arc[i] = a[1] - a[i];
	
	i	a	delta	b
	0	3
	1	3	1
	2	1	1
	3	2	1
		
		1	2
		3	1
		2	1


{general case}

what is the absolute diff between a[i] and a[i + 1]

while (i < a[0])
{
	if (a[i] == a[0])
	{
		if(a[i] == a[0] && a[i + 1] == 1)
			ac[i] = 1;
		else
			ac[i] = a[i] - a[i + 1];
	
	}
		ac[i] = a[i] - a[i + 1];
	if (a[i] > a[j])
		ac[i - 1] = a[i - 1] - a[i]
	else
		ac[i - 1] = a[i] - a[i - 1]
}

while (i++ < a[0])
	sum_d += ac[i];
ac[0] = sum_d;
}


*/
//maybe include provision for other stacks?
t_snap	*get_delta(t_snap *s)
{
	if (0 < s->a[0])
		s->ac = xa_delta(s->a, s->ac, 0);
	if (0 < s->b[0])
		s->bc = xb_delta(s->b, s->bc, 0);
	s->delta = s->ac[0] + s->bc[0];
	return (s);
}
/*
stack order		expected next


1

expnxt = nbr+1 (unless size, when it is 1)

2

diff expnxt // next

if diff > size/2
	diff = size - diff


n = 9

i	n	x	a	d	c
0	9	0		12	8
1	2	3	3	0	0
2	3	4	4	0	0
3	4	5	5	0	0
4	5	6	6	0	0
5	6	7	1	6	3 (if d > size/2, c = size - d)
6	1	2	7	5	4
7	7	8	8	0	0
8	8	9	9	0	0
9	9	1	2	1	1

*/

t_snap	*delta(t_snap *s)
{
	
}

short		*xa_delta(unsigned short *n, short *dif, int i)
{
	while (1 < n[0] && i++ < n[0])
	{
		if (n[i] != n[0])
			dif[i] = n[i] + 1;
		else
			dif[i] = 1;
		if (i == n[0] && dif[i] > n[1])
			dif[i] = (dif[i] - n[1]);
		else if (i == n[0] && dif[i] < n[1])
			dif[i] = (n[1] - dif[i]);
		else if (i != n[0] && dif[i] > n[i + 1])
			dif[i] = (dif[i] - n[i + 1]);
		else if (i != n[0] && dif[i] < n[i + 1])
			dif[i] = (n[i + 1] - dif[i]);
		if (dif[i] > n[0] / 2)
			dif[i] = n[0] - dif[i];
		dif[0] += dif[i];
	}
	return (dif);
}

short		*xb_delta(unsigned short *b, short *dif, int i)
{
	while (1 < b[0] && i++ < b[0])
	{
		if (b[i] != 1)
			dif[i] = b[i] - 1;
		else
			dif[i] = b[0];
		if (i == b[0] && dif[i] > b[1])
			dif[i] = (dif[i] - b[1]);
		else if (i == b[0] && dif[i] < b[1])
			dif[i] = (b[1] - dif[i]);
		else if (i != b[0] && dif[i] > b[i + 1])
			dif[i] = (dif[i] - b[i + 1]);
		else if (i != b[0] && dif[i] < b[i + 1])
			dif[i] = (b[i + 1] - dif[i]);
		if (dif[i] > b[0] / 2)
			dif[i] = b[0] - dif[i];
		dif[0] += dif[i];
	}
	return (dif);
}



/* t_snap	*get_delta(t_snap *snap)
{
	unsigned short	cost;//collective
	short			delta;//difference between index and pos
	unsigned short	size;//size of stack in question
	int			i;//iterator
	
	i = 1;//set to 1 to avoid size-info
	cost = 0;
	delta = 0;
	size = snap->size;
	if (snap->a != NULL)
	{
		snap->ar = get_rcost(snap);
		snap->ac = get_acost(snap);
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
 */


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
/* BITMASK NOT MODULO
	&	BIT WISE AND
	MAKES REUSLT EQUAL TO EVERY POSITION BOTH VALUES HAVE A 1 AT

	0101 0101 & 0000 1111
	
	0101 0101					& 1
	0000 1111					
=	0000 0101

*/
/* short	*get_acost(t_snap *snap)
{
	short			delta;//difference between index and pos
	short			mid;//difference between index and pos
	int			i;//iterator
	
	i = 0;
	delta = 0;
	if (snap->a[0] != 0)
	{
		mid = (snap->a[0] / 2 + snap->a[0] & 0b1);
		while (i++ < snap->a[0])
		{
			if (i <= mid && snap->a[i] <= mid)
				snap->ar[i] = snap->a[0] - i - snap->a[i];
			if (i <= mid && snap->a[i] > mid)
				snap->ar[i] = snap->a[i] - i;
			if (i >= mid && snap->a[i] <= mid)
				snap->ar[i] = snap->a[0] - i + snap->a[i];
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
} */

/* short	*get_bcost(t_snap *snap)
{
	short			delta;//difference between index and pos
	short			mid;//stack is most interesting at edges
	int			a;//iterator for A - stack
	int			b;//iterator for B - stack
	
	a = 0;
	b = 0;
	delta = 0;
	if (snap->a[0] != 0)
	{
		mid = (snap->a[0] / 2 + snap->a[0] % 2);
		while (a++ < snap->a[0])
		{
			
		}
	}
	if (snap->b[0] != 0 && snap->a[0] != 0)
	{
	
	}
	snap->br[0] = delta;
	return (snap->br);
} */
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
/* keep it secret, keep it safe*/
/* short	*get_bcost(t_snap *snap)
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
*/
/*	musing on cost and b-relative measures
i need it to be:
		the cost of moving 'x' to
			correct place	this should be 'i - x' but reversed?
						so, if its past midpoint but home in first
						so, if its past midpoint but home in first
			then it would be size - index + pos
			because:
			+	size		what is max value for index (is it close to edge)
			-	index		what distance is it from bottom?
			+	pos		
			correct stack	this adds +1 for B items
i should consider:
		in A numbers must be low-to-high to be "in order"
		in B numbers must be high-to-low to be "in order"
it's irrelevant if there is only one number in B:
		because it depends on the order of A
	(if top number in A is ONE HIGHER than top number in B, then B is good)
vice versa, it is irrelevant if there is only one number in A:
		because it depends on the order of B
	(if top number in B is ONE LOWER than top number in B, then B is good)

			
*/