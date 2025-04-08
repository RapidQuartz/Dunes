/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:31:51 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/08 15:16:13 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	EXECUTE_C IS A SINGLE DOC VERSION OF PUSH_SWAP

2025-04-08	TODO:1:2:3:4:5:6:
:1:
this check for too few arguments needs to come after args are parsed:
L113	if (!(argc >= 2 && argc <= 501) || (!argn_map || argn_map == NULL))
			error_end_arr(argn_map);
:2:
around here, args need to be normalized
L119	if (!arg_duplicate(arr))
		nexus = arr_to_stk(arr);
:3:
make the following functions::
void		select_target(t_stk *s)
void		align_or_not(t_stk *s)
void		store_moves(t_stk *s)
void		do_moves(t_stk *s)
void		realign_or_not(t_stk *stk)
void		push_back(t_stk *stk)
:4:
look over the get_cost
:5:
make "sort_three" clause for stack
:6:
fix the atoi monster, it doesnt work lol
need to do the whole "divide by ten" thing i guess
or. i dunno. maybe investigate it.
{it was missing "num +=" so it never plussed the stuff. lol.}
*/
/* ALTERNATIVE FOR GET_COST

2:
instead of 'which is bigger, x[i] or y[i]?'
it should be 'which is closer to the top?'
which is found by saying

void		find_closer(t_stk *s, int i)
{
	int	i;
	
	i = 0;
	x = s->x;
	y = s->y;
	while (s->a[0] > i++)
		if (x[i] != 0 && y[i] != 0)
			get_closer_b(0, s, i, s->b)
		else if (x[i] != 0 && y[i] == 0)
			get_closer_b(1, s, i, s->b)
		else if (x[i] == 0 && y[i] != 0)
			get_closer_b(2, s, i, s->b)
}
	
void		get_closer_b(int mode, t_stk *s, int i, int *b)
{
	int	*x;
	int	*y;
	int	x_closer;
	int	y_closer;

	x = s->x;
	y = s->y;
	x_closer = 0;
	y_closer = 0;
	if ((mode == 0 || mode == 1) && x[i] < (b[0] / 2 + b[0] % 2))
		x_closer = (b[0] / 2 + b[0] % 2) - x[i]
	else if ((mode == 0 || mode == 1) && x[i] > (b[0] / 2 + b[0] % 2))
		x_closer = x[i] - (b[0] / 2 + b[0] % 2)
	if ((mode == 0 || mode == 2) && y[i] < (b[0] / 2 + b[0] % 2))
		y_closer = (b[0] / 2 + b[0] % 2) - y[i]
	else if ((mode == 0 || mode == 2) && y[i] > (b[0] / 2 + b[0] % 2))
		y_closer = y[i] - (b[0] / 2 + b[0] % 2)
	if (mode == 1 || (mode == 0 && x_closer < y_closer))
		s->d[i] = x_closer
	else if (mode == 2 || (mode == 0 && x_closer > y_closer))
		s->d[i] = y_closer
}

1:
OR! should i compare x[i] and y[i]
pick whichever is cheaper to align
then set that as target


cus now what im doing is say "if there isnt a smaller, go for bigger. but smaller can be buried and i dont care"
worth looking into LATER
*/
//	filename
//		declarations
///	MAIN:C:
int		*arg_check(char *arg, int *argn, int j);
int		*arg_to_arr(int *argn, char **argv);
t_stk		*arr_to_stk(int *arr);
bool		arg_duplicate(int *arr);
int		*arr_normalize(int *arr);
int		*arg_normalizer(int *arr, int siz);
int		*arr_transcriber(int *arr, int *brr, int siz);
long		arg_to_int(char *arg, int argn);
bool		arr_unsorted(int *arr);

///	PUSH:SWAP:C:
void		push_swap(t_stk **nexus);
bool		stack_unsorted(t_stk *nexus);
///		TURK:C:
void		exec_turk(t_stk **stk);
void		realign_or_not(t_stk *stk);
void		push_back(t_stk *stk);
///		PUSH:C:
t_stk		*push_a(int *a, int *b, t_stk *c);
t_stk		*push_b(int *a, int *b, t_stk *c);
int		*realign_stack(int *s);
///		SWAP:C:
int		*swap_a(int *a);
int		*swap_b(int *b);
t_stk		*swap_s(t_stk *s);
///		ROTATE:C:
int		*rotate_a(int *a, int post);
int		*rotate_b(int *b, int post);
t_stk		*rotate_s(t_stk *a);
///		REVERSE:C:
int		*reverse_a(int *a, int post);
int		*reverse_b(int *b, int post);
t_stk		*reverse_s(t_stk *a);
///		SORT:THREE:C:
void		sort_three(t_stk **stk);
int		*three_ops(int *a, int *b);

