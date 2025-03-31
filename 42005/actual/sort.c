	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:32:08 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/31 13:53:01 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stk)
{
	int		ops[5];
	int		i;
	t_stack	*sta;
	int		*s;

	sta = (*stk);
	if (sta->a[0] == 3)
		s = sta->a;
	while (i++ < 4)
		ops[i] = 0;
	if ((s[1] < s[2]) && (s[1] < s[3]) &&  (s[2] > s[3]))//acb//rra//sa
		ops[0] = 1;
	if ((s[1] > s[2]) && (s[1] < s[3]) &&  (s[2] < s[3]))//bac//sa
		ops[1] = 1;
	if ((s[1] < s[2]) && (s[1] > s[3]) &&  (s[2] > s[3]))//bca//sa/rra
		ops[2] = 1;
	if ((s[1] > s[2]) && (s[1] > s[3]) &&  (s[2] < s[3]))//cab//ra
		ops[3] = 1;
	if ((s[1] > s[2]) && (s[1] > s[3]) &&  (s[2] > s[3]))//cba//rra
		ops[4] = 1;
	s = three_ops(s, ops);
	(*stk) = sta;
	return ;
}

int		*three_ops(int *a, int *b)
{
	int	i;

	i = 0;
	while (i++ < 2)
	{
		if ((i == 1 && (b[0] == 1 || b[4] == 1)) || (i == 2 && b[2] == 1))
			a = reverse_a(a);
		if ((i == 1 && (b[1] == 1 || b[2] == 1)) || (i == 2 && b[0] == 1))
			a = swap_a(a);
		if (i == 1 && b[3] == 1)
			a = rotate_a(a);
	}
	return (a);
}
