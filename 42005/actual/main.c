/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:06:33 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/17 12:57:45 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_ree		*new_tree(t_ree *root, t_snap *snap);
void	run_program(t_snap *vic);

int	main(int argc, char **argv)
{
	int			argn;
	int			*array;
	t_snap		*stack;
	t_ree			*root;

	if (argc < 2)
		return (2);
	array = arg_instigator(argc, argv, array);
	if (!array)
		return (3);
	argn = array[0];
	stack = init_stack(array, argn);
	if (!stack_isunsorted(stack))
		return (4);
	root = init_tree(NULL, stack);
	if (!root || root == NULL || !stack || stack == NULL)
		return (5);
	stack = push_swap(&stack);
	if (!stack || stack == NULL)
		return (6);
	run_program(stack);
	free (stack);
	return (0);
}

void	run_program(t_snap *vic)
{
	int	i;
	char *op;
	t_snap	*tmp;
	debug("in RP");
	if (vic->delta == 0)
	{
		while (vic->up != NULL)
		{
			op = get_opname(vic->op);
			// printf("iteration: %d\tvic->op: %s\n", vic->tree->iteration, op);
			tmp = vic;
			vic->up->sol = tmp->op;
			vic->tree->moves[0] = tmp;
			vic = vic->up;
		}
		if (vic->up == NULL)
			vic->tree->moves[0] = vic;
	}
	while (vic != NULL && vic->sol != 0)
	{
		op = get_opname(vic->sol);
		printf("%s\n", op);
		vic = vic->tree->moves[vic->sol];
	}
	/* while (vic->delta != 0)
	{
		vic = vic->tree->moves[0];
		
		write(1, op, 3);
		write(1, "\n", 1);
	} */
}

t_ree		*init_tree(t_ree *root, t_snap *snap)
{
	t_ree		*tree;
	int		i;

	i = 0;
	tree = malloc(sizeof(*tree));
	if (!tree)
		return (NULL);
	if (root == NULL)
		tree->iteration = 0;
	else
		tree->iteration = 1 + root->iteration;
	while (i < 11)
		tree->moves[i++] = NULL;
	snap->tree = tree;
	tree->order = snap;
	return (tree);
}

t_snap	*init_stack(int *array, int argn)
{
	int		i;
	t_snap	*new;

	i = 0;
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->a = malloc(sizeof(short) * argn + 1);
	new->b = malloc(sizeof(short) * argn + 1);
	new->ac = malloc(sizeof(short) * argn + 1);
	new->bc = malloc(sizeof(short) * argn + 1);
	new->ar = malloc(sizeof(short) * argn + 1);
	new->br = malloc(sizeof(short) * argn + 1);
	if (!(new->a || new->ac))
		return (NULL);
	new->size = array[0];
	new = nullify_new(new);
	new->a[0] = new->size;
	new = arg_normalizer(new, array);
	new = get_delta(new);
	new->up = NULL;
	free (array);
	return (new);
}

t_snap	*new_snap(t_ree *tree)
{
	int		argn;
	t_snap	*new;
	
	argn = tree->order->size;
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->a = malloc(sizeof(short) * argn + 1);
	new->b = malloc(sizeof(short) * argn + 1);
	new->ac = malloc(sizeof(short) * argn + 1);
	new->bc = malloc(sizeof(short) * argn + 1);
	new->ar = malloc(sizeof(short) * argn + 1);
	new->br = malloc(sizeof(short) * argn + 1);
	if (!(new->a || new->b || new->ac || new->bc || new->ar || new->br))
		return (NULL);
	new = nullify_new(new);
	new->tree = new_tree(tree, new);
	new->sol = 0;
	new->up = tree->order;
	new->size = argn;
	return (new);
}

t_ree		*new_tree(t_ree *root, t_snap *snap)
{
	t_ree		*tree;
	int		branches;
	
	branches = 0;
	tree = malloc(sizeof(*tree));
	if (!tree)
		return (NULL);
	tree->iteration = 1 + root->iteration;
	while (branches++ < 11)
		tree->moves[branches] = NULL;
	tree->order = snap;
	return (tree);
}

t_snap	*nullify_new(t_snap *new)
{
	int	i;

	i = 0;
	while (i++ < new->size)
	{
		new->a[i] = 0;
		new->b[i] = 0;
		new->ac[i] = 0;
		new->bc[i] = 0;
		new->ar[i] = 0;
		new->br[i] = 0;
	}
	return (new);
}