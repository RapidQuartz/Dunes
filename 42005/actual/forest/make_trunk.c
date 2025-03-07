/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_trunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:43:23 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/07 20:29:18 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


/* helper functions for ops:
move whole stack 1 increment
*/

//same as rev rotate
void		move_forward(t_byte *branch, short dir, char stack)
{
	t_byte	*snap;
	short		*memory;
	// short		mem;
	short		ory;
	short		i;
	short		j;

	i = 0;
	j = snap->b[2] + 4;
	snap = branch;
	ory = snap->a[2] + snap->b[2];
	memory = malloc(sizeof(short) * ory);
	while (j > 5)
	{
		memory[i] = snap
		// mem = snap->b[j];
		// snap->b[j + 1] = mem;
	}
	j = snap->a[2] + 4;
	while (i < j)
	{
		mem = snap->a[i];
		if (i == 5)
			snap->a[i] = ory;
		i++;
	}
	while (j > 5)
	{
		mem = snap->b[j];
		snap->a[i] = mem;
		mem = snap->a[i + 1];
		snap->a[i + 1] = ory;
		snap->b[j] = snap->b[j - 1];
	}
	while (snap->b[j] != 0)
		j++;
	
}