/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:27:05 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/04 15:47:21 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	turk process::
{turk::
push 2
{loop::
check sort

{unsorted::stay loop
	get cost
	select target
	align or not
	store moves
	do moves
::unsorted}::stay loop}

{sorted::break loop
	realign or not
	push back
	return
::sorted}::break loop}
return
::turk}

*/
void	exec_turk(t_stack **stk)
{
	int 		*a;
	int 		*b;
	t_stack		*s;

	s = (*stk);
	a = s->a;
	b = s->b;
	//	push 2
	s = push_b(a, b, s);
	s = push_b(a, b, s);
	d_print_stack(s);
	while (unsorted(s));
	{
		get_cost(s);
		select_target(s);
		align_or_not(s);
		store_moves(s);
		do_moves(s);
	}
	realign_or_not(s);
	push_back(s);
	return ;
}
/*	check rotation
if (a[1] > b[1])
	is a[1] bigger than all of b?
		YES - cost to rotate b so a[1] is 'below' highest
			find_highest_index
		NO	- cost to rotate b so a[1] is 'below' higher and 'above' smaller
			find_higher_index
			find_smaller_index
if (a[1] < b[1])
	is a[1] smaller than all of b?
		YES	- cost to rotate b so a[1] is 'above' smallest
			find_smallest_index
		NO	- cost to rotate b so a[1] is 'above' smaller and 'below' higher
			find_smaller_index
			find_higher_index
*/
/*		align
*/
/*		push next
*/
//	last 3
/*		sort 3
*/
/*	push back
*/
/*	output instructions
*/
/* void	check_rotation(t_stack **stk)
{
	int		i;
	int		h;
	int		*a;
	int		*b;
	t_stack	*s;

	i = 0;
	s = (*stk);
	a = s->a;
	b = s->b;
	if (a[1] > b[1])
	{
		h = 1;
		while (i++ < b[0])
		{
			if (b[i] > b[h])
				h = i;
		}
		s->d = h;
		h = 1;
		i = 0;
		while (i++ < a[0])
		{
			if (a[i] > a[h])
		}
	}
	else if (s->a[1] < s->b[1])
	(*stk) = s;
} */
