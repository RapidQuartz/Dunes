/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:31:51 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/10 19:49:50 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	EXECUTE_C IS A SINGLE DOC VERSION OF PUSH_SWAP
:::::::*/
/*	2025-04-10	TODO:
:::::::

*/
/*	2025-04-09	TODO:1:2:3:4:5:6:
:::::::
:1:
make:ft:int		get_abs(int num);//return (abs);
//takes:		an int that is either positive or negative
//returns:		a positive int
:2:
set up t_stk->size
:3:
store::
index/distance from top of i == a_cost
target for i
index/distance from top of target for i == b_cost
:4:
somethign fucky is up...
i need the following:
compare:		
if (i > a_mid)
	a_cost = 
if (i < a_mid)
	a_cost = 
:5:
ok now working on check_sort_a check_sort_b and check_sort
check_sort
	calls 
check_sort_a
	checks sort for stack a
		returns based on state
			0	-	`size` numbers are in a[0], from `1` to `size`
			1	-	all the numbers in a[0] are +/- 1 in rising sequence
			2	-	all the numbers in a[0] are +/- 1 
			3	-	some of the numbers in a[0] are +/- > 1 
check_sort_b
	checks sort for stack b
		returns based on state
			0	-	0 numbers are in b[0]
			1	-	all the numbers in b[0] are +/- 1 in falling sequence
			2	-	all the numbers in b[0] are +/- 1 
			3	-	some of the numbers in b[0] are +/- > 1 
:6:
TODO: testing. havent run this beast at all. lol.
:::::::
*/
/*	2025-04-08	TODO:1:2:3:4:5:6:
:::::::
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
:::::::
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
		s->b_ops[i] = x_closer
	else if (mode == 2 || (mode == 0 && x_closer > y_closer))
		s->b_ops[i] = y_closer
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
/////	WIP:
int		get_abs(int num);//return (abs);
void		final_twist(t_stk *s);
void		preen(t_stk *s);
void		biggest_bois(t_stk *s, int *guys);

///	MAIN:C:
int		*arg_check(char *arg, int *argn, int j);
int		*arg_to_arr(int *argn, char **argv);
t_stk		*arr_to_stk(int *arr, t_stk *nexus);
t_stk		*stk_allocator(int *arr, t_stk *s);
bool		arg_duplicate(int *arr);
int		*arr_normalize(int *arr);
int		*arr_normalizer(int *arr, int siz);
int		*arr_transcriber(int *arr, int *brr, int siz);
long		arg_to_int(char *arg, int argn);
bool		arr_unsorted(int *arr);
int		check_sort(t_stk *s);
int		check_sort_a(t_stk *s);
int		check_sort_b(t_stk *s);

///	PUSH:SWAP:C:
void		push_swap(t_stk **nexus);
bool		stack_unsorted(t_stk *nexus);
///		TURK:C:
void		exec_turk(t_stk **stk);
void		ft_clear_values(t_stk *s);
void		realign_or_not(t_stk *s);
void		push_back(t_stk *stk);
///		PUSH:C:
t_stk		*push_a(int *a, int *b, t_stk *c);
t_stk		*push_b(int *a, int *b, t_stk *c);
int		*realign_stack(int *s);
///		SWAP:C:
t_stk		*swap_a(t_stk *s);
t_stk		*swap_b(t_stk *s);
t_stk		*swap_s(t_stk *s);
///		ROTATE:C:
void		rotate_a(t_stk *s, int post);
void		rotate_b(t_stk *s, int post);
void		rotate_s(t_stk *s);
///		REVERSE:C:
void		reverse_a(t_stk *s, int post);
void		reverse_b(t_stk *s, int post);
void		reverse_s(t_stk *s);
///		SORT:THREE:C:
void		sort_three(t_stk **stk);
t_stk		*three_ops(t_stk *s, int *b);

///	COST:C:
void		set_cost(int smaller, int bigger, t_stk *s, int i);
void		get_cost(t_stk *s, int *a, int *b);
void		compare_cost(t_stk *s, int *a, int *b);
int		find_next_bigger(int *s, int n);
int		find_next_smaller(int *s, int n);
void		select_target(t_stk *s);
void		align_or_not(t_stk *s);
void		store_moves(t_stk *s);
void		do_moves(t_stk *s, int *a, int *b, int *c);
int		*get_collective_cost(int *a, int *b, int *c, t_stk *s);
////		SPLIT:THIS:

///	UTIL:C:
void		ft_put(char *str);
void		ft_put_struct(t_stk *stk);
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
	arr = arr_normalizer(arr, arr[0]);
	nexus = arr_to_stk(arr, nexus);//TODO:1
	if (!nexus || nexus == NULL)
		error_end_stk(&nexus);
	ft_put_struct(nexus);
	push_swap(&nexus);
	ft_put_struct(nexus);
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
//182-184//	nexus->a = (int *)malloc(sizeof(int) * (arr[0] + 1));
*/
t_stk		*arr_to_stk(int *arr, t_stk *s)
{
	int	i;

	i = -1;
	s = malloc(sizeof(*s));
	if (!s || s == NULL)
		error_end_arr(arr);
	s->size = arr[0];
	s->a = (int *)malloc(sizeof(int) * (s->size + 1));
	s->b = (int *)malloc(sizeof(int) * (s->size + 1));
	s->a_mov = (int *)malloc(sizeof(int) * (s->size + 1));
	s->b_mov = (int *)malloc(sizeof(int) * (s->size + 1));
	s->a_cost = (int *)malloc(sizeof(int) * (s->size + 1));
	s->b_cost = (int *)malloc(sizeof(int) * (s->size + 1));
	s->c_cost = (int *)malloc(sizeof(int) * (s->size + 1));
	s->a_tgt = (int *)malloc(sizeof(int) * (s->size + 1));
	s->b_tgt = (int *)malloc(sizeof(int) * (s->size + 1));
	s->sm = (int *)malloc(sizeof(int) * (s->size + 1));
	s->bg = (int *)malloc(sizeof(int) * (s->size + 1));
	if (s->a == NULL || s->b == NULL || s->a_cost == NULL || \
s->b_cost == NULL || s->c_cost == NULL ||	s->sm == NULL || s->a_tgt == NULL \
|| s->bg == NULL || s->a_mov == NULL || s->b_mov == NULL || s->b_tgt == NULL)
		error_end_stk(&s);//FREE ARR
	while (s->size >= ++i)
		s->a[i] = arr[i];
	return (s);
}

