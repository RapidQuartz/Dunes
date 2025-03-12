/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:49:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/12 19:26:40 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_snap	*init_moves(t_ree *tree, int op);
void		print_branch(t_ree *root);

t_snap		*make_moves(t_ree *root, int op);

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
	int		delta;
	int		dummy = 0;

	root = (*stack)->tree;
	delta = root->order->delta;
	j = 0;
	k = 0;
	while (root->moves[0] == NULL && dummy++ < 11)
	{
		i = 0;
		root = branch_tree(root);
		if (root->order != NULL)
		{
			j = 0;
			printf("ITERATION: %d\nsize:%d\t delta:%d\t penalty:%d\t op:%d\n", root->iteration, \
				root->order->size, root->order->delta, root->order->penalty, root->order->op);
			while (j++ < root->order->size)
				printf("a:\t%d=||=%d\t:b\n", root->order->a[j], root->order->b[j]);
			
		}
		while (i++ < 11)
		{
			if (root->moves[i] != NULL)
			{
				j = 0;
				printf("op: %d\t delta:%d\na-size:\t%d=||=%d\t:b-size\n", \
				root->moves[i]->op, root->moves[i]->delta, root->moves[i]->a[0], root->moves[i]->b[0]);
				fflush(stdout);
				while (j++ < root->order->size)
				{	
					printf("a:\t%d=||=%d\t:b\n", root->moves[i]->a[j], root->moves[i]->b[j]);
					fflush(stdout);
				}
			}
		}
		if (root == NULL)
			return (NULL);
		compare_branch(root);
		if (k++ < 11)
		{
			while (root->moves[k] == NULL)
				k++;
			if (root->moves[k] != NULL)
				root = root->moves[k]->tree;
		}
		else
			break ;
			// print_branch(root);
	}
	return (root->order);
}
void		print_branch(t_ree *root)
{
	int	i = 0;
	int	j;
	while (i++ < 12)
	{
		j = 0;

		if (root->moves[i] != NULL)
		{
			if (root->moves[i]->tree == NULL)
			{
				printf("size:%d\t delta:%d\t penalty:%d\t op:%d\n", root->moves[i]->size, root->moves[i]->delta, \
					root->moves[i]->penalty, root->moves[i]->op);
				while (j < root->moves[i]->size)
				{
					printf("a:\t%d=||=%d\t:b\n", root->moves[i]->a[j], root->moves[i]->b[j]);
					j++;
				}
			}
			else
			{
				fflush(stdout);
				print_branch(root->moves[i]->tree);
			}

		}
	}
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
			else
				root->moves[op] = move;
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
	if (op >= 1 && op <= 2)//push
		new = do_push(new, root, op);
	else if (op >= 3 && op <= 5)//swap
		new = do_swap(new, root, op);
	else if (op >= 6 && op <= 8)//rotate
		new = do_rotate(new, root, op);
	else if (op >= 9 && op <= 11)//reverse
		new = do_reverse(new, root, op);
	new = get_delta(new);
	root->probation[op] += new->delta;
	new->op = op;
	new->up = root->order;
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
