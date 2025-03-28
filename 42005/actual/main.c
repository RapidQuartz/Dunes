/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:38:31 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/28 11:54:19 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_b;
	// t_n	*stack_a;
	// t_n	*stack_b;
	int		*arr;
	int		i;
	int		argn;
	
	if (argc < 2)
		return (-1);
	stack = NULL;
	argn = count_arg(argc, argv);
	arr = make_arr(argc, argv, argn, arr);
	arr = arg_normalizer(arr, argn);
	stack_genesis(&stack, arr);
	if (stack == NULL)
		d_end();
	// sta = init_stack_a(arr);
	// stb = init_stack_b();
	// else if (stack_is_sorted(stack_a))
	// {
	// 	debug("sorted");
	// 	d_end();
	// }
	else
		push_swap(&stack);
	// d_print_stack(&stack_a);
	// d_print_stack(&stack_a);
	d_end();
}
