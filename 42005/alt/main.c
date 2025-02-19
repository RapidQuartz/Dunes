/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:32:50 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/18 19:58:11 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		t_size;


	if (argc < 2)
		return (1);
	stack_b = NULL;
	stack_a = stack_maker(argc, argv);
	stack_a->hed = set_head(stack_a);
	while (1)
	{
		break ;
	}
	return (0);
}

/*	[LEGACY ALT MAIN]
int	main(int count, char **arg)
{
	int	members;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp;
	
	if (count < 2)
		return (1);
	if (count > 100)
		return (2);
	stack_b = NULL;
	members = arg_inspector(count, arg);
	if (!members)
		error_handling(NULL, NULL);
	stack_a = stack_maker(count, arg, members);
	temp = stack_a;
	debug_print(temp, "STACK_A-INITIAL");
	//debug("01");
	if (!sort_checker(stack_a))
		push_swap(&stack_a, &stack_b, members);
		// //debug("lol");
	// do_sa(&stack_a);
	debug_print(stack_a, "STACK_A-RESULT");
	//debug("ending, trying to free A");
	free_memory(&stack_a);
	//debug("ending, trying to free B");
	free_memory(&stack_b);
	//debug("end of program");
	return (0);
}				
*/