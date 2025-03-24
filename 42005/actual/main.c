/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:38:31 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/21 14:32:07 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_n	*sta;
	t_n	*stb;
	int	*arr;
	int	i;
	int	argn;
	
	if (argc < 2)
		return (-1);
	argn = count_arg(argc, argv);
	arr = make_arr(argc, argv, argn, arr);
	arr = arg_normalizer(arr, argn);
	sta = init_stack_a(arr);
	stb = init_stack_b();
	if (stack_is_sorted(sta))
	{
		debug("sorted");
		d_end();
	}
	d_print_stack(&sta);
	push_swap(&sta, &stb);
	d_end();
}
