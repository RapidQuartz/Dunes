/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:49:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/11 16:33:16 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_snap	*init_moves(t_ree *tree, int op);
t_snap		*make_moves(t_ree *root, int op);

//does the heavy lifting:
//	//iterates ``branch_tree`` until a sort is found
//	//returns `root` which represents the solved stack
//	//this is passed to `print_program`
//	//
t_snap *push_swap(t_snap **stack)
{
	short		size;
	t_snap	*snap;
	t_ree		*root;
	int		delta;

	root = (*stack)->tree;
	size = root->order->size;
	delta = root->order->delta;
	while (root->moves[0] == NULL)
	{
		root = branch_tree(root);
		if (root == NULL)
			return (NULL);
		compare_branch(root);
	}
	return (root->order);
}

t_ree		*branch_tree(t_ree *root)
{
	int		op;
	t_snap	*move;
	t_ree		*tree;

	op = 0;
	while (op++ < 11)
	{
		if (move_islegal(root, op))
		{
			move = make_moves(root, op);
			if (move == NULL)
				return (NULL);
		}
	}
	return (root);
}

t_snap		*make_moves(t_ree *root, int op)
{
	t_snap	*new;
	
	new = new_snap(root);
	if (!new || new == NULL)
		return (NULL);//ERROR
	root->moves[op] = new;
	if (op >= 1 && op <= 2)//push
		new = do_push(root, op);
	else if (op >= 3 && op <= 5)//swap
		new = do_swap(root, op);
	else if (op >= 6 && op <= 8)//rotate
		new = do_rotate(root, op);
	else if (op >= 9 && op <= 11)//reverse
		new = do_reverse(root, op);
	new = get_delta(new);
	root->probation[op] += new->delta;
	new->op = op;
	return (new);
}

short		move_islegal(t_ree *tree, short op)
{
	short		i;
	t_snap	*order;

	order = tree->order;
	if (((op == 1 || op == 4 || op == 7 || op == 10) \
	&& (order->b[0] > 0)) \
	|| ((op == 2 || op == 3 || op == 6 || op == 9) \
	&& (order->a[0] > 0)) \
	|| ((op == 5 || op == 8 || op == 11) \
	&& (order->a[0] > 0 && order->b[0] > 0)))
		return (1);
	else
	{
		tree->moves[op] = NULL;
		tree->probation[op] = -1;
	}
	return (0);
}