bool		arg_duplicate(int	*arr)
{
	int	i;
	int	j;
	int	sub;
	int	size;

	i = 0;
	if (!(arr[0] > 0))
		return (true);//TODO: ERROR handling
	size = arr[0];
	while (size > i++)
	{
		j = 0;
		sub = arr[i];
		while (size > j++)
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
	if (!(arr[0] > 0))
		return (NULL);//TODO: ERROR handling
	brr[i] = arr[0];
	while (++i <= siz)
	{
		brr[i] = 0;
	}
	brr = arr_transcriber(arr, brr, siz);
	free (arr);
	return (brr);
}

int	*arr_transcriber(int *arr, int *brr, int siz)//TODO: send `s->size` as param
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
			(*nexus) = swap_a((*nexus));
		else if ((*nexus)->a[0] == 3)
			sort_three(nexus);
		else if ((*nexus)->a[0] > 3)
			exec_turk(nexus);
	}
	return ;
}

/*
RETURNS::
0	-	s->a[0] == s->size, s->a[i] == i, s->b[0] == 0
1	-	UNSORTED
*/
int		check_sort(t_stk *s)
{
	int	a;
	int	b;
	
	if (s->a[0] > 0)
		a = check_sort_a(s);//TODO:2
	else
		return (3);
	if (a != 0)
	{
		if (s->b[0] > 0)
			b = check_sort_b(s);//TODO:3
		else
			b = 0;
	}
	else if (a == 0)
		return (0);
	else if (a == 1 && b == 1)
		return (1);
	else
		return (2);
	return (3);
}
/* check_sort_a
	checks sort for stack a
		returns based on state
			0	-	`size` numbers are in a[0], from `1` to `size`
			1	-	all the numbers in a[0] are +/- 1 in rising sequence
			2	-	all the numbers in a[0] are +/- 1 
			3	-	some of the numbers in a[0] are +/- > 1  */
