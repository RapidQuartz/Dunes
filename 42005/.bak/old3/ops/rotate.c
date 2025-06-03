/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:57:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/13 13:28:20 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_snap	*do_rotate(t_snap *new, t_ree *tree, t_ops op)
{
	short		mem[6];

	//ra//rr
	new = transcribe_snap(tree->order, new);
	if (op == RA || op == RR)
	{
		mem[0] = new->a[0];
		mem[1] = new->a[1];
		mem[2] = new->a[mem[0]];
	}
	//rb//rr
	if (op == RB || op == RR)
	{
		mem[3] = new->b[0];
		mem[4] = new->b[1];
		mem[5] = new->b[mem[3]];
	}
	new = ft_rotate(new, mem, op);
	return (new);
}

//TOP to BOT
t_snap	*ft_rotate(t_snap *new, short *mem, t_ops op)
{
	if (op == RA || op == RR)
	{
		new->a[mem[0]] = mem[1];
		while (mem[0]-- > 1)
		{
			mem[1] = new->a[mem[0]];
			new->a[mem[0]] = mem[2];
			mem[2] = mem[1];
		}
	}	
	if (op == RB || op == RR)
	{
		new->b[mem[3]] = mem[4];
		while (mem[3]-- > 1)
		{
			mem[4] = new->b[mem[3]];
			new->b[mem[3]] = mem[5];
			mem[5] = mem[4];
		}
	}
	return (new);
}

t_snap	*do_reverse(t_snap *new, t_ree *tree, t_ops op)
{
	short		mem[6];

	//rra//rrr
	new = transcribe_snap(tree->order, new);
	if (op == RRA || op == RRR)
	{
		mem[0] = new->a[0];
		mem[1] = new->a[1];
		mem[2] = new->a[mem[0]];
	}
	//rrb//rrr
	if (op == RRB || op == RRR)
	{
		mem[3] = new->b[0];
		mem[4] = new->b[1];
		mem[5] = new->b[mem[3]];
	}
	new = ft_reverse(new, mem, op);
	return (new);
}


//BOT to TOP
t_snap	*ft_reverse(t_snap *new, short *mem, t_ops op)
{
	int	i;
	if (op == RA || op == RR)
	{
		i = 0;
		new->a[1] = mem[2];
		while (i++ < mem[0])
		{
			mem[2] = new->a[i];
			new->a[i] = mem[1];
			mem[1] = mem[2];
		}
	}	
	if (op == RB || op == RR)
	{
		i = 0;
		new->b[1] = mem[5];
		while (i++ < mem[3])
		{
			mem[5] = new->b[i];
			new->b[i] = mem[4];
			mem[4] = mem[5];
		}
	}
	return (new);
}
