/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:01:43 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/02 17:44:52 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* 2025-03-01 14:01:52 */

int		ft_cost(t_stack *stack, char cost_n)
{
	t_stack	*sub;
	int		i;
	int		sum;

	if (!stack)
		return (0);
	i = 0;
	sum = 0;
	sub = stack;
	if (cost_n == 'a')
		return (ft_comcost(sub, 'a'));
	else if (cost_n == 'r')
		return (ft_comcost(sub, 'r'));
	while (cost_n == 's' && i++ < sub->size)
	{
		sum += ft_sumcost(sub, i);
		sub->cost_s = sum;
		sub = sub->next;
	}
	return (0);
}

int		ft_comcost(t_stack *stack, char cost_n)
{
	int		cost_a;
	int		cost_b;
	int		target;
	t_stack	*mem;

	mem = stack;
	target = stack->pos;
	cost_a = 0;
	cost_b = 0;
	while (stack->index != target)
	{
		stack = stack->next;
		cost_a++;
	}
	while (mem->index != target)
	{
		mem = mem->prev;
		cost_b++;
	}
	if (cost_a > cost_b && cost_n == 'r')
		cost_a = -cost_b;
	else if (cost_a > cost_b && cost_n == 'a')
		cost_a = cost_b;
	return (cost_a);
}

int		ft_sumcost(t_stack *stack, int index)
{
	int		cost_a;
	int		cost_b;
	t_stack	*mem;
	t_stack	*eme;
	
	cost_a = 0;
	cost_b = 0;
	mem = stack;
	eme = mem;
	while (eme->pos != index)
	{
		eme = eme->next;
		cost_a++;
	}
	while (mem->pos != index)
	{
		mem = mem->prev;
		cost_b++;
	}
	if (cost_a <= cost_b)
		return (cost_a);
	return (cost_b);
}
