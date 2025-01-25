/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:16:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/24 16:46:59 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//---------------------------------------------------------------------------//
void		negadjacent(t_stack **st, int	g);
void		sorter(t_stack **stack_a, t_stack **stack_b, int size);
int		issorted(t_stack **stack_a);
//---------------------------------------------------------------------------//
void		dosort_abc(t_stack **stack, t_stack **kcats, int flag);
void		dosort_def(t_stack **stack, t_stack **kcats, int flag);
//---------------------------------------------------------------------------//
void		dosort_a(t_stack **stack);
void		dosort_b(t_stack **stack);
void		dosort_c(t_stack **stack);
void		dosort_d(t_stack **stack);
void		dosort_e(t_stack **stack);
void		dosort_f(t_stack **stack);
//---------------------------------------------------------------------------//

void		negadjacent(t_stack **st, int	g) 
{
	int	d;//distance
	int	e;//index(own)
	int	f;//index(higher)
	t_stack	*h;

	h = *st;
	e = h->index;
	f = h->higher->index;
	d = h->adjacency;
	if(d > (g-e))
		h->adjacency = (f-e);
}
/* sorting the leaves		*/
/* attempting




sorter()
void		sorter(t_stack **stack_a, t_stack **stack_b, int size);
void		sorter(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	t_stack	*stack;
}

































					*/
int		analyzer(t_stack **stack)
{
	int		pp;
	int		cp;
	int		np;
	
	if ((*stack)->prev == NULL || (*stack)->next == NULL)
		return (0);
	cp = (*stack)->position;
	np = (*stack)->next->position;
	pp = (*stack)->prev->position;
	if (pp < cp && cp < np && pp < np)//a<b/b<c/a<c//25
		return (25);
	if (pp < cp && cp > np && pp < np)//a<b/b>c/a<c//21
		return (21);
	if (pp > cp && cp < np && pp < np)//ab/bc/ac//26
		return (26);
	if (pp < cp && cp > np && pp > np)//ab/bc/ac//37
		return (37);
	if (pp > cp && cp < np && pp > np)//ab/bc/ac//42
		return (42);
	if (pp > cp && cp > np && pp > np)//ab/bc/ac//38
		return (38);
	return (0);
}
/*
1		//a<b
2		//a>b
4		//b>c
8		//b<c
16		//a<c
32		//a>c

1 2 3	-	abc	-	25//1/8/16		+0
1 3 2	-	acb	-	21//1/4/16		+1
2 1 3	-	bac	-	26//2/8/16		+1
2 3 1	-	bca	-	37//1/4/32		+3
3 1 2	-	cab	-	42//2/8/32		+2
3 2 1	-	cba	-	38//2/4/32		+4
*/
/* doodle corner

''
int		analyzer(t_stack **stack)
{
	t_stack	*h;
	t_stack	*f;
	int		pp;
	int		cp;
	int		np;
	
	h = (*stack);
	if ((*stack)->prev != NULL)
		pp = (*stack)->prev->position;
	cp = (*stack)->position;
	if ((*stack)->next != NULL)
		np = (*stack)->next->position;
	if ((f != NULL) &&  pp < cp && cp < np && pp < np)//a<b/b<c/a<c//25
		return (25);
	if ((f != NULL) &&  pp < cp && cp > np && pp < np)//a<b/b>c/a<c//21
		return (21);
	if ((f != NULL) &&  pp > cp && cp < np && pp < np)//ab/bc/ac//26
		return (26);
	if ((f != NULL) &&  pp < cp && cp > np && pp > np)//ab/bc/ac//37
		return (37);
	if ((f != NULL) &&  pp > cp && cp < np && pp > np)//ab/bc/ac//42
		return (42);
	if ((f != NULL) &&  pp > cp && cp > np && pp > np)//ab/bc/ac//38
		return (38);
	return (0);
}
''
int		analyzer(t_stack **stack)
{
	t_stack	*h;
	t_stack	*f;
	int		pp;
	int		cp;
	int		np;
	
	h = (*stack);
	if ((*stack)->prev != NULL)
		pp = (*stack)->prev->position;
	cp = (*stack)->position;
	if ((*stack)->next != NULL)
		np = (*stack)->next->position;
	if ((f != NULL) &&  pp < cp && cp < np && pp < np)//a<b/b<c/a<c//25
		return (25);
	if ((f != NULL) &&  pp < cp && cp > np && pp < np)//a<b/b>c/a<c//21
		return (21);
	if ((f != NULL) &&  pp > cp && cp < np && pp < np)//ab/bc/ac//26
		return (26);
	if ((f != NULL) &&  pp < cp && cp > np && pp > np)//ab/bc/ac//37
		return (37);
	if ((f != NULL) &&  pp > cp && cp < np && pp > np)//ab/bc/ac//42
		return (42);
	if ((f != NULL) &&  pp > cp && cp > np && pp > np)//ab/bc/ac//38
		return (38);
	return (0);
}
''

''
int		analyzer(t_stack **stack)
{
	t_stack	*h;
	int		f;
	
	h = *stack;
	f = 0;
	if ((h->prev != NULL) &&  h->prev->position < h->position)//a<b
		f += 1;
	if ((h->prev != NULL) &&  h->prev->position > h->position)//a>b
		f += 2;
	if ((h->next != NULL) && h->position > h->next->position)//b>c
		f += 4;
	if ((h->next != NULL) && h->position < h->next->position)//b<c
		f += 8;
	if (((h->prev != NULL) && ((h->next != NULL) && \
	(h->prev->position < h->next->position))))
		f += 16;
	if (((h->prev != NULL) && ((h->next != NULL) && \
	(h->prev->position > h->next->position))))
		f += 32;
	return (f);
}
''
1 2 3	-	abc	-	25//1/8/16
1 3 2	-	acb	-	21//1/4/16
2 1 3	-	bac	-	26//2/8/16
2 3 1	-	bca	-	37//1/4/32
3 1 2	-	cab	-	42//2/8/32
3 2 1	-	cba	-	38//2/4/32

--		p p p			- 3	+0+0+0	+0
--		p s p p		- 4	+0+1+0	+1
--		s p p p		- 4	+1+0+0	+1
--		r s p rr p p	- 6	+2+1+0	+3
--		s p s p p		- 5	+1+1+0	+2
--		r r p rr p rr p	- 7	+2+1+1	+4
*/

