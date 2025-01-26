/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:24:41 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/23 16:53:35 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* just the pushing ok */
#include "push_swap.h"

// void	push(t_stack **st_from, t_stack **st_to);
// void	do_pa(t_stack **st_from, t_stack **st_to);
// void	do_pb(t_stack **st_from, t_stack **st_to);
// void	do_papa(t_stack **st_from, t_stack **st_to);
// void	do_pbpb(t_stack **st_from, t_stack **st_to);

void	push(t_stack **st_from, t_stack **st_to)
{
	t_stack	*stt_t;
	
	if (*st_from == NULL)
		return ;
	stt_t = (*st_from)->next;
	(*st_from)->next = *st_to;
	*st_from = stt_t;
}