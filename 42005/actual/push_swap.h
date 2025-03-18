/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:30:20 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/18 17:12:49 by akjoerse         ###   ########.fr       */
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
	int		a;
	int		asz;
	int		b;
	int		bsz;
	int		siz;
	struct s_n	*n;
} t_n;




///
///
///
///	INIT:
t_n	*make_st(int *arr);

///	ARG:
int	count_arg(int argc, char **argv);
int	arg_counter(char *args);
int	arg_checker(char a, char b);

///	ARR:
int	*make_arr(int argc, char **argv, int argn, int *arr);
void	check_minmax(long int value, t_n **st);
int	*normalizer(int *arr, int argn);

///	UTIL:
long	get_number(char *arg, int argn);

///	PS:
void	push_swap(t_n **st);

#endif