int		check_sort_a(t_stk *s)
{
	int	gd;//greatest_distance;
	int	seq;
	int	i;
	int	*a;
	int	n;//key number

	i = 0;
	seq = 1;
	a = s->a;
	gd = INT_MIN;
	while (i++ < s->a[0])
	{
		if (i > 1 && a[i] - n > gd)
			gd = a[i] - n;
		if (seq == 1 && i > 1 && a[i] - 1 != n)
			seq = 0;
		n = a[i];
	}
	if (a[0] == s->size && gd == 1 && seq == 1)
		return (0);
	if (gd == 1 && seq == 1)
		return (1);
	if (gd == 1 && seq != 1)
		return (2);
	return (3);
}
/* check_sort_b
	checks sort for stack b
		returns based on state
			0	-	0 numbers are in b[0]
			1	-	all the numbers in b[0] are +/- 1 in falling sequence
			2	-	all the numbers in b[0] are +/- 1 
			3	-	some of the numbers in b[0] are +/- > 1  */
int		check_sort_b(t_stk *s)
{
	int	gd;//greatest_distance;
	int	seq;
	int	i;
	int	*b;
	int	n;//key number

	gd = 0;
	seq = 1;
	i = 0;
	b = s->b;
	while (i++ < s->b[0])
	{
		n = b[i];
		if (i == 1 || b[i] - n > gd)
			gd = b[i] - n;
		if (seq == 1 && i > 1 && b[i] + 1 != n)
			seq = 0;
	}
	if (b[0] == 0)
		return (0);
	if (gd == 1 && seq == 1)
		return (1);
	if (gd == 1)
		return (2);
	return (3);
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
	t_stk		*s;

	s = (*stk);
	//	push 2
	s = push_b(s->a, s->b, s);//TODO:9
	if (s->size >= 5)
		s = push_b(s->a, s->b, s);
	while (check_sort(s) && s->a[0] > 3)
	{
		ft_clear_values(s);
		get_cost(s, s->a, s->b);//TODO:3
		do_moves(s, s->a_cost, s->b_cost, s->c_cost);
		s = push_b(s->a, s->b, s);
		ft_put_struct(s);
	}
	sort_three(&s);
	ft_put_struct(s);
	ft_clear_values(s);
	realign_or_not(s);
	(*stk) = s;
	return ;
}

void		ft_clear_values(t_stk *s)
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

void		do_moves(t_stk *s, int *a, int *b, int *c)
{
	while (get_abs(a[0]) != 0 || get_abs(b[0]) != 0)
	{
		if (a[0] < 0 && b[0] < 0)
			reverse_s(s);
		else if (a[0] > 0 && b[0] > 0)
			rotate_s(s);
		else
		{
			if (a[0] > 0 && (b[0] == 0 || b[0] < 0))
				rotate_a(s, 1);
			else if (a[0] < 0 && (b[0] == 0 || b[0] > 0))
				reverse_a(s, 1);//TODO:10
			if (b[0] > 0 && (a[0] == 0 || a[0] < 0))
				rotate_b(s, 1);
			else if (b[0] < 0 && (a[0] == 0 || a[0] > 0))
				reverse_b(s, 1);//TODO:11
		}
		c[0]--;
	}
}

