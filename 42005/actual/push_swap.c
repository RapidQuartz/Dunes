/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:46 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/20 13:36:25 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	algo(t_n **a, t_n **b);
t_n	*new_st(t_n *s, t_n *n);
void	push_b(t_n **a, t_n **b);

void	push_swap(t_n **sta, t_n **stb)
{
	int	i;
	t_n	*s;
	t_n	*a;
	
	i = 0;
	a = (*sta);
	algo(sta, stb);
	printf("\n");
	return ;
}

void	algo(t_n **a, t_n **b)
{
	push_b(a, b);
	push_b(a, b);
}
