/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:37:32 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/24 14:25:11 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_n	*init_stack_a(int *arr)
{
	int	i;
	int	size;
	t_n	*stack_a;
	t_n	*prev;
	t_n	**head;

	i = 0;
	size = arr[0];
	prev = NULL;
	head = NULL;
	while (++i <= size)
	{
		stack_a = new_node(stack_a, prev);
		if (i == 1)
			head = head_node(stack_a, head);
		stack_a->h = head;
		stack_a->v = arr[i];
		if (i != size)
			prev = stack_a;
	}
	stack_a->n = (*head);
	(*head)->p = stack_a;
	info_node_a(head, arr[0]);
	return ((*head));
}

t_n	*init_stack_b(void)
{
	t_n	*stack_b;

	stack_b = malloc(sizeof(t_n));
	if (!stack_b)
		d_end();
	stack_b->v = 0;
	stack_b->h = NULL;
	stack_b->c = NULL;
	stack_b->i = stack_b;
	stack_b->p = NULL;
	stack_b->n = NULL;
	return (stack_b);
}


t_n	**head_node(t_n *new, t_n **head)
{
	if (!head || head == NULL)
	{
		head = malloc(sizeof(t_n *));
		if (!head)
			d_end();
	}
	*head = new;
	return (head);
}
/* 	curr->n = (*curr->h);
	head->p = curr; */

t_n	*new_node(t_n *new, t_n *prev)
{
	new = malloc(sizeof(*new));
	if (!new || new == NULL)
		d_end();
	if (prev == NULL)
		new->p = NULL;
	else
	{
		new->p = prev;
		prev->n = new;
	}
	new->c = NULL;
	return (new);
}

void	info_node_a(t_n **head, int size)
{
	t_n	*info;
	t_n	*oper;

	info = malloc(sizeof(*info));
	if (!info || info == NULL)
		d_end();
	info->i = info;
	info->v = size;
	if (head != NULL && size > 0)
	{
		oper = (*head);
		info->h = head;
		info->p = (*head)->p;
		info->n = (*head);
		while (oper->n != (*head))
		{
			oper->i = info;
			oper = oper->n;
		}
		oper->i = info;
	}
}

t_n	*info_node_b(void);

