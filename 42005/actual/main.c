/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:06:33 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/09 19:30:29 by akjoerse         ###   ########.fr       */
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
	argc = array_isunsorted(array, n) < 0;
	if (argc < 1)
		return (4);
	stack = take_snap(array, n);
	if (!stack || stack == NULL)
		return (5);
	push_swap(&stack);
	if (!stack || stack == NULL)
		return (6);
	free (array);
	free_stack(stack);
	return (0);
}
