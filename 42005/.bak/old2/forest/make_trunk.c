/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_trunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:43:23 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/08 11:24:57 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


/* helper functions for ops:
move whole stack 1 increment
*/

//same as rev rotate
/*	on moving forward

the snap will receive an instruction to traverse.
following this, it will produce a new snap, replete with mallocs and whatnots.
due to this, the new snap will be a different one from the one that was sent,
eg. if snap 0 should be rotated, snap 1 will be its rotated form.
this means, while moving through the iterations,
that the first number on the zero index of *a is the iteration
and the first number on the zero index of *b is the move
in order to traverse through the tree, it might be prudent to give links
the links should be optional, meaning that if a given move was not legal,
then the pointer should be NULL, and otherwise, it should be possible to use
the move itself as a reference.
for instance, the B operation will only happen once to a given snap.
and to avoid the snap becoming sequentially iterated (next->next etc)
it makes sense to create an 11 member array of pointers
(or 12 for "sorted, no move")
*/
void		move_forward(t_byte *branch, short dir, char stack)
{
	t_byte	*snap;
	short		*memory;
	short		mem;
	short		ory;
	short		i;
	short		j;

	i = 5;
	j = snap->b[2] + 4;
	snap = branch;
	ory = snap->a[2] + snap->b[2];
	memory = malloc(sizeof(short) * ory);
	while (j > 5)
	{
		memory[i] = snap->a[j];
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