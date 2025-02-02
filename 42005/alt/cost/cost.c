/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:20:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/02 13:18:31 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//NOT USED
int	count_samecost(t_stack *stack_a)
{
	debug("in count_samecost()");
	t_stack	*ledger;
	int		same;

	if (stack_a)
		printf("same_cost output 0: %d\tpointer: %p\n", stack_a->value, stack_a);
	ledger = stack_a;
	same = 0;
	while (ledger->next != NULL)
	{
		if (ledger->cost_b != 0)
			same++;
		ledger = ledger->next;
	}
	if (stack_a)
		printf("same_cost output 1: %d\tpointer: %p\n", stack_a->value, stack_a);
	return (same);
}

void	samecost_decider(t_stack **stack_a, int count, int same)
{
	t_stack	*ledger;
	int		num;
	
	printf(BLUTXT"in samecost_decider()\n");
	DEFTXT;
	ledger = (*stack_a);
	printf(GRNTXT"pointer for stack: %p\n"DEFTXT, ledger);
	printf(GRNTXT"\"next\" for stack: %p\n"DEFTXT, ledger->next);
	num = ledger->cost_b;
	printf(GRNTXT"pointer for stack: %p\t next: %p\n"DEFTXT, ledger, ledger->next);
	while (ledger->next != NULL)
	{
		printf(BLUTXT"LOOPINGGGGGGG\n"DEFTXT);
		if (num > 0)
		{
			do_ra(find_top(ledger));
			num--;
		}
		ledger = find_top(ledger);
	}
}