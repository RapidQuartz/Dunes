/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:29:35 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/17 14:47:02 by akjoerse         ###   ########.fr       */
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
	
	debug_print(*stack_a, "BEFORE SORT3");
	x = (*stack_a)->pos;
	y = (*stack_a)->next->pos;
	z = (*stack_a)->next->next->pos;
	printf("%d\t", x);
	printf("%d\t", y);
	printf("%d\t", z);
	if (x < y && x < z && y < z)//	abc
	return ;////	TODO: make sure this is graceful
	else if (x > y && x > z && y < z)//	cab
	{
		debug(BLUTXT"1"DEFTXT);
		swap_xy(stack_a);
		swap_yz(stack_a);
	}
	else if ((x > y && x > z && y > z) || (x < y && x > z && y > z))//	cba/start
	{
		debug(BLUTXT"2"DEFTXT);
		swap_yz(stack_a);
		swap_xy(stack_a);
	}
	else if (x > y && x < z && y < z)//	bac
	{
		debug(BLUTXT"3"DEFTXT);
		swap_xy(stack_a);
	}
	if ((x > y && x > z && y > z) || (x < y && x < z && y > z))//	cba/end acb
	{
		debug(BLUTXT"4"DEFTXT);
		swap_yz(stack_a);
	}
	debug_print(*stack_a, "AFTER SORT3");
}

void		swap_xy(t_stack **stack_a)
{
	do_sa(stack_a);
	debug("doing sa [1]");
}
void		swap_yz(t_stack **stack_a)
{
	t_stack	*temp;
	temp = find_top(*stack_a);
	debug(BLUTXT"doing ra"DEFTXT);
	debug_print(temp, "BEFORE RA");
	do_ra(&temp);
	debug("doing sa [2]");
	temp = find_top(*stack_a);
	debug_print(temp, "BEFORE SA");
	do_sa(&temp);
	debug(BLUTXT"doing rra"DEFTXT);
	temp = find_top(*stack_a);
	debug_print(temp, "BEFORE RRA");
	do_rra(&temp);
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