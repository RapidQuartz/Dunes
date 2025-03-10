/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climb_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:42:53 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/10 18:08:40 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_snap	*penalizer(t_snap *snap, int delta);

void		climb_tree(t_ree *tree)
{
	short		i;
	short		j;
	int		sharp;
	t_snap	*snap;

	i = 0;
}

t_snap	*penalizer(t_snap *snap, int delta)
{
	short		i;
	short		j;
	t_ree		*tree;
	int		sharp;

	i = 0;
	tree = snap->prev;
	sharp = snap->delta;
	while (i < 3)
	{
		j = 1;
		while (j < 12)
		{
			if (tree->moves[j] != NULL)
				;
			
			j++;
		}
		i++;
	}
	snap->penalty = snap->delta - delta;
	return (snap);
}

