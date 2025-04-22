/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:03 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/21 15:43:26 by akjoerse         ###   ########.fr       */
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
void	error_end_stk(t_stk **s)
{
	if (s)
		free (s);
	ft_put("Error");
	exit (2);
}

//		FOR DEBUG:	outputs the structure/stacks
void	ft_put_struct(t_stk *s)
{
	int	i;

	i = 1;
	while (i <= s->a[0] || i <= s->b[0])
	{
		printf("a: ");
		if (s->a[0] == 0 || s->a[0] < i)
			printf("-\t");
		else if (i <= s->a[0])
			printf("%d\t", s->a[i]);
		printf("b: ");
		if (s->b[0] == 0 || s->b[0] < i)
			printf("-");
		else if (i <= s->b[0])
			printf("%d", s->b[i]);
		printf("\n");
		i++;
	}
	printf("\n");
}

//s -- print stack
//c -- show move count at end
void	do_flag(t_stk *s)
{
	if (!s || s == NULL || !s->flag || s->flag == 0)
		return ;
	else if (s->flag == 1 || s->flag == 3)
		ft_put_struct(s);
	if (!unsorted(s) && s->flag >= 2)
		ft_put_steps(s->steps);
}


/* how many digits for int
then print one by one
	by:
	looping through
	divide by 10 to power of number of digits */
void	ft_put_steps(int steps)
{
	char	c;
	
	if (steps > 10)
	c = (steps % 10) + '0';
	write (1, &c, 1);
}
/* hypo
s->steps == 6342

while (s->steps - num > 0)
steps = s->steps
steps == 6342
steps/10 == 634
steps/10 == 63
steps/10 == 6
write ()
steps = 


 */