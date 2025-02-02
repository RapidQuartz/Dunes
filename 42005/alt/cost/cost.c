/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:20:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/02 12:13:29 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_samecost(t_stack *stack_a)
{
	debug("in count_samecost()");
	t_stack	*ledger;
	int		same;

	ledger = stack_a;
	while (ledger->next != NULL)
	{
		while (stack_a->next != NULL)
		{
			stack_a = stack_a->next;
			same = 0;
			if (ledger->cost_a == stack_a->cost_a)
				same++;
		}
		if (stack_a->next == NULL)
			stack_a = ledger->next;
		ledger = ledger->next;
		printf("same cost as: %d\n", same);
	}
	return (same);
}

int	samecost_decider(t_stack *stack_a, int count, int same);