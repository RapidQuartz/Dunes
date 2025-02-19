/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inspector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:42:33 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/19 17:10:17 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//	verifies if the stack contains duplicates
void	stack_inspector(t_stack **stk)
{
	t_stack	*t;
	t_stack	*p;
	int	d;
	int	i;

	t = (*stk);
	p = (*stk)->next;
	d = 0;
	i = 0;
	while (p != NULL)
	{
		i = t->value;
		while (d == 0 && p != NULL)
		{
			if (p->value == i)
				d++;
			else
				p = p->next;
			if (d > 0)
				error_handling(stk, NULL);
		}
		p = t->next->next;
		t = t->next;
	}
	return ;
}
