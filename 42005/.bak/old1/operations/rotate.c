/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:27:34 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/23 18:03:57 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


//sa(t_stack **t);
void	sa(t_stack **t)
{
	write(1, "sa\n", 4);
	return ;
}

//sb(t_stack **t);
void	sb(t_stack **t)
{
	write(1, "sb\n", 4);
	return ;
}

//ss(t_stack **t, t_stack **s);
void	ss(t_stack **t, t_stack **s)
{
	write(1, "ss\n", 4);
	return ;
}

//ra(t_stack **t);
void	ra(t_stack **t)
{
	write(1, "ra\n", 4);
	return ;
}

//rb(t_stack **t);
void	rb(t_stack **t)
{
	write(1, "rb\n", 4);
	return ;
}

//rr(t_stack **t, t_stack **s);
void	rr(t_stack **t, t_stack **s)
{
	write(1, "rr\n", 4);
	return ;
}

//rra(t_stack **t);
void	rra(t_stack **t)
{
	write(1, "rra\n", 4);
	return ;
}

//rrb(t_stack **t);
void	rrb(t_stack **t)
{
	write(1, "rrb\n", 4);
	return ;
}

//rrr(t_stack **t, t_stack **s);
void	rrr(t_stack **t, t_stack **s)
{
	write(1, "rrr\n", 4);
	return ;
}

//pa(t_stack **t, t_stack **s);
void	pa(t_stack **t, t_stack **s)
{
	write(1, "pa\n", 4);
	return ;
}

//pb(t_stack **t, t_stack **s);
void	pb(t_stack **t, t_stack **s)
{
	/* (*t)->head = t->next;
	(*t)->prev->next = (*t)->head;
	(*s)->head = t;
	(*s)->prev->next = (*t);
	(*t)->next = (*s);
	(*s)->prev = (*t);
	 */
	write(1, "pb\n", 4);
	return ;
}

/* 
void	do_ra(t_stack **stack)
{
	write(1, "ra\n", 3);
	rotate_head(stack);
}

void	do_rra(t_stack **stack)
{
	write(1, "rra\n", 3);
	reverse_rotate_head(stack);
}
//	FIRST TO LAST
void		rotate_head(t_stack **stack)
{
	(*stack)->head = (*stack)->prev;
}
//	LAST TO FIRST
void		reverse_rotate_head(t_stack **stack)
{
	(*stack)->head = (*stack)->next;
}
 */