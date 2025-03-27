/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:30:20 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/27 12:46:45 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>	
#include <stdlib.h>
#include <limits.h>

typedef	struct	s_n
{
	int		v;
	struct s_n	**h;
	struct s_n	*i;
	struct s_c	*c;
	struct s_n	*p;
	struct s_n	*n;
} t_n;

typedef	struct	s_c
{
	t_n		**cap;
	t_n		*ego;
	t_n		*tgt;
	char		stk;
	int		mov;
	int		dif;
	int		dis;
	int		rot;
	int		rev;
} t_c;


///
///	COST:
void		init_cost(t_n **sta, t_n **stb, t_c *c_a, t_c *c_b);
void	get_cost(t_n *node_a, t_n *node_b, t_c *cost_a, t_c *cost_b);
///
void		find_move(t_n **stack_a, t_n **stack_b);
///	SORT:
void	sort_stack(t_n **sta, t_n **stb);
///
int	select_push_node(t_n **stack);
///
///	TURK:
void	exec_turk(t_n **sta, t_n **stb);
void	next_find(t_n **sta, t_n **stb);
void	next_align(t_n **sta, t_n **stb, t_n *next);
void	next_push(t_n **sta, t_n **stb, t_n *next);
void	last_push(t_n **sta, t_n **stb);
void	last_align(t_n **sta, t_n **stb);

///	DEBUGPRINTSTACKS:
void	d_print_twostack_values(t_n **sta, t_n **stb, int mode);


///	INIT:
//`init_stack_a` :	initializes the first stack from the int array of arguments
t_n	*init_stack_a(int *arr);
t_n	*init_stack_b(void);
//`new_node` :	allocates new stacks and optionally sets prev/next pointers
t_n	*new_node(t_n *stack, t_n *prev);
//`info_node_a` :	keeps the size of the stack, is pointed to by all in stack
void	info_node_a(t_n **head, int size);
t_n	**head_node(t_n *new, t_n **head);


///	ARG:
int	count_arg(int argc, char **argv);
int	arg_counter(char *args);
int	arg_checker(char a, char b);

///	ARR:
int	*make_arr(int argc, char **argv, int argn, int *arr);
void	check_minmax(long int value, t_n **st);
int	*arg_normalizer(int *arr, int siz);
int	*arr_transcriber(int *arr, int *brr, int siz);

///	UTIL:
long	get_number(char *arg, int argn);

///	DEBUG:
void		debug(char *str);
void		d_end(void);
void		d_print_stack(t_n **sta);
void		d_print_cost(t_c *cst);
void		d_print_array(int *arr);


///	STACKS:
void	info_node_a(t_n **head, int size);
t_n	*info_node_b(void);


///	PS:
void	push_swap(t_n **stack_a, t_n **stack_b);
void	push(t_n **stack_src, t_n **stack_dst);


///	SORT:
void	sort_three(t_n **sta);
void	sort_stack(t_n **sta, t_n **stb);


///	CHECK:
int	stack_is_sorted(t_n *sta);

///	OPS:
void	reverse(t_n **sta);
void	rotate(t_n **sta);
void	swap(t_n **sta);

void	push(t_n **stack_src, t_n **stack_dst);



#endif