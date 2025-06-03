/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:25:38 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/22 20:45:33 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
#

typedef struct s_stk
{
	int			steps;
	int			size;
	int			*a;
	int			*b;
	int			a_mid;
	int			b_mid;
	int			*a_tgt;
	int			*b_tgt;
	int			*a_mov;
	int			*b_mov;
	int			*ops;
	int			*a_cost;
	int			*b_cost;
	int			*c_cost;
	int			*sm;
	int			*bg;
	int			a_sort;
	int			b_sort;
	int			c_sort;
}	t_stk;
// main.c
int		main(int argc, char **argv);
void	push_swap(t_stk *stack);
void	exec_turk(t_stk *s);
void	sort_three(t_stk *s);
t_stk	*three_ops(t_stk *s, int *ops);
// init.c
long	arg_to_int(char *arg, int argn);
int		*arg_to_arr(int *arr, int *argn, char **argv);
int		*arr_normalizer(int *arr, int siz);
t_stk	*arr_to_stk(int *arr, t_stk *s);
int		*arr_transcriber(int *arr, int *brr, int siz);
// array.c
int		*ft_make_null_arr(int n);
int		*ft_argn_map(int *argn_map, int argc, char **argv);
// turk.c
void	do_moves(t_stk *s, int *a, int *b, int *c);
void	realign_or_not(t_stk *s);
void	realign_b(t_stk *s);
int		final_alignment(t_stk *s);
// push_swap.c
t_stk	*push_a(int *a, int *b, t_stk *c);
t_stk	*push_b(int *a, int *b, t_stk *c);
t_stk	*swap_a(t_stk *s);
t_stk	*swap_b(t_stk *s);
t_stk	*swap_s(t_stk *s);
// rotate.c
void	rotate_a(t_stk *s, int post);
void	rotate_b(t_stk *s, int post);
void	rotate_s(t_stk *s);
// reverse.c
void	reverse_a(t_stk *s, int post);
void	reverse_b(t_stk *s, int post);
void	reverse_s(t_stk *s);
// cost.c
void	get_cost(t_stk *s, int *a, int *b);
void	set_cost(int smaller, int bigger, t_stk *s, int i);
void	set_target(t_stk *s, int i, int target, int cost);
int		*get_collective_cost(int *a, int *b, int *c, t_stk *s);
// check.c
bool	illegal(char *arg, int i);
bool	arg_duplicate(int *arr);
int		*arg_count(char *arg, int *argn, int j);
bool	unsorted(t_stk *s);
bool	ifnull(t_stk *s);
// find.c
int		find_next_bigger(int *s, int n);
int		find_next_smaller(int *s, int n);
void	find_bigs(t_stk *s, int *arr);
int		set_alignment(t_stk *s);
// util.c
int		get_abs(int num);
void	ft_put(char *str);
void	ft_put_struct(t_stk *stk);
void	ft_clear_values(t_stk *s);
void	ft_liberation(t_stk **s);
// error.c
void	error_end_arr(int *array);
void	error_end_stk(t_stk **stack);

#endif