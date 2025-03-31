/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:42:01 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/31 12:19:31 by akjoerse         ###   ########.fr       */
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
	arr = malloc(sizeof(int) * (argn + 1));
	if (!arr || arr == NULL)
		d_end();
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
	return (arg_normalizer(arr, argn));
}

void	check_minmax(long int value, t_n **st)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		if (st || (*st) != NULL)
			d_end();
		else
			d_end();
	}
}

int	*arg_normalizer(int *arr, int siz)
{
	int	i;
	int	*brr;

	i = 0;
	brr = malloc(sizeof(int) * (siz + 1));
	if (!brr || brr == NULL)
		d_end();
	brr[i] = arr[0];
	while (++i <= siz)
	{
		brr[i] = 0;
	}
	brr = arr_transcriber(arr, brr, siz);
	free (arr);
	return (brr);
}

int	*arr_transcriber(int *arr, int *brr, int siz)
{
	int			pos;
	int			i;
	int			j;
	
	i = 0;
	pos = 0;
	j = INT_MIN;
	brr[0] = arr[0];
	while (siz > 0 && i++ < arr[0])
	{
		if (arr[i] > j && brr[i] == 0)
		{
			pos = i;
			j = arr[i];
		}
		if (i == arr[0] && brr[pos] == 0)
		{
			brr[pos] = siz--;
			j = INT_MIN;
			i = 0;
		}
	}
	return (brr);
}
