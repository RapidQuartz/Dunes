/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:27:31 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/27 13:21:47 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		push_multi(t_stack **sa, t_stack **sb, char dest, int multi)
{
	while (multi--)
	{
		if (dest == 'a')
			do_pa(sa, sb);
		if (dest == 'b')
			do_pb(sa, sb);
	}
}

void		do_pa(t_stack **sa, t_stack **sb)
{
	t_stack **ss;

	ss = (*sa)->head;
	printf(GRNTXT"\n\n\npa\n\n\n"DEFTXT);
	if (!sb || (*sb) == NULL)
	{
		sb = sa;
		(*ss)->prev->next = (*ss)->next;
		*((*ss)->head) = (*ss)->next;
		*((*sb)->head) = (*sa);
		(*sb)->next = (*sa);
		(*sb)->prev = (*sa);
	}
	else
	{
		(*sb)->prev->next = (*sa);
		(*sa)->next = (*sb)->next;
		(*sa)->prev = (*sb)->prev;
		*((*sb)->head) = (*sa);
		(*sb)->prev = (*sa);

	}
	//TODO: make/copy putstr//DEBUG ONLY
}

void		do_pb(t_stack **sa, t_stack **sb)
{
	printf("pb");
	//TODO: make/copy putstr//DEBUG ONLY
}