void		realign_or_not(t_stk *s)
{
	int	*a;
	int	*b;
	int	z;
	
	a = s->a;
	b = s->b;
	z = s->size;
	preen(s);
	ft_put_struct(s);
	while (check_sort(s) && s->a[0] < z)
	{
		printf("check_sort:	%d\n", check_sort(s));
		ft_clear_values(s);
		if (s->a[0] != z && s->b[0] > 0 && s->a[1] > s->b[1])// && !(s->b[0] > 0 && s->a[s->a[0]] > s->b[1]))
			s = push_a(s->a, s->b, s);//TODO:8
		if ((s->a[0] == z && a[1] != 1) || \
		(s->b[0] > 0 && s->a[s->a[0]] > s->b[1]))
			reverse_a(s, 1);
		ft_put_struct(s);
	}
	printf("FINAL\ncheck_sort:	%d\n", check_sort(s));
	return ;
}

/*
is a[1] or a[a[0]] compatible with b[1]?

simplified:

is a[1] bigger than b[1]?
OR
is there no smaller number than a[1] in b[i]?
OR
is a[size] smaller?
OR
is any a[i] smaller than b[1]?
OR
is there any a[i] > b[1]
	AND
	i != 1
OR
if (a[SIZE] > b[1])
{
	while (a[SIZE] > b[1])
		reverse_a(s);
}
*/

void		biggest_bois(t_stk *s, int *guys)
{
	int	big_lad;
	int	big_lass;
	int	size;
	int	i;

	i = 1;
	size = s->b[0];
	big_lad = 1;
	big_lass = INT_MIN;
	while (i++ < size)
	{
		if (s->b[i] > s->b[big_lad])
		{
			big_lad = i;
			big_lass = s->b[i];
		}
	}
	guys[0] = big_lad;
	guys[1] = big_lass;
	return ;
}

//find biggest, bring to top
void		preen(t_stk *s)
{
	int	big_guys[2];

	biggest_bois(s, big_guys);
	while (s->b[1] != big_guys[1])
	{
		if (big_guys[0] <= s->b_mid)
			rotate_b(s, 1);
		else if (big_guys[0] > s->b_mid)
			reverse_b(s, 1);
	}
}

