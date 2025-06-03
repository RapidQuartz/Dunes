/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:47:49 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/08 17:43:57 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_byte	*init_tbyte(t_byte *snap, t_byte *new, short acorn)
{
	int	i;
	int	s;

	i = 5;
	s = ((snap->a[2] + snap->a[3]) + (snap->b[2] + snap->b[3]));
	new->a = malloc(sizeof(char) * acorn);
	new->b = malloc(sizeof(char) * acorn);
	while (i - 4 < s)
	{
		new->a[i] = 0;
		new->b[i] = 0;
		i++;
	}
	return (new);
}

t_byte	*iter_count(t_byte *snap, t_byte *new, char op)
{
	if (snap->a[0] == 255)
	{
		new->a[0] = 0;
		new->b[0] = snap->b[0] + 1;
	}
	else if (snap->a[0] < 255)
		new->a[0] = snap->a[0] + 1;
	if (snap->a[1] == 251 && op == 'B')
		new->a[1] = 253;
	else if (snap->a[1] == 252 && op == 'A')
		new->a[1] = 253;
	else if (snap->a[1] == 253 && snap->a[3] + snap->b[3] == 1 && op == 'A')
			new->a[1] = 251;
	else if (snap->a[1] == 253 && snap->a[2] + snap->b[2] == 1 && op == 'B')
			new->a[1] = 252;
	else
		new->a[1] = snap->a[1];
	new->b[1] = op;
	return (new);
}

int		not_sorted(t_byte *tree)
{
	int		i;
	int		j;
	t_byte	*branch;
	t_byte	*stump;

	stump = NULL;
	branch = tree;
	while (i < 12)
	{
		j = 0;
		if (branch->xroad->m[i] != NULL)
		{
			branch = branch->xroad->m[i];
			print_tree(branch);
			stump = branch;
			while (j < 12)
			{
				if (stump->xroad->m[j] != NULL)
				{
					stump = stump->xroad->m[j];
					print_tree(stump);
				}
				j++;
			}
		}
		i++;
	}
	return (1);
}
