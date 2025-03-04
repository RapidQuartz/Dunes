/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:42:23 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/04 19:20:15 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* process:
try 1 * 11 moves on primary trunk

try 6 * 11 moves on secondary trunk

try 36 * 5 finishers on tertiary trunk

*/
void		forest(t_stack **stack_a, t_stack **stack_b, t_tree **tree)
{
	//try 11 moves
		//program way to change trunk based on 11 moves
		//!! num is stack-size when stack begins
			//copy from stackA up to st[i] < '0'
		//!! num is -1 when stackA is over
			//copy from stackB up to st[i] < '0'
		//!! num is -2 when stackB is over
			//read up to st[i] < '0'
		
//default	--	number of moves
//	sa	--	change i == 1 with i == 2 `provided 0 but not -1 observed`
	//	swap_trunk{tgt = 0, src = 0}
//	sb	--	change i == 1 with i == 2 `provided -1 but not -2 observed`
	//	swap_trunk{tgt = -1, src -1}
//	ss	--	saved as separate move but calls sa/sb for trunk manipulation
//	ra	--	shift all values -1 between 0 and -1
	//	shift_trunk{cmd = -1}
//	rb	--	shift all values -1 between -1 and -2
	//	shift_trunk{cmd = -2}
//	rr	--	saved as separate move but calls ra/rb for trunk manipulation
	//	shift_trunk{cmd = -3}
//	rra	--	shift all values +1 between 0 and -1
	//	shift_trunk{cmd = 1}
//	rrb	--	shift all values +1 between -1 and -2
	//	shift_trunk{cmd = 2}
//	rrr	--	saved as separate move but calls rra/rrb for trunk manipulation
	//	shift_trunk{cmd = -3}
//	pa	--	move -1 delimiter +1 slot, shift all values +1 between 0 and -1, copy head after -1 to slot after 0
	//	push_trunk{cmd = 1}
	//	shift_trunk{cmd = 1}
	//	swap_trunk{tgt = 0, src -1}
//	pb	--	move -1 delimiter -1 slot, copy head after 0 to slot after -1, shift all values -1 between 0 and -1, 
	//	push_trunk{cmd = -1}
	//	swap_trunk{tgt = -1, src 0}
	//	shift_trunk{cmd = -1}
}


//shift values
//	cmd can be -1 or +1 /a/ -2 or +2 /b/ -3 or +3 /a + b/
void	shift_trunk(t_tree *tree, int cmd, int ind)
{
	short	size;
	short	mark;
	int	i;
	int	j;

	i = 1;
	size = measure_trunk(tree, cmd, ind);
	if (cmd < 0)
	{
		while (i < size)
		{
			if (i == 1)
				mark = tree->trunk[ind][i];
			tree->trunk[ind][i] = tree->trunk[ind][i + 1];
		}
	}
	else if (cmd > 0)
}

short	measure_trunk(t_tree *tree, int cmd, int ind)
{
	int	i;
	int	prim;
	int	seco;

	i = 1;
	seco = 0;
	while (tree->trunk[ind][i] != -1)
		i++;
	prim = i - 1;
	while (tree->trunk[ind][i] != -2)
		i++;
	seco = i - prim - 1;
	if (cmd == 1 || cmd == -1)
		return (prim);
	else if (cmd == 2 || cmd == -2)		
		return (seco);
	else if (cmd == 3 || cmd == -3)
		return (prim + seco);
}

//swap values
void	swap_trunk(t_tree *tree, int cmd, int tgt, int src)
{

	
}

//move values
void	push_trunk(t_tree *tree, int cmd, int ind)
{
	short	size;
	
	size = measure_trunk(tree, cmd, ind);

}