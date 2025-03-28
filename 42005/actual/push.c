/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:50:39 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/28 13:27:19 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_info(t_n **stk, t_n *tail, t_n *head, t_n *info);
void	ft_push_src(t_n **stack_src, t_n *src_info);
// void	ft_push_dst(t_n **stack_dst, t_n *dst_info);
void	ft_push_dst(t_n **stack_dst, t_n *dst_info, t_n **new_head);
/* THIS ONE MIGHT NOT */
void	push(t_stack **stack_src, int	idt)
{
	int	*sta;
	int	*stb;

	if (stack_src != NULL && (*stack_src)->st_a != NULL)
		sta = (*stack_src)->st_a;
	if (stack_src != NULL && (*stack_src)->st_b != NULL)
		stb = (*stack_src)->st_b;
	if (idt == 0)
		ft_ppb(sta, stb);
	else if (idt == 1)
		ft_pa(sta, stb);
	else if (idt == 2)
		ft_pb(sta, stb);
	
}

void	ft_ppb(int *sta, int *stb);
void	ft_ppb(int *sta, int *stb)
{
	ft_pb(sta, stb);
	ft_pb(sta, stb);
}
void	ft_pa(int *sta, int *stb);
void	ft_pa(int *sta, int *stb)
{
	
}
void	ft_pb(int *sta, int *stb);
void	ft_pb(int *sta, int *stb)
{
	
}
void	ft_push_b(t_stack *stk);
void	ft_push_b(t_stack *stk)
{
	int	*t;
	int	n;
	int	i;

	i = 0;
	t = malloc(sizeof(int) * stk->size);
	if (!t || t == NULL)
		free (stk);
	else
	{
		ft_pushto(stk, stk->st_a, stk->st_b);
		ft_pushfrom(stk, stk->st_a, stk->st_b);
		if (stk->err != 0)
			d_end();
	}
}
void	ft_push_a(t_stack *stk);
void	ft_push_a(t_stack *stk)
{
	int	*t;
	int	n;
	int	i;

	i = 0;
	t = malloc(sizeof(int) * stk->size);
	if (!t || t == NULL)
		free (stk);
	else
	{
		ft_pushto(stk, stk->st_b, stk->st_a);
		ft_pushfrom(stk, stk->st_b, stk->st_a);
		if (stk->err != 0)
			d_end();
	}
}
int	*ft_pushto(t_stack *stk, int *src, int *dst);
int	*ft_pushfrom(t_stack *stk, int *src, int *dst);
int	*ft_pushto(t_stack *stk, int *src, int *dst)
{
	int	i;
	int	j;
	int	n;
	int	*s;
	int	*d;

	i = 1;
	n = src[1];
	while (i < src[0])
		src[i++] = src[i];
	src[0] -= 1;
	dst[0] += 1;
	i = dst[0];
	while (i < 0)
		dst[i--] = dst[i];
	free (dst);
	return (d);
}
int	*ft_pushfrom(t_stack *stk, int *src, int *dst)
{
	int	i;
	int	n;

	i = 0;
	src[0]--;
	n = src[0];
}
int	*move_stack_fwd(int *stk, int num);
int	*move_stack_fwd(int *stk, int num)
{
	int	*t;
	int	n;
	int	i;

	i = 0;
	t = malloc(sizeof(int) * stk[0]);
	if (!t || t == NULL)
		free (stk);
	if (num == 0)
		ft_pushfrom(stk);
	else
	{
		n = stk[0];
		while (i != n)	
		{
			t[num + i] = 
		}
	}
	return (stk);
}
int	*move_stack_bwd(int *stk, int num);
int	*move_stack_bwd(int *stk, int num)
{
	if (num != 0)
	if (num <= -1)
	if (num >= 1)
	return (stk);
}
/*{ 
	t_n	*src_info;
	t_n	*src_info;
	t_n	*dst_info;
	t_n	**dst_head;
	char	dst_stk;
	
	debug("1");
	
d_print_twostack_values(stack_src, stack_dst, 1);
	
	src_info = (*stack_src)->i;
	debug("2");
	
d_print_twostack_values(stack_src, stack_dst, 0);
	
	dst_info = (*stack_dst)->i;
	debug("3");
	
d_print_twostack_values(stack_src, stack_dst, 0);
	
	dst_head = src_info->h;
	debug("4");
	
d_print_twostack_values(stack_src, stack_dst, 0);
	
	// dst_stk = (*dst_head)->c->stk;
	// d_print_twostack_values(stack_src, stack_dst, 0);
	dst_info->h = dst_head;
	debug("5");
	
d_print_twostack_values(stack_src, stack_dst, 0);
	
	if (src_info->n->c->stk == 'A')
		(*dst_head)->c->stk = 'B';
	else if (src_info->n->c->stk == 'B')
		(*dst_head)->c->stk = 'A';
	debug("6");
	
d_print_twostack_values(stack_src, stack_dst, 0);
	
	ft_push_src(stack_src, src_info);
	debug("7");
	
d_print_twostack_values(stack_src, stack_dst, 0);
	
	ft_push_dst(stack_dst, dst_info, dst_head);
	debug("8");
	
d_print_twostack_values(stack_src, stack_dst, 1);
	
} */
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
			src_head = src_info->p;
		else if (src_info->v > 1)
			src_head = src_info->n->n;
		src_head->h = &src_head;
		src_head->p = src_tail;
		src_tail->n = src_head;
		reset_info(stack_src, src_tail, src_head, src_info);
	}
	else if (src_info->v == 0)
		reset_info(stack_src, NULL, NULL, NULL);
}

void	reset_info(t_n **stk, t_n *tail, t_n *head, t_n *info)
{
	info->n = head;
	info->h = &head;
	info->p = tail;
}

// void	ft_push_dst(t_n **stack_dst, t_n *dst_info)
void	ft_push_dst(t_n **stack_dst, t_n *dst_info, t_n **new_head)
{
	t_n	*dst_tail;
	t_n	*dst_head;
	
	dst_info->v += 1;
	dst_tail = dst_info->p;
	dst_head = (*new_head);
	if (dst_info->v > 1)
	{
		if (dst_info->v == 2)
			dst_head = dst_tail;
		else if (dst_info->v > 2)
			dst_head = dst_info->n->n;
		dst_head->p = dst_tail;
		reset_info(stack_dst, dst_tail, dst_head, dst_info);
	}
	else if (dst_info->v == 1)
	{
		reset_info(stack_dst, (*dst_info->h), (*dst_info->h), dst_info);
		dst_head = (*dst_info->h);
	}
	dst_head->p = dst_info->p;
	dst_head->n = dst_info->n;
	dst_head->h = dst_info->h;
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
	return (0);
}