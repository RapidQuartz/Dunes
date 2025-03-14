/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:49:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/14 13:41:54 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_snap	*init_moves(t_ree *tree, t_ops op);
void		print_tree(t_ree *root);
void		print_branch(t_snap *snap);
char		*get_opname(t_ops op);



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
	t_snap	*snap;
	t_ree		*root;
	t_ree		*stump;
	int		delta;

	root = (*stack)->tree;
	delta = root->order->delta;
	j = 42;
	k = 0;
	i = 0;
	stump = root;
	while (root->moves[0] == NULL && k++ < j)
	{
		if (i == 11)
			i = 0;
		if (i < 11)
			i++;
		if (k == 1)
			root = branch_tree(root);
		else if (i > 0 && root->moves[i] != NULL)
			root = branch_tree(root->moves[i]->tree);
		if (root->moves[0] != NULL)
		{
			debug("EUREKA");
			print_branch(root->moves[0]);
			return (root->moves[0]);
		}
		if (root->order != NULL)
			print_tree(root);
		compare_branch(root);
		if (k == j)
			debug("ran out of time");
		
	}
	return (root->order);
}

char *get_opname(t_ops op)
{
	if (op == NONE)
		return ("\0\0\0");
	if (op == PA)
		return ("pa\0");
	if (op == PB)
		return ("pb\0");
	if (op == SA)
		return ("sa\0");
	if (op == SB)
		return ("sb\0");
	if (op == SS)
		return ("ss\0");
	if (op == RA)
		return ("ra\0");
	if (op == RB)
		return ("rb\0");
	if (op == RR)
		return ("rr\0");
	if (op == RRA)
		return ("rra");
	if (op == RRB)
		return ("rrb");
	if (op == RRR)
		return ("rrr");
	return ("\0");
}

void		print_branch(t_snap *snap)
{
	int	j;
	int	i;
	char	*opname;
	t_snap	*orig;
	
	i = 0;
	while (1)
	{
		printf("iteration: %d\noperation: %s\n", snap->tree->iteration, \
			get_opname(snap->op));
		j = 1;
		while (j <= snap->size && (j <= snap->a[0] || j <= snap->b[0]))
		{
			if (j <= snap->a[0])
				printf("a:\t%d=|", snap->a[j]);
			else
				printf("a:\t =|");
			if (j <= snap->b[0])
				printf("|=%d\t:b\n", snap->b[j]);
			else
				printf("|= \t:b\n");
			j++;
		}
		break ;
	}
}

void		print_tree(t_ree *root)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < 11)
	{
		if (root->order != NULL && i == 1)
			print_branch(root->order);
		if (root->moves[i] != NULL)
			print_branch(root->moves[i]);
	}
}
t_ree		*branch_tree(t_ree *root)
{
	t_ops		op;
	t_snap	*move;
	t_ree		*tree;
	int		unsorted;

	op = NONE;
	unsorted = 1;
	while (++op < END)
	{
		if (move_islegal(root, op))
		{
			move = make_moves(root, op);
			if (move == NULL)
				return (NULL);
			if (move->a[0] == move->size)
				unsorted = stack_isunsorted(move);
			if (move->delta != 0 && unsorted)
				root->moves[op] = move;
			else if (move->delta == 0 && !unsorted)
				root->moves[0] = move;
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

	o = tree->order;
	p = o->op;
	if ((o->a[0] > 0 && (op == PB && p != PA)) || (o->b[0] > 0 && \
(op == PA && p != PB)) || (o->a[0] > 1 && ((op == SA && (p != SA && p != SB)) \
|| (op == RA && p != RRA) || (op == RRA && p != RA))) || \
(o->b[0] > 1 && ((op == SB && (p != SA && p != SB)) || \
(op == RB && p != RRB))) || \
((o->a[0] > 1 && o->b[0] > 1) && \
((op == PB && p != PA) || (op == PA && p != PB) || (op == RB && p != RA) || \
(op == RA && p != RB) || (op == SS && p != SS) || \
(op == RR && p != RRR) || (op == RRR && p != RR))))
		return (1);
	else
	{
		tree->moves[op] = NULL;
		tree->probation[op] = -1;
	}
	return (0);
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