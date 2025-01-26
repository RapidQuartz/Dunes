/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:49 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/23 16:52:36 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void swap(t_stack *stack);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);
t_stack	*get_penultimate(t_stack *stack);

/* execute_ functions call the function and print string with operation [putstr("op\n")]
void	execute_sa(t_stack **stack_a);
void	execute_sb(t_stack **stack_b);
void	execute_ss(t_stack **stack_a, t_stack **stack_b);
void	execute_ra(t_stack **stack_a);
void	execute_rb(t_stack **stack_b);
void	execute_rr(t_stack **stack_a, t_stack **stack_b);
void	execute_rra(t_stack **stack_a);
void	execute_rrb(t_stack **stack_b);
void	execute_rrr(t_stack **stack_a, t_stack **stack_b);
*/

void swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
	temp = stack->position;
	stack->position = stack->next->position;
	stack->next->position = temp;
}

void rotate(t_stack **stack)
{
	t_stack	*temporary_stack;
	t_stack	*bottom;

	temporary_stack = *stack;
	*stack = (*stack)->next;
	bottom = find_stack_bottom(*stack);
	temporary_stack->next = NULL;
	bottom->next = temporary_stack;
}


void reverse_rotate(t_stack **stack)
{
	t_stack	*temporary_stack;
	t_stack	*penultimate;
	t_stack	*bottom;

	temporary_stack = *stack;
	bottom = find_stack_bottom(*stack);
	*stack = bottom;
	(*stack)->next = temporary_stack;
	penultimate = get_penultimate(*stack);
	penultimate->next = NULL;
}

t_stack	*get_penultimate(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}