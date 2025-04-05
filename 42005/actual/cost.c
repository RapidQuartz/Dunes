/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:54:11 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/05 19:49:36 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_biggest(int *s);
int		find_smallest(int *s);
int		find_next_bigger(int *s, int n);
int		find_next_smaller(int *s, int n);
void		get_cost(t_stack *stk);
t_stack	*compare_targets(t_stack *stk, int i);
int		iterate_cost(int a, int *b);

/*	get_cost_2

*/
/*	counting cost
while ()
*/
/*	*/
/*	*/
/*	*/
void		get_cost(t_stack *stk)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i++ < stk->a[0])
	{
		stk->c[i] = find_biggest(stk->b);
		stk->d[i] = find_smallest(stk->b);
		stk->e[i] = find_next_bigger(stk->b, stk->a[i]);
		stk->f[i] = find_next_smaller(stk->b, stk->a[i]);
		stk = compare_targets(stk, i);
	}
}
/*	placement logics
	seems the logic is just to put it
	above the next smaller/below the next bigger
*/
/*convert from target to moves:
it basically only wants to be
above the next smaller
or
below the next bigger

*/
/*	comparing targets

the target number which requires the fewest moves to align, is the best
if it is
bigger 	than a[i]
	find out if it is the NEXT bigger number in b[]
smaller	than a[i]
	find out if it is the NEXT smaller number in b[]

if this approach would allow numbers to be pushed to a next
which is highest but not next higher:
	then alignment would be necessary later.


so it seems like finding the NEXT is all that is needed
if a number is bigger
(if (a[i] < b[big]))
then compare cost of aligning to smaller
if no number is bigger
(if (a[i] > b[big]))
then it would sit ABOVE the next SMALLER
if a number is smaller
(if (a[i] > b[small]))
then compare cost of aligning to bigger
if no number is smaller
(if (a[i] < b[small]))
it would sit ABOVE the biggest.

//	RAMBLINS::
//compare values of e[] f[] ->
		//halfway or not?
		//so... before halfway::
		//i < (size / 2 + size % 2)
		//so... up = i (distance from top where 1 is NULL)
		//so... after halfway::
		//i > (size / 2 + size % 2)
		//so... down = size - i + 2 (distance from bottom, plus one for over the hump)
		//if index is 1, it is 'free' (costs 1/PUSH)
		//if index is `size` it costs 1 (reverse) + 1 (push)

	```
t_stack	*compare_targets(t_stack *stk, int i)
{
	if (stk->e[i] == 0 && stk->a[i] > stk->b[stk->e[i]])//it's biggest
	if (stk->f[i] == 0 && stk->a[i] < stk->b[stk->f[i]])//it's smallest
	if (stk->e[i] != 0 && stk->f[i] != 0)//it's middle
	{
		
	}
	if (stk->b[stk->f[i]] == 0)
	if (stk->c[i] < (stk->s / 2 + stk->s % 2))
		;
	else if (stk->c[i] > (stk->s / 2 + stk->s % 2))
		;
		stk->d[i]
	if (stk->b[stk->c[i]] < stk->a[i] || stk->b[stk->d[i]] > stk->a[i])
		//
	//a[i] is bigger than the biggest || smaller than the smallest
	else
	//a[i] is NOT bigger than the biggest || NOT smaller than the smallest
//OR
	//a[i] is smaller than the smallest number
//A	//we want it ABOVE the biggest::
	if (stk->b[stk->c[i]] > stk->a[i] || stk->b[stk->d[i]] < stk->a[i])
	//a[i] is smaller than the biggest (and bigger than the smallest)
//B	//we want it ABOVE the next smaller
//	(if it is smallest or biggest: ABOVE the biggest)
//	(if it isn't smallest or biggest: ABOVE the next smaller)
	//a[i] is bigger than the smallest
//OR
	//a[i] is smaller than the biggest)
	
	return (stk);
	```
*/
/*	'pad'
	if (stk->e[i] == 0 && stk->a[i] > stk->b[stk->e[i]])//it's biggest
	if (stk->f[i] == 0 && stk->a[i] < stk->b[stk->f[i]])//it's smallest
	if (stk->e[i] != 0 && stk->f[i] != 0)//it's middle

*/
t_stack	*compare_targets(t_stack *stk, int i)
{
	return (stk);
}

