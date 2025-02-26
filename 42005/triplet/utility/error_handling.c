/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:17:11 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/26 18:31:37 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

////	ERRORCHECKING:
////	free memory
////	output `Error\n`
////	end program
////	

void	error_handling(t_stack **one, t_stack **other)
{
	//debug("in error handling");
	if (one == NULL  || (*one) != NULL)
	{
		//debug("freeing one");
		free_memory(one);
	}
	if (other == NULL  || (*other) != NULL)
	{
		//debug("freeing other");
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
	//debug("in free memory");
	t_stack	*mem;
	
	if (!stack || !*stack)
		return ;
	printf("stack: %p\n", *stack);
	// printf("stack value: %d\n", (*stack)->value);
	// printf("stack->next: %p\n", (*stack)->next);
	while (*stack)
	{
		//debug("in _fm_ loop");
		mem = (*stack)->next;
		printf("freeing node: %p\n", *stack);
		free(*stack);
		*stack = mem;
	}
	//debug("setting to NULL");
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
void	check_minmax(long int value, t_stack **stack)
{
	//debug("in check_minmax()");
	if (value > INT_MAX || value < INT_MIN)
	{
		if (stack || (*stack) != NULL)
			error_handling(stack, NULL);
		else
			error_handling(NULL, NULL);
	}
}

void	debug_print(t_stack *stack, char *msg)
{
	int	i = 0;
	
	printf("\t\t[INSIDE DEBUG PRINT]\n");
	printf("\t\t[%s]\n", msg);
	while (1)
	{
		printf("value: %d\tindex: %d\tposition:%d\t"
"cost_a:%d\tcost_b:%d\n\tprev:%p\tnext:%p\t\n\n", stack->value, \
		stack->index, stack->pos, \
		stack->cost_a, stack->cost_b, stack->prev, stack->next);
		if (stack->next == *stack->head)
			break ;
		stack = stack->next;
		i++;
	}
	printf("\t\t[LEAVING DEBUG PRINT]\n");
}
/* higher:%p\tlower:%p\t */
/* stack->higher, stack->lower ,*/
//printf("");
//
void	debug_cost_print(int *num, int size)
{
	int	i;
	int	j;

	i = 0;
	printf(REDTXT"\n\n\nCOST NUMS\n"DEFTXT);
	while (i < size)
	{
		printf("\n ====");
		j = 0;
		printf(GRNTXT"VALUE OF COST AT\t"DEFTXT);
		printf(GRNTXT"\t\tnum[%d]\t ="
			"\t %d"DEFTXT, i, num[i]);
		printf(BLUTXT"\n ==== \n"DEFTXT);
		i++;
	}
	DEFTXT;
}