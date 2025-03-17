/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:35:30 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/17 19:18:43 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
int	main(void)
{
	// int	array[] = {1, 2, 3};
	// int	array[] = {3, 2, 1};
	int	array[] = {3, 3, 3};
	int	res = array_isunsorted(array, 3);
	int	i = 0;
	printf("::res::%d\n", res);
	while (i < 3)printf("::\t%d::\n", array[i++]);
	printf("\n");
	return (0);
} */
int	stack_isunsorted(t_snap *s)
{
	int j;
	int ba;
	int ab;

	
	ba = 0;
	ab = 0;
	j = 1;
	while (j++ < s->a[0])
	{
		if (s->a[j - 1] > s->a[j])
			ba++;
	}
	j = 1;
	while (j++ < s->b[0])
	{
		if (s->b[j - 1] < s->b[j])
			ab++;
	}
	if (ba > 0 || ab > 0)
		return (1);
	return (0);
}
int	array_isunsorted(int *a, int n)
{
	int	i;
	int	j;
	int	m;

	j = 0;
	while (i + 1 < n)
	{
		i = ++j;
		m = a[i];
		// printf("\n:e:%d::%d::%d\n", i, j, m);
		while (j + 1 < n)
		{
			if (m > a[j])
				return (1);
			if (m == a[j])
				i = (n * n);
			j++;
			// printf("\n:i:%d::%d::%d\n", i, j, m);
		}
		if (i == n * n)
			return(-1);
	}
	return (0);
}
