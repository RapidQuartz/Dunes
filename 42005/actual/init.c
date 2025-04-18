/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:24 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/18 09:59:36 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	arg_to_int(char *arg, int argn)
{
	long	num;
	int		mag;
	int		i;
	char	c;

	num = 0;
	mag = 1;
	i = 0;
	c = 0;
	while (argn && arg[i])
	{
		c = arg[i++];
		if ((c >= '0' && c <= '9') && argn == 1)
		{
			num *= 10;
			num += c - '0';
		}
		if (argn == 1 && c == '-')
			mag *= -1;
		else if ((c >= '0' && c <= '9') && \
		!(arg[i] >= '0' && arg[i] <= '9'))
			argn--;
	}
	return (num * mag);
}

int	*arg_to_arr(int *arr, int *argn, char **argv)
{
	int		i;
	int		j;
	long	num;
	int		n;

	i = 1;
	j = 0;
	arr = ft_make_null_arr(argn[0] + 1);
	if (!arr || arr == NULL)
		error_end_arr(arr);
	arr[0] = argn[0];
	while (i <= argn[0] && ++j)
	{
		n = 0;
		while (n++ < argn[j])
		{
			num = arg_to_int(argv[j], n);
			if (num < INT_MIN || num > INT_MAX)
				error_end_arr(arr);
			arr[i++] = (int)num;
		}
	}
	free (argn);
	return (arr);
}

int	*arr_normalizer(int *arr, int siz)
{
	int	i;
	int	*brr;

	i = 0;
	brr = NULL;
	brr = ft_make_null_arr(siz + 1);
	if (!brr || brr == NULL)
		error_end_arr(arr);
	if (!(arr[0] > 0))
		return (NULL);
	brr[i] = arr[0];
	brr = arr_transcriber(arr, brr, siz);
	free (arr);
	return (brr);
}

t_stk	*arr_to_stk(int *arr, t_stk *s)
{
	int	i;

	i = -1;
	s = NULL;
	s = malloc(sizeof(*s));
	if (!s || s == NULL)
		error_end_arr(arr);
	s->size = arr[0];
	s->a = ft_make_null_arr(s->size + 1);
	s->b = ft_make_null_arr(s->size + 1);
	s->a_mov = ft_make_null_arr(s->size + 1);
	s->b_mov = ft_make_null_arr(s->size + 1);
	s->a_cost = ft_make_null_arr(s->size + 1);
	s->b_cost = ft_make_null_arr(s->size + 1);
	s->c_cost = ft_make_null_arr(s->size + 1);
	s->a_tgt = ft_make_null_arr(s->size + 1);
	s->b_tgt = ft_make_null_arr(s->size + 1);
	s->sm = ft_make_null_arr(s->size + 1);
	s->bg = ft_make_null_arr(s->size + 1);
	if (ifnull(s))
		error_end_stk(&s);
	while (s->size >= ++i)
		s->a[i] = arr[i];
	free (arr);
	return (s);
}

int	*arr_transcriber(int *arr, int *brr, int siz)
{
	int			pos;
	int			i;
	int			j;

	i = 0;
	pos = 0;
	j = INT_MIN;
	if (!arr || !brr || arr == NULL || brr == NULL)
		return (NULL);
	brr[0] = arr[0];
	while (siz > 0 && i++ < arr[0])
	{
		if (arr[i] > j && brr[i] == 0)
		{
			pos = i;
			j = arr[i];
		}
		if (i == arr[0] && brr[pos] == 0)
		{
			brr[pos] = siz--;
			j = INT_MIN;
			i = 0;
		}
	}
	return (brr);
}
