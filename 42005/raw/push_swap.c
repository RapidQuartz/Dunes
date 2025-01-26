/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:53 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/26 16:39:57 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_stack **st_a, t_stack **st_b)
{
	////	DEBUG:OUTPUT:
	printf("debug: push_swap()\n");

	int		size;
/*DEBUG*/
	t_stack	*stt_a;
	t_stack	*stt_b;
	t_stack	*stt_t;
	
	stt_a = *st_a;
	stt_b = *st_b;
	stt_t = *st_a;
/*DEBUG*/
	printf("note: calling get_stack_size\n");
	size = get_stack_size(*st_a);
	printf("note: calling give_stack_position\n");
	give_stack_position(*st_a, size);
/*DEBUG*/
	printf("[STACK_A-INITIAL]\n\n");
	while (st_a != NULL)
	{
		printf("value: %d\tindex: %d\tposition:%d\t"
"adjacency:%d\n\thigher:%p\tlower:%p\tprev:%p\tnext:%p\t\n\n", (*st_a)->value, \
		(*st_a)->index, (*st_a)->position, (*st_a)->adjacency, \
		(*st_a)->higher, (*st_a)->lower, (*st_a)->prev, (*st_a)->next);
		if ((*st_a)->next == NULL)
			break ;
		(*st_a) = (*st_a)->next;
	}
/*DEBUG*/
	printf("note: entering sort()\n");
	sort(&stt_a, &stt_b, size);
	(*st_a) = stt_t;
	printf("[STACK_A-RESULT]\n\n");
	while (st_a != NULL)
	{
		printf("value: %d\tindex: %d\tposition:%d\t"
"adjacency:%d\n\thigher:%p\tlower:%p\tprev:%p\tnext:%p\t\n\n", (*st_a)->value, \
		(*st_a)->index, (*st_a)->position, (*st_a)->adjacency, \
		(*st_a)->higher, (*st_a)->lower, (*st_a)->prev, (*st_a)->next);
		if ((*st_a)->next == NULL)
			break ;
		(*st_a) = (*st_a)->next;
	}
	printf("[STACK_A-random]\n[st_a->prev = %lld(as long long int)]\n", (long long int)(*st_a)->prev);

/*DEBUG*/
	// sort(st_a, st_b, size);
	free_memory(st_a);
	free_memory(st_b);
}
