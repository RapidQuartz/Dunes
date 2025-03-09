/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inspector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:42:33 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/02 10:39:11 by akjoerse         ###   ########.fr       */
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
	p = t->next;
	i = p->size + 1;
	while (i--)
	{
		while (t->value != p->value)
			p = p->next;
		if (t->value == p->value && t->pos != p->pos)
			error_handling(stk, NULL);
		else
			t = t->next;
	}
	return ;
}
