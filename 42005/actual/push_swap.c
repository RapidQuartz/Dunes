/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:46 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/18 17:08:52 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_n **st)
{
	int	i;
	t_n	*s;
	
	i = 0;
	s = (*st);
	//DO IT//
	while (s->siz > i++)
	{
		if (s->a != 0)
			printf("\n");
		if (s->b != 0)
			printf("\n");
		printf("\n");
	}
	return ;
}