/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:24:54 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/22 17:17:59 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_make_null_arr(int n)
{
	int	i;
	int	*arr;

	i = -1;
	arr = NULL;
	if (n <= 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr || arr == NULL)
		return (NULL);
	while (++i < n)
		arr[i] = 0;
	return (arr);
}


int	*arg_to_arr(int *arr, int *argn, char **argv)
{
	int		i;
	int		j;
	long	num;
	int		n;

	i = 1;
	j = 0;
	arr = ft_make_null_arr(argn[0] + 1);
	if (!arr || arr == NULL)
		error_end_arr(arr);
	arr[0] = argn[0];
	while (i <= argn[0] && ++j)
	{
		n = 0;
		while (n++ < argn[j])
		{
			num = arg_to_int(argv[j], n);
			if (num < INT_MIN || num > INT_MAX)
				error_end_arr(arr);
			arr[i++] = (int)num;
		}
	}
	free (argn);
	return (arr);
}

int	*arr_normalizer(int *arr, int siz)
{
	int	i;
	int	*brr;

	i = 0;
	brr = NULL;
	brr = ft_make_null_arr(siz + 1);
	if (!brr || brr == NULL)
		error_end_arr(arr);
	if (!(arr[0] > 0))
		return (NULL);
	brr[i] = arr[0];
	brr = arr_transcriber(arr, brr, siz);
	free (arr);
	return (brr);
}