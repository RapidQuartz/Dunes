/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/10 18:16:50 by akjoerse         ###   ########.fr       */
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
	struct s_ree	*prev;
} t_snap;

typedef	struct s_ree
{
	struct s_snap	*order;
	struct s_snap	*moves[12];
} t_ree;

t_ree		*new_branch(t_snap *snap, t_ree **head);



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
t_snap	*init_stack(unsigned short *array, int argn);
t_snap	*new_snap(t_ree *tree);
t_ree		*init_tree(t_snap *snap);
t_ree		*make_tree(t_snap *stack, t_ree *root);

////	COST:
t_snap	*get_delta(t_snap *snap);
short		*get_acost(t_snap *snap);
short		*get_bcost(t_snap *snap);

////	MOVES:
short		move_islegal(t_snap *order, short op);


////	OPS:
t_snap	*do_push(t_ree *tree, int op);
t_snap	*do_swap(t_ree *tree, int op);
//
short		*ft_rotate(unsigned short *obj);
t_snap	*do_rotate(t_ree *tree, int op);
t_snap	*do_reverse(t_ree *tree, int op);
short		*ft_reverse(unsigned short *obj);

////	UTILITY:
void		check_minmax(long int value, t_snap **stack);
int		get_factor(int *array, int argn);

////	ERROR:
void		error_handling(t_snap **one, t_snap **other);
void		debug(char *str);
// void		free_stack(t_snap **stack);
////	:

#endif
