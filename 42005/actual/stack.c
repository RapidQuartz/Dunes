/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:10:32 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/31 14:58:33 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	arr_to_sta(int *arr, t_stack **stk, int i, int siz);
// void	stack_genesis(t_stack **stack_a, t_stack **stack_b);1
// void	stack_genesis(t_stack **stack_a, t_stack **stack_b, int *array);
// void	stack_genesis(t_n **stack_a, t_n **stack_b, int *array);
// void	stack_genesis(t_n **stack_a, t_n **stack_b, int *array)
t_stack	*stack_genesis(t_stack **stack, int *array)
{
	t_stack	*stk;
	
	if (array != NULL && array[0] > 0)
	{
		stk =  malloc(sizeof(*stk));
		if (!stk || stk == NULL)
			return (NULL);
		stk->b = malloc(sizeof(int) * (array[0] + 1));
		if (!stk->b || stk->b == NULL)
			return (NULL);
		stk->b = nullify_arr(stk->b, array[0]);
		stk->a = array;
		stk->c = malloc(sizeof(int) * (array[0] + 1));
		if (!stk->c || stk->c == NULL)
			return (NULL);
		stk->c = nullify_arr(stk->c, array[0]);
		stk->d = 0;
		stk->e = 0;
		(*stack) = stk;
		return (*stack);
	}
	else
		return (NULL);
}

int	*nullify_arr(int *arr, int size)
{
	int	i;

	i = -1;
	while (i++ < size)
		arr[i] = 0;
	return (arr);
}