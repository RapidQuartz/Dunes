/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:48 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/13 17:31:00 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//		returns a positive integer
int	get_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

//		outputs a string and a newline
void	ft_put(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i++];
		write (1, &c, 1);
	}
	write (1, "\n", 1);
}

//		outputs the structure/stacks
void	ft_put_struct(t_stk *stk)
{
	int	i;

	i = 1;
	while (i <= stk->a[0] || i <= stk->b[0])
	{
		printf("a: ");
		if (stk->a[0] == 0 || stk->a[0] < i)
			printf("-\t");
		else if (i <= stk->a[0])
			printf("%d\t", stk->a[i]);
		printf("b: ");
		if (stk->b[0] == 0 || stk->b[0] < i)
			printf("-");
		else if (i <= stk->b[0])
			printf("%d", stk->b[i]);
		printf("\n");
		i++;
	}
	printf("\n");
}

void	ft_clear_values(t_stk *s)
{
	int	i;

	i = 0;
	s->a_mid = (s->a[0] / 2 + s->a[0] % 2);
	s->b_mid = (s->b[0] / 2 + s->b[0] % 2);
	while (i < s->size)
	{
		s->a_tgt[i] = 0;
		s->b_tgt[i] = 0;
		s->a_mov[i] = 0;
		s->b_mov[i] = 0;
		s->a_cost[i] = 0;
		s->b_cost[i] = 0;
		s->c_cost[i] = 0;
		s->sm[i] = 0;
		s->bg[i] = 0;
		i++;
	}
}

void	ft_liberation(t_stk **s)
{
	free ((*s)->a);
	free ((*s)->b);
	free ((*s)->a_tgt);
	free ((*s)->b_tgt);
	free ((*s)->a_mov);
	free ((*s)->b_mov);
	// free ((*s)->ops);
	free ((*s)->a_cost);
	free ((*s)->b_cost);
	free ((*s)->c_cost);
	free ((*s)->sm);
	free ((*s)->bg);
	free (*s);
	*s = NULL;
}
