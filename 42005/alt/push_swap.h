/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/30 16:55:35 by akjoerse         ###   ########.fr       */
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
	int				position;
	int				cost_a;
	int				cost_b;
	struct	s_stack	*higher;
	struct	s_stack	*lower;
	struct	s_stack	*prev;
	struct	s_stack	*next;
} t_stack;

//
////		FUNCTIONS:
////		
////		
////		PRIMARY:
//	gets ready made stacks and does magic
void	push_swap(t_stack **stk_a, t_stack **stk_b);

////		ARGUMENTS:
//	returns: [number of (individually valid args)] [0 if invalid] [-1 if small]
int		arg_inspector(int count, char **args);

/* needs subfunctions	::
						::	can use arg check for validation or index of args?
						::	wants to return a char**
						::	
						
						::
 */
char 	**arg_normalizer(int count, char **arg, int members);

////		STACK:
//	assigns the index/position integers
void	stack_indexer(t_stack **stk);

//	assigns the higher/lower, prev/next pointers
void	stack_navigator(t_stack **stk);

//	investigates the stack for malignancy or opportunity
void	stack_inspector(t_stack **stk);

//	converts arguments into stack values
t_stack	*stack_maker(int count, char **arg);

//	an ft_atoi clone, mutated into a push swap creation
////		UTILITY:
long	get_number(char *arg, int argn);

t_stack *find_bottom(t_stack *stack);

void	make_bottom(t_stack **stack, t_stack *new);



#endif
