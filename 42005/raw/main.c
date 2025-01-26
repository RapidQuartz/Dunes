/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:44 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/26 16:36:09 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
////	FUNC:main()
int	main(int ac, char **av)
{
////	DEBUG:OUTPUT:
	printf("debug: main()\t");
	printf("function: just checking that the program runs.\t");
	printf("\n");
	// char *str[] = {"a.out", "1 2", "3", "4", "5", "6"};
	// char *str[] = {"a.out", "5", "6", "3", "2", "1 4"};
	char *str[] = {"a.out", "90", "91", "30", "0", "-10 70"};
	t_stack *stack_a;
	t_stack *stack_b;
////	DEBUG:VARIABLE:
	int	i;

	i = 0;
	if (ac < 2)
	{
		ac = 6;
		av = str;
		//return (1);
	}
////	DEBUG:OUTPUT:
	printf("variable: argc = %d\targv = ", ac);
	while (++i < ac)
	{
////	DEBUG:OUTPUT:
		printf("%s\t", av[i]);
	}
////	DEBUG:OUTPUT:
	printf("\n");
	printf("note: entering arg checker\n");
	if (!arg_checker(ac, av))////	CALL:0:2:1
		return (0);
	stack_b = NULL;
	printf("note: making stack A with stack_maker()\n");
	stack_a = stack_maker(ac, av);//// CONSIDER: moving this to main()
	printf("note: checking for duplicates\n");
	duplicate_checker(&stack_a);
	printf("note: running push_swap()\n");
	push_swap(&stack_a, &stack_b);////	CALL:0:3:1:main()
	return (0);
}