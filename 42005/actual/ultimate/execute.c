/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:31:51 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/07 20:53:58 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	EXECUTE_C IS A SINGLE DOC VERSION OF PUSH_SWAP
it exists to allow vscode to debug.
*/
//		declarations
///	MAIN:C:
int			*arg_check(char *arg, int *argn, int j);
int			*arg_to_arr(int *argn, char **argv);
t_stk		*arr_to_stk(int *arr);
bool		arg_duplicate(int	*arr);
long		arg_to_int(char *arg, int argn);

///	PUSH:SWAP:C:
void		push_swap(t_stk **nexus);
bool		check_sort(t_stk *nexus);
///		TURK:C:
void		exec_turk(t_stk **stk);
void		realign_or_not(t_stk *stk);
void		push_back(t_stk *stk);
///		PUSH:C:
t_stk		*push_a(int *a, int *b, t_stk *c);
t_stk		*push_b(int *a, int *b, t_stk *c);
int			*realign_stack(int *s);
///		SWAP:C:
int			*swap_a(int *a);
int			*swap_b(int *b);
t_stk		*swap_s(t_stk *s);
///		ROTATE:C:
int			*rotate_a(int *a, int post);
int			*rotate_b(int *b, int post);
t_stk		*rotate_s(t_stk *a);
///		REVERSE:C:
int			*reverse_a(int *a, int post);
int			*reverse_b(int *b, int post);
t_stk		*reverse_s(t_stk *a);
///		SORT:THREE:C:
void		sort_three(t_stk **stk);
int			*three_ops(int *a, int *b);

///	COST:C:
void		get_cost(t_stk *s, int *a, int *b, int *c);
int			find_next_bigger(int *s, int n);
int			find_next_smaller(int *s, int n);
void		select_target(t_stk *s);
void		align_or_not(t_stk *s);
void		store_moves(t_stk *s);
void		do_moves(t_stk *s);

///	UTIL:C:
void		ft_put(char *str);
void		ft_put_struct(t_stk **stk);
void		error_end_arr(int *array);
void		error_end_stk(t_stk **nexus);

////	MAIN:C:
//		take args. check them.
int			main(int argc, char **argv)
{
	int	i;
	int	*argn_map;
	//DEBUG
	int	count = 2;
	char *vars[] = { "dummy", "1 3 2" };
	//DEBUG
	int	*arr;
	t_stk	*nexus;

	i = 0;
	argn_map = (int *)malloc(sizeof(int) * (argc + 1));
	// if (!(argc >= 2 && argc <= 501) || (!argn_map || argn_map == NULL))
	// 	error_end_arr(argn_map);
	//DEBUG
	argc = count;
	argv = vars;
	//DEBUG
	argn_map[0] = 0;
	while (++i < argc)
		argn_map = arg_check(argv[i], argn_map, i);
	arr = arg_to_arr(argn_map, argv);
	if (!arg_duplicate(arr))
		nexus = arr_to_stk(arr);
	if (!nexus || nexus == NULL)
		error_end_stk(&nexus);
	push_swap(&nexus);
	return (0);
}
//MINUS 9 DEBUG LINES

int			*arg_check(char *arg, int *argn, int j)
{
	int	i;
	int	in;

	i = 0;
	in = 0;
	while (arg[i] != '\0')
	{
		if (in == 0 && (arg[i] == '+' || arg[i] == '-'))
			in = -1;
		else if (in <= 0 && arg[i] >= '0' && arg[i] <= '9')
		{
			in = 1;
			argn[j]++;
		}
		else if (in == -1 && !(arg[i] >= '0' && arg[i] <= '9'))
			error_end_stk(NULL);
		else if (in == 1 && (arg[i] == ' ' || arg[i] == '\0'))
			in = 0;
		i++;
	}
	argn[0] += argn[j];
	return (argn);
}

