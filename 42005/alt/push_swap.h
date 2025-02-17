/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/17 15:09:24 by akjoerse         ###   ########.fr       */
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
	int				bucket;
	int				cost_a;
	int				cost_b;
	struct	s_stack	*prev;
	struct	s_stack	*next;
} t_stack;

////		FUNCTIONS:
////		TODO:	make some structure here bwoi


//		adds info like position, next/prev pointers etc
t_stack	*find_lowest(t_stack *stack);

////		ERROR:
void		error_handling(t_stack **one, t_stack **other);
void		free_memory(t_stack **stack);

////		UTILITY:
//		an ft_atoi clone, mutated into a push swap creation
long		get_number(char *arg, int argn);
void		check_minmax(long int value, t_stack **stack);
t_stack	*find_penultimate(t_stack *stack);
int		get_absolute(int rel);
t_stack	*find_top(t_stack *stack);//?? where ??
t_stack	*find_bottom(t_stack *stack);//?? where ??

////		PRIMARY:
//		gets ready made stacks and does magic
void		push_swap(t_stack **stack_a, t_stack **stack_b, int members);

////		ARGUMENTS:
t_stack	*arg_stacker(int value, t_stack *prev);
int		arg_counter(char *args);
int		arg_inspector(int count, char **args);

////		STACK:
void		make_bottom(t_stack **stack, t_stack *new);
//		investigates the stack for malignancy or opportunity
void		stack_inspector(t_stack **stk);
//		assigns the index/position integers
void		stack_indexer(t_stack **stk);
void		stack_positioner(t_stack **stack, int members);
void		stack_finisher(t_stack **stack, t_stack **lowest, int members);
//		calls various functions to process stack
t_stack	*stack_maker(int count, char **arg, int members);
//		converts arguments into stack values
t_stack	*stack_filler(int count, char **arg, int members);

////		DEBUG:
void		debug(char *str);
void		debug_print(t_stack *stack, char *msg);

////		OPERATIONS:
void		do_swap(t_stack *stack);
void		do_twoswap(t_stack *stack);
void		do_sa(t_stack **stack);
void		do_sb(t_stack **stack);
void		do_ra(t_stack **stack);
void		do_rra(t_stack **stack);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
////			TODO:
// void		do_rb(t_stack **stack);
// void		do_rr(t_stack **stack_a, t_stack **stack_b);
// void		do_rrb(t_stack **stack);
// void		do_rrr(t_stack **stack_a, t_stack **stack_b);

////		SORTING:
int		sort_checker(t_stack *stack);
void		sort_cost(t_stack **stack_a, int size);
void		sort_three(t_stack **stack_a, t_stack **stack_b, int members);
void		swap_xy(t_stack **stack_a);
void		swap_yz(t_stack **stack_a);

////		COST:
void		cost_check(t_stack **stack);
int		count_samecost(t_stack *stack_a);
void		samecost_decider(t_stack **stack_a, int count, int same);
void		set_cost(t_stack **stack_a, t_stack **stack_b, int size);
void		sort_costcompare(t_stack **stack_a, t_stack **stack_b, int size);
void		sort_positivecost(t_stack **stack_a);
void		sort_bigbee(t_stack **stack_a);



////		LEGACY:	DISUSED:
// char		**arg_normalizer(int count, char **arg, int members);//NOT PRESENT
// void		stack_navigator(t_stack **stk);
#endif
