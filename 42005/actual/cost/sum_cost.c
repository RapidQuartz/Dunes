/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:01:43 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/01 15:30:28 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* 2025-03-01 14:01:52 */

//// ft_cost
int		ft_cost(t_stack *stack, char cost_n)
{
	int		sum_cost;
	int		rel_cost;
	int		abs_cost;
	t_stack	*sub;
	t_stack	*bus;
	
	sub = stack;
	if (sub->low != NULL)
		sum_cost = sub->low->cost_s;
	if (sub->high != NULL)
	{
		abs_cost = ft_comcost(sub, 'a');
		rel_cost = ft_comcost(sub, 'r');
		sum_cost += abs_cost;
		if (cost_n == 'a')
			return (abs_cost);
		else if (cost_n == 'a')
			return (rel_cost);
		else if (cost_n == 's')
			return (sum_cost);
	}
	return (0);
}

//// ft_comcost
int		ft_comcost(t_stack *stack, char cost_n)
{
	int		cost_a;
	int		cost_b;
	t_stack	*sub;
	t_stack	*bus;
	
	sub = stack;
	bus = sub->high;
	cost_a = 0;
	cost_b = 0;
	while (sub->next != bus && cost_a++)
		sub = sub->next;
	while (bus->prev != sub && cost_b++)
		bus = bus->prev;
	if (cost_a > cost_b && cost_n == 'r')
		cost_a = -cost_b;
	else if (cost_a > cost_b && cost_n == 'a')
		cost_a = cost_b;
	return (cost_a);
}
