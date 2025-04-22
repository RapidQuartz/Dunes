/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:29 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/22 17:41:20 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//		take args. check them.
int	main(int argc, char **argv)
{
	int		i;
	int		*argn_map;
	int		*arr;
	t_stk	*stack;

	i = 0;
	argn_map = NULL;
	arr = NULL;
	stack = NULL;
	argn_map = ft_argn_map(argn_map, argc, argv);
	if (argn_map == NULL)
		error_end_arr(NULL);
	arr = arg_to_arr(arr, argn_map, argv);
	if ((!arr || arr == NULL) || arg_duplicate(arr))
		error_end_arr(arr);
	arr = arr_normalizer(arr, arr[0]);
	stack = arr_to_stk(arr, stack);
	if (!stack || stack == NULL)
		error_end_stk(&stack);
	push_swap(stack);
	ft_liberation(&stack);
	return (0);
}

void	push_swap(t_stk *nexus)
{
	if (nexus != NULL && nexus->a != NULL && unsorted(nexus))
	{
		if (nexus->a[0] == 2)
			nexus = swap_a(nexus);
		else if (nexus->a[0] == 3)
			sort_three(nexus);
		else if (nexus->a[0] > 3)
			exec_turk(nexus);
	}
	return ;
}

void	exec_turk(t_stk *s)
{
	s->steps = 0;
	s = push_b(s->a, s->b, s);
	s->steps++;
	if (s->size >= 5)
	{
		s->steps++;
		s = push_b(s->a, s->b, s);
	}
	while (unsorted(s) && s->a[0] > 3)
	{
		ft_clear_values(s);
		get_cost(s, s->a, s->b);
		do_moves(s, s->a_cost, s->b_cost, s->c_cost);
		s = push_b(s->a, s->b, s);
	}
	sort_three(s);
	ft_clear_values(s);
	realign_or_not(s);
	return ;
}

void	sort_three(t_stk *sta)
{
	int		*ops;
	int		*s;

	s = NULL;
	ops = ft_make_null_arr(5);
	if (sta != NULL && sta->a != NULL && sta->a[0] == 3)
		s = sta->a;
	else
		return ;
	if (s != NULL && (s[1] < s[2]) && (s[1] < s[3]) && (s[2] > s[3]))
		ops[0] = 1;
	if (s != NULL && (s[1] > s[2]) && (s[1] < s[3]) && (s[2] < s[3]))
		ops[1] = 1;
	if (s != NULL && (s[1] < s[2]) && (s[1] > s[3]) && (s[2] > s[3]))
		ops[2] = 1;
	if (s != NULL && (s[1] > s[2]) && (s[1] > s[3]) && (s[2] < s[3]))
		ops[3] = 1;
	if (s != NULL && (s[1] > s[2]) && (s[1] > s[3]) && (s[2] > s[3]))
		ops[4] = 1;
	sta = three_ops(sta, ops);
	free (ops);
	return ;
}

t_stk	*three_ops(t_stk *s, int *ops)
{
	int	i;

	i = 0;
	while (ops != NULL && i++ < 2 && s != NULL)
	{
		if ((i == 1 && ops[2] == 1) || (i == 2 && ops[4] == 1))
			reverse_a(s, 1);
		if (i == 1 && (ops[0] == 1 || ops[1] == 1 || ops[4] == 1))
			swap_a(s);
		if ((i == 1 && ops[3] == 1) || (i == 2 && ops[0] == 1))
			rotate_a(s, 1);
	}
	return (s);
}
