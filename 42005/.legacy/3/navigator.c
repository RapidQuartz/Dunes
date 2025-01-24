/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:41:09 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/20 15:13:39 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* to navigate the stack and discover useful things about it
*/

t_stack	*navigator(t_stack **st_a, t_stack **st_b, int size);
t_stack	*smolfind(t_stack *sss, int size);
void		prevfind(t_stack **sss, t_stack **smol, int size);
void		indexize(t_stack **sss, int adj, int siz);
void		backtracker(t_stack **sss, int siz);

/* specific designations:
	//1:locate stack position/locate index of smallest/next value:
		-[later used to find cost of sorting by index directly]
		-[#CHANGED to PREVIOUS VALUE cus NEXT IS KNOWN]
		-[bro chill i meant like next index]
		-[#OK then maybe suggest using same logic ok sorry]
		-[all good lets add it]
			//t_stack	indexer
			//t_stack	previndex
			//t_stack	nextindex
	//2:compare cost of processing top value:
	//3:compare cost for both stacks:
	//4:output as grid of stats/int*:
*/

t_stack	*navigator(t_stack **st_a, t_stack **st_b, int size)
{
	int		i;
	t_stack	*stack;
	t_stack	*smol;
	t_stack	*prev;
	
	i = 0;
	smol = smolfind(*st_a, size);
	prevfind(*st_a, smol, size);
	backtracker(*st_a, size);
	return (stack);
}

t_stack	*smolfind(t_stack *sss, int size)
{
	t_stack	*smol;
	
	smol = sss;
	while (smol->next != NULL)
	{
		if (smol->position == 1)
			break;
		else if (smol->position != 1)
			smol = smol->next;
	}
	return (smol);
}

void	prevfind(t_stack **sss, t_stack **smol, int size)
{
	int		i;
	t_stack	*stack;
	t_stack	*prev;
	
	stack = *sss;
	prev = *smol;
	while (stack->position < size)
	{
		i = 0;
		while (i < size && stack->position != (prev->position + 1))
		{
			i++;
			if (stack->next == NULL)
				stack = *sss;
			else
				stack = stack->next;
		}
		prev->higher = stack;
		stack->lower = prev;
		indexize(stack, i, size);
		prev = stack;
		if (stack->position == size)
			return ;
	}
	return ;
}

/* added 2025-01-20 12:39:32
gives the 'adjacency number'
*/
void		indexize(t_stack **sss, int adj, int siz)
{
	t_stack	*stack;
	
	stack = *sss;
	stack->adjacency = adj;
}
/* backtracker bug <%<:log3:>%%> */
void		backtracker(t_stack **sss, int siz)
{
	int		i;
	t_stack	*stack;
	
	i = 0;
	stack = *sss;
	while (stack->position != siz)
	{
		if (stack->next == NULL)
			stack = *sss;
		stack = stack->next;
	}
	*sss = stack;
	while (siz--)
	{
		while (stack->prev != NULL && stack->position != siz)
		{
			stack = stack->prev;
			i++;
		}
		if (stack->prev == NULL)
			stack = *sss;
		if (i < stack->adjacency && stack->lower != NULL)
			stack->adjacency = (i * - 1);
	}	
}

/* so skip backtracker?
for now? the negative values stuff isnt working cus of a previous bug of mine i cant quite catch. */