/*	process:
compare	::	[i] of c, d, e, f
assign	::	val[] = {c, d, e, f}
		::	ch = }cheapest value{
		::	ind = }index of cheapest value{

*/
//	selects lowest value from 'biggest, smallest, bigger, smaller'
int		ft_find_cheapest(int *a, t_stack *s)
{
	int	i;
	int	ch;
	int	ind;
	int	val[4];

	i = 0;
	ch = INT_MAX;
	ind = 0;
	while (i++ < a[0])
	{	
		val[0] = s->c[i];
		val[1] = s->d[i];
		val[2] = s->e[i];
		val[3] = s->f[i];
		ft_cheapest_mode(val, s, i);
	}
}

/*	process:
compare	:: the values v[0-3] represent [i] of {c, d, e, f}
find		:: the lowest one
assign	:: 1-4 to s->g to represent {c, d, e, f}
		::
pseudo	;; need a way to	::
					:: use the ->[x] that is cheapest
		;; 1-4 just says WHICH of the indexes is smaller 
		;; so i dont really need anything fancy
		;; because the return is quite simple: which B[i] is the target?
		;; then, s->g denotes which is cheaper for that A[i]
		;; and in the `actual rotation/move function` s->g is checked
		;; and depending on if it is {1-4}, the target is chosen {c-f}
		;;
					:: 
					:: 

TODO:::
something needs to call `ft_find_cheapest`
that something will use s->g to select target
then call a move/align function
which
	calls
		and
	stores
		the actual operation

and then returns to
	turk
		to check
			sort
				and
			status
:::


|||arch|||
<<0>>
	turk
<<1>>
	check sort
<<2>>
	find cheapest
<<3>>
	do & store moves
<<4>>
	reproduce/print moves
|||
;;;
<<0>>
turk
<<1>>	check sort
		UNSORTED
>>2>>	find cheapest
>>3>> do & store moves
		SORTED
<<4<<	return and output moves ()
;;;


*/
void		ft_findnext(int *v, t_stack *s)
{
	if (v[2] == 0 && v[3] != 0)//`bigger` doesn`t exist but `smaller` does
		;
	else if (v[2] != 0 && v[3] == 0)//`bigger` exists but `smaller` doesn't
		;
	else if (v[2] != 0 && v[3] != 0)//`bigger` and `smaller` both exist
		;
	return ;
}

void		ft_cheapest_mode(int *v, t_stack *s, int i)
{
	if (v[0] < v[1] && v[0] < v[2] && v[0] < v[3])
		s->g[i] = s->c[i];
	else if (v[1] < v[0] && v[1] < v[2] && v[1] < v[3])
		s->g[i] = s->d[i];
	else if (v[2] != 0 && v[2] < v[0] && v[2] < v[1] && v[2] < v[3])
		s->g[i] = s->e[i];
	else if (v[1] != 0 && v[3] < v[0] && v[3] < v[1] && v[3] < v[2])
		s->g[i] = s->f[i];
}

//
/*	decides whether to align

when to align?

	when Btarget is not at top
	when Atarget is not at top

how to decide?
	
	compare all cost values for all a[i]
	select A/B-target based on:
		how far from top/bottom?
		how good match?
			?(better to go +1 / -1)
			?(better to do fewest moves)
			?(better to go simple)
*/
void		align_or_not(t_stack *s, int i)
{
	int	t;
	int	s;
	
	s = (s->b[0] / 2 + s->b[0] % 2);
	while ()
	{
		t = s->g[i];
		if (t >= s)
			s = -1;
		else if (t < s)
			s = 1;
	}
}

void		do_and_store(t_stack *s)
{
	int	target;
	target = s->g;
}
/* int		ft_cheapest_mode(int *v, t_stack *s, int i)
{
	if (v[0] < v[1] && v[0] < v[2] && v[0] < v[3])
		s->g[i] = 1;
	else if (v[1] < v[0] && v[1] < v[2] && v[1] < v[3])
		s->g[i] = 2;
	else if (v[2] < v[0] && v[2] < v[1] && v[2] < v[3])
		s->g[i] = 3;
	else if (v[3] < v[0] && v[3] < v[1] && v[3] < v[2])
		s->g[i] = 4;
} */

