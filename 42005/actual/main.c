/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:38:31 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/31 14:25:11 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		*arr;
	int		i;
	int		argn;
	
	if (argc < 2)
		return (-1);
	arr = NULL;
	stack = NULL;
	stack_genesis(&stack, make_arr(argc, argv, count_arg(argc, argv), arr));
	if (stack == NULL || stack->a == NULL || stack->b == NULL)
		d_end();
	else
		push_swap(&stack);
	d_print_stack(stack);
	d_end();
}


void		d_print_stack(t_stack *s)
{
	int	i;

	i = 1;
	if (s == NULL || s->e != 0)
		return ;
	while (i <= s->a[0] || i <= s->b[0])
	{
		if (i <= s->a[0])
			printf("a: %d\t", s->a[i]);
		else
			printf("a: --\t");
		if (i <= s->b[0])
			printf("b: %d\n", s->b[i]);
		else
			printf("b: --\n");
		i++;
	}
}