int			*arg_to_arr(int *argn, char **argv)
{
	int	i;
	int	j;
	int	*arr;
	long	num;
	int	n;

	i = 1;
	j = 1;
	arr = (int *)malloc(sizeof(int) * (argn[0] + 1));
	if (!arr || arr == NULL)
		error_end_arr(arr);
	arr[0] = argn[0];
	while (i <= argn[0])
	{
		n = 0;
		while (n++ < argn[j])
		{
			num = arg_to_int(argv[j], n);
			if (num < INT_MIN || num > INT_MAX)
				error_end_arr(arr);
			arr[i++] = (int)num;
		}
		j++;
	}
	return (arr);
}

t_stk		*arr_to_stk(int *arr)
{
	t_stk	*nexus;
	int	i;

	i = -1;
	nexus = malloc(sizeof(*nexus));
	if (!nexus || nexus == NULL)
		error_end_arr(arr);
	nexus->a = (int *)malloc(sizeof(int) * arr[0]);
	nexus->b = (int *)malloc(sizeof(int) * arr[0]);
	nexus->c = (int *)malloc(sizeof(int) * arr[0]);
	if (nexus->a == NULL || nexus->b == NULL || nexus->c == NULL)
		error_end_stk(&nexus);//FREE ARR
	while (i++ < arr[0])
		nexus->a[i] = arr[i];
	free (arr);
	return (nexus);
}

bool		arg_duplicate(int	*arr)
{
	int	i;
	int	j;
	int	sub;

	i = 0;
	while (arr[0] > i++)
	{
		j = 0;
		sub = arr[i];
		while (arr[0] > j++)
		{
			if (j != i && sub == arr[j])
				return (true);
		}
	}
	return (false);	
}
////		PUSH:SWAP:C:
void		push_swap(t_stk **nexus)
{
	if(check_sort(*nexus))
	{
		if ((*nexus)->a[0] == 2)
			(*nexus)->a = swap_a((*nexus)->a);
		else if ((*nexus)->a[0] == 3)
			sort_three(nexus);
		else if ((*nexus)->a[0] > 3)
			exec_turk(nexus);
	}
	return ;
}

bool		check_sort(t_stk *nexus)
{
	int	i;
	
	i = 1;
	while (i < nexus->a[0] || i < nexus->b[0])
	{
		if (i > 1 && i < nexus->a[0] && nexus->a[i - 1] != nexus->a[i] - 1)
				return (true);
		if (i > 1 && i < nexus->b[0] && nexus->b[i - 1] != nexus->b[i] + 1)
				return (true);
		i++;
	}
	if (0 < nexus->a[0] && 0 < nexus->b[0] && nexus->a[1] - 1 == nexus->b[1])
		return (false);
	else if (0 < nexus->a[0])
		return (false);
	else
		return (true);
}
////		TURK:C:

void		exec_turk(t_stk **stk)
{
	int 		*a;
	int 		*b;
	int 		*c;
	t_stk		*s;

	s = (*stk);
	a = s->a;
	b = s->b;
	c = s->c;
	//	push 2
	s = push_b(a, b, s);
	if (a[0] >= 5)
		s = push_b(a, b, s);
	while (check_sort(s))
	{
		get_cost(s, a, b, c);
		select_target(s);
		align_or_not(s);
		store_moves(s);
		do_moves(s);
	}
	realign_or_not(s);
	push_back(s);
	return ;
}

void		realign_or_not(t_stk *stk)
{
	return ;
}

void		push_back(t_stk *stk)
{
	return ;
}

////		COST:C:
void		get_cost(t_stk *s, int *a, int *b, int *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < a[0])
	{
		c[i] = find_next_smaller(b, a[i]);
		if (c[0] == 0)
			c[i] = find_next_bigger(b, a[i]) - 1;
			//-1 because 'bigger' needs to be on bottom
		if (b[0] / 2 + b[0] % 2 < c[i])
			c[i] = -c[i] - 2;
			//-2 because from 'size' it takes 2 moves to push
			//(index 2 carries the cost of 'rotate & push')
//NB:		this cost is *negative*. it still carries 'absolute cost'
	}
}

