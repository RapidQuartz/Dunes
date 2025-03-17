/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:49:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/17 22:06:44 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//does the heavy lifting:
//	//iterates ``branch_tree`` until a sort is found
//	//returns `root` which represents the solved stack
//	//this is passed to `print_program`
//	//
t_snap *push_swap(t_snap **stack)
{
	short		i;
	short		j;
	short		k;
	t_ree		*root;
	int		delta;

	root = (*stack)->tree;
	j = 420;
	k = 0;
	i = 0;
	root = branch_tree(root);
	//`k`is a dummy measure to keep it from looping infinitely
	while (k++ < j && root->moves[0] != NULL)
	{
		root = branch_tree(root);
		compare_branch(root);
		root = 
	}
	if (k == j)
		debug("ran out of time");
	return (root->moves[0]);
}

t_ree		*branch_tree(t_ree *root)
{
	t_ops		op;
	t_snap	*move;
	t_snap	*trail;

	op = NONE;
	while (++op < END && !root->moves[0])
	{
		if (move_islegal(root, op))
		{
			move = make_moves(root, op);
			if (stack_isunsorted(move))
				root->moves[op] = move;
			else if (move->delta == 0 && !stack_isunsorted(move) && move->a[0] == move->size)
				root->moves[0] = move;
		}
		else
		{
			move = NULL;
			root->moves[op] = NULL;
		}
	}
	return (root);
}

t_snap		*make_moves(t_ree *root, t_ops op)
{
	t_snap	*new;
	
	new = new_snap(root);
	if (!new || new == NULL)
		return (NULL);//ERROR
	if (op >= PA && op <= PB)//push
		new = do_push(new, root, op);
	else if (op >= SA && op <= SS)//swap
		new = do_swap(new, root, op);
	else if (op >= RA && op <= RR)//rotate
		new = do_rotate(new, root, op);
	else if (op >= RRA && op <= RRR)//reverse
		new = do_reverse(new, root, op);
	new = get_delta(new);
	root->probation[op] += new->delta;
	new->op = op;
	new->up = root->order;
	return (new);
}

short		move_islegal(t_ree *tree, t_ops op)
{
	t_snap	*o;
	t_ops		p;
	short		legal;

	o = tree->order;
	p = o->op;
	legal = 0;
	if ( \
	((o->a[0] > 0 && op == PB) || (o->b[0] > 0 && op == PA) || \
	(o->a[0] > 1 && (op == SA || op == RA || op == RRA)) || \
	(o->b[0] > 1 && (op == SB || op == RB || op == RRB)) || \
	(o->a[0] > 1 && o->b[0] > 1 && (op == SS || op == RR || op == RRR))))
	{
		if (p != NONE)
			legal = move_isredundant(tree, op, p);
		else
			legal = 1;
	}
	return (legal);
}

//	if a move is LEGAL
//	^^^^^ABOVE^^^^^
//	vvvvvBELOWvvvvv
//	if a move is REDUNDANT
/* a move is redundandy if the previous move has the opposite effect OR
if a combo move is more efficient*/
short		move_isredundant(t_ree *tree, t_ops op, t_ops p)
{
	if ((op == PA && p != PB) || (op == PB && p != PA) || \
(op == SA && (p != SA && p != SB)) || (op == SB && (p != SA && p != SB)) || \
(op == RRA && p != RA) || (op == RA && p != RRA) || (op == RB && p != RRB) || \
(op == RRR && p != RR) || (op == RR && p != RRR) || (op == RA && p != RB) || \
(op == RB && p != RA) || (op == SS && p != SS))
		return (1);
	else
		return (0);
	/* 
	if ((o->a[0] > 0 && (op == PB && p != PA)) || (o->b[0] > 0 && \
		(op == PA && p != PB)) || (o->a[0] > 1 && ((op == SA && (p != SA && p != SB)) \
		|| (op == RA && p != RRA) || (op == RRA && p != RA))) || \
		(o->b[0] > 1 && ((op == SB && (p != SA && p != SB)) || \
		(op == RB && p != RRB))) || \
		((o->a[0] > 1 && o->b[0] > 1) && \
		((op == PB && p != PA) || (op == PA && p != PB) || (op == RB && p != RA) || \
		(op == RA && p != RB) || (op == SS && p != SS) || \
		(op == RR && p != RRR) || (op == RRR && p != RR))))
	 */
}
//TODO PROVISION REDUNDANCY
/*redundant moves in sequence:
sa/sb == ss

ra/rb == rr
rra/rrb == rrr
*/
/*illogical moves:
sx if any x has 1 member
sx->sx
rx if any x has 1 member
rx->rx
rrx if any x has 1 member
*/
//ENUM FOR READABILITY
//defines?