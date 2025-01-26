/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:38 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/23 17:05:03 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void		do_push(t_stack **stack, t_stack **dest);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_swap(t_stack **stack);
void		do_rotate(t_stack **stack);
void		do_ra(t_stack **stack);
void		do_rb(t_stack **stack);
////////	DEBUG: using printf instead of putstr
////	printf("sa");
// void		dd(void *(*f)(t_stack **, t_stack **), t_stack **fst, t_stack **scd);
void		dd(void (*f)(t_stack **, t_stack **), t_stack **fst, t_stack **scd);
void		do_double(void (*f)(t_stack **), t_stack **fst);
////
////	TODO:	move bigger funcs out?
// void		dd(void *(*f)(t_stack **, t_stack **), t_stack **fst, t_stack **scd)
void		dd(void (*f)(t_stack **, t_stack **), t_stack **fst, t_stack **scd)
{
	if ((!fst || !(*fst)) || (!scd || !(*scd)))
		return ;
	if (fst != NULL && scd != NULL)
	{
		f(fst, scd);
		f(fst, scd);
	}
}
void		do_double(void (*f)(t_stack **), t_stack **fst)
{
	if (!fst || !(*fst))
		return ;
	if (fst != NULL)
	{
		f(fst);
		f(fst);
	}
}

////
void		do_pa(t_stack **stack_a, t_stack **stack_b)
{
	printf("pa");
	push(stack_b, stack_a);
	//TODO: make/copy putstr//DEBUG ONLY
}

void		do_pb(t_stack **stack_a, t_stack **stack_b)
{
	printf("pb");
	push(stack_a, stack_b);
	//TODO: make/copy putstr//DEBUG ONLY
}

////	TODO:	consider adding some magic spice (find adjacency)
void		do_swap(t_stack **stack)
{
	t_stack	*swap;
	t_stack	*paws;
	
	swap = *stack;//		1
	paws = swap->next;//		p = 1>2
	paws->index = swap->index;
	swap->index = paws->index;
	swap->next = paws->next;//		1>2 + 2(>3) = 1>3
	swap->prev = paws;
	paws->prev = NULL;//		3.1 = 3.0
	paws->next = swap;	
}

void		do_sa(t_stack **stack)
{
	printf("sa");
	do_swap(stack);
}
void		do_sb(t_stack **stack)
{
	printf("sb");
	do_swap(stack);
}

void		do_rotate(t_stack **stack)
{
	printf("");
	rotate(&(*stack));
	
}
void		do_ra(t_stack **stack)
{
	printf("ra");
	rotate(&(*stack));
}

void		do_rb(t_stack **stack)
{
	printf("rb");
	rotate(&(*stack));
	
}
void		do_rra(t_stack **stack)
{
	printf("rrb");
	reverse_rotate(&(*stack));
	
}
void		do_rrb(t_stack **stack)
{
	printf("rrb");
	reverse_rotate(&(*stack));
}