int		find_next_bigger(int *s, int n)
{
	int	i;
	int	ind;
	int	big;//previous smaller
	bool	found;//next smaller
	
	i = 0;
	ind = 0;
	big = INT_MIN;
	found = false;
	while (i++ < s[0])
	{
		if (s[i] > n && (found == false || (found == true && big > s[i])))
		{
			big = s[i];
			found = true;
			ind = i;
		}
	}
	return (ind);
}

int		find_next_smaller(int *s, int n)
{
	int	i;
	int	ind;
	int	sml;//previous smaller
	bool	found;//next smaller
	
	i = 0;
	ind = 0;
	sml = INT_MAX;
	found = false;
	while (i++ < s[0])
	{
		if (s[i] < n && (found == false || (found == true && sml < s[i])))
		{
			sml = s[i];
			found = true;
			ind = i;
		}
	}
	return (ind);
}

void		select_target(t_stk *s)
{
	
}

void		align_or_not(t_stk *s)
{
	
}

void		store_moves(t_stk *s)
{
	
}

void		do_moves(t_stk *s)
{
	
}

////		PUSH:C:
t_stk		*push_a(int *a, int *b, t_stk *c)
{
	int	i;
	int	s;
	int	m;
	int	n;

	i = 0;
	a[0]++;
	s = a[0];
	m = b[1];
	while (i++ < s)
	{
		n = a[i];
		a[i] = m;
		m = n;
	}
	b = realign_stack(b);
	write (1, "pa\n", 3);
	return (c);
}

t_stk		*push_b(int *a, int *b, t_stk *c)
{
	int	i;
	int	s;
	int	m;
	int	n;

	i = 0;
	b[0]++;
	s = b[0];
	m = a[1];
	while (i++ < s)
	{
		n = b[i];
		b[i] = m;
		m = n;
	}
	a = realign_stack(a);
	write (1, "pb\n", 3);
	return (c);
}

int		*realign_stack(int *s)
{
	int	i;
	int	m;
	int	n;

	if (s[0] > 0)
	{
		i = s[0];
		m = s[i];
		s[i] = 0;
		while (i-- != 1)
		{
			n = s[i];
			s[i] = m;
			m = n;
		}
	}
	else
		s[1] = 0;
	s[0]--;
	return (s);
}

////		SWAP:C:
int		*swap_a(int *a)
{
	int	s;

	s = a[1];
	a[1] = a[2];
	a[2] = s;
	write (1, "sa\n", 3);
	return (a);
}

int		*swap_b(int *b)
{
	int	s;

	s = b[1];
	b[1] = b[2];
	b[2] = s;
	write (1, "sa\n", 3);
	return (b);
}

t_stk		*swap_s(t_stk *s)
{
	int	*a;
	int	*b;
	int	n;
	int	m;

	a = s->a;
	b = s->b;
	n = a[1];
	a[1] = a[2];
	a[2] = n;
	m = b[1];
	b[1] = b[2];
	b[2] = m;
	write (1, "ss\n", 3);
	return (s);
}

////		ROTATE:C:
int		*rotate_a(int *a, int post)
{
	int	i;
	int	s;
	int	m;
	int	n;

	s = a[0];
	i = s;
	m = a[s];
	a[s] = a[1];
	while (i-- > 1)
	{
		n = a[i];
		a[i] = m;
		m = n;
	}
	if (post == 1)
		write (1, "ra\n", 3);
	return (a);
}

int		*rotate_b(int *b, int post)
{
	int	i;
	int	s;
	int	m;
	int	n;

	s = b[0];
	i = s;
	m = b[s];
	b[s] = b[1];
	while (i-- > 1)
	{
		n = b[i];
		b[i] = m;
		m = n;
	}
	if (post == 1)
		write (1, "rb\n", 3);
	return (b);
}

t_stk		*rotate_s(t_stk *a)
{
	a->a = rotate_a(a->a, 0);
	a->b = rotate_b(a->b, 0);
	write (1, "rr\n", 3);
	return (a);
}

////		REVERSE:C:

