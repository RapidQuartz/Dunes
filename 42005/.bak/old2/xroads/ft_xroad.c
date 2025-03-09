/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xroad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:28:06 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/08 17:45:47 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* procedure:
0. first snap is generated from stack
`snap = ft_gensnap(stack)`*/
/*1. ft_xroad is called
`xroad = ft_xroad(snap)`
	`xroad->m[0] = snap;`*/
/*2. legal moves are attempted
`if (ft_islegal(snap, op))`
	`xroad->m[1..11] = ft_move(snap, op)`*/
/*3. snap is analyzed
`snap->a[1] = ft_analyze(snap)`
measured as 0 - 255 for low - high disorder (comparatively)*/
/*4. eventually/sometime, branches are pruned
??when??
//go back to xroad->m[0]->-> and cut ineffective or redundant branches*/
/*5. (maybe) a hash is used to compare moves?
maybe `sum cost` or `rank in orderliness` is stored in a[4]b[4]?
*/

int		ft_islegal(t_byte *snap, char op);

// a single iteration of xroad
t_xroad	*ft_xroad(t_byte *snap, short acorn)
{
	t_xroad	*xroad;
	char		op;

	op = 'A';
	xroad = malloc(sizeof(*xroad));
	while (op <= 'K')
	{
		if (ft_islegal(snap, op))
			xroad->m[op - 64] = ft_move(snap, op, acorn);
		else
			xroad->m[op - 64] = NULL;
		op++;
	}
	return (xroad);
}

/*	legal moves and their flags
//A//pa//LEGAL if tree->a[1] == 252 || tree->a[1] == 253	{!= 251}			1
//B//pb//LEGAL if tree->a[1] == 251 || tree->a[1] == 253	{!= 252}			2
//C//sa//LEGAL if tree->a[1] == 251 || tree->a[1] == 253	{!= 252}			2
//D//sb//LEGAL if tree->a[1] == 252 || tree->a[1] == 253	{!= 251}			1
//E//ss//LEGAL if tree->a[1] == 253					{!= 252 && != 251}	3
//F//ra//LEGAL if tree->a[1] == 251 || tree->a[1] == 253	{!= 252}			2
//G//rb//LEGAL if tree->a[1] == 252 || tree->a[1] == 253	{!= 251}			1
//H//rr//LEGAL if tree->a[1] == 253					{!= 252 && != 251}	3
//I//rra//LEGAL if tree->a[1] == 251 || tree->a[1] == 253	{!= 252}			2
//J//rrb//LEGAL if tree->a[1] == 252 || tree->a[1] == 253	{!= 251}			1
//K//rrr//LEGAL if tree->a[1] == 253				{!= 252 && != 251}	3
*/
//	determines if a move is legal based on the population of the stack
//	NB::	might need provisions for size?
//		::unless i determine that in the ops,
//		::a swap on a one-large snap is irrelevant but adds moves. OK!
int		ft_islegal(t_byte *snap, char op)
{
	short	flag;

	flag = 0;

	if (snap->a[1] != 251)
		flag = 1;
	else if (snap->a[1] != 252)
		flag = 2;
	else if (snap->a[1] == 253)
		flag = 3;
	if (flag == 0)
		return (0);
	if ((op == 'A' || op == 'D' || op == 'G' || op == 'J') && flag == 1)
		return (1);
	else if ((op == 'B' || op == 'C' || op == 'F' || op == 'I') && flag == 2)
		return (1);
	else if ((op == 'E' || op == 'H' || op == 'K') && flag == 3)
		return (1);
	else
		return (0);
}
/*	operations with similar traits
/1/ pa pb /2/ sa sb ss /3/ ra rb rr /4/ rra rrb rrr //
1:	(pa: b is main/a is sub) (pb: a is main/b is sub)
	copy numbers from sub[i] to sub[i + 1] (inc. delimiter)
	copy main[j]
*/
//	dispatches functions to manipulate snap by copying contents to new snap
t_byte		*ft_move(t_byte *snap, char op, short acorn)
{
	t_byte	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new = init_tbyte(snap, new, acorn);
	//3 types // push // swap // rotate
	//3 subtypes // one / other / both
	if (op >= 'A' && op <= 'B')
		new = ft_xpush(snap, new, op);
	if (op >= 'C' && op <= 'E')
		new = ft_xswap(snap, new, op);
	if (op >= 'F' && op <= 'H')
		new = ft_xrotate(snap, new, op);
	if (op >= 'I' && op <= 'K')
		new = ft_xreverse(snap, new, op);
	return (new);
}