void		final_twist(t_stk *s)
{
	
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

//
/*		get_cost
- finds smaller-than-a[i]-in-B if it exists
- finds bigger-than-a[i]-in-B if it exists
--	calls move-setter
*/
void		get_cost(t_stk *s, int *a, int *b)
{
	int	i;
		
	i = 0;
	while (i++ < a[0])
	{
		s->sm[i] = find_next_smaller(b, a[i]);//TODO:7
		s->bg[i] = find_next_bigger(b, a[i]);//TODO:6
		set_cost(s->sm[i], s->bg[i], s, i);
	}
	s->c_cost = get_collective_cost(s->a_cost, s->b_cost, s->c_cost, s);//TODO:5
	return ;
}

/*		set_bigsmall
- sets move-cost based on
- - if both exist -> cheapest 
- - if one exists -> that one
sets index of target in B for target i in A
*/
//really what it does is:
//- set cost
void		set_cost(int smaller, int bigger, t_stk *s, int i)
{
	int	c;
	int	d;
	
	if (i <= s->a_mid)
		s->a_cost[i] = i - 1;
	else if (i > s->a_mid)
		s->a_cost[i] = i - s->a[0] -1;//changed: added '-1'
	if (smaller != 0 && smaller <= s->b_mid)
		c = (smaller - 1);
	else if (smaller != 0 && smaller > s->b_mid)
		c = (smaller - s->b[0] - 1);//changed: added '-1'
	if (bigger != 0 && bigger <= s->b_mid)
		d = (bigger - 2);
	else if (bigger != 0 && bigger > s->b_mid)
		d = (bigger - s->b[0]);//changed: added '-1'
	if ((bigger == 0 && smaller != 0) || (get_abs(c) <= get_abs(d)))
	{
		s->b_tgt[i] = smaller;
		s->b_cost[i] = c;
	}
	else if ((bigger != 0 && smaller == 0) || (get_abs(c) > get_abs(d)))
	{
		s->b_tgt[i] = bigger;
		s->b_cost[i] = d;
	}
}

/*		compare_cost
- compares the cost of different moves
- selects the one that is cheapest
*/
int		*get_collective_cost(int *a, int *b, int *c, t_stk *s)
{
	int	i;
	int	bargain;
	int	offer;

	i = 0;
	bargain = INT_MAX;
	while (i++ < s->a[0])
	{
		c[i] = get_abs(a[i]) + get_abs(b[i]);
		if (c[i] < bargain || i == 1)
		{// a_cost[i] = 2,  b_cost[i] = -2,  c_cost[i] = 4
			bargain = c[i];//cheapest combination of a + b realignment
			offer = i;
		}
	}
	s->a_tgt[0] = offer;
	s->b_tgt[0] = s->b_tgt[offer];//
	// s->b_tgt[0] = s->b_tgt[offer];//should be "a_tgt[offer]"
	s->a_cost[0] = a[offer];
	s->b_cost[0] = b[offer];
	c[0] = bargain;
	return (c);
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
t_stk		*swap_a(t_stk *s)
{
	int	n;

	n = s->a[1];
	s->a[1] = s->a[2];
	s->a[2] = n;
	write (1, "sa\n", 3);
	return (s);
}

t_stk		*swap_b(t_stk *s)
{
	int	n;

	n = s->b[1];
	s->b[1] = s->b[2];
	s->b[2] = n;
	write (1, "sa\n", 3);
	return (s);
}

t_stk		*swap_s(t_stk *s)
{

	int	n;
	int	m;

	n = s->a[1];
	s->a[1] = s->a[2];
	s->a[2] = n;
	m = s->b[1];
	s->b[1] = s->b[2];
	s->b[2] = m;
	write (1, "ss\n", 3);
	return (s);
}

////		ROTATE:C:
void		rotate_a(t_stk *s, int post)
{
	int	i;
	int	size;
	int	m;
	int	n;

	size = s->a[0];
	i = size;
	m = s->a[size];
	s->a[size] = s->a[1];
	while (i-- > 1)
	{
		n = s->a[i];
		s->a[i] = m;
		m = n;
	}
	if (s->a_cost[0] > 0)
		s->a_cost[0]--;
	if (post == 1)
		write (1, "ra\n", 3);
}

void		rotate_b(t_stk *s, int post)
{
	int	i;
	int	size;
	int	m;
	int	n;

	size = s->b[0];
	i = size;
	m = s->b[size];
	s->b[size] = s->b[1];
	while (i-- > 1)
	{
		n = s->b[i];
		s->b[i] = m;
		m = n;
	}
	if (s->b_cost[0] > 0)
		s->b_cost[0]--;
	if (post == 1)
		write (1, "rb\n", 3);
}

void		rotate_s(t_stk *s)
{
	rotate_a(s, 0);
	rotate_b(s, 0);
	write (1, "rr\n", 3);
}

////		REVERSE:C:

void		reverse_a(t_stk *s, int post)
{
	int	i;
	int	size;
	int	m;
	int	n;

	i = 0;
	size = s->a[0];
	m = s->a[size];
	while (i++ < size)
	{
		n = s->a[i];
		s->a[i] = m;
		m = n;
	}
	if (s->a_cost[0] < 0)
		s->a_cost[0]++;
	if (post == 1)
		write (1, "rra\n", 4);
}

void		reverse_b(t_stk *s, int post)
{
	int	i;
	int	size;
	int	m;
	int	n;

	i = 0;
	size = s->b[0];
	m = s->b[size];
	while (i++ < size)
	{
		n = s->b[i];
		s->b[i] = m;
		m = n;
	}
	if (s->b_cost[0] < 0)
		s->b_cost[0]++;
	if (post == 1)
		write (1, "rrb\n", 4);
}

void		reverse_s(t_stk *s)
{
	reverse_a(s, 0);
	reverse_b(s, 0);
	write (1, "rrr\n", 4);
}

////		SORT:THREE:C:
void		sort_three(t_stk **stk)
{
	int		ops[5];
	int		i;
	t_stk		*sta;
	int		*s;

	i = 0;
	sta = (*stk);
	if (sta->a[0] == 3)
		s = sta->a;
	while (i++ < 4)
		ops[i] = 0;
	if ((s[1] < s[2]) && (s[1] < s[3]) && (s[2] > s[3]))
		ops[0] = 1;
	if ((s[1] > s[2]) && (s[1] < s[3]) &&  (s[2] < s[3]))//bac//sa
		ops[1] = 1;
	if ((s[1] < s[2]) && (s[1] > s[3]) &&  (s[2] > s[3]))//bca//sa/rra
		ops[2] = 1;
	if ((s[1] > s[2]) && (s[1] > s[3]) &&  (s[2] < s[3]))//cab//ra
		ops[3] = 1;
	if ((s[1] > s[2]) && (s[1] > s[3]) &&  (s[2] > s[3]))//cba//rra/sa
		ops[4] = 1;
	sta = three_ops(sta, ops);
	(*stk) = sta;
	return ;
}

t_stk		*three_ops(t_stk *s, int *b)
{
	int	i;

	i = 0;
	while (i++ < 2)
	{
		if ((i == 1 && (b[0] == 1 || b[4] == 1)) || (i == 2 && b[2] == 1))
			reverse_a(s, 1);
		if ((i == 1 && (b[1] == 1 || b[2] == 1)) || \
		(i == 2 && (b[0] == 1 || b[4] == 1)))
			swap_a(s);
		if (i == 1 && b[3] == 1)
			rotate_a(s, 1);
	}
	return (s);
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
		else if ((c >= '0' && c <= '9') && \
		(arg[i] == ' ' || arg[i] == '\0'))
			argn--;
	}
	return (num * mag);
}

//		returns a positive integer
int		get_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
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

//		outputs the structure/stacks
void		ft_put_struct(t_stk *stk)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	while (++i && i <= stk->a[0] || i <= stk->b[0])
	{
		printf("a: ");
		if (i <= stk->a[0])
			printf("%d\t", stk->a[i]);
		else
			printf("-\t");
		printf("b: ");
		if (i <= stk->b[0])
			printf("%d", stk->b[i]);
		else
			printf("-");
		printf("\n");
	}
	printf("\n");
}

