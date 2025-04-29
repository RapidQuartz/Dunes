/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:03 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/22 20:55:52 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//		attempts to free array from memory and exit
void	error_end_arr(int *array)
{
	if (array)
		free (array);
	write (2, "Error\n", 6);
	exit (2);
}

//		attempts to free stack from memory and exit
void	error_end_stk(t_stk **stack)
{
	if (stack)
		free (stack);
	write (2, "Error\n", 6);
	exit (2);
}
