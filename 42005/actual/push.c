/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:50:39 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/24 17:55:46 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_src(t_n **stack_src, t_n *src_info);
void	ft_push_dst(t_n **stack_dst, t_n *dst_info);
/* THIS ONE MIGHT NOT */
void	push(t_n **stack_src, t_n **stack_dst)
{
	t_n	*src_info;
	t_n	*src_head;
	t_n	*dst_info;
	t_n	**dst_head;

	src_info = (*stack_src)->i;
	dst_info = (*stack_dst)->i;
	
	dst_head = src_info->h;
	src_head = (*dst_head)->h;
	dst_info->h = src_info->h;
	ft_push_src(stack_src, src_info);
	ft_push_src(stack_dst, dst_info);

}
/* THIS ONE MIGHT WORK LEL
void	push(t_n **stack_src, t_n **stack_dst)
{
	t_n	*src_info;
	t_n	*dst_info;
	t_n	**push_obj;

	src_info = (*stack_src)->i;
	dst_info = (*stack_dst)->i;
	dst_info->h = src_info->h;
	ft_push_src(stack_src, src_info);
	ft_push_src(stack_dst, dst_info);

} */

void	ft_push_src(t_n **stack_src, t_n *src_info)
{
	t_n	*src_tail;
	t_n	*src_head;
	
	src_info->v -= 1;
	if (src_info->v > 0)
	{
		src_tail = src_info->p;
		if (src_info->v == 1)
		{
			src_head = src_tail;
			src_head->n = src_tail;
			src_head->p = src_tail;
		}
		else if (src_info->v >= 1)
			src_head = src_info->n->n;
		src_head->p = src_tail;
		src_info->n = src_head;
		src_info->h = &src_head;
	}
	else if (src_info->v == 0)
	{
		src_info->p = NULL;
		src_info->n = NULL;
		src_info->h = NULL;
	}
}

void	ft_push_dst(t_n **stack_dst, t_n *dst_info)
{
	t_n	*dst_tail;
	t_n	*dst_head;
	
	dst_info->v += 1;
	if (dst_info->v > 1)
	{
		dst_tail = dst_info->p;
		if (dst_info->v == 2)
			dst_head = dst_tail;
		else if (dst_info->v > 2)
			dst_head = dst_info->n->n;
		dst_head->p = dst_tail;
		dst_info->n = dst_head;
		dst_info->h = &dst_head;
	}
	else if (dst_info->v == 1)
	{
		dst_info->p = (*dst_info->h);
		dst_info->n = (*dst_info->h);
	}
}

	///	X:
	//remove a member from src
	//suture ->n & ->p ptrs for src
	//reduce ->i->v -1 for src
	//set new head ptr
	///	X:
	//add a member to dst
	//increase ->i->v +1 for dst
	//set new head ptr
	///	X:
	//check if dst->i->v is 0
	//top of src becomes head of dst
	//
	///	X:

// t_n	*src_ptr;
// t_n	*tail;
// t_n	*old_head;
// t_n	*new_head;
// t_n	**head_ptr;


/*______________________________________________________________*\
||                                                              ||
|| select which node pushed to what stack by how many rotations ||
|| manipulates the cost->dif variable and cost->mov variables   ||
||______________________________________________________________||
\*                                                              */

int	select_push_node(t_n **stack)
{
	
}