/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:27:05 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/02 10:55:42 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_n	*highest_member_b(t_n **stb);


void	exec_turk(t_stack **stk)
{
	int 		*a;
	int 		*b;
	t_stack		*s;

	s = (*stk);
	a = s->a;
	b = s->b;
	//	push 2
	s = push_b(a, b, s);
	s = push_b(a, b, s);
	d_print_stack(s);
	while (!stack_is_sorted(*stk))
	{
		check_rotation((*stk)->a, (*stk)->b, (*stk)->c);
	}

	HALLO
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
/*		align
*/
/*		push next
*/
//	last 3
/*		sort 3
*/
/*	push back
*/
/*	output instructions
*/
}
void	check_rotation(t_stack **stk)
{
	int		i;

	i = 0;
	
}
/* void	check_rotation(t_stack **stk)
{
	int		i;
	int		h;
	int		*a;
	int		*b;
	t_stack	*s;

	i = 0;
	s = (*stk);
	a = s->a;
	b = s->b;
	if (a[1] > b[1])
	{
		h = 1;
		while (i++ < b[0])
		{
			if (b[i] > b[h])
				h = i;
		}
		s->d = h;
		h = 1;
		i = 0;
		while (i++ < a[0])
		{
			if (a[i] > a[h])
		}
	}
	else if (s->a[1] < s->b[1])
	(*stk) = s;
} */

void	next_find(t_n **sta, t_n **stb);
void	next_find(t_n **sta, t_n **stb)
{
	int	i;
	int	j;
	int	max;
	t_n	*tgt;

	i = 0;
	while (i < (*sta)->i->v)
	{
		tgt = NULL;
		j = 0;
		while (j < (*stb)->i->v)
		{
			if (((*stb)->v < (*sta)->v) &&
			tgt == NULL || (*stb)->v > tgt->v)
				tgt = (*stb);
			(*stb) = (*stb)->n;
			j++;
		}
		if (tgt == NULL)
			(*sta)->c->tgt = highest_member_b(stb);
		else
			(*sta)->c->tgt = tgt;
		(*sta) = (*sta)->n;
		i++;
	}
}

t_n	*highest_member_b(t_n **stb)
{
	int	size;
	int	max;
	t_n	*tgt;
	int	i;

	size = (*stb)->i->v;
	max = INT_MIN;
	tgt = NULL;
	i = 0;
	while (i < size)
	{
		if ((*stb)->v > max)
		{
			max = (*stb)->v;
			tgt = (*stb);
		}
		i++;
	}
	return (tgt);
}

void	next_align(t_n **sta, t_n **stb, t_n *next);
/* aligns stack A and B so each target is ready for pushing
eg; if first to push is the second in B, this is reflected thus:
	A[1]->c->tgt = B[2]
	A[2]->c->tgt = B[1]
then, instead of reordering B, reorder A so A[2] is on top
consider "cost" the number of moves needed to align stacks
*/
void	next_align(t_n **sta, t_n **stb, t_n *next)
{
	int	rotate;
	int	reverse;
	t_n	*fwd;
	t_n	*rev;
	
	next->c->rot = 0;
	next->c->rev = 0;
	if ((*stb) == next)
		return ;
	else if ((*stb) != next)
	{
		fwd = (*stb)->n;
		rev = (*stb)->p;
		while (fwd->c->tgt != next && next->c->rot++)
			fwd = fwd->n;
		while (rev->c->tgt != next && next->c->rev++)
			rev = rev->p;
		if (next->c->rot < next->c->rev)
			next->c->rev = -1;
		else
			next->c->rot = -1;
	}
}

void	next_push(t_n **sta, t_n **stb, t_n *next);
void	next_push(t_n **sta, t_n **stb, t_n *next)
{
	
}
void	last_push(t_n **sta, t_n **stb);
void	last_push(t_n **sta, t_n **stb)
{
	
}

void	last_align(t_n **sta, t_n **stb);
void	last_align(t_n **sta, t_n **stb)
{
	
}
