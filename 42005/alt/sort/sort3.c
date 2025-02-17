/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:29:35 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/17 11:11:39 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

////	TODO:	call this function if argn == 3
////	this happens in:
//	void	push_swap(t_stack **stack_a, t_stack **stack_b, int members)
//	if "members == 3"
//	proto:
//	sort_three(stack_a, stack_b, members);
//	sort_three(t_stack **stack_a, **t_stack stack_b, int members);
void		sort_three(t_stack **stack_a, t_stack **stack_b, int members);
void		swap_xy(t_stack **stack_a);
void		swap_yz(t_stack **stack_a);

void		sort_three(t_stack **stack_a, t_stack **stack_b, int members)
{
	int	x;
	int	y;
	int	z;

	x = (*stack_a)->pos;
	y = (*stack_a)->next->pos;
	z = (*stack_a)->next->next->pos;
	if (x < y && x < z && y < z)//	abc
		return ;////	TODO: make sure this is graceful
	else if (x > y && x > z && y < z)//	cab
	{
		swap_xy(stack_a);
		swap_yz(stack_a);
	}
	else if ((x > y && x > z && y > z) || (x < y && x > z && y > z))//	cba/start
	{
		swap_yz(stack_a);
		swap_xy(stack_a);
	}
	if ((x > y && x > z && y > z) || (x < y && x < z && y > z))//	cba/end acb
		swap_yz(stack_a);
	if (x > y && x < z && y < z)//	bac
		swap_xy(stack_a);
}

void		swap_xy(t_stack **stack_a)
{
	do_sa(stack_a);
	debug("doing sa [1]");
}
void		swap_yz(t_stack **stack_a)
{
	debug("doing ra");
	do_ra(stack_a);
	debug("doing sa [2]");
	do_sa(stack_a);
	debug("doing rra");
	do_rra(stack_a);
}
/*
-	if argn is 3
	->	if n0 > n1 && n0 > n2
	->	if n0 > n1 && n0 < n2
	->	if n0 < n1 && n0 > n2
	->	if n0 < n1 && n0 > n2

		generalized (just using `n` to represent relative index)
				definition
					x = n + 0
					y = n + 1
					z = n + 2
					(should have done xyz)
		abc		if x < y && x < z && y < z
	end	0
		acb		if x < y && x < z && y > z
		swap y and z
			rotate
			swap
			reverse rotate
	end	3
		cab		if x > y && x > z && y < z
		swap x and y
			swap
		swap y and z
			rotate
			swap
			reverse rotate
	end	4
		cba		if x > y && x > z && y > z
		swap y and z
			rotate
			swap
			reverse rotate
		swap x and y
			swap
		swap y and z
			rotate
			swap
			reverse rotate
	end	7
		bca		if x < y && x > z && y > z
		swap y and z
			rotate
			swap
			reverse rotate
		swap x and y
			swap
	end	4
		bac		if x > y && x < z && y < z
		swap x and y
			swap
	end	1
*/