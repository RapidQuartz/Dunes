// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:30:05 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/02 14:05:27 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void		three_sort(t_stack **stack, t_stack *opt, int count, char clu)
{
	if ((clu >= 'a' && clu <= 'd') || clu == 'g')
		clue_reader_abcdg(stack, opt, count, clu);
	else if (clu == 'e' || clu == 'f' || clu == 'h' || clu == 'i')
		clue_reader_efhi(stack, opt, count, clu);
}

void		one_sort(t_stack **stack)
{
	t_stack	*target;
	t_stack	*subject;

	subject = (*stack);
	target = NULL;
	if ((*stack)->pos + 1 != (*stack)->size)
	{
		debug(REDTXT"`pos + 1` is size"GRNTXT);
		return ;
	}
	while (target == NULL)
	{
		if (subject->next->pos == (*stack)->pos + 1)
			target = subject->next;
		else
			subject = subject->next;
	}
	/* sorts a single node
	process:
		find next larger (check for `pos == size`)
		calculate moves there (cost_s for that node)
	*/
}
