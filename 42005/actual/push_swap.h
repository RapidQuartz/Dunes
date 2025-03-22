/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:30:20 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/22 18:55:41 by akjoerse         ###   ########.fr       */
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
	int		val;
	int		ssz;
	int		siz;
	struct s_n	*n;
} t_n;




///
///
///
///	INIT:
t_n	*make_st(int *arr);
t_n	*new_st(t_n *s, t_n *n);


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
void		d_arrayprint(int *arr);

///	PS:
void	push_swap(t_n **sta, t_n **stb);

#endif