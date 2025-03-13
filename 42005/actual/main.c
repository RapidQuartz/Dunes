/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:06:33 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/13 18:02:46 by akjoerse         ###   ########.fr       */
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
	if (!array_isunsorted(array, argn))
		return (4);
	stack = init_stack(array, argn);
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
	t_snap	*snap;

	i = 0;
	snap = malloc(sizeof(*snap));
	if (!snap)
		return (NULL);
	snap->a = malloc(sizeof(unsigned short) * argn + 1);
	snap->b = malloc(sizeof(unsigned short) * argn + 1);
	snap->ac = malloc(sizeof(unsigned short) * argn + 1);
	snap->bc = malloc(sizeof(unsigned short) * argn + 1);
	if (!(snap->a || snap->ac))
		return (NULL);
	snap->size = array[0];
	snap->a[0] = snap->size;
	while (i++ < argn)
		snap->a[i] = array[i];
	snap = get_delta(snap);
	snap->up = NULL;
	free (array);
	snap = arg_normalizer(snap);
	return (snap);
}

t_snap	*new_snap(t_ree *tree)
{
	int		argn;
	t_snap	*new;
	
	argn = tree->order->size;
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->a = malloc(sizeof(unsigned short) * argn + 1);
	new->b = malloc(sizeof(unsigned short) * argn + 1);
	new->ac = malloc(sizeof(unsigned short) * argn + 1);
	new->bc = malloc(sizeof(unsigned short) * argn + 1);
	if (!(new->a || new->b || new->ac || new->bc))
		return (NULL);
	new->tree = new_tree(tree, new);
	new->sol = 0;
	new->up = tree->order;
	new->size = argn;
	new->a[0] = 0;
	new->b[0] = 0;
	new->ac[0] = 0;
	new->bc[0] = 0;
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
