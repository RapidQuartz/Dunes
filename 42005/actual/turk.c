/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:46 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/21 15:40:11 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_moves(t_stk *s)
{
	s->steps = 0;
	while (s->steps < 2)
	{
		if (s->flag != 0)
			do_flag(s);
		s = push_b(s->a, s->b, s);
		s->steps++;
		if (s->size == 4)
			break ;
	}
}

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
	realign_biggest_b(s);
	while (unsorted(s))
	{
		do_flag(s);
		s->steps++;
		ft_clear_values(s);
		if (s->a[0] != s->size)
			alignment = pushback_alignment(s);
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
void	realign_biggest_b(t_stk *s)
{
	int	arr[2];

	biggest_element(s, arr);
	while (s->b[1] != arr[1])
	{
		do_flag(s);
		if (arr[0] <= s->b_mid)
			rotate_b(s, 1);
		else if (arr[0] > s->b_mid)
			reverse_b(s, 1);
	}
}

int	final_alignment(t_stk *s)
{
	int	i;
	int	alignment;

	i = 0;
	alignment = 0;
	if (s->a[1] != 1)
	{
		while (i++ < s->a[0] && alignment == 0)
		{
			if (s->a[i] == 1)
				alignment = i;
		}
		if (alignment <= s->a_mid)
			alignment = 1;
		else if (alignment > s->a_mid)
			alignment = -1;
	}
	return (alignment);
}
