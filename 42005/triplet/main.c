/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:32:50 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/26 19:28:39 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void		print_stack(t_stack *stack, int i, int argn);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		argn;
	int		i;
	char		c;

	i = 0;
	if (argc < 2 || !(argn = arg_inspector(argc, argv)))
		return (1);
	stack_b = NULL;
	stack_a = stack_maker(argc, argv, argn);
	if (sort_checker(stack_a))
		debug(GRNTXT"\n\n\n\n\t\t\t STACK IS SORTED!!!!!!!\n\n\n\n"DEFTXT);
	else
	{
		debug("\n\n\n\nBEFORE SORT\n\n\n\n");
		print_stack(stack_a, 0, argn);
		stack_assay(&stack_a, &stack_b, stack_a->size + 1);
		print_stack(stack_a, 0, argn);
		push_swap(&stack_a, &stack_b);
	}
	debug("\n\n\n\nAFTER SORT\n\n\n\n");
	stack_a = *stack_a->head;
	print_stack(stack_a, 0, argn);
	return (0);
}

void		print_stack(t_stack *stack, int i, int argn)
{
	printf("\t\t\t\t[\t\tSTACK\t\t]\n");
	while (i < argn)
	{
		i++;
		printf("\n[%d]\tvalue = %d"
			" index = %d"
			" pos = %d\t"
			" clue = %c"
			" cost_a = %d"
			" cost_b = %d\t"
			" next->value = %d"
			" prev->value = %d"
			" head = %p\n", \
			i, stack->value, \
			stack->index, \
			stack->pos, \
			stack->clue, \
			stack->cost_a, \
			stack->cost_b, \
			stack->next->value, \
			stack->prev->value, \
			stack->head);
		stack = stack->next;
	}
}