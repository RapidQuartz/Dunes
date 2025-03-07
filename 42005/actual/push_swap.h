/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/07 14:28:33 by akjoerse         ###   ########.fr       */
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
/* alt stack
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
//
/* tree for new approach */

typedef struct s_tree
{
	short				rings;//'steps' so the first are 
	short				**trunk;//stack projection
	char				**branch;//ALL movesets
	short				**leaf;//entropy measurement
	char				**seed;//5 candidate movesets
	struct	s_tree	**roots;//head basically
	struct	s_tree	*next;
} t_tree;

typedef	struct s_byte
{
	unsigned char	*a;
	unsigned char	*b;
	struct s_byte	*next;
} t_byte;

////		TREEDEFS:

#ifndef MAX_MOVES
# define MAX_MOVES 5507
#endif
#ifndef MAX_NUM
# define MAX_NUM 500
#endif


////		TREEFUNCTIONS:

////	FOREST:
void		forest(t_stack **stack_a, t_stack **stack_b);
////	FT:PROTO:
//	'forest' introduces the new project to the stack
void		forest(t_stack **stack_a, t_stack **stack_b);
//	'worldtree' allocates memory according to stack size
t_byte	*worldtree(t_byte *tree, short acorn);
//	'baumschule' dispatches initializing functions
void		baumschule(t_byte **tree, short acorn, t_stack **stack);
//	'imprinting' currently not in use
t_byte	*imprinting(t_byte **tree, short acorn, t_stack **stack);
//	'init_sbyte' makes all variables 0 except for info at ab[]
void		init_sbyte(t_byte **tree, short acorn);
//	'transcribe_sbyte' fills initial t_byte with stack info, liek a snapshot
void		transcribe_sbyte(t_byte **tree, short acorn, t_stack **stack);
//	'init_branch' initializes the next branch, setting tree->next to the branch;
void		init_branch(t_byte **tree, t_byte *branch, char ops);
//	'perform_ops' attempts to perform the operation on the snapshot
t_byte	*perform_ops(t_byte *branch, t_byte *shoot, char ops);
//	'perform_a' tries to implement the "pa" operation
//pa	--		{ii{mm}[aa+1]/{cc}[bb#1]{pp}[aa#1]/{mm}[bb-1]/{uu}[aa+1]{uu}[bb-1]ee}
///neo=		
t_byte	*perform_a(t_byte *branch, t_byte *shoot, char ops);
//	'perform_b' tries to implement the "pb" operation
//pb	--		{ii{mm}[bb+1]/{cc}[aa#1]{pp}[bb#1]/{mm}[aa-1]/{uu}[aa-1]/{uu}[bb-1]ee}/
///neo=		
t_byte	*perform_b(t_byte *branch, t_byte *shoot, char ops);
//	'perform_c' tries to implement the "sa" operation
//sa	--		{ii/{cc}[aa#2]/{cc}[aa#1]/{pp}[aa#1]/{pp}[aa#2]//ee}
///neo=		
t_byte	*perform_c(t_byte *branch, t_byte *shoot, char ops);
//	'perform_d' tries to implement the "sb" operation
//sb	--		{ii/{cc}[bb#2]/{cc}[bb#1]/{pp}[bb#1]/{pp}[bb#2]/ee}
///neo=		
t_byte	*perform_d(t_byte *branch, t_byte *shoot, char ops);
//	'perform_e' tries to implement the "ss" operation
//ss	--		{ii/{sa}/{sb}/ee}
///neo=		
t_byte	*perform_e(t_byte *branch, t_byte *shoot, char ops);
//	'perform_f' tries to implement the "ra" operation
//ra	--		{ii/{cc}[aa#1]/{mm}[aa-1]/{pp}[aa#L]/ee}
///neo=		
t_byte	*perform_f(t_byte *branch, t_byte *shoot, char ops);
//	'perform_g' tries to implement the "rb" operation
//rb	--		{ii/{cc}[bb#1]/{mm}[bb-1]/{pp}[bb#L]/ee}
///neo=		
t_byte	*perform_g(t_byte *branch, t_byte *shoot, char ops);
//	'perform_h' tries to implement the "rr" operation
//rr	--		{ii/{ra}/{rb}/ee}
///neo=		
t_byte	*perform_h(t_byte *branch, t_byte *shoot, char ops);
//	'perform_i' tries to implement the "rra" operation
//rra	--		{ii/{cc}[aa#L]/{mm}[aa+1]/{pp}[aa#1]/ee}
///neo=		
t_byte	*perform_i(t_byte *branch, t_byte *shoot, char ops);
//	'perform_j' tries to implement the "rrb" operation
//rrb	--		{ii/{cc}[bb#L]/{mm}[bb+1]/{pp}[bb#1]/ee}
///neo=		
t_byte	*perform_j(t_byte *branch, t_byte *shoot, char ops);
//	'perform_k' tries to implement the "rrr" operation
//rrr	--		{ii/{rra}/{rrb}/ee}
///neo=		
t_byte	*perform_k(t_byte *branch, t_byte *shoot, char ops);

//	''
//	

////	PLANT: begins branching out
void		plant_tree(t_byte **tree, short acorn);
//	legal actions?
short		islegal(t_byte *tree, char ops);
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
