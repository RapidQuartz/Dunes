/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:54:11 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/31 14:06:42 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_c	*new_cost(t_n *node, t_c *cost, int size);
t_c	*get_node_cost(t_n *node, t_c *cost);
/*
typedef	struct	s_c
{
	t_n		**cap;
	t_n		*ego;
	t_n		*tgt;
	int		dif;
	int		dis;
	int		rot;
	int		rev;
} t_c;
*/
//	
//	//===========================//
//	// initializes `cost` struct //
//	//  used to calculate moves  //
//	//===========================//
//	
void		init_cost(t_n **sta, t_n **stb, t_c *c_a, t_c *c_b)
{
	t_n	*n_a;
	t_n	*n_b;
	
	if (sta != NULL && (*sta)->i->v != 0)
		n_a = (*(*sta)->h);
	else
		n_a = NULL;
	if (stb != NULL && (*stb)->i->v != 0)
		n_b = (*(*stb)->h);
	else
		n_b = NULL;
	if (c_a == NULL && n_a != NULL)
		c_a = new_cost(n_a, c_a, n_a->i->v);
	if ((c_a != NULL || c_b != NULL) && (n_a != NULL || n_b != NULL))
		get_cost(n_a, n_b, c_a, c_b);
}

void	get_cost(t_n *node_a, t_n *node_b, t_c *cost_a, t_c *cost_b)
{
	int	size_a;
	int	size_b;

	size_a = 0;
	size_b = 0;
	if (node_a != NULL)
		size_a = node_a->i->v;
	if (node_b != NULL)
		size_b = node_a->i->v;
	while (size_a > 0)
	{
		cost_a = get_node_cost(node_a, cost_a);
		node_a = node_a->n;
		cost_a = node_a->c;
		size_a--;
	}
	while (size_b > 0)
	{
		cost_b = get_node_cost(node_b, cost_b);
		node_b = node_b->n;
		cost_b = node_b->c;
		size_b--;
	}
}
t_c	*new_cost(t_n *node, t_c *cost, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (cost == NULL)
			cost = malloc(sizeof(*cost));
		if (!cost || cost == NULL)
			d_end();
		cost->ego = node;
		cost->cap = node->h;
		node->c = cost;
		cost->tgt = NULL;
		cost->stk = 'A';
		cost->mov = 0;
		cost->dif = 0;
		cost->dis = 0;
		cost->rot = -1;
		cost->rev = -1;
		if (node->n != *node->h)
			node = node->n;
	}
	cost = (*node->h)->c;
	return (cost);
}

/* gets a pair: node//cost and determines:
t_n*	tgt	what is the target?
			'one higher' (for most members)
			or 'smallest' (for greatest value))
			or 'custom' (in other cases)
int	dif	what is the difference in size to the next number?
int	dis	what is the distance to the number one higher?
int	rot	how many rotations positive (bubbling) to reach target
int	rev	how many rotations negative (sinking) to reach target
*/
t_c	*get_node_cost(t_n *node, t_c *cost)
{
	int	n;
	int	t;
	int	z;
	t_n	*seco;

	seco = node;
	n = node->v;
	z = node->i->v;
	if (n == z)
		n = 0;
	t = n + 1;
	while (cost->rot++ < z && node->v != t)
		node = node->n;
	while (cost->rev++ < z && seco->v != t)
		seco = seco->p;
	cost->tgt = node;
	if (cost->ego->v == z)
		cost->dif = 1;
	else
		cost->dif = cost->ego->n->v - cost->ego->v;
	if (cost->rev < cost->rot)
		cost->dis = cost->rev;
	else
		cost->dis = cost->rot;
	return (cost);
}
/* 
void		find_move(t_n **stack_a, t_n **stack_b)
{
	t_n	*n;
	t_n	*t;

	n = (*stack_a);
	t = n->c->tgt;
	if (t->c->dif == -1 && n->c->rev == 1)//so if the target's 'next' is one lower than target
		n->c->mov = 9;//9 is reverse
	else if (t->c->dif == 1 && n->c->rev == 1)
		n->c->mov = 0;//0 is NO MOVE
	else if (t->c->dif > 1 || n->c->rev > 1)
		n->c->mov = select_push_node(stack_a);
	} */
	
	/*
	n->c->mov = 0;//
int	select_push_node(t_n **stack);
int	select_push_node(t_n **stack)
{
}
	*/

/* PSEUDOCODE TO COMPLY WITH TURK */
/* push 2 to B		-	ONCE
initial_push()
	push_b()
	push_b()
*/
/* select next to push	-	REPEATS
find_next()
	if (head_a < head_b)
		find_lower(head_a)
			add_moves()
	else if (head_a > head_b)
		find_higher()
			add_moves()
*/
/* rotate to next		-	REPEATS
rotate_next()
	if (stack_a != next)
rotate_b()
	if (stack_b != neighbor)
*/
/* push next		-	REPEATS
push_next()
	if (size_a > 3)
*/
/* final_three		-	ONCE
sort_three()
*/
/* push back		-	ONCE
if (stack_a = neighbor)
	push_a()
*/
/* realign		-	ONCE
if (stack_a != 1)
	realign_a()
	[find cheaper rot/rev]
*/
/* PSEUDOCODE TO COMPLY WITH TURK */
