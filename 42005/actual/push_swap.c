/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:49:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/10 18:28:32 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_snap	*init_moves(t_ree *tree, int op);
t_snap		*make_moves(t_ree *tree, int op);

//does the heavy lifting:
//	//iterates ``make_tree`` until a sort is found
//	//returns `root` which represents the solved stack
//	//this is passed to `print_program`
//	//
t_snap *push_swap(t_snap **stack)
{
	short		size;
	t_ree		*tree;
	t_snap	*snap;
	t_snap	*root;
	int		delta;

	root = (*stack);
	size = root->size;
	tree = NULL;
	delta = root->delta;
	tree = make_tree(root, tree);
	if (!tree || tree == NULL)
		return (NULL);
	while (tree->moves[0] == NULL)
	{
		tree = 
	}
		//	climb_tree// ft for checking order along whole array/tree
//	ft_arborist// ft for selecting branches to prune
//	ft_treesurgeon// ft for pruning/freeing
//	print_program// ft for outputting instructions
	return (root);
}

t_ree		*make_tree(t_snap *stack, t_ree *root)
{
	int	i;

	i = 0;
	if (root == NULL)
		root = malloc(sizeof(*root));
	if (!root)
		return (NULL);
	root->moves[0] = NULL;
	while (i++ < 11)
		root->moves[i] = init_moves(root, i);
	return (root);
}

t_snap	*init_moves(t_ree *tree, int op)
{
	t_snap	*new;
	short		factor;

	new = new_snap(tree);
	if (!new || new == NULL)
		return (NULL);
	new->prev = tree;
	new = make_moves(tree, op);
	return (new);
}

t_snap		*make_moves(t_ree *tree, int op)
{
	t_snap	*new;
	
	new = tree->moves[op];
	if (move_islegal(tree->order, op))
	{
		new->op = op;
		if (op >= 1 && op <= 2)//push
			new = do_push(tree, op);
		else if (op >= 3 && op <= 5)//swap
			new = do_swap(tree, op);
		else if (op >= 6 && op <= 8)//rotate
			new = do_rotate(tree, op);
		else if (op >= 9 && op <= 11)//reverse
			new = do_reverse(tree, op);
		new = get_delta(new);
		return (new);
	}
	else
		free (tree->moves[op]);
	return (NULL);
}

short		move_islegal(t_snap *order, short op)
{
	short	i;

	if (((op == 1 || op == 4 || op == 7 || op == 10) \
	&& (order->b[0] > 0)) \
	|| ((op == 2 || op == 3 || op == 6 || op == 9) \
	&& (order->a[0] > 0)) \
	|| ((op == 5 || op == 8 || op == 11) \
	&& (order->a[0] > 0 && order->b[0] > 0)))
		return (1);
	else
		return (0);
}
