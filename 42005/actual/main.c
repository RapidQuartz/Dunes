/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:06:33 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/10 18:16:58 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			n;
	unsigned short	*array;
	t_snap		*stack;

	if (argc < 2)
		return (2);
	array = arg_instigator(argc, argv, array);
	if (!array)
		return (3);
	else
		n = array[0];
	argc = array_isunsorted(array, n);
	if (argc < 1)
		return (4);
	stack = init_stack(array, n);
	free (array);
	if (!stack || stack == NULL)
		return (5);
	stack = push_swap(&stack);
	if (!stack || stack == NULL)
		return (6);
	debug(RED"DONT LEAVE STACK UNFREED"DEF);
		// free_stack(stack);
	return (0);
}

t_snap	*init_stack(unsigned short *array, int argn)
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
	snap->prev = NULL;
	if (!(snap->a || snap->b || snap->ac || snap->bc))
		return (NULL);
	snap->size = array[0];
	snap->a[0] = snap->size;
	snap->b[0] = 0;
	while (i++ < argn)
		snap->a[i] = array[i];
	snap = get_delta(snap);
	return (snap);
}

t_snap	*new_snap(t_ree *tree)
{
	int		i;
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
	new->prev = tree;
	return (new);
}