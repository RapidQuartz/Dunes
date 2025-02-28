/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:30:05 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/27 15:08:37 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		three_sort(t_stack **stack_a, t_stack **stack_b)
{
	char	clu;

	clu = (*stack_a)->next->clue;
	if (clu >= 'a' && clu <= 'f')
		debug("state");
}

void		clue_reader(t_stack **stack_a, t_stack **stack_b, char clu)
{
	int	set;
	char	mod;
	char	stk;
	
	if (clu == 'a')//abc/push if many more numbers to sort AND makes more sorted
		push_multi(stack_a, stack_b, 'b', 3);
	if (clu == 'b')//acb/swap y and z, rotate, swap, reverse rotate
	{
		do_sa(stack_a);
		do_rotate(stack_a, stack_b, 'a', 1);
		do_sa(stack_a);
		do_rotate(stack_a, stack_b, 'a', -1);
		return ;
	}
	if (clu == 'c')
		do_sa(stack_a);
	;
}
/* c//bac		if x > y && x < z && y < z
		swap x and y
			swap
	end	1 */
/* b//acb		if x < y && x < z && y > z
		swap y and z
			rotate
			swap
			reverse rotate
	end	3 */


/*
bca		if x < y && x > z && y > z
		swap y and z
			rotate
			swap
			reverse rotate
		swap x and y
			swap
*/
/* misc copypasta

t_stack
(*stack_a)
(*stack_b)
->
next
prev
head
high
low
clue

if ()

while ()
*/