/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:32:08 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/24 14:26:35 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_n **sta)
{
	int	ops[3];
	int	i;
	t_n	*s;

	s = (*sta);
	i = 0;
	s = *s->h;
	while (i < 3)
		ops[i++] = 0;
	if (((s->v < s->n->v) && (s->n->v > s->p->v) && (s->v > s->p->v)) || \
	((s->v < s->n->v) && (s->n->v > s->p->v) && (s->v < s->p->v)))
		ops[0] = 1;
	if (((s->v > s->n->v) && (s->n->v < s->p->v) && (s->v > s->p->v)) || \
	((s->v > s->n->v) && (s->n->v > s->p->v) && (s->v > s->p->v)))
		ops[1] = 1;
	if (((s->v < s->n->v) && (s->n->v > s->p->v) && (s->v < s->p->v)) || \
	((s->v > s->n->v) && (s->n->v > s->p->v) && (s->v > s->p->v)) || \
	((s->v > s->n->v) && (s->n->v < s->p->v) && (s->v < s->p->v)))
		ops[2] = 1;
	if (ops[0] == 1)
		reverse(sta);
	if (ops[1] == 1)
		rotate(sta);
	if (ops[2] == 1)
		swap(sta);
}

void	sort_stack(t_n **sta, t_n **stb)
{
	t_c	*cost;

	if ((sta != NULL && (*sta)->c == NULL) || (stb != NULL&& (*stb)->c == NULL))
		cost = NULL;
	cost = init_cost(sta, cost);
	if (cost != NULL)
		find_move(sta);
	if (cost->mov == 6 && cost->rot == 1)
		rotate(sta);
	else if (cost->mov == 9 && cost->rev == 1)
		reverse(sta);
	else if (cost->mov == 2)
		push(sta, stb);
	else if (cost->mov == 3)
		swap(sta);
	d_print_cost(&cost);
}

void	reverse(t_n **sta)
{
	t_n	*s;
	t_n	**h;

	h = NULL;
	s = (*sta);
	h = &s->p;
	s->i->n = (*h);
	s->i->p = (*h)->p;
	s->h = h;
	sta = &s;
	d_print_stack(&s);
}

void	rotate(t_n **sta)
{
	t_n	*s;
	t_n	**h;

	h = NULL;
	s = (*sta);
	h = &s->n;
	s->i->n = (*h);
	s->i->p = (*h)->p;
	s->h = h;
	sta = &s;
	d_print_stack(&s);
}

void	swap(t_n **sta)
{
	t_n	*old_head;
	t_n	*new_head;
	t_n	*tail;
	t_n	**head_ptr;

	old_head = (*(*sta)->h);
	new_head = old_head->n;
	tail = old_head->p;
	new_head->p = tail;
	tail->n = new_head;
	old_head->p = new_head;
	old_head->n = new_head->n;
	new_head->n = old_head;
	head_ptr = &new_head;
	new_head->h = head_ptr;
	new_head->i->n = new_head;
	new_head->i->p = tail;
	sta = &new_head;
	d_print_stack(sta);
}
