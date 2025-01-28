/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:44 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/28 15:43:34 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
////	FUNC:main()
int	main(int ac, char **av)
{
////	DEBUG:OUTPUT:
	// debug("");
	debug("main()\tfunction: just checking that the program runs.\t");
	// char *str[] = {"a.out", "1 2", "3", "4", "5", "6"};
	// char *str[] = {"a.out", "5", "6", "3", "2", "1 4"};
	char *str[] = {"a.out", "90", "91", "30", "0", "-10 70"};
	t_stack *stack_a;
	t_stack *stack_b;
////	DEBUG:VARIABLE:
	int	i;

	debug("testing");
	// return (0);
	i = 0;
	if (ac < 2)
	{
		ac = 6;
		av = str;
		//return (1);
	}
	while (i < ac)
	{
		debug(str[i]);
		i++;
	}
	i = 0;
////	DEBUG:OUTPUT:
	debug("note: entering arg checker");
	if (!arg_checker(ac, av))////	CALL:0:2:1
		return (0);
	stack_b = NULL;
	debug("note: making stack A with stack_maker()");
	stack_a = stack_maker(ac, av);//// CONSIDER: moving this to main()
	debug("note: checking for duplicates");
	duplicate_checker(&stack_a);
	debug("note: running push_swap()");
	push_swap(&stack_a, &stack_b);////	CALL:0:3:1:main()
	return (0);
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