///	COST:C:
void		get_cost(t_stk *s, int *a, int *b, int *c);
int		find_next_bigger(int *s, int n);
int		find_next_smaller(int *s, int n);
void		select_target(t_stk *s);
void		align_or_not(t_stk *s);
void		store_moves(t_stk *s);
void		do_moves(t_stk *s);
////		SPLIT:THIS:

///	UTIL:C:
void		ft_put(char *str);
void		ft_put_struct(t_stk **stk);
void		error_end_arr(int *array);
void		error_end_stk(t_stk **nexus);

////	MAIN:C:
//		take args. check them.

int		main(int argc, char **argv)
{
	int	i;
	int	*argn_map;
	//DEBUG
	// int	count = 2;
	// char 	*vars[] = { "dummy", "1 3 2" };
	// argc = count;
	// argv = vars;
	//DEBUG
	int	*arr;
	t_stk	*nexus;

	i = 0;
	argn_map = (int *)malloc(sizeof(int) * (argc + 1));
	if (!(argc >= 2 && argc <= 501) || (!argn_map || argn_map == NULL))
		error_end_arr(argn_map);
	argn_map[0] = 0;
	while (++i < argc)
		argn_map = arg_check(argv[i], argn_map, i);
	arr = arg_to_arr(argn_map, argv);
	free (argn_map);
	if (!arr || arr == NULL || arg_duplicate(arr))
		error_end_arr(arr);
	arr = arg_normalizer(arr, arr[0]);
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

bool		arr_unsorted(int *arr)
{
	int	i;
	int	n;
	int	z;

	i = 1;
	z = arr[0];
	n = arr[i];
	while (i++ < z)
	{
		if (arr[i] - 1 == n)
			n = arr[i];
		else
			return (true);
	}
	return (false);
}

/*		TODO:2025-04-08:
L188make a combo-free for stack and arrays?
////		DONE:added '+1'
//182-184//	nexus->a = (int *)malloc(sizeof(int) * arr[0] + 1);
*/
t_stk		*arr_to_stk(int *arr)
{
	t_stk	*s;
	int	i;

	i = -1;
	s = malloc(sizeof(*s));
	if (!s || s == NULL)
		error_end_arr(arr);
	s->a = (int *)malloc(sizeof(int) * arr[0] + 1);
	s->b = (int *)malloc(sizeof(int) * arr[0] + 1);
	s->c = (int *)malloc(sizeof(int) * arr[0] + 1);
	s->d = (int *)malloc(sizeof(int) * arr[0] + 1);
	s->a_cost = (int *)malloc(sizeof(int) * arr[0] + 1);
	s->b_cost = (int *)malloc(sizeof(int) * arr[0] + 1);
	s->x = (int *)malloc(sizeof(int) * arr[0] + 1);
	s->y = (int *)malloc(sizeof(int) * arr[0] + 1);
	if (s->a == NULL || s->b == NULL || s->c == NULL || s->x == NULL || \
	s->d == NULL || s->a_cost == NULL || s->b_cost == NULL || s->y == NULL)
		error_end_stk(&s);//FREE ARR
	while (i++ < arr[0])
		s->a[i] = arr[i];
	return (s);
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

//	SPECIAL IMPORT

int	*arr_normalizer(int *arr, int siz)
{
	int	i;
	int	*brr;

	i = 0;
	brr = malloc(sizeof(int) * (siz + 1));
	if (!brr || brr == NULL)
		error_end_arr(arr);
	brr[i] = arr[0];
	while (++i <= siz)
	{
		brr[i] = 0;
	}
	brr = arr_transcriber(arr, brr, siz);
	free (arr);
	return (brr);
}

int	*arr_transcriber(int *arr, int *brr, int siz)
{
	int			pos;
	int			i;
	int			j;
	
	i = 0;
	pos = 0;
	j = INT_MIN;
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
//	SPECIAL IMPORT

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

//R:TRUE[unsorted]:FALSE[sorted]
bool		stack_unsorted(t_stk *nexus)
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
	while (check_sort(s) && a[0] > 3)
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
/*		DONE:
now: if (c[i] == 0)
was: if (c[0] == 0))
*/


void		get_cost(t_stk *s, int *a, int *b, int *c)
{
	int	i;
	int	*a_cost;
	int	*b_cost;
	int	*d;
	int	a_mid;
	int	b_mid;

	i = 0;
	d = s->d;
	a_mid = (a[0] / 2 + a[0] % 2);
	b_mid = (b[0] / 2 + b[0] % 2);
	// a_cost = s->a_cost;
	// b_cost = s->b_cost;
	while (i++ < a[0])
	{
		s->x[i] = find_next_smaller(b, a[i]);
		s->y[i] = find_next_bigger(b, a[i]);
		c[i] = find_closer(s, s->x[i], s->y[i]);//index for target
		d[i] = select_move(c, i, a_mid, b_mid);//decides what move to do
	}
}

int		select_move(int *c, int i, int a_mid, int b_mid)
{
	int	result;
	
	if (i == 1 && c[i] == 1)
		result = 0;
	else if ((a_mid > i) && t == 1)
		result = -1;
	else if (i == 1 && (b_mid > c[i]))
		result = -2;
	else if ((a_mid < i) && t == 1)
		result = -3;
	else if (i == 1 && (b_mid < c[i]))
		result = -4;
	else if ((a_mid > i) && (b_mid > c[i]))
		result = -5;
	else if ((a_mid < i) && (b_mid < c[i]))
		result = -6;
	else if ((a_mid > i) && (b_mid < c[i]))
		result = -7;
	else if ((a_mid < i) && (b_mid > c[i]))
		result = -8;
	return (result);
}

int		find_closer(t_stk *s, int *x, int *y)
{
	int	i;
	int	closer;
	
	
	i = 0;
	closer = 0;
	while (s->a[0] > i++)
	{
		if (x[i] != 0 && y[i] != 0)
			closer = get_closer_b(0, s, i, s->b);
		else if (x[i] != 0 && y[i] == 0)
			closer = get_closer_b(1, s, i, s->b);
		else if (x[i] == 0 && y[i] != 0)
			closer = get_closer_b(2, s, i, s->b);
	}
	return (closer);
}
	
int		get_closer_b(int mode, t_stk *s, int i, int *b)
{
	int	*x;
	int	*y;
	int	x_closer;
	int	y_closer;

	x = s->x;
	y = s->y;
	x_closer = 0;
	y_closer = 0;
	if ((mode == 0 || mode == 1) && x[i] < (b[0] / 2 + b[0] % 2))
		x_closer = (b[0] / 2 + b[0] % 2) - x[i];
	else if ((mode == 0 || mode == 1) && x[i] > (b[0] / 2 + b[0] % 2))
		x_closer = x[i] - (b[0] / 2 + b[0] % 2);
	if ((mode == 0 || mode == 2) && y[i] < (b[0] / 2 + b[0] % 2))
		y_closer = (b[0] / 2 + b[0] % 2) - y[i];
	else if ((mode == 0 || mode == 2) && y[i] > (b[0] / 2 + b[0] % 2))
		y_closer = y[i] - (b[0] / 2 + b[0] % 2);
	if (mode == 1 || (mode == 0 && x_closer < y_closer))
		return (x_closer);
	else if (mode == 2 || (mode == 0 && x_closer > y_closer))
		return (y_closer);
}

/* 
void		get_cost(t_stk *s, int *a, int *b, int *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < a[0])
	{
		s->x[i] = find_next_smaller(b, a[i]);
		s->y[i] = find_next_bigger(b, a[i]);
		if (s->x[i] != 0 && s->y[i] != 0 && s->x[i] < s->y[i])//both exist and - is bigger
		else if (s->x[i] != 0 && s->y[i] != 0 && s->x[i] > s->y[i])//both exist and - is bigger
		//there IS a smaller in B and it's in the TOP half
		//the cost of aligning it is s->x - 1
		if (s->x[i] != 0 && b[0] / 2 + b[0] % 2 > c[i])
			s->b_cost = (s->x[i] - 1);
//there IS a smaller in B and it's in the BOTTOM half
//the cost of aligning it is (s->x * -1) - 1
		else if (s->x[i] != 0 && b[0] / 2 + b[0] % 2 < c[i])
			s->b_cost = (-s->x[i] - 1);
//there ISN'T a smaller in B but BIGGER is in the TOP half
//the cost of aligning it is s->y - 1
		if (s->x == 0 && s->y[i] != 0 && b[0] / 2 + b[0] % 2 > c[i])
			s->b_cost = (s->x[i] - 1);
//there ISN'T a smaller in B but BIGGER is in the BOTTOM half
//the cost of aligning it is (s->y * -1) - 1
		else if (s->x == 0 && s->y[i] != 0 && b[0] / 2 + b[0] % 2 < c[i])
			s->b_cost = (-s->x[i] - 1);

		if (b[0] / 2 + b[0] % 2 < c[i])
			s->b_cost[i] = -c[i] - 2;
		//-2 because from 'size' it takes 2 moves to push
//NB:		this cost is *negative*. it still carries 'absolute cost'
		else if (b[0] / 2 + b[0] % 2 > c[i])
			s->b_cost[i] = c[i];
		if (a[0] / 2 + a[0] % 2 < i)
			s->a_cost[i] = -i - 2;
		else if (a[0] / 2 + a[0] % 2 > i)
			s->a_cost[i] = i;
	}
} */

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

// void		select_target(t_stk *s, int size)
/* PSEUDO:
legend:
a[i]		subject
b[c[i]]	target
d[i]		a_cost
e[i]		b_cost

what I have:
c[i] == COST (not yet index) for number lower-or-higher-than a[i]
the one with the lowest cost wins*/

/* LOGIX
d[i] = 0	NO MOVE
		if both i == 1 and t == 1
d[i] = -1	ROTATE A
		if a[i] in top half and t == 1
d[i] = -2	ROTATE B
		if i == 1 and b[t] in top half
d[i] = -3	REVERSE A
		if a[i] in bottom half and t == 1
d[i] = -4	REVERSE B
		if i == 1 and b[t] in bottom half
d[i] = -5	ROTATE BOTH
		if both a[i] and b[t] are in top half
d[i] = -6	REVERSE BOTH
		if both a[i] and b[t] are in bottom half
d[i] = -7	ROTATE A & REVERSE B
		if a[i] but not b[t] are in top half
d[i] = -8	REVERSE A & ROTATE B
		if a[i] but not b[t] are in bottom half
*/
/* PRIORITY
if (d[i] == 0)
	;//go to push
else if (d[i] == -1)
else if (d[i] == -2)
else if (d[i] == -3)
else if (d[i] == -4)
else if (d[i] == -5)
else if (d[i] == -6)
else if (d[i] == -7)
else if (d[i] == -8)
*/
/* IMPLEMENTATION
1. get index of subject and target
sub = i;
tgt = c[i];
2. compare to size/placement and assign d[i] mode
d[i] = {LOGIX}
3. get index for new target depending on d[i] mode
NB: for `in stack B and smaller` we want index 1
difference between `t` and 1
NB: for `in stack B and bigger` we want index SIZE
difference between `t` and SIZE
NB: for `in stack A and smaller` we want index SIZE
difference between `i` and SIZE
NB: for `in stack A and bigger` we want index 1
difference between `i` and 1
X. get cost by summing indices and considering over the hump
4. get a_moves `x` and b_moves `y`
5. do combo moves if both are same direction until one is correct
6. so single moves on remaining
*/
/* D-MODE
if (i == 1 && c[i] == 1)
	d[i] = 0;
else if ((a[0] / 2 + a[0] % 2 > i) && t == 1)
	d[i] = -1;
else if (i == 1 && (b[0] / 2 + b[0] % 2 > c[i]))
	d[i] = -2;
else if ((a[0] / 2 + a[0] % 2 < i) && t == 1)
	d[i] = -3;
else if (i == 1 && (b[0] / 2 + b[0] % 2 < c[i]))
	d[i] = -4;
else if ((a[0] / 2 + a[0] % 2 > i) && (b[0] / 2 + b[0] % 2 > c[i]))
	d[i] = -5;
else if ((a[0] / 2 + a[0] % 2 < i) && (b[0] / 2 + b[0] % 2 < c[i]))
	d[i] = -6;
else if ((a[0] / 2 + a[0] % 2 > i) && (b[0] / 2 + b[0] % 2 < c[i]))
	d[i] = -7;
else if ((a[0] / 2 + a[0] % 2 < i) && (b[0] / 2 + b[0] % 2 > c[i]))
	d[i] = -8;
*/
/* D-MOVE
if (d[i] == -0)
	;//NO MOVE
if (d[i] == -1)
	;//ROTATE A `x` times
if (d[i] == -2)
	;//ROTATE B `y` times
if (d[i] == -3)
	;//REVERSE A `x` times
if (d[i] == -4)
	;//REVERSE B `y` times
if (d[i] == -5)
	;//ROTATE BOTH `x` times
if (d[i] == -6)
	;//REVERSE BOTH `x` times	
if (d[i] == -7)
	;//ROTATE A `x` times & REVERSE B `y` times
if (d[i] == -8)
	;//REVERSE A `x` times & ROTATE B `y` times
*/
// void		select_target_index(t_stk *s)
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
			a = reverse_a(a, 1);
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
			num += c - '0';
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
