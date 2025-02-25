/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/25 16:36:22 by akjoerse         ###   ########.fr       */
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
	int				*cost_a;
	int				*cost_b;
	struct	s_stack	**head;
	struct	s_stack	*low;
	struct	s_stack	*high;
	struct	s_stack	*prev;
	struct	s_stack	*next;
} t_stack;

////		FUNCTIONS:
////		TODO:	make `cost_*` pointers for positioning.


//		adds info like position, next/prev pointers etc
t_stack	*find_lowest(t_stack *stack);

////		ERROR:
void		error_handling(t_stack **one, t_stack **other);
void		free_memory(t_stack **stack);

////		UTILITY:
//		an ft_atoi clone, mutated into a push swap creation
long		get_number(char *arg, int argn);
void		check_minmax(long int value, t_stack **stack);
int		get_absolute(int rel);

void		*ft_calloc(size_t nmemb, size_t size);
int		**ft_nzero(int **s, size_t n, size_t m);

////		PRIMARY:
//		gets ready made stacks and does magic
void		push_swap(t_stack **stack_a, t_stack **stack_b, int members);

////		ARGUMENTS:
t_stack	*stack_stacker(int value, t_stack *prev);
int		arg_counter(char *args);
int		arg_inspector(int argc, char **argv);
int		arg_checker(char a, char b);

////		STACK:
t_stack	*stacker(int *array, int argn, t_stack **head, int index);
t_stack	*create_node(int value, t_stack *prev, int index, int argn);
void		ouroboros(t_stack **snek, int argn);
t_stack	*highlow_value(t_stack *stack, int argn);

//		investigates the stack for malignancy or opportunity
void		stack_inspector(t_stack **stk);
//		assigns the index/position integers
void		stack_indexer(t_stack **stk);
void		positioner(t_stack **stack, int argn);
void		stack_finisher(t_stack **stack, t_stack **lowest, int members);
//		calls various functions to process stack
t_stack	*stack_maker(int argc, char **argv, int stk_size);
//		converts arguments into stack values
t_stack	*stack_filler(int argc, char **argv, int stk_size);
//
t_stack	*stack_array(int *array, int argn);
//		uses an array to make stack in the right direction
//
//		sets higher/lower pointers for stack
void		stack_hilofinder(t_stack **stack, int size);
int		stack_hilosetter(t_stack *stack, t_stack *next, int size);

//	[	DENIM	EDITION	]
int		set_argn(int argc, char **argv);
t_stack	*set_head(int value, t_stack *last, t_stack *head);

////		ARGUMENTS:
int		*arg_array(int argc, char **argv, int argn, int *array);

////		DEBUG:
void		debug(char *str);
void		debug_print(t_stack *stack, char *msg);
void		debug_cost_print(int **num, int size);

////		BUCKET:
void		set_bucket(t_stack *stack);

////		OPERATIONS:
void		do_swap(t_stack *stack);
void		rotate_head(t_stack **stack);
void		reverse_rotate_head(t_stack **stack);
////		CO:OPS:
void		sa(t_stack **t);
void		sb(t_stack **t);
void		ss(t_stack **t, t_stack **s);
void		ra(t_stack **t);
void		rb(t_stack **t);
void		rr(t_stack **t, t_stack **s);
void		rra(t_stack **t);
void		rrb(t_stack **t);
void		rrr(t_stack **t, t_stack **s);
void		pa(t_stack **t, t_stack **s);
void		pb(t_stack **t, t_stack **s);

////		SORTING:
int		sort_stack(t_stack **stack_a, t_stack **stack_b);
void		sort_trip(t_stack **st, t_stack **ts, char cl);
void		sort_doub(t_stack **st, t_stack **ts, char cl);
void		sort_sing(t_stack **st, t_stack **ts, char cl);

////		ASSAY:
void		stack_assay(t_stack **st, t_stack **ts, int size);
void		is_adjacent(t_stack **st);
void		check_adjacency(t_stack **st);
t_stack	*nav_ptr_set(t_stack **st, int size);
void		cost_get(t_stack **st, t_stack **ts, int size, int **num);


int		sort_checker(t_stack *stack);
void		sort_cost(t_stack **stack_a, int size);
void		sort_three(t_stack **stack_a, t_stack **stack_b, int members);
void		swap_xy(t_stack **stack_a);
void		swap_yz(t_stack **stack_a);

////		COST:
void		trip_cost_get(t_stack **st);
void		doub_cost_get(t_stack **st);
void		sing_cost_get(t_stack **st);


////		LEGACY:	DISUSED:
#endif
