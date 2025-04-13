/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:46 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/13 19:02:30 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_moves(t_stk *s, int *a, int *b, int *c)
{
	// usleep(20000);
	// printf("STEPS:\n%d\n", s->steps++);
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

int	*realign_stack(int *s)
{
	int	i;
	int	m;
	int	n;

	if (s[0] > 0)
	{
		i = s[0];
		m = s[i];
		s[i] = 0;
		while (i-- != 1)
		{
			n = s[i];
			s[i] = m;
			m = n;
		}
	}
	else
		s[1] = 0;
	s[0]--;
	return (s);
}

void	realign_or_not(t_stk *s)
{
	int	porridge;

	porridge = 0;
	preen(s);
	//ft_put_struct(s);
	// while (unsorted(s) || s->a[0] != s->size)
	while (unsorted(s))
	{
		// usleep(20000);
		s->steps++;
		ft_clear_values(s);
		if (s->a[0] != s->size)
			porridge = goldilox(s);
		else if (s->a[0] == s->size)
			porridge = bears_come_home(s);
		// printf("STEPS:\n%d\n", s->steps++);
		if (porridge < 0)
			reverse_a(s, 1);
		else if (porridge > 0)
			rotate_a(s, 1);
		else if (porridge == 0 && s->b[0] > 0)
			s = push_a(s->a, s->b, s);
		//ft_put_struct(s);
	}
	return ;
}

//	find biggest in B and bring it to top
void	preen(t_stk *s)
{
	int	big_guys[2];

	biggest_bois(s, big_guys);
	while (s->b[1] != big_guys[1])
	{
		if (big_guys[0] <= s->b_mid)
			rotate_b(s, 1);
		else if (big_guys[0] > s->b_mid)
			reverse_b(s, 1);
	}
}

int	bears_come_home(t_stk *s)
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
