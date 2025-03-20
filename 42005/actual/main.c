/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:38:31 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/20 12:49:29 by akjoerse         ###   ########.fr       */
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
	d_arrayprint(arr);
	sta = make_st(arr);
	stb = new_st(sta, stb);
	push_swap(&sta, &stb);
	d_end();
}
