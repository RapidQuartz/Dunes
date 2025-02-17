/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inspector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:42:33 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/17 17:27:44 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_inspector(t_stack **stk)
{
	//debug("in stack_inspector()");
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
			printf("_si_: %p --- d = %d --- t->value = %d\n", t, d, t->value);
			if (d > 0)
				error_handling(stk, NULL);
		}
		p = t->next->next;
		t = t->next;
	}
	debug("_si_: leaving");
	return ;
}
