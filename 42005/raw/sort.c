/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:08:34 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/26 16:59:19 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
////	FUNC:
int		is_sorted(t_stack *stack);
void		sort(t_stack **st_a, t_stack **st_b, int size);

//-----------------------------------------------------------------------------
void		sort(t_stack **st_a, t_stack **st_b, int size)
{
	////	DEBUG:OUTPUT:
	printf("debug: in sort()\n");
	t_stack	*stack;
//	:0:	check sort vs size (small algo special)
//	:1:	sort	(ask for help for godssakes)
	stack = (*st_a);
	printf("note: if sorted, will stop here\n");
	if (is_sorted(*st_a))
		return ;
	printf("note: trying to add 'adjacency'\n");
	stack = adjacency(stack, size);
	printf("note: trying to run 'navigator'\n");
	stack = navigator(st_a, st_b, size);
}
////	HELPER:
//is_sorted
int		is_sorted(t_stack *stack)
{
	t_stack	*check;
	
	while (stack)
	{
		check = stack;
		stack = stack->next;
		if (stack && stack->value < check->value)
			return (0);
	}
	return (1);
}

t_stack	*adjacency(t_stack *sss, int size)
{
	t_stack	*tmp;
	t_stack	*nxp;
	t_stack	*prp;

	tmp = sss;
	nxp = NULL;
	prp = NULL;
	while (size--)
	{
		while (sss && sss->next && (nxp == NULL && prp == NULL))
		{
			if (nxp == NULL)
				nxp = getnxtptr(sss, size);
			if (prp == NULL)
				prp = getnxtptr(sss, size - 1);
			if (sss->next == NULL)
				sss = tmp;
			else
				sss = sss->next;
		}
		sss->lower = prp;
		if (nxp != prp)
			sss->higher = nxp;
	}
	return(0);
}

t_stack	*getnxtptr(t_stack *ptr, int size)
{
	t_stack	*stack;
	
	stack = ptr;
	while (ptr->next != NULL)
	{
		if (size == ptr->position)
			break ;
		if (ptr->next == NULL)
			ptr = stack;
		else
			ptr = ptr->next;
	}
	return (ptr);
}