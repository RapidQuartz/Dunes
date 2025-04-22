/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:07:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/22 17:18:08 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	arg_duplicate(int	*arr)
{
	int	i;
	int	j;
	int	sub;
	int	size;

	i = 0;
	if (!(arr[0] > 0))
		return (true);
	size = arr[0];
	while (size > i++)
	{
		j = 0;
		sub = arr[i];
		while (size > j++)
		{
			if (j != i && sub == arr[j])
			{
				return (true);
			}
		}
	}
	return (false);
}

// int	*arg_count(char *arg, int *argn, int j)
// {
// 	int	in[4];

// 	in[0] = 0;//iterator
// 	in[1] = 0;//in: number
// 	in[2] = 0;//in: negative
// 	in[3] = 0;//in: the end of a 'word' (out)
// 	while (arg[in[0]] != '\0')
// 	{
// 		if (in[1] > 0 || in[2]arg[in[0]] >= 0 && arg[in[0]] <= '9')
// 			in[1]++;
// 		else if (arg[in[0]] == '-' || arg[in[0]] == '+')//
// 			in[2]++;
// 		else if (in[1] == 1 && (arg[in[0]] == ' ' || arg[in[0]] == '\0'))
// 			in[3]++;
// 		if (in[0] == 0 && in[1] == 0 && in[2] == 0
// 		!(arg[in[0]] >= 0 && arg[in[0]] <= '9'))//
// 			in = 0;
// 		else if (((in == -1 && out == 0) || in == 0) && \
// 		(arg[in[0]] >= 0 && arg[in[0]] <= '9'))//
// 			in = 1;
// 		if (in[1] == 1)//
// 			argn[j] += in[1]--;
// 		in[0]++;
// 	}
// 	argn[0] += argn[j];
// 	return (argn);
// }


bool	unsorted(t_stk *s)
{
	int	i;
	int	bigger;
	int	smaller;

	i = 0;
	if (s->b[0] > 0)
		return (true);
	while (i++ < s->a[0])
	{
		bigger = find_next_bigger(s->a, s->a[i]);
		smaller = find_next_smaller(s->a, s->a[i]);
		if ((bigger != 0 && bigger != i + 1) \
		|| (smaller != 0 && smaller != i - 1) \
		|| (i + 1 <= s->a[0] && s->a[i] > s->a[i + 1]) \
		|| (i - 1 > 0 && s->a[i] < s->a[i - 1]))
			return (true);
	}
	return (false);
}

bool	ifnull(t_stk *s)
{
	if (!s || s == NULL || s->a == NULL || s->b == NULL || \
	s->a_cost == NULL || s->sm == NULL || s->b_cost == NULL || \
	s->c_cost == NULL || s->a_tgt == NULL || s->bg == NULL || \
	s->a_mov == NULL || s->b_mov == NULL || s->b_tgt == NULL)
		return (true);
	else
		return (false);
}
