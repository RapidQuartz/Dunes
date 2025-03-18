/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:42:01 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/18 17:12:38 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_arr(int argc, char **argv, int argn, int *arr)
{
	short	index;
	short	iter;
	short	argi;
	short	count;
	long	num;

	index = 1;
	iter = 1;
	arr[0] = argn;
	while (iter < argc)
	{
		argi = 0;
		count = arg_counter(argv[iter]);
		while (argi++ != count)
		{
			num = get_number(argv[iter], argi);
			check_minmax(num, NULL);
			arr[index++] = num;
		}
		iter++;
	}
	num = normalizer(arr, argn);
	return (arr);
}

void	check_minmax(long int value, t_n **st)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		if (st || (*st) != NULL)
			error_handling(st, NULL);
		else
			error_handling(NULL, NULL);
	}
}

int	*normalizer(int *arr)
{
	short			pos;
	int			i;
	int			j;
	int			siz;
	
	i = 0;
	j = INT_MIN;
	while (i++ < arr[0])
	{
		if (arr[i] > j)
		{
			pos = i;
			j = arr[i];
		}
		if (i == arr[0])
		{
			new->a[pos] = new->b[0]--;
			j = INT_MIN;
			i = 0;
		}
	}
	return (new);
}