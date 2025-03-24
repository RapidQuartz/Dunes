/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:54:11 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/24 17:46:01 by akjoerse         ###   ########.fr       */
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
t_c		*init_cost(t_n **sta, t_c *cost)
{
	t_n	*node;
	int	size;
	
	node = (*(*sta)->h);
	size = node->i->v;
	if (cost == NULL)
		cost = new_cost(node, cost, size);
	while (size--)
	{
		cost = get_node_cost(node, cost);
		node = node->n;
		cost = node->c;
	}
	return (cost);
}

t_c	*new_cost(t_n *node, t_c *cost, int size)
{
	int	i;
	t_n	**cap;

	i = 0;
	if (node == *node->h)
		cap = node->h;
	while (i++ < size)
	{
		cost = malloc(sizeof(*cost));
		if (!cost || cost == NULL)
			d_end();
		cost->ego = node;
		cost->cap = cap;
		node->c = cost;
		cost->tgt = NULL;
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

void		find_move(t_n **stack)
{
	t_n	*n;
	t_n	*t;

	n = (*stack);
	t = n->c->tgt;
	if (t->c->dif == -1 && n->c->rev == 1)//so if the target's 'next' is one lower than target
		n->c->mov = 9;//9 is reverse
	else if (t->c->dif == 1 && n->c->rev == 1)
		n->c->mov = 0;//0 is NO MOVE
	else if (t->c->dif > 1 || n->c->rev > 1)
		n->c->mov = select_push_node(stack);
	}
	
	/*
	n->c->mov = 0;//
int	select_push_node(t_n **stack);
int	select_push_node(t_n **stack)
{
}
	*/