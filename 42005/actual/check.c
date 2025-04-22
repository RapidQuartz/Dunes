/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:07:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/22 18:01:24 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	illegal(char *arg, int i)
{
	while (arg[i] != '\0')
	{
		if (!(arg[i] >= '0' && arg[i] <= '9') && \
		(!(arg[i] == ' ' || arg[i] == '+' || arg[i] == '-') || \
		(i > 0 && (arg[i - 1] == '-' || arg[i - 1] == '\0'))))
			return (true);
		i++;
	}
	return (false);
}

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

int	*arg_count(char *arg, int *argn, int j)
{
	int	i;
	int	in;

	i = 0;
	in = 0;
	if (illegal(arg, i))
		return (NULL);
	while (arg[i] != '\0')
	{
		if (in == 0 && (arg[i] == '+' || arg[i] == '-'))
			in = -1;
		else if (in <= 0 && arg[i] >= '0' && arg[i] <= '9')
		{
			in = 1;
			argn[j]++;
		}
		else if (in == 1 && (arg[i] == ' ' || arg[i] == '\0'))
			in = 0;
		i++;
	}
	argn[0] += argn[j];
	return (argn);
}

/* 
int	*arg_count(char *arg, int *argn, int j)
{
	int	i;
	int	in;

	i = 0;
	in = 0;
	while (arg[i] != '\0')
	{
		if (in == 0 && (arg[i] == '+' || arg[i] == '-'))
			in = -1;
		else if (in <= 0 && arg[i] >= '0' && arg[i] <= '9')
		{
			in = 1;
			argn[j]++;
		}
		else if (in == -1 && !(arg[i] >= '0' && arg[i] <= '9'))
			return (NULL);
		else if (in == 1 && (arg[i] == ' ' || arg[i] == '\0'))
			in = 0;
		i++;
	}
	argn[0] += argn[j];
	return (argn);
}
 */
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
