/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/01 19:02:46 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>	
#include <stdlib.h>
#include <limits.h>

/* the stack
?? what variables are useful
-- value
-- initial index
-- positional index
-- pointer to prev
-- pointer to next
-- pointer to ??? - (prev. iteration had higher/lower, but unknown if useful)
-- pointer to ??? - (prev. iteration had higher/lower, but unknown if useful)
-- "cost" variable B - (A/B are arbitrary)
-- "cost" variable A - (A/B are arbitrary)
-- "memory" variable M - stores information about transaction
*/
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

/* 	struct	s_stack	*higher;
	struct	s_stack	*lower; */
//
////		FUNCTIONS:
////		
////		
////		PRIMARY:
//	gets ready made stacks and does magic
void	push_swap(t_stack **stack_a, t_stack **stack_b, int members);

////		ARGUMENTS:
//	returns: [number of (individually valid args)] [0 if invalid] [-1 if small]
int		arg_inspector(int count, char **args);

/* needs subfunctions	::
						::	can use arg check for validation or index of args?
						::	wants to return a char**
						::	
						
						::
 */
int	arg_counter(char *args);
char 	**arg_normalizer(int count, char **arg, int members);
t_stack	*arg_stacker(int value, t_stack *prev);

////		STACK:
//	assigns the index/position integers
void	stack_indexer(t_stack **stk);

//	assigns the higher/lower, prev/next pointers
void	stack_navigator(t_stack **stk);

//	investigates the stack for malignancy or opportunity
void	stack_inspector(t_stack **stk);

//	calls various functions to process stack
t_stack	*stack_maker(int count, char **arg, int members);
//	converts arguments into stack values
t_stack	*stack_filler(int count, char **arg, int members);

//	adds info like position, next/prev pointers etc
void	stack_finisher(t_stack **stack, t_stack **lowest, int members);
void	stack_positioner(t_stack **stack, int members);
t_stack	*find_top(t_stack *stack);
t_stack	*find_lowest(t_stack *stack);
//	an ft_atoi clone, mutated into a push swap creation
////		UTILITY:
int	sort_checker(t_stack *stack);
long	get_number(char *arg, int argn);
void	check_minmax(long int value, t_stack **stack);

t_stack *find_bottom(t_stack *stack);
void		make_bottom(t_stack **stack, t_stack *new);
void		error_handling(t_stack **one, t_stack **other);
void		free_memory(t_stack **stack);
void		debug(char *str);
void		debug_print(t_stack *stack, char *msg);

void		do_swap(t_stack *stack);
void		do_sa(t_stack **stack);
void		do_sb(t_stack **stack);

void	do_ra(t_stack **stack);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);

t_stack	*get_penultimate(t_stack *stack);


#endif
