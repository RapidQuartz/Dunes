/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/02 20:12:46 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>	
#include <stdlib.h>
#include <limits.h>

# define REDTXT "\033[1;31m"
# define BLUTXT "\033[1;34m"
# define GRNTXT "\033[1;32m"
# define YLWTXT "\033[1;33m"
# define DEFTXT "\033[0m"


typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				size;
	char				clue;
	int				cost_a;
	int				cost_r;
	int				cost_s;
	int				cost_m;
	struct	s_stack	**head;
	struct	s_stack	*low;
	struct	s_stack	*high;
	struct	s_stack	*prev;
	struct	s_stack	*next;
} t_stack;
/* 
typedef struct s_stack
{
	int		value;
	int		index;
	int		pos;
	char		clue;
	int		size;
	int		cost_r;
	int		cost_a;
	t_stack	**head;
	t_stack	*low;
	t_stack	*high;
	t_stack	*prev;
	t_stack	*next;
	int		(*cost_s)(struct t_stack);
} t_stack; */

////		FUNCTIONS:
///////		ACTUAL:

////	MAIN:
//actual/main.c
void		print_stack(t_stack *stack, int i, int argn);

////	COST:
//actual/cost/sum_cost.c
int		ft_cost(t_stack *stack, char cost_n);
int		ft_comcost(t_stack *stack, char cost_n);

////	ARGS:
//actual/args/arg_inspector.c
int		arg_inspector(int argc, char **argv);
int		arg_counter(char *args);
int		arg_checker(char a, char b);
//actual/args/arg_array.c
int		*arg_array(int argc, char **argv, int argn, int *array);

////	STACK:
//actual/stack/stack_maker.c
t_stack	*stack_maker(int argc, char **argv, int argn);
t_stack	*stacker(int *array, int argn, int index, t_stack **head);
t_stack	*create_node(int value, t_stack *prev, int index, int argn);
void		positioner(t_stack **stack, int argn);
t_stack	*highlow_value(t_stack *stack, int argn);
//actual/stack/stack_inspector.c
void		stack_inspector(t_stack **stk);

////	UTIL:
//actual/util/utilities.c
long		get_number(char *arg, int argn);
void		debug(char *str);
//actual/util/memory_utils.c
void		*ft_calloc(size_t nmemb, size_t size);
int		*ft_nzero(int *s, size_t n);
//actual/util/error_handling.c
void		check_minmax(long int value, t_stack **stack);
void		error_handling(t_stack **one, t_stack **other);
void		free_stack(t_stack **stack);

////	CHECK:
//actual/check/sort_checker.c
int		sort_checker(t_stack *stack);

////	COST:
//actual/cost/stack_assay.c
void		stack_assay(t_stack **st, t_stack **ts, int size);
void		check_adjacency(t_stack **st);
t_stack	*nav_ptr_set(t_stack **st, int size);
//cost/sum_cost.c
int		ft_cost(t_stack *stack, char cost_n);
int		ft_comcost(t_stack *stack, char cost_n);
int		ft_sumcost(t_stack *stack, int index);

////	PUSH:SWAP:
//actual/sort/push_swap.c
void		push_swap(t_stack **stack_a, t_stack **stack_b);

////	OPS:
//actual/ops/push.c
void		push_multi(t_stack **sa, t_stack **sb, char dest, int multi);
void		do_pa(t_stack **sa, t_stack **sb);
void		do_pb(t_stack **sa, t_stack **sb);
//actual/ops/rotate.c
void		do_rotate(t_stack **stack_a, t_stack **stack_b, char stk, int dir);
void		rotate_head(t_stack **old, t_stack **new, char stk, int dir);
//actual/ops/swap.c
void		do_sa(t_stack **stack);
void		do_sb(t_stack **stack);
void		do_swap(t_stack **stack);
void		update_head(t_stack **old_head, t_stack *new_head);

////	SORTING:
//actual/sort/stack_sorter.c
void		three_sort(t_stack **stack, t_stack *opt, int count, char clu);
void		one_sort(t_stack **stack);

//actual/sort/clue.c
int		move_counter(t_stack *stack, char clu);
void		clue_find(t_stack **stack, int size);
int		clue_counter(t_stack *stack, char clu);
void		clue_reader_abcdg(t_stack **stack, t_stack *opt, int c, char clu);
void		clue_reader_efhi(t_stack **stack, t_stack *opt, int c, char clu);

////	:

#endif
