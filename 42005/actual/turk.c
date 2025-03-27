/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:27:05 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/27 12:47:42 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_n	*highest_member_b(t_n **stb);

/* on the process of the turk
set target
	sets a target (in B) that is close to the element (in A)
		the target:
			is close in value
			can be smaller or greater
			
*/
void	exec_turk(t_n **sta, t_n **stb);
void	exec_turk(t_n **sta, t_n **stb)
{
	t_n	*next;
	t_n	*db;
	int	v;
	int	n;
	int	p;
	int	h;
	
	d_print_twostack_values(sta, stb, 1);
	push(sta, stb);
	push(sta, stb);
	while ((*sta)->i->v > 3)
	{
		next_find(sta, stb);//finds target for whole A stack
		next = (*sta)->c->tgt;//
		/* should actually optimize so A is aligned, but will iterate anyway. */
		next_align(sta, stb, next);
		next_push(sta, stb, next);
		(*sta) = (*sta)->n;
	}
	sort_three(sta);
	last_push(sta, stb);
	last_align(sta, stb);
}

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
