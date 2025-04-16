/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:03 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/16 12:40:58 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//		attempts to free array from memory and exit
void	error_end_arr(int *array)
{
	if (array)
		free (array);
	ft_put("Error");
	exit (2);
}

//		attempts to free stack from memory and exit
void	error_end_stk(t_stk **nexus)
{
	if (nexus)
		free (nexus);
	ft_put("Error");
	exit (2);
}

//		FOR DEBUG:	outputs the structure/stacks
void	ft_put_struct(t_stk *stk)
{
	int	i;

	i = 1;
	while (i <= stk->a[0] || i <= stk->b[0])
	{
		printf("a: ");
		if (stk->a[0] == 0 || stk->a[0] < i)
			printf("-\t");
		else if (i <= stk->a[0])
			printf("%d\t", stk->a[i]);
		printf("b: ");
		if (stk->b[0] == 0 || stk->b[0] < i)
			printf("-");
		else if (i <= stk->b[0])
			printf("%d", stk->b[i]);
		printf("\n");
		i++;
	}
	printf("\n");
}
