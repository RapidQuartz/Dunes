/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:36:09 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/01 18:17:50 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Return values	::	[0 - all well][1 - too few args][2 - too many args]
// order of business::	[copy atoi][copy PARTS of makestack][select mode fwd]
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
	debug("01");
	if (!sort_checker(stack_a))
		push_swap(&stack_a, &stack_b, members);
		// debug("lol");
	// do_sa(&stack_a);
	debug_print(stack_a, "STACK_A-RESULT");
	debug("ending, trying to free A");
	free_memory(&stack_a);
	debug("ending, trying to free B");
	free_memory(&stack_b);
	debug("end of program");
	return (0);
}

