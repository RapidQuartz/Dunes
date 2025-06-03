/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:10:32 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/04 14:28:00 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
t_stack	*stack_init_first(t_stack **stack, int size);
t_stack	*stack_init_second(t_stack **stack, int size);
t_stack	*stack_genesis(t_stack **stack, int *array)
{
	t_stack	*stk;
	
	if (array != NULL && array[0] > 0)
	{
		stk =  malloc(sizeof(*stk));
		if (!stk || stk == NULL)
			return (NULL);
		stk->s = array[0];
		stk = stack_init_first(&stk, array[0]);
		if (!stk || stk == NULL)
			return (NULL);
		stk = stack_init_second(&stk, array[0]);
		if (!stk || stk == NULL)
			return (NULL);
		(*stack) = stk;
		return (*stack);
	}
	else
		return (NULL);
}

///first part
//*g
//*o
//*a
//*b
t_stack	*stack_init_first(t_stack **stack, int size)
{
	if (!stack || stack == NULL || !(*stack) || (*stack) == NULL)
		return (NULL);
	(*stack)->g = nullify_arr((*stack)->g, size);
	if (!(*stack)->g || (*stack)->g == NULL)
		return (NULL);
	(*stack)->o = nullify_arr((*stack)->o, MAX_OPS);
	if (!(*stack)->o || (*stack)->o == NULL)
		return (NULL);
	(*stack)->a = nullify_arr((*stack)->a, size);
	if (!(*stack)->a || (*stack)->a == NULL)
		return (NULL);
	(*stack)->a[0] = size;
	(*stack)->b = nullify_arr((*stack)->b, size);
	if (!(*stack)->b || (*stack)->b == NULL)
		return (NULL);
	return (*stack);
}

///second part
//*c
//*d
//*e
//*f
t_stack	*stack_init_second(t_stack **stack, int size)
{
	if (!stack || stack == NULL || !(*stack) || (*stack) == NULL)
		return (NULL);
	(*stack)->c = nullify_arr((*stack)->c, size);
	if (!(*stack)->c || (*stack)->c == NULL)
		return (NULL);
	(*stack)->d = nullify_arr((*stack)->d, size);
	if (!(*stack)->d || (*stack)->d == NULL)
		return (NULL);
	(*stack)->e = nullify_arr((*stack)->e, size);
	if (!(*stack)->e || (*stack)->e == NULL)
		return (NULL);
	(*stack)->f = nullify_arr((*stack)->f, size);
	if (!(*stack)->f || (*stack)->f == NULL)
		return (NULL);
	return (*stack);
}

int	*nullify_arr(int *arr, int size)
{
	int	i;

	i = -1;
	arr = malloc(sizeof(int) * (size + 1));
	if (!arr || arr == NULL)
		return (NULL);
	while (i++ < size)
		arr[i] = 0;
	return (arr);
}
