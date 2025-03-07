/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:38:37 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/07 14:41:17 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		plant_tree(t_byte **tree, short acorn)
{
	char		ops;
	t_byte	*branch;

	ops = 'A';
	branch = (*tree);
	while (ops < 'K')
	{
		if (islegal(branch, ops))
		{
			branch = worldtree(branch, acorn + 12);
			init_branch(tree, branch, ops);
		}
		ops++;
	}
}

////	TODO:	consider if a certain size is necessary for certain moves
////	TODO:	consider past moves in another function, or send from this to that.
//helper to validate moves
short		islegal(t_byte *tree, char ops)
{
	short	flag;

	flag = 0;
	if (tree->a[1] == 252 || tree->a[1] == 253)
		flag = 1;
	else if (tree->a[1] == 251 || tree->a[1] == 253)
		flag = 2;
	else if (tree->a[1] == 253)
		flag = 1;
	if ((ops == 'A' || ops == 'D' || ops == 'G' || ops == 'J') && flag == 1)
		return (1);
	else if ((ops == 'B' || ops == 'C' || ops == 'F' || ops == 'I') && flag == 2)
		return (1);
	else if ((ops == 'E' || ops == 'H' || ops == 'K') && flag == 3)
		return (1);
	else
		return (0);
}

void		init_branch(t_byte **tree, t_byte *branch, char ops)
{
	t_byte	*shoot;

	shoot = (*tree);
	while (shoot->next != NULL)
	{
		branch->a[0] = shoot->a[0] + 1;
		branch->b[0] = ops;
		//move this to different ft. set ops first for all ops, then transpose
		//branch = perform_ops(branch, shoot, ops);
		while (shoot->next != NULL)
			shoot = shoot->next;
	}
}

t_byte	*perform_ops(t_byte *branch, t_byte *shoot, char ops)
{
	if (branch->b[0] = 65)
		perform_a(branch, shoot, ops);
	else if (branch->b[0] = 66)
		perform_b(branch, shoot, ops);
	else if (branch->b[0] = 67)
		perform_c(branch, shoot, ops);
	else if (branch->b[0] = 68)
		perform_d(branch, shoot, ops);
	else if (branch->b[0] = 69)
		perform_e(branch, shoot, ops);
	else if (branch->b[0] = 70)
		perform_f(branch, shoot, ops);
	else if (branch->b[0] = 71)
		perform_g(branch, shoot, ops);
	else if (branch->b[0] = 72)
		perform_h(branch, shoot, ops);
	else if (branch->b[0] = 73)
		perform_i(branch, shoot, ops);
	else if (branch->b[0] = 74)
		perform_j(branch, shoot, ops);
	else if (branch->b[0] = 75)
		perform_k(branch, shoot, ops);
	return (branch);
}
