/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/11 17:33:31 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>	
#include <stdlib.h>
#include <limits.h>

# define RED "\033[1;31m"
# define BLU "\033[1;34m"
# define GRN "\033[1;32m"
# define YLW "\033[1;33m"
# define DEF "\033[0m"

#ifndef MAX_ARG
# define MAX_ARG 500
#endif

typedef	struct s_snap
{
	unsigned short	*a;
	unsigned short	*b;
	unsigned short	*ac;
	unsigned short	*bc;
	unsigned short	op;
	unsigned short	delta;
	unsigned short	size;
	unsigned short	penalty;
	struct s_snap	*up;
	struct s_ree	*tree;
} t_snap;


/* ideas 2025-03-11 11:25:47
init tree first
mark as zero'th iteration
set *order to initial stack img
populate with movesets
set deltas directly (either skip `delta` var or use combination to determine pruning)
using negatives to mark advantage is also an idea. then calculate:
	is the probation negative?
	is the absolute value of probation lower than others?
probation should also represent the degree to which a branch has changed in entropy
*/
typedef	struct s_ree
{
	short			iteration;
	struct s_snap	*order;
	struct s_snap	*moves[12];
	short			probation[12];
} t_ree;

/* typedef	struct s_valinor
{
	struct s_valinor	*fangorn;
	struct s_ree	*telperion;
	struct s_snap	*laurelin;
} t_valinor; */

t_ree		*new_branch(t_snap *snap, t_ree **head);
void		compare_branch(t_ree *root);
int		climb_tree(t_ree *tree, int i);

int	array_isunsorted(int *a, int n);


////	FUNKY:
t_snap	*push_swap(t_snap **stack);
t_snap	*take_snap(int *array, int argn);

long		get_number(char *arg, int argn);

////	ARGS:
int		*arg_instigator(int argc, char **argv, int *array);
int		arg_counter(char *args);
int		arg_checker(char a, char b);
int		*arg_array(int argc, char **argv, int argn, int *array);

////	INIT:
t_snap	*init_stack(int *array, int argn);
t_snap	*new_snap(t_ree *tree);
t_ree		*init_tree(t_ree *root, t_snap *snap);
t_ree		*branch_tree(t_ree *root);

////	COST:
t_snap	*get_delta(t_snap *snap);
unsigned short	*get_acost(t_snap *snap);
unsigned short	*get_bcost(t_snap *snap);

////	MOVES:
short		move_islegal(t_ree *tree, short op);


////	OPS:
t_snap	*do_push(t_ree *tree, int op);
t_snap	*do_swap(t_ree *tree, int op);
//
unsigned short		*ft_rotate(unsigned short *obj);
t_snap	*do_rotate(t_ree *tree, int op);
t_snap	*do_reverse(t_ree *tree, int op);
unsigned short		*ft_reverse(unsigned short *obj);

////	UTILITY:
void		check_minmax(long int value, t_snap **stack);
int		get_factor(int *array, int argn);

////	ERROR:
void		error_handling(t_snap **one, t_snap **other);
void		debug(char *str);
// void		free_stack(t_snap **stack);
////	:

#endif
