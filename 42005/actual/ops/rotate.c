/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:57:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/10 17:21:49 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_snap	*do_rotate(t_ree *tree, int op)
{
	t_snap		*new;
	unsigned short	*obj;

	new = tree->moves[op];
	//rra//rrr
	if (op == 6 || 8)
	{
		obj = new->a;
		obj = ft_reverse(obj);
		new->a = obj;
	}
	//rrb//rrr
	if (op == 7 || 8)
	{
		obj = new->b;
		obj = ft_reverse(obj);
		new->b = obj;
	}
	return (new);
}

//TOP to BOT
short		*ft_rotate(unsigned short *obj)
{
	short		top;
	short		end;
	short		mem;
	short		i;

	i = obj[0];
	end = obj[i];
	top = obj[1];
	obj[i] = top;
	while (i-- > 1)
	{
		mem = obj[i];
		obj[i] = end;
		end = mem;
	}
	return (obj);
}

t_snap	*do_reverse(t_ree *tree, int op)
{
	t_snap		*new;
	unsigned short	*obj;

	new = tree->moves[op];
	//rra//rrr
	if (op == 9 || 11)
	{
		obj = new->a;
		obj = ft_reverse(obj);
		new->a = obj;
	}
	//rrb//rrr
	if (op == 10 || 11)
	{
		obj = new->b;
		obj = ft_reverse(obj);
		new->b = obj;
	}
	return (new);
}

//BOT to TOP
short		*ft_reverse(unsigned short *obj)
{
	short		size;
	short		top;
	short		mem;
	short		i;

	i = 0;
	size = obj[i];
	top = obj[1];
	obj[1] = obj[size];
	while (i++ < size)
	{
		mem = obj[i];
		obj[i] = top;
		top = mem;
	}
	return (obj);
}