/*	the issue of modulo

if (index < size / 2 + size % 2)//(then rotate)
if (index > size / 2 + size % 2)//(then reverse)

*/
/*	aligning stack to cost
//A	//we want it BELOW the smallest::
	//stack top should be stk->d[i] + 1
	//unless stk->d[i] == b[0])
	//in which case stack top should be 1
*/
/*	finding the right target
		to do::
		stk->e[i] = find_biggest
			index of biggest
		stk->f[i] = find_smallest
			index of smallest
		
		if (b[j] > a[i])
//biggest is BIGGER than a[i], we need the 'next bigger than a[i]
		stk->e[i] = find_bigger
			index of NEXT bigger
		if (b[k] > a[i])
//smallest is SMALLER than a[i], we need the 'next smaller than a[i]
		stk->f[i] = find_smaller
			index of NEXT smaller
		*/
	
//returns index of biggest number in stack provided
int		find_biggest(int *s)
{
	int	i;
	int	ind;
	int	big;
	
	i = 0;
	ind = 0;
	big = INT_MIN;
	while (i++ < s[0])
	{
		if (s[i] > big)
		{
			big = s[i];
			ind = i;
		}
	}
	return (ind);
}

int		find_smallest(int *s)
{
	int	i;
	int	ind;
	int	sml;
	
	i = 0;
	ind = 0;
	sml = INT_MAX;
	while (i++ < s[0])
	{
		if (s[i] < sml)
		{
			sml = s[i];
			ind = i;
		}
	}
	return (ind);
}
/*
int	dist;
int	cost;
int	tgt;

dist = (size_a / 2 + size_a % 2)
tgt = find_next_bigger(s, a[i]);
if (!tgt)
	tgt = find_next_smaller(s, a[i]);
if (tgt < (size_a / 2 + size_a % 2))
if (i < (size_a / 2 + size_a % 2))
	cost = i + tgt;
else
	cost = size - i + tgt;
if (find_next_bigger(s, a[i])) */
int		find_next_bigger(int *s, int n)
{
	int	i;
	int	ind;
	int	big;//previous smaller
	bool	found;//next smaller
	
	i = 0;
	ind = 0;
	big = INT_MIN;
	found = false;
	while (i++ < s[0])
	{
		if (s[i] > n && (found == false || (found == true && big > s[i])))
		{
			big = s[i];
			found = true;
			ind = i;
		}
	}
	return (ind);
}

int		find_next_smaller(int *s, int n)
{
	int	i;
	int	ind;
	int	sml;//previous smaller
	bool	found;//next smaller
	
	i = 0;
	ind = 0;
	sml = INT_MAX;
	found = false;
	while (i++ < s[0])
	{
		if (s[i] < n && (found == false || (found == true && sml < s[i])))
		{
			sml = s[i];
			found = true;
			ind = i;
		}
	}
	return (ind);
}


int		iterate_cost(int a, int *b)
{
	int	j;
	
	j = 0;
	while (j++ < b[0])
	{
		if ((a + 1) == b[j])
			return (j);
		else if ((a - 1) == b[j])
			return (-j);
	}
	return (0);
}
/*	get_cost_1
1.	check cost of aligning stack/s to different pushed values
	i.	cost of pushing
		a.	a[1] without aligning b[1]
		((c[1] = 0))
		((d = 1))
		((e = 1))
		b.	a[1] by aligning b[j]
		((c[1] = steps +/- to rotate b[j]))
		((d = 1))
		((e = j))
		c.	a[i] without aligning b[1]
		((c[i] = 0))
		((d = i))
		((e = 1))
		d.	a[i] by aligning b[]
		((c[i] == steps +/- to rotate b[j]))
		((d = i))
		((e = j))
	ii.	store `cost`(*) at `c[i]`(**)
		((*) cost == steps to rotate b)
		((**) i == index of target (the one to be pushed))
	iii.	store `target index` at `d`
	iv.	verify that `d != 0`
	--	this way, multiple `candidates` can be evaluated
	--	the `a[index]` of the `winner` can be stored as `d`
	--	OR should it store the `value` of the target?
	--	the `b[index]` of the `target` can be stored as `e`
	--	OR should it store the `value` of the target? */
/* void		get_cost(t_stack *s)
{
	//cost of pushing
	////a.	a[1] without aligning b[1]
	//	def	//t_stack stk->
			//
	////b.	a[1] by aligning b[j]
	//	def	//
			//
	////c.	a[i] without aligning b[1]
	//	def	//
			//
	////d.	a[i] by aligning b[]
	//	def	//
			//
} */