int		*reverse_a(int *a, int post)
{
	int	i;
	int	s;
	int	m;
	int	n;

	i = 0;
	s = a[0];
	m = a[s];
	while (i++ < s)
	{
		n = a[i];
		a[i] = m;
		m = n;
	}
	if (post == 1)
		write (1, "rra\n", 4);
	return (a);
}

int		*reverse_b(int *b, int post)
{
	int	i;
	int	s;
	int	m;
	int	n;

	i = 0;
	s = b[0];
	m = b[s];
	while (i++ < s)
	{
		n = b[i];
		b[i] = m;
		m = n;
	}
	if (post == 1)
		write (1, "rrb\n", 4);
	return (b);
}

t_stk		*reverse_s(t_stk *a)
{
	a->a = reverse_a(a->a, 0);
	a->b = reverse_b(a->b, 0);
	write (1, "rrr\n", 4);
	return (a);
}

////		SORT:THREE:C:
void		sort_three(t_stk **stk)
{
	int		ops[5];
	int		i;
	t_stk		*sta;
	int		*s;

	sta = (*stk);
	if (sta->a[0] == 3)
		s = sta->a;
	while (i++ < 4)
		ops[i] = 0;
	if ((s[1] < s[2]) && (s[1] < s[3]) &&  (s[2] > s[3]))//acb//rra//sa
		ops[0] = 1;
	if ((s[1] > s[2]) && (s[1] < s[3]) &&  (s[2] < s[3]))//bac//sa
		ops[1] = 1;
	if ((s[1] < s[2]) && (s[1] > s[3]) &&  (s[2] > s[3]))//bca//sa/rra
		ops[2] = 1;
	if ((s[1] > s[2]) && (s[1] > s[3]) &&  (s[2] < s[3]))//cab//ra
		ops[3] = 1;
	if ((s[1] > s[2]) && (s[1] > s[3]) &&  (s[2] > s[3]))//cba//rra
		ops[4] = 1;
	s = three_ops(s, ops);
	(*stk) = sta;
	return ;
}

int		*three_ops(int *a, int *b)
{
	int	i;

	i = 0;
	while (i++ < 2)
	{
		if ((i == 1 && (b[0] == 1 || b[4] == 1)) || (i == 2 && b[2] == 1))
			a = reverse_a(a);
		if ((i == 1 && (b[1] == 1 || b[2] == 1)) || (i == 2 && b[0] == 1))
			a = swap_a(a);
		if (i == 1 && b[3] == 1)
			a = rotate_a(a, 1);
	}
	return (a);
}

////		UTIL:C:
long		arg_to_int(char *arg, int argn)
{
	long	num;
	int	mag;
	int	i;
	char	c;
	
	num = 0;
	mag = 1;
	i  = 0;
	c = 0;
	while (argn && arg[i])
	{
		c = arg[i++];
		if ((c >= '0' && c <= '9') && argn == 1)
		{
			num *= 10;
			num = c - '0';
		}
		if (argn == 1 && c == '-')
			mag *= -1;
		else if ((c >= '0' && c <= '9')  && (arg[i] == ' ' || arg[i] == '\0'))
			argn--;
	}
	return (num * mag);
}

//		outputs a string and a newline
void		ft_put(char *str)
{
	int	i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i++];
		write (1, &c, 1);
	}
	write (1, "\n", 1);
}

void		ft_put_struct(t_stk **stk)
{
	t_stk	*s;
	int	i;
	int	a;
	int	b;

	s = (*stk);
	i = 0;
	while (i++ && i <= s->a[0] || i <= s->b[0])
	{
		printf("a: ");
		if (i <= s->a[0])
			printf("%d", s->a[i]);
		else
			printf("-");
		printf("b: ");
		if (i <= s->b[0])
			printf("%d", s->b[i]);
		else
			printf("-");
		printf("\n");
	}
}

//		attempt to free memory and exit
void		error_end_arr(int *array)
{
	if (array)
		free (array);
	ft_put("Error");
	exit (2);
}

void		error_end_stk(t_stk **nexus)
{
	if (nexus)
		free (nexus);
	ft_put("Error");
	exit (2);
}
