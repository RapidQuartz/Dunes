/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:17:11 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/31 14:38:53 by akjoerse         ###   ########.fr       */
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
	debug("in error handling");
	if (one == NULL  || (*one) != NULL)
	{
		debug("freeing one");
		free_memory(one);
	}
	if (other == NULL  || (*other) != NULL)
	{
		debug("freeing other");
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
	debug("in free memory");
	t_stack	*mem;
	
	if (!stack || !*stack)
		return ;
	printf("stack: %p\n", *stack);
	// printf("stack value: %d\n", (*stack)->value);
	// printf("stack->next: %p\n", (*stack)->next);
	while (*stack)
	{
		debug("in _fm_ loop");
		mem = (*stack)->next;
		printf("freeing node: %p\n", *stack);
		free(*stack);
		*stack = mem;
	}
	debug("setting to NULL");
	*stack = NULL;
}

void		debug(char *str)
{
	int	i;
	char	c;

	i = 0;
	if (!str || str[0] == '\0')
		return ;
	write (1, "\n{debug:\n", 8);
	while (str[i] != '\0')
	{
		c = str[i];
		write (1, &c, 1);
		i++;
	}
	write (1, "}\n", 2);
}

void	debug_print(t_stack *stack, char *msg)
{
	printf("\t\t[%s]\n", msg);
	while (stack != NULL)
	{
		printf("value: %d\tindex: %d\tposition:%d\t"
"bucket:%d\n\thigher:%p\tlower:%p\tprev:%p\tnext:%p\t\n\n", stack->value, \
		stack->index, stack->position, stack->bucket, \
		stack->higher, stack->lower, stack->prev, stack->next);
		if (stack->next == NULL)
			break ;
		stack = stack->next;
	}
}