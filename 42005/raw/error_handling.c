/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:17:11 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/26 16:10:27 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

////	ERRORCHECKING:
////	free memory
////	output `Error\n`
////	end program
////	

void	error_handling(t_stack **one, t_stack **other)
{
	if (one == NULL  || (*one) != NULL)
	{
		free_memory(one);
		one = NULL;
	}
	if (other == NULL  || (*other) != NULL)
	{
		free_memory(other);
		other = NULL;
	}
	////DEBUG:REPLACE:WITH:PUTSTR:OR:WRITE:
	// printf("Error\n");
	////DEBUG:REPLACE:WITH:WRITE:
	write (2, "Error\n", 6);
	exit (1);
}

void	free_memory(t_stack **stack)
{
	t_stack	*mem;
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		mem = (*stack)->next;
		free (*stack);
		*stack = mem;
	}
	*stack = NULL;
}