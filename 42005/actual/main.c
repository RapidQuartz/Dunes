/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:29 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/22 17:25:13 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	legal_arg(char *c)
{
	int	i;
	char	p;

	i = 0;
	p = '\0';
	while (*c != '\0')
	{
		if (!(( \
		((p == '\0') || (p == ' ' )) \
		&& ((*c == ' ') || (*c == '-' || *c == '+') \
		|| (*c >= '0' && *c <= '9'))) \
		|| \
		((p == '-' || p == '+') \
		&& (*c >= '0' && *c <= '9')) \
		|| \
		((p >= '0' && p <= '9') \
		&& ((*c == ' ') \
		|| (*c >= '0' && *c <= '9')))))
			return (false);
		else
			p = *c;
		c++;
	}
	return (true);
}

int	get_argnum(char *c)
{
	int	n;

	n = 0;
	while (*c)
	{
		if (*c == ' ')
			c++;
		if (*c == '-' || *c == '+')
			c++;
		if (*c >= '0' && *c <= '9')
		{
			n++;
			while (*c >= '0' && *c <= '9')
				c++;
		}
	}
	return (n);
}

int	get_arglen(char *c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = -1;
	len = 0;
	while (c[i] != '\0')
	{
		if (j < 0 && (c[i] == '-' || c[i] == '+' || \
			(c[i] >= '0' && c[i] <= '9')))
			j = i;
		if ((j >= 0 && i > j) && (c[i] == ' ' || c[i] == '\0'))
			len += (i - j);
		if (c[i] == ' ' || c[i] == '\0')
			j = -1;
		i++;
	}
	return (len);
}

char	*ft_split_put(int *i, char *b, char **c, int *d)
{
	while (d[0] < i[0])
	{
		while (c[d[0]][d[1]] == ' ')
			d[1]++;
		if ((c[d[0]][d[1]] == '-' || c[d[0]][d[1]] == '+') ||
		(c[d[0]][d[1]] >= '0' && c[d[0]][d[1]] <= '9'))
		{
			while ((c[d[0]][d[1]] == '-' || c[d[0]][d[1]] == '+') \
			|| (c[d[0]][d[1]] >= '0' && c[d[0]][d[1]] <= '9'))
				b[d[2]++] = c[d[0]][d[1]++];
			b[d[2]] = ' ';
		}
		if (c[d[0]][d[1]] == '\0')
		{
			d[0]++;
			d[1] = 0;
		}
	}
	if (d[2] > 0 && b[d[2] - 1] == ' ')
		b[d[2] - 1] = '\0';
	else
		b[d[2]] = '\0';
	d[0] = i[1];
	ft_num_array(d, i, b);
	return (b);
}

void	ft_num_array(int *a, int *b, char *c)
{
	b[0] = 0;
	b[2] = 0;
	a = char_to_int(a, b, c);
	a = arr_normalizer(a, a[0]);
	if (!a || a == NULL)
		return ;
}

int	*check_legal_arg(int *i, char **c, int l, int n)
{
	i = malloc(sizeof(int) * 3);
	if (!i || i == NULL)
		return (NULL);
	while (l < 3)
		i[l++] = 0;
	while (++i[0] < n)
	{
		if (!legal_arg(c[i[0]]))
			return (NULL);
		i[1] += get_argnum(c[i[0]]);
		i[2] += get_arglen(c[i[0]]);
	}
	i[0] = n;
	return (i);
	if (n < 2 || i[1] < 2 || i[2] < 3)
		return (NULL);
}

t_hold *ft_init_test(int a, char **c)
{
	t_hold	*bucket;
	char		*str;
	int		*d;
	int		*i;
	int		l;

	str = NULL;
	i = NULL;
	l = 0;
	i = check_legal_arg(i, c, l, a);
	if (i == NULL)
		return (NULL);
	d = ft_make_null_arr(i[1]);
	if (!d || d == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (i[1] + i[2] + 1));
	if (!str || str == NULL)
		return (NULL);
	str = ft_split_put(i, str, c, d);
	bucket = malloc(sizeof(*bucket));
	if (!bucket || bucket == NULL)
		return (NULL);
	bucket->arg_key = str;
	bucket->arg_map = d;
	return (bucket);
}

//		take args. check them.
int	main(int a, char **c)
{
	t_hold	*hold;
	t_stk		*s;

	hold = NULL;
	s = NULL;
	if (a > 1)
		hold = ft_init_test(a, c);
	if ((!hold || hold == NULL) || arg_duplicate(hold->arg_map))
		error_end_stk(NULL);
	hold->arg_map = arr_normalizer(hold->arg_map, hold->arg_map[0]);
	s = arr_to_stk(hold->arg_map, s);
	if (!s || s == NULL)
		error_end_stk(&s);
	if (hold && hold != NULL && hold->arg_key != NULL)
		s = ft_arg_stk(hold, s);
	if (s != NULL)
		push_swap(s);
	else
		return (-1);
	ft_liberation(&s);
	return (0);
		return (-1);
}

void	push_swap(t_stk *s)
{
	if (s != NULL && s->a != NULL && unsorted(s))
	{
		if (s->a[0] == 2)
			s = swap_a(s);
		else if (s->a[0] == 3)
			sort_three(s);
		else if (s->a[0] > 3)
			exec_turk(s);
	}
	return ;
}

void	exec_turk(t_stk *s)
{
	while (unsorted(s) && s->a[0] > 3)
	{
		ft_clear_values(s);
		if (s->steps == 0)
			first_moves(s);
		else if (s->steps > 0)
		{
			get_cost(s, s->a, s->b);
			do_moves(s, s->a_cost, s->b_cost, s->c_cost);
			s = push_b(s->a, s->b, s);
			if (s->flag != 0)
				do_flag(s);
		}
	}
	do_flag(s);
	sort_three(s);
	ft_clear_values(s);
	realign_or_not(s);
	return ;
}

void	sort_three(t_stk *s)
{
	int		*ops;
	int		*a;

	a = NULL;
	ops = ft_make_null_arr(5);
	if (s != NULL && s->a != NULL && s->a[0] == 3)
		a = s->a;
	else
		return ;
	if (a != NULL && (a[1] < a[2]) && (a[1] < a[3]) && (a[2] > a[3]))
		ops[0] = 1;
	if (a != NULL && (a[1] > a[2]) && (a[1] < a[3]) && (a[2] < a[3]))
		ops[1] = 1;
	if (a != NULL && (a[1] < a[2]) && (a[1] > a[3]) && (a[2] > a[3]))
		ops[2] = 1;
	if (a != NULL && (a[1] > a[2]) && (a[1] > a[3]) && (a[2] < a[3]))
		ops[3] = 1;
	if (a != NULL && (a[1] > a[2]) && (a[1] > a[3]) && (a[2] > a[3]))
		ops[4] = 1;
	s = three_ops(s, ops);
	free (ops);
	return ;
}

t_stk	*three_ops(t_stk *s, int *ops)
{
	int	i;

	i = 0;
	while (ops != NULL && i++ < 2 && s != NULL)
	{
		if ((i == 1 && ops[2] == 1) || (i == 2 && ops[4] == 1))
			reverse_a(s, 1);
		if (i == 1 && (ops[0] == 1 || ops[1] == 1 || ops[4] == 1))
			swap_a(s);
		if ((i == 1 && ops[3] == 1) || (i == 2 && ops[0] == 1))
			rotate_a(s, 1);
	}
	return (s);
}
