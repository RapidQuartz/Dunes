/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/09 19:38:55 by akjoerse         ###   ########.fr       */
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
	unsigned short	*c;
	unsigned short	*d;
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
int		*arg_instigator(int argc, char **argv, int *array);
int		arg_counter(char *args);
int		arg_checker(char a, char b);
int		*arg_array(int argc, char **argv, int argn, int *array);
long		get_number(char *arg, int argn);

////	UTILITY:
void	check_minmax(long int value, t_snap **stack);
int	get_factor(int *array, int argn);

////	ERROR:
void	error_handling(t_snap **one, t_snap **other);
void		free_stack(t_snap **stack);
////	:

#endif