void		sorter(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	t_stack	*stack;
	while (!issorted(stack_a))
	{
		i = analyzer(stack_a);
		if ((i == 25) || (i == 21) || (i == 26))
			dosort_abc(stack_a, stack_b, i);
		if ((i == 37) || (i == 42) || (i == 38))
			dosort_def(stack_a, stack_b, i);
		if (i == 0)
			return ;
	}
}
/*
dosort_a()//25	--		p p p			- 3	+0+0+0	+0
dosort_b()//21	--		p s p p		- 4	+0+1+0	+1
dosort_c()//26	--		s p p p		- 4	+1+0+0	+1
dosort_d()//37	--		r s p rr p p	- 6	+2+1+0	+3
dosort_e()//42	--		s p s p p		- 5	+1+1+0	+2
dosort_f()//38	--		r r p rr p rr p	- 7	+2+1+1	+4
*/
//dosort_a()//25	--		p p p			- 3	+0+0+0	+0
//dosort_b()//21	--		p s p p		- 4	+0+1+0	+1
//dosort_c()//26	--		s p p p		- 4	+1+0+0	+1

void		dosort_abc(t_stack **stack, t_stack **kcats, int flag)
{
	if (flag == 25)
	{
		dd(do_pb, &(*stack), &(*kcats));
		do_pb((stack), (kcats));
	}
	if (flag == 21)
	{
		do_pb(&(*stack), &(*kcats));
		do_sa(&(*stack));
		dd(do_pb, &(*stack), &(*kcats));
	}
	if (flag == 26)
	{
		do_sa(&(*stack));
		dd(do_pb, &(*stack), &(*kcats));
		do_pb(&(*stack), &(*kcats));
	}
}
void		dosort_def(t_stack **stack, t_stack **kcats, int flag)
{
	if (flag == 37)
	{
		do_ra(&(*stack));
		do_sa(&(*stack));
		do_pb(&(*stack), &(*kcats));
		do_rra(&(*stack));
		dd(do_pb, &(*stack), &(*kcats));
	}
	if (flag == 42)
	{
		do_sa(&(*stack));
		do_pb(&(*stack), &(*kcats));
		do_sa(&(*stack));
		dd(do_pb, &(*stack), &(*kcats));
	}
	if (flag == 38)
	{
		do_double(rotate, &(*stack));
		do_ra(&(*stack));
		do_pb(&(*stack), &(*kcats));
		do_rra(&(*stack));
		do_pb(&(*stack), &(*kcats));
		do_rra(&(*stack));
		do_pb(&(*stack), &(*kcats));
	}
}
/*
//25--		p p p			-
void		dosort_a(t_stack **stack)
{
	do_push((*stack));
	do_push((*stack));
	do_push((*stack));
	return ;
}

//21--		p s p p		-
void		dosort_b(t_stack **stack)
{
	do_push((*stack));
	do_swap((*stack));
	do_push((*stack));
	do_push((*stack));
	return ;
}

//26--		s p p p		-
void		dosort_c(t_stack **stack)
{
	do_swap((*stack));
	do_push((*stack));
	do_push((*stack));
	do_push((*stack));
	return ;
}

//37--		r s p rr p p	-
void		dosort_d(t_stack **stack)
{
	do_rotate((*stack));
	do_swap((*stack));
	do_push((*stack));
	do_reverse((*stack));
	do_push((*stack));
	do_push((*stack));
	return ;
}

//42--		s p s p p		-
void		dosort_e(t_stack **stack)
{
	do_swap((*stack));
	do_push((*stack));
	do_swap((*stack));
	do_push((*stack));
	do_push((*stack));
	return ;
}

//38--		r r p rr p rr p	-
void		dosort_f(t_stack **stack)
{
	do_rotate((*stack));
	do_rotate((*stack));
	do_push((*stack));
	do_reverse((*stack));
	do_push((*stack));
	do_reverse((*stack));
	do_push((*stack));
	return ;
}
*/
/* 	
				*/
int		issorted(t_stack **stack_a)
{
	if (!(*stack_a))
		return (0);
	while ((*stack_a)->next != NULL)
	{
		if (((*stack_a)->position) > ((*stack_a)->next->position))
			return (0);
		(*stack_a) = (*stack_a)->next;
	}
	return (1);
}
/* 					*/