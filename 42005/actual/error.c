/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:03 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/13 18:43:03 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///	TODO:	add flag/mode to exit or return control
//		attempt to free array from memory and exit
void	error_end_arr(int *array)
{
	if (array)
		free (array);
	ft_put("Error");
	exit (2);
}

///	TODO:	add flag/mode to exit or return control
//		attempt to free stack from memory and exit
void	error_end_stk(t_stk **nexus)
{
	if (nexus)
		free (nexus);
	ft_put("Error");
	exit (2);
}
// char *ft_rev_str(char *str, int len)
// {
	
// }

char *ft_itoa(int num, char *str, int i)
{
	int	digit;

	if (num == 0)
		return (str);
	digit = num % 10;
	str[i++] = digit + '0';
	return (ft_itoa(num / 10, str, i));
}

void	put_num(int num)
{
	int	mem;
	int	len;
	char	*digit;

	if (num == 0)
		return ;
	mem = num;
	len = 0;
	while (mem /= 10)
		len++;
	digit = (char *)malloc(len + 1);
	mem = num;
	digit = ft_itoa(num, digit, 0);
	// digit = ft_rev_str(digit, len);
	while (len)
		write (1, &digit[len--], 1);
}


void	ft_put_ops(t_stk *s)
{
	int	i;

	i = 0;
	// put_num(s->ops[0]);
	// while (i++ < s->ops[0])
	// 	ft_scrbl(s, i);
	// printf("MOVES:\n%d\n", s->ops[0]);
	printf("MOVES:\n%d\n", s->steps);
}
/* 
void	ft_scrbl(t_stk *s, int i)
{	
	if (s->ops[i] == 1)
		ft_put("pa");
	if (s->ops[i] == 2)
		ft_put("pb");
	if (s->ops[i] == 3)
		ft_put("sa");
	if (s->ops[i] == 4)
		ft_put("sb");
	if (s->ops[i] == 5)
		ft_put("ss");
	if (s->ops[i] == 6)
		ft_put("ra");
	if (s->ops[i] == 7)
		ft_put("rb");
	if (s->ops[i] == 8)
		ft_put("rr");
	if (s->ops[i] == 9)
		ft_put("rra");
	if (s->ops[i] == 10)
		ft_put("rrb");
	if (s->ops[i] == 11)
		ft_put("rrr");
} */
/* 
void	ft_keep_op(char *op, t_stk *s)
{
	int	i;

	i = ++s->ops[0];
	if (op[0] == 'p' && op[1] == 'a')//pa
		s->ops[i] = 1;
	else if (op[0] == 'p' && op[1] == 'b')//pb
		s->ops[i] = 2;
	else if (op[0] == 's' && op[1] == 'a')//sa
		s->ops[i] = 3;
	else if (op[0] == 's' && op[1] == 'b')//sb
		s->ops[i] = 4;
	else if (op[0] == 's' && op[1] == 's')//ss
		s->ops[i] = 5;
	else if (op[0] == 'r' && op[1] == 'a')//ra
		s->ops[i] = 6;
	else if (op[0] == 'r' && op[1] == 'b')//rb
		s->ops[i] = 7;
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == '\0')//rr
		s->ops[i] = 8;
	else if (op[2] == 'a' && op[3] == '\0')//rra
		s->ops[i] = 9;
	else if (op[2] == 'b' && op[3] == '\0')//rrb
		s->ops[i] = 10;
	else if (op[2] == 'r' && op[3] == '\0')//rrr
		s->ops[i] = 11;
} */

/*
1	- pa
2	- pb
3	- sa
4	- sb
5	- ss
6	- ra
7	- rb
8	- rr
9	- rra
10	- rrb
11	- rrr











*/