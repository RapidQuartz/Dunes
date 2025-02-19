/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:10:47 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/19 15:11:53 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		*arg_array(int argc, char **argv, int argn, int *array)
{
	int	index;
	int	argi;
	int	step;
	int	count;
	long	num;

	index = 0;
	step = 1;
	array = malloc(sizeof(int*) * argn);
	if (!array)
		return (0);
	while (step < argc)
	{
		argi = 0;
		count = arg_counter(argv[step]);
		while (argi != count)
		{
			argi++;
			num = get_number(argv[step], argi);
			check_minmax(num, NULL);
			array[index++] = num;
		}
		step++;
	}
	return (array);
}
