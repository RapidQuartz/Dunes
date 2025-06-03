/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:25:38 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/13 09:53:58 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define	PUSH_SWAP_H
#
#ifndef	MAX_DISPLAY
# define	MAX_DISPLAY 50
#endif
#
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#
typedef	struct	s_stk
{
	size_t		size;
	int			*a;
	int			*b;
	int			a_mid;
	int			b_mid;
	int			*a_tgt;
	int			*b_tgt;
	int			*a_mov;
	int			*b_mov;
	int			*ops;
	int			*ops;
	int			*a_cost;
	int			*b_cost;
	int			*c_cost;
	int			*sm;
	int			*bg;
	int			a_sort;
	int			b_sort;
	int			c_sort;
	// int			*ops;
	int			step;
	char			*p_op;
} t_stk;
#

#

#

#
#endif