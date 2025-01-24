/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/23 17:02:36 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

/*		!!!![[[[this is changed for test purposes]]]]!!!!
		2025-01-15 15:50:01
changes:

*/
typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				adjacency;
	struct	s_stack	*higher;
	struct	s_stack	*lower;
	struct	s_stack	*prev;
	struct	s_stack	*next;
} t_stack;

////	FUNCTIONS:
// void		dd(void *(*f)(t_stack **, t_stack **), t_stack **fst, t_stack **scd);
void		dd(void (*f)(t_stack **, t_stack **), t_stack **fst, t_stack **scd);
void		do_double(void (*f)(t_stack **), t_stack **fst);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
//void		do_swap(t_stack **stack);//RETIRED
void		do_sa(t_stack **stack);
void		do_sb(t_stack **stack);
void		do_ra(t_stack **stack);
void		do_rb(t_stack **stack);
void		do_rra(t_stack **stack);
void		do_rrb(t_stack **stack);
int		analyzer(t_stack **stack);
void		sorter(t_stack **stack_a, t_stack **stack_b, int size);
void		dosort_abc(t_stack **stack, t_stack **kcats, int flag);
void		dosort_def(t_stack **stack, t_stack **kcats, int flag);
int		issorted(t_stack **stack_a);
void		push_swap(t_stack **st_a, t_stack **st_b);
t_stack	*stack_maker(int ac, char **av);
t_stack	*new_stack_entry(int value, t_stack *prev);
t_stack	*find_stack_bottom(t_stack *stack);
void		add_to_bottom(t_stack **stack, t_stack *new);
void		give_stack_position(t_stack *stack, int size);
int		get_stack_size(t_stack *stack);
long    	get_number(char *arg, int argn);
int		arg_checker(int ac, char **av);
int		arg_counter(char *av);
int		validity_checker(char a, char b);
void		free_memory(t_stack **stack);
t_stack	*navigator(t_stack **st_a, t_stack **st_b, int size);
t_stack	*smolfind(t_stack *sss, int size);
void		prevfind(t_stack **sss, t_stack **smol, int size);
void		indexize(t_stack **sss, int adj, int siz);
void swap(t_stack *stack);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);
t_stack	*get_penultimate(t_stack *stack);
void		push(t_stack **st_from, t_stack **st_to);
void		sort(t_stack **st_a, t_stack **st_b, int size);
////	:

/*		-previous struct:2025-01-15 15:49:05:-

typedef struct s_stack
{
	int		value;
	int		index;
	int		position;
	int		target;
	int		a_cost;
	int		b_cost;
	struct	s_stack	*next;
} t_stack;

*/
/* typedef struct s_stack
{
	int		value;
	int		index;
	int		position;
	int		target;
	int		a_cost;
	int		b_cost;
	struct	s_stack	*next;
} t_stack; */
/* OLD 
////	FUNCTIONS:
static void	push_swap(int argn, char **argv, int argc);

////	STACK:
void		stack_bottom(t_stack **st, t_stack *val);
t_stack 	*stack_new(int v, int i);
t_stack		*stack_fill(int	argn, char **argv, int argc);

////	GET:
t_stack		*get_bottom(t_stack *stack);
int			get_argn(char *v, int n);
long		get_num(const char *nptr, int n);

////	CHECK:
int			check_num(char *c);
int			check_delta(t_stack *s);
;
////	ERROR:
;
////	SORT:
;
////	INIT:
;
////	UTIL:
;

// commented out 29.12.24 for cleanup
////	FUNCTIONS:
///////	CHECK:
int	validizer(int argc, char **argv);
///////	ERROR:
int		error(t_stack *a_stack, t_stack *b_stack);
void	free_stack(t_stack **st);
///////	GET:
t_stack	*get_bottom(t_stack *st);
int		get_size(t_stack *stack);
// void	get_index(t_stack *stack_a, int size);
int	get_index(t_stack *stack);
int		get_argn(char *v, int n);
///////	SORT:
static void	push_swap(int argn, char **argv, int argc);
///////	CHECK:
int	check_input(int argc, char **argv);
int	check_sort(t_stack *stack);
////	INIT:
t_stack	*stack_fill(int	argn, char **argv, int argc);
t_stack	*stack_make(int	argn, char **argv, int argc);
// t_stack	*stack_make(int argc, char **argv);
t_stack	*stack_init(int argc, char **argv);
void	stack_bottom(t_stack **stack, t_stack *val);
t_stack	*stack_new(int v, int i);
// t_stack	*stack_new(int v);
void	stack_index(t_stack **stack);
////	UTIL:
long	ft_atoi(const char *nptr);
long	get_num(const char *nptr, int n);
////	STACK:
*/

#endif