void		check_alignment(t_stack *s, int a, int b)
{
	if (a == 1 && b == 1)
		s->c[a]++;
		s->d[b]++;
	if (a == 1 && b != 1)
		return ;
	if (a != 1 && b == 1)
		return ;
	if (a != 1 && b != 1)
		return ;
}
/* what IS `cost` anyway?
int	*c
	i = index in A stack
	c[i] = moves to align A
int	*d
	j = index in B stack
	d[j] = moves to align B
int	e
	e = target in a[]
int	f
	f = target in b[]
*/
/* what IS `alignment` anyway?
desired target:
	a: the number in a the fewest moves from top
	b: the number in b the fewest moves from top
process:
	first try a[1] with b[1]
		if a[1] == b[1] +/- 1
			c[1] == 0if (i < size/2)
					== i
				if (i > size/2)
					== size - i
		if a[1] == b[j] +/- 1
			c[1] == 0
			d[j] ==
				if (j <= b_size/2)
					== j
				if (j > b_size/2)
					== size - j
*/
/*	moves 'n notation
[PUSH]
[+]	PA
[-]	PB
{ROTATE}
{+}	RA
{-}	RB
}REVERSE{
}+{	RRA
}-{	RRB
{{BOTH}}
{{+}} RR
{{-}} RRR
(SWAP)
(+)	SA
(-)	SB
((SWAP))

*/
/*
size		3	2	2	3
size/2	1	1	1	1
		
		a	b	a	b
		1	5	3	1
		3	2	4	5
		4			2

i	=	1		
j	=	2

c[1]	=	0		0
d[1]	=	0		

c[2]	=	1
d[2]	=	2
c[3]	=	1
e	=	1
f	=	1

e symbolizes "what is index of desired 'next' number in a?"
f symbolizes "what is index of desired 'next' number in b?"

a	b	x	a	b	y	a	b
1	5	x	5	2	y	2	5
3	2	x	1		y	3		
4		x	3		y	4		
			4			1
		[+1]+1[+1](+1){-1}	{{+1}}+1{-1}+1
** here we have the 'desired' "end of turk":
	3 numbers in a
	a is sorted (not sequential)
	b is sorted (not sequential)

***	then the question is:
	"which b[] should be pushed back?"
x		e = 1 (1)
		f = 1 (5)
OR
y		e = 2 (3)
		f = 2 (2)
	"how much should a[] rotate?"
x		c[1] = 0 (nothing)
OR
y		c[2] = 1 (to bring 3 to top)
	"how much should b[] rotate?"
x		d[1] = 0 (nothing)
OR
y		d[2] = 1 (to bring 2 to top)

RESULT:

x	=	\1\ PA	\2\
y	=	\1\ RR->PA	\2\

a	b
5	2
1	
3	
4	

			e == 1
			f == j
	then try a[i] with b[1] until i == a[0]
		if a[i] == b[1] +/- 1
			c[i] ==
				if (i <= a_size/2)
					== i
				if (i > a_size/2)
					== size - i
			d[1] == 0
			e == i
			f == 1
	last try a[i] with b[j] until j == b[0] && i == a[0]
		if a[i] == b[j] +/- 1
			c[i] == 
				if (i <= a_size/2)
					== i
				if (i > a_size/2)
					== size - i
			d[j] == 0
				if (j <= b_size/2)
					== j
				if (j > b_size/2)
					== size - j
			e == i
			f == j
	finally if none of the above are possible
		look for smallest/largest

****	last one
	"which b[] should be pushed back?"
		e = 1 (2)
	"how much should a[] rotate?"
		c[1] = 2 (rotate + 2 (up two))
	"how much should b[] rotate?"
		d[1] = 0 (nothing)

*****	align
	while ((e != 1 && c[e] != 0) || (f != 1 && d[f] != 0))
	{
		if (c[e] > 0)
		{
			rotate_a()
			c[e]--;
		}
		if (c[e] < 0)
		{
			reverse_a()
			c[e]++;
		}
		if (d[f] > 0)
		{
			rotate_b()
			d[f]--;
		}
		if (d[f] < 0)
		{
			reverse_b()
			d[f]++;
		}
	}
				*/

