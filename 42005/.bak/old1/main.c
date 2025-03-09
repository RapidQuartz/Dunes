/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:32:50 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/23 18:02:00 by akjoerse         ###   ########.fr       */
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
	// argn = arg_inspector(argc, argv);
	// if (!argn)
	// 	return 1;
	stack_b = NULL;
	stack_a = NULL;
	stack_a = stack_maker(argc, argv, argn);
	if (sort_checker(stack_a))
		debug(GRNTXT"\n\n\n\n\t\t\t STACK IS SORTED!!!!!!!\n\n\n\n"DEFTXT);
	write(2, "\n", 1);
	write(2, &c, 1);
	write(2, "\n", 1);
	print_stack(stack_a, 0, argn);
	debug("\n\n\n\nBEFORE SORT\n\n\n\n");
	if (c == '0')
		// sort_stack(stack_a, stack_b);
	print_stack(stack_a, 0, argn);
	debug("\n\n\n\nAFTER SORT\n\n\n\n");
	return (0);
}

void		print_stack(t_stack *stack, int i, int argn)
{
	printf("\t\t\t\t[\t\tSTACK\t\t]\n");
	while (i < argn)
	{
		i++;
		printf("[%d]\t\tvalue = %d\t"
			"index = %d\t"
			"pos = %d\t"
			"next->value = %d\t\t"
			"prev->value = %d\n", \
			i, stack->value, \
			stack->index, \
			stack->pos, \
			stack->next->value, \
			stack->prev->value);
		stack = stack->next;
	}
}