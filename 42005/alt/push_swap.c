/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:21:49 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/01 19:04:34 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	sort_small(t_stack **stack_a, t_stack **stack_b, int size);
void	sort_costcompare(t_stack **stack_a, t_stack **stack_b, int size);
void		sort_negativecost(t_stack **stack_a);
void		sort_positivecost(t_stack **stack_a);
void		sort_bigbee(t_stack **stack_a);


void	push_swap(t_stack **stack_a, t_stack **stack_b, int members)
{
	if (members == 2)
		do_sa(stack_a);
	if (members > 2 && members < 6)
		sort_small(stack_a, stack_b, members);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	int		n;
	int		m;
	t_stack	*tumbler;

	tumbler = (*stack_a);
	m = 0;
	debug("02");
	while (m != size)
	{
		i = tumbler->index;
		n = tumbler->pos;
		if (i != n)
		{
			if (n > i)
				tumbler->cost_a = (i - n);
			if (i > n)
				tumbler->cost_a = (n - i);
		}
		if (tumbler->next != NULL)
			tumbler = tumbler->next;
		m++;
	}
	sort_costcompare(stack_a, stack_b, size);
	/* if  */
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
	while (m != size)
	{
		cost_a  = tumbler->cost_a;
		cost_b = tumbler->cost_b;
		if (cost_a < 0)
			sort_negativecost(stack_a);
		else if (cost_a > 0)
			sort_positivecost(stack_a);
		if (tumbler->next != NULL)
			tumbler = tumbler->next;
		m++;
	}
	debug("leaving sort_compare()");
}
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
				debug("welpppp");
				if (temp->cost_a == -1)
					do_ra(stack_a);
			}
		}
		if (memo->next != NULL && temp->next == NULL)
			temp = memo;
	}
}
void		sort_negativecost(t_stack **stack_a)
{
	debug("in sort_negativecost()");
	int	i;
	t_stack	*temp;

	i = 0;
	temp = find_top(*stack_a);
	while (temp && temp->next)
	{
		printf("temp->index: %d\n", temp->index);
		debug("gooby pls");
		while ((*stack_a)->next != NULL)
		{
			debug("we loopin");
			if (temp->cost_a == (*stack_a)->next->cost_a)
			{
				debug("yee");
				i++;
			}
			(*stack_a) = (*stack_a)->next;
		}
		if (temp->next != NULL && (*stack_a)->next == NULL)
		{
			debug("wooooah");
			(*stack_a) = temp;
		}
		temp = temp->next;
		debug("lyk ok ig");
	}
	temp->cost_b = i;
	debug("we outtahear");
	return ;
	//(*stack_)
}

void		sort_positivecost(t_stack **stack_a)
{
	debug("in sort_positivecost()");
	int	i;
	t_stack	*temp;

	i = 0;
	temp = (*stack_a);
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