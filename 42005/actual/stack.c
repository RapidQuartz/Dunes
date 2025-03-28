/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:10:32 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/28 12:23:25 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	arr_to_sta(int *arr, t_stack **stk, int i, int siz);
// void	stack_genesis(t_stack **stack_a, t_stack **stack_b);1
// void	stack_genesis(t_stack **stack_a, t_stack **stack_b, int *array);
// void	stack_genesis(t_n **stack_a, t_n **stack_b, int *array);
// void	stack_genesis(t_n **stack_a, t_n **stack_b, int *array)
void	stack_genesis(t_stack **stack, int *array)
{
	if (array != NULL && array[0] > 0)
	{
		*stack = malloc(sizeof(*stack));
		if ((*stack) == NULL)
			return ;
		arr_to_sta(array, stack, -1, array[0]);
	}
	else
		return ;
	return ;
}

void	arr_to_sta(int *arr, t_stack **stk, int i, int siz)
{
	int	*don;
	int	*bon;

	don = malloc(sizeof(int) * siz);
	bon = malloc(sizeof(int) * siz);
	*stk = malloc(sizeof(*stk));
	if ((stk == NULL || (*stk) == NULL) || (!don || !bon))
		return ;
	while (i++ < siz)
	{
		don[i] = arr[i];
		bon[i] = 0;
	}
	(*stk)->size = arr[0];
	(*stk)->st_a = don;
	(*stk)->st_b = bon;
	(*stk)->err = 0;
	return ;
}
