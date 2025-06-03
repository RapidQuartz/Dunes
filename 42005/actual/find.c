/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:18 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/22 20:38:48 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_bigger(int *s, int n)
{
	int		i;
	int		ind;
	int		big;
	bool	found;

	i = 0;
	ind = 0;
	big = INT_MIN;
	found = false;
	if (s && s != NULL)
	{
		while (i++ < s[0])
		{
			if (s[i] > n && (found == false || \
				(found == true && big > s[i])))
			{
				big = s[i];
				found = true;
				ind = i;
			}
		}
	}
	return (ind);
}

int	find_next_smaller(int *s, int n)
{
	int		i;
	int		ind;
	int		sml;
	bool	found;

	i = 0;
	ind = 0;
	sml = INT_MAX;
	found = false;
	if (s && s != NULL)
	{
		while (i++ < s[0])
		{
			if (s[i] < n && (found == false || \
				(found == true && sml < s[i])))
			{
				sml = s[i];
				found = true;
				ind = i;
			}
		}
	}
	return (ind);
}

void	find_bigs(t_stk *s, int *arr)
{
	int	big_num;
	int	big_ind;
	int	size;
	int	i;

	i = 1;
	size = s->b[0];
	big_num = 1;
	big_ind = s->b[1];
	while (i++ < size)
	{
		if (s->b[i] > s->b[big_num])
		{
			big_num = i;
			big_ind = s->b[i];
		}
	}
	arr[0] = big_num;
	arr[1] = big_ind;
	return ;
}

int	set_alignment(t_stk *s)
{
	int	nb;
	int	ns;

	nb = find_next_bigger(s->a, s->b[1]);
	ns = find_next_smaller(s->a, s->b[1]);
	if (nb != 0 && nb != 1)
	{
		if (nb <= s->a_mid)
			return (1);
		else if (nb > s->a_mid)
			return (-1);
	}
	else if (nb == 0 && ns != 0 && ns != s->a[0])
	{
		if (ns > s->a_mid)
			return (-1);
		else if (ns <= s->a_mid)
			return (1);
	}
	return (0);
}