///	TODO:	add flag/mode to exit or return control
//		attempt to free array from memory and exit
void		error_end_arr(int *array)
{
	if (array)
		free (array);
	ft_put("Error");
	exit (2);
}

///	TODO:	add flag/mode to exit or return control
//		attempt to free stack from memory and exit
void		error_end_stk(t_stk **nexus)
{
	if (nexus)
		free (nexus);
	ft_put("Error");
	exit (2);
}


//////	WIP:

//



/* PSEUDO:
legend:
a[i]		subject
b[c[i]]	target
b_ops[i]		a_cost
e[i]		b_cost

what I have:
c[i] == COST (not yet index) for number lower-or-higher-than a[i]
the one with the lowest cost wins*/
/* LOGIX
b_ops[i] = 0	NO MOVE
		if both i == 1 and t == 1
b_ops[i] = -1	ROTATE A
		if a[i] in top half and t == 1
b_ops[i] = -2	ROTATE B
		if i == 1 and b[t] in top half
b_ops[i] = -3	REVERSE A
		if a[i] in bottom half and t == 1
b_ops[i] = -4	REVERSE B
		if i == 1 and b[t] in bottom half
b_ops[i] = -5	ROTATE BOTH
		if both a[i] and b[t] are in top half
b_ops[i] = -6	REVERSE BOTH
		if both a[i] and b[t] are in bottom half
b_ops[i] = -7	ROTATE A & REVERSE B
		if a[i] but not b[t] are in top half
b_ops[i] = -8	REVERSE A & ROTATE B
		if a[i] but not b[t] are in bottom half
*/
/* PRIORITY
if (b_ops[i] == 0)
	;//go to push
else if (b_ops[i] == -1)
else if (b_ops[i] == -2)
else if (b_ops[i] == -3)
else if (b_ops[i] == -4)
else if (b_ops[i] == -5)
else if (b_ops[i] == -6)
else if (b_ops[i] == -7)
else if (b_ops[i] == -8)
*/
/* IMPLEMENTATION
1. get index of subject and target
sub = i;
tgt = c[i];
2. compare to size/placement and assign b_ops[i] mode
b_ops[i] = {LOGIX}
3. get index for new target depending on b_ops[i] mode
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
/* D-MODE::DEPRECATED?
if (i == 1 && c[i] == 1)
	b_ops[i] = 0;
else if ((a[0] / 2 + a[0] % 2 > i) && t == 1)
	b_ops[i] = -1;
else if (i == 1 && (b[0] / 2 + b[0] % 2 > c[i]))
	b_ops[i] = -2;
else if ((a[0] / 2 + a[0] % 2 < i) && t == 1)
	b_ops[i] = -3;
else if (i == 1 && (b[0] / 2 + b[0] % 2 < c[i]))
	b_ops[i] = -4;
else if ((a[0] / 2 + a[0] % 2 > i) && (b[0] / 2 + b[0] % 2 > c[i]))
	b_ops[i] = -5;
else if ((a[0] / 2 + a[0] % 2 < i) && (b[0] / 2 + b[0] % 2 < c[i]))
	b_ops[i] = -6;
else if ((a[0] / 2 + a[0] % 2 > i) && (b[0] / 2 + b[0] % 2 < c[i]))
	b_ops[i] = -7;
else if ((a[0] / 2 + a[0] % 2 < i) && (b[0] / 2 + b[0] % 2 > c[i]))
	b_ops[i] = -8;
*/
/* D-MOVE::DEPRECATED?
if (b_ops[i] == -0)
	;//NO MOVE
if (b_ops[i] == -1)
	;//ROTATE A `x` times
if (b_ops[i] == -2)
	;//ROTATE B `y` times
if (b_ops[i] == -3)
	;//REVERSE A `x` times
if (b_ops[i] == -4)
	;//REVERSE B `y` times
if (b_ops[i] == -5)
	;//ROTATE BOTH `x` times
if (b_ops[i] == -6)
	;//REVERSE BOTH `x` times	
if (b_ops[i] == -7)
	;//ROTATE A `x` times & REVERSE B `y` times
if (b_ops[i] == -8)
	;//REVERSE A `x` times & ROTATE B `y` times
*/
/*	2025-04-10 13:04:06	-	program output:
`
c4c1c4% ./push_swap "900 32 55 6434 1 435 -29 442"
pb
pb
pb
a: 8    b: 4
a: 2    b: 3
a: 5    b: 7
a: 1    b: -
a: 6    b: -
pb
a: 2    b: 8
a: 5    b: 4
a: 1    b: 3
a: 6    b: 7
pb
a: 5    b: 2
a: 1    b: 8
a: 6    b: 4
a: -    b: 3
a: -    b: 7
sa
pa
a: 2    b: 8
a: 1    b: 4
a: 5    b: 3
a: 6    b: 7
pa
a: 8    b: 4
a: 2    b: 3
a: 1    b: 7
a: 5    b: -
a: 6    b: -
pa
a: 4    b: 3
a: 8    b: 7
a: 2    b: -
a: 1    b: -
a: 5    b: -
a: 6    b: -
pa
a: 3    b: 7
a: 4    b: -
a: 8    b: -
a: 2    b: -
a: 1    b: -
a: 5    b: -
a: 6    b: -
pa
a: 7    b: -
a: 3    b: -
a: 4    b: -
a: 8    b: -
a: 2    b: -
a: 1    b: -
a: 5    b: -
a: 6    b: -

a: 7    b: -
a: 3    b: -
a: 4    b: -
a: 8    b: -
a: 2    b: -
a: 1    b: -
a: 5    b: -
a: 6    b: -
`

*/
/*	2025-04-10 13:29:14	-		lessons and fixes
WIP	-->	null out values after use, before new calculation

*/