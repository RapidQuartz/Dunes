// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:21:49 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/02 10:13:09 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void		sort_negativecost(t_stack **stack_a);
void		set_cost(t_stack **stack_a, t_stack **stack_b, int size);
void		sort_costcompare(t_stack **stack_a, t_stack **stack_b, int size);
void		sort_positivecost(t_stack **stack_a);
void		sort_bigbee(t_stack **stack_a);

void	push_swap(t_stack **stack_a, t_stack **stack_b, int members)
{
	if (members == 2)
		do_sa(stack_a);
	// if (members > 2 && members < 6)
	if (members > 2)
		set_cost(stack_a, stack_b, members);
}

//MISLEADING NAME
void	set_cost(t_stack **stack_a, t_stack **stack_b, int size)
{
	debug("in sort_small()");
	int		index;
	int		pos;
	int		m;
	t_stack	*tumbler;

	tumbler = (*stack_a);
	m = 0;
	//debug("02");
	while (m != size)
	{
		debug("_setcost_ in small loop");
		if (tumbler->index != tumbler->pos)
			tumbler->cost_a = (tumbler->pos - tumbler->index);
		if (tumbler->next != NULL)
			tumbler = tumbler->next;
		m++;
	}
	printf("m: %d\n", m);
	sort_costcompare(stack_a, stack_b, size);
	m = count_samecost(find_top(*stack_a));
	printf("samecost m: %d\n", m);
}

void	sort_costcompare(t_stack **stack_a, t_stack **stack_b, int size)
{
	debug("in sort_compare()");
	int		m;
	int		cost_a;
	int		cost_b;
	t_stack	*tumbler;


	tumbler = (*stack_a);
	m = 1;
	while (m != size && tumbler)
	{
		cost_a  = tumbler->cost_a;
		cost_b = tumbler->cost_b;
		if (cost_a != 0)
			sort_cost(stack_a, size);
		// else if (cost_a > 0)
		// 	sort_positivecost(stack_a);
		// else if (cost_a == 0)
		if (tumbler->next != NULL)
			tumbler = tumbler->next;
		m++;
	}
	debug("leaving sort_compare()");
}

/* cost_check() prototype:

	purpose:	check `cost` values
			(/and potentially return/ instructions for operations)
	design:	iterative/
	/recursive??
	variables:	[t_stack]stack, ledger;[int]cost_a, cost sum, cost constant?
		remember: if i pass the cost as an int, i can pass the stack->cost
	called by:	push_swap() i guess
*/
/* check difference between greatest and smallest cost */
//NOT YET BUILT
void		cost_check(t_stack **stack)
{
	debug("in cost_check()");
	t_stack	*ledger;
	int		*arr;
	int		costsum;
	int		costavg;
	int		costcount;
	/* sum of all costs, average and count of 'any cost' */
	//NB to use an int array i need to allocate memory usefully
	//eg. i need the member count.
		//	1. include as param
		//	2. count in spe
		//	3. use `*arr` elsewhere
	
	ledger = (*stack);
	costcount = 0;
	costsum = 0;
	while (ledger->next != NULL)
	{
		//debug("in loop");
		costsum += get_absolute(ledger->cost_a);
		if (ledger->cost_a != 0)
//might want an absolute counter here.[X]
			costcount++;
		ledger = ledger->next;			
	}
	//debug("");
	/* some differential?
	what i was planning to do:
	use similar "cost", eg two numbers with -1,
	to find moves that sort MORE numbers */
	/* so lets say:
	1. the cost of two elements is identical.
	2. the other elements have higher cost.
	3. one move would sort more numbers.
	4. i should use a 'matrix' to decide on outcomes.
	5. hmm. what about an int array?
	index in [0][] position in [1][] cost in [2] or sth*/
}

//NOT YET IMPLEMENTED
void		sort_bigbee(t_stack **stack_a)
{
	debug("in sort bigbee");
	t_stack	*temp;
	t_stack	*memo;
	
	temp = find_top(*stack_a);
	memo = temp;
	while (temp && temp->next)
	{
		if (temp->cost_b > 0)
		{
			while (temp->prev && temp->cost_a == temp->prev->cost_a)
			{
				//debug("welpppp");
				if (temp->cost_a == -1)
					do_ra(stack_a);
			}
		}
		if (memo->next != NULL && temp->next == NULL)
			temp = memo;
	}
}

void		sort_cost(t_stack **stack_a, int size)
{
	debug("in sort_negativecost()");
	int		i;
	int		count;
	t_stack	*temp;
	t_stack	*store;

	temp = find_top(*stack_a);
	count = count_samecost(temp);
	while (temp && temp->next)
	{
		debug("entered loop");
		i = 1;
		while ((*stack_a)->next != NULL)
		{
		debug("in subloop");
			if (temp->cost_a == (*stack_a)->next->cost_a)
				i++;
			(*stack_a) = (*stack_a)->next;
		}
		if (i > 1)
			temp->cost_b = i;
		temp = temp->next;
		if (temp->next != NULL && (*stack_a)->next == NULL)
			(*stack_a) = temp;
		debug("end of loop");
	}
	debug("leaving sort_negativecost()");
	return ;
}

//DEFUNCT
void		sort_positivecost(t_stack **stack_a)
{
	debug("in sort_positivecost()");
	int	i;
	t_stack	*temp;

	i = 0;
	temp = find_top(*stack_a);
	// temp = (*stack_a);
	while ((*stack_a))
	{
		debug("in loop");
		if (i - temp->cost_a > (*stack_a)->next->cost_a && (*stack_a)->next != NULL)
		{
			debug("1");
			i++;
		}
		if ((*stack_a)->next != NULL)
		{
			debug("2");
			(*stack_a) = (*stack_a)->next;
		}
		if ((*stack_a)->next == NULL)
		{
			debug("3");
			break ;
		}
	}
	temp->cost_b = i;
	return ;
	//(*stack_)
}