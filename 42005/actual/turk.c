/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:46 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/22 20:38:21 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_moves(t_stk *s, int *a, int *b, int *c)
{
	s->steps++;
	while (get_abs(a[0]) != 0 || get_abs(b[0]) != 0)
	{
		if (a[0] < 0 && b[0] < 0)
			reverse_s(s);
		else if (a[0] > 0 && b[0] > 0)
			rotate_s(s);
		else
		{
			if (a[0] > 0 && (b[0] == 0 || b[0] < 0))
				rotate_a(s, 1);
			else if (a[0] < 0 && (b[0] == 0 || b[0] > 0))
				reverse_a(s, 1);
			if (b[0] > 0 && (a[0] == 0 || a[0] < 0))
				rotate_b(s, 1);
			else if (b[0] < 0 && (a[0] == 0 || a[0] > 0))
				reverse_b(s, 1);
		}
		c[0]--;
	}
}

void	realign_or_not(t_stk *s)
{
	int	alignment;

	alignment = 0;
	realign_b(s);
	while (unsorted(s))
	{
		s->steps++;
		ft_clear_values(s);
		if (s->a[0] != s->size)
			alignment = set_alignment(s);
		else if (s->a[0] == s->size)
			alignment = final_alignment(s);
		if (alignment < 0)
			reverse_a(s, 1);
		else if (alignment > 0)
			rotate_a(s, 1);
		else if (alignment == 0 && s->b[0] > 0)
			s = push_a(s->a, s->b, s);
	}
	return ;
}

//	find biggest in B and bring it to top
void	realign_b(t_stk *s)
{
	int	arr[2];

	find_bigs(s, arr);
	while (s->b[1] != arr[1])
	{
		if (arr[0] <= s->b_mid)
			rotate_b(s, 1);
		else if (arr[0] > s->b_mid)
			reverse_b(s, 1);
	}
}

int	final_alignment(t_stk *s)
{
	int	i;
	int	papabear;

	i = 0;
	papabear = 0;
	if (s->a[1] != 1)
	{
		while (i++ < s->a[0] && papabear == 0)
		{
			if (s->a[i] == 1)
				papabear = i;
		}
		if (papabear <= s->a_mid)
			papabear = 1;
		else if (papabear > s->a_mid)
			papabear = -1;
	}
	return (papabear);
}
