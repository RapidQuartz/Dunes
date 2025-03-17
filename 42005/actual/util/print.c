/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:22:11 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/17 13:22:04 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void		print_tree(t_ree *root)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < 11)
	{
		if (root->order != NULL && i == 1)
			print_branch(root->order);
		if (root->moves[i] != NULL)
			print_branch(root->moves[i]);
	}
}

void		print_branch(t_snap *snap)
{
	int	j;
	int	i;
	char	*opname;
	t_snap	*orig;
	
	i = 0;
	if (snap != NULL && snap->tree != NULL && snap->up != NULL)
	{
		printf("iteration: %d\t delta: %d\t probation: %d\n" \
				"operation: %s\t previous operation: %s\n", \
			snap->tree->iteration, snap->delta, snap->tree->probation[snap->op],\
				get_opname(snap->op), get_opname(snap->up->op));
		j = 1;
		while (j <= snap->size && (j <= snap->a[0] || j <= snap->b[0]))
		{
			if (j <= snap->a[0])
				printf("a:\t%d=|", snap->a[j]);
			else
				printf("a:\t =|");
			if (j <= snap->b[0])
				printf("|=%d\t:b\n", snap->b[j]);
			else
				printf("|= \t:b\n");
			j++;
		}

	}
}

char *get_opname(t_ops op)
{
	if (op == NONE)
		return ("\0\0\0");
	if (op == PA)
		return ("pa\0");
	if (op == PB)
		return ("pb\0");
	if (op == SA)
		return ("sa\0");
	if (op == SB)
		return ("sb\0");
	if (op == SS)
		return ("ss\0");
	if (op == RA)
		return ("ra\0");
	if (op == RB)
		return ("rb\0");
	if (op == RR)
		return ("rr\0");
	if (op == RRA)
		return ("rra");
	if (op == RRB)
		return ("rrb");
	if (op == RRR)
		return ("rrr");
	return ("\0");
}