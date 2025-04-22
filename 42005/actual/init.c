/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:24 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/22 17:17:31 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//k--sentence,a--argc,c--argv,i--position

int		check_flag(int a, char **c);

//NEW

//OLD
/* int	check_flag(int argc, char **argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (argv[1][i] != '\0' && i < 3 && argv[1][i] != ' ')
	{
		if (argv[1][0] == '-')
		{
			if (i > 0 && argv[1][i] == 'c')
				flag += 1;
			else if (i > 0 && argv[1][i] == 's')
				flag += 2;
		}
		else if (argv[1][0] != '-')
			break ;
		i++;
	}
	return (flag);
} */

//

int	*char_to_int(int *arr, int *ind, char *arg)
{
	long	num;

	while (arg[ind[0]] != '\0')
	{
		num = 0;
		ind[1] = 1;
		while (arg[ind[0]] != ' ' && arg[ind[0]] != '\0')
		{
			if ((arg[ind[0]] >= '0' && arg[ind[0]] <= '9'))
			{
				num *= 10;
				num += arg[ind[0]] - '0';
			}
			else if (arg[ind[0]] == '-')
				ind[1] *= -1;
			ind[0]++;				
		}
		if (num * ind[1] > INT_MAX || num * ind[1] < INT_MIN)
			return (NULL);
		arr[ind[2]++] = num * ind[1];
	}
	free (ind);
	return (arr);
}
//

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
t_stk	*ft_arg_stk(t_hold *key, t_stk *s);
t_stk	*ft_arg_stk(t_hold *key, t_stk *s)
{
	size_t	siz;
	int		*arr;

	arr = key->arg_map;
	siz = arr[0] + 1;
	s = stk_init(arr, s);
	if (!s || s == NULL)
		error_end_arr(arr);
	s->b = ft_make_null_arr(siz);
	s->a_mov = ft_make_null_arr(siz);
	s->b_mov = ft_make_null_arr(siz);
	s->a_cost = ft_make_null_arr(siz);
	s->b_cost = ft_make_null_arr(siz);
	s->c_cost = ft_make_null_arr(siz);
	s->a_tgt = ft_make_null_arr(siz);
	s->b_tgt = ft_make_null_arr(siz);
	s->sm = ft_make_null_arr(siz);
	s->bg = ft_make_null_arr(siz);
	if (ifnull(s))
		error_end_stk(&s);
	free (key);
	return (s);
}

t_stk	*stk_init(int *arr, t_stk *s)
{
	int	i;

	i = -1;
	if (arr != NULL && arr[0] > 0)
		error_end_arr(arr);
	s = malloc(sizeof(*s));
	if (!s || s == NULL)
		error_end_arr(arr);
	else
		s->a = ft_make_null_arr(arr[0] + 1);
	if (!s->a || s->a == NULL)
		error_end_stk(&s);
	s->size = arr[0];
	while (++i <= arr[0])
		s->a[i] = arr[i];
	s->steps = 0;
	s->flag = 0;
	return (s);
}

t_stk	*arr_to_stk(int *arr, t_stk *s)
{
	s = NULL;
	s = stk_init(arr, s);
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
