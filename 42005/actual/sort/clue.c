/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clue.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:34:51 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/04 17:36:46 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		clue_find(t_stack **stack, int size)
{
	t_stack	*sub;
	t_stack	*mem;
	int		count;

	sub = *((*stack)->head);
	while (size--)
	{
		sub->cost_m = move_counter(sub, sub->clue);
		sub = sub->next;
	}
	while (++size < sub->size)
	{
		if (sub->cost_m < sub->next->cost_m)
		{
			count = sub->cost_s;
			mem = sub;
		}
		sub = sub->next;
	}
	three_sort(stack, mem, count, mem->clue);
}

void		clue_reader_abcdg(t_stack **stack, t_stack *opt, int c, char clu)
{
	int	set;
	char	mod;
	char	stk;
	
	if (clu == 'a' && opt->index)//abc/push if many more numbers to sort AND makes more sorted
		return ;
	if (clu == 'b')
		do_sa(stack);
	print_stack(*((*stack)->head), 0, (*stack)->size);
	if (clu == 'c')//acb/rotate, swap, reverse rotate
	{
		do_rotate((*stack)->head, NULL, 'a', 1);
		do_sa((*stack)->head);
		do_rotate((*stack)->head, NULL, 'a', -1);
	}
	if (clu == 'd')//bca/rotate, swap, reverse rotate, swap
	{
		do_rotate(stack, NULL, 'a', 1);
		do_sa(stack);
		do_rotate(stack, NULL, 'a', -1);
		do_sa(stack);
	}
}

void		clue_reader_efhi(t_stack **stack, t_stack *opt, int c, char clu)
{
	// while ((*stack) != opt && c)
	// 	rotate_head(stack, NULL, 'a', c--);
	if (clu == 'e')//cab/swap, rotate, swap, reverse rotate
	{
		do_sa(stack);
		do_rotate(stack, NULL, 'a', 1);
		do_sa(stack);
		do_rotate(stack, NULL, 'a', -1);
	}
	if (clu == 'f')//cab/swap, rotate, swap, reverse rotate
	{
		do_rotate(stack, NULL, 'a', 1);
		do_sa(stack);
		do_rotate(stack, NULL, 'a', -1);
		do_sa(stack);
		do_rotate(stack, NULL, 'a', 1);
		do_sa(stack);
		do_rotate(stack, NULL, 'a', -1);
	}
	if (clu == 'h')
		do_sa(stack);
	if (clu == 'i')
		one_sort(stack);
}

int		move_counter(t_stack *stack, char clu)
{
	t_stack	*fwd;
	t_stack	*bwd;
	int		count;
	
	fwd = stack;
	bwd = stack;
	count = 0;
	while (fwd != *(stack->head) && bwd != *(stack->head))
	{
		fwd = fwd->next;
		bwd = bwd->prev;
		count++;
	}
	return (stack->cost_s + count + clue_counter(stack, clu));
}

int		clue_counter(t_stack *stack, char clu)
{
	if (clu == 'b')
		return (1);
	if (clu == 'c')
		return (3);
	if (clu == 'd' || clu == 'e')
		return (4);
	if (clu == 'f')
		return (7);
	else
		return (0);
}
	////	TODO:	send 'rotation count'
	/* rotation count
	considers `count` number of moves to sort a clue.
	adds 'number of reverse/rotations to access clue' to `count`
	performs move with:
		a. fewest added moves
		b. fewest total moves
		c. fewest rotations before default `count`
	*/