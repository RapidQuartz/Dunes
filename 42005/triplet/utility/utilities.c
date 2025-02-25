/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:56:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/24 18:55:42 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	get_number(char *arg, int argn)
{
	int		i;
	int		neg;
	long int	num;

	i = 0;
	while (argn && arg[i] != '\0')
	{
		neg = 1;
		num = 0;
		if (argn == 1 && arg[i] == '-')
			neg *= -1;
		if (arg[i] == '+' || arg[i] == '-' || arg[i] == ' ')
			i++;
		while (arg[i] <= '9' && arg[i] >= '0')
		{
			if (argn == 1)
				num += (arg[i] - '0');
			i++;
			if ((arg[i] != '\0') && (arg[i] != ' ') && argn == 1)
				num *= 10;
		}
		if (arg[i] == ' ' || arg[i] == '\0')
			argn--;
	}
	return (num * neg);
}



t_stack	*find_top(t_stack *stack)
{
	t_stack	*top;
	int	i = 0;
	debug(YLWTXT"inside find stack top"DEFTXT);
	
	top = stack;
	if (top->prev != NULL)
	{
		while (top->prev != NULL && i < 10)
		{
			i++;
			top = top->prev;
			printf("<%d>\n", i);
			DEFTXT;
		}
	}
	debug(GRNTXT"done with find top"DEFTXT);//SEGFAULT
	return (top);
}

int		get_absolute(int rel)
{
	//debug("in get_absolute()");
	if (rel < 0)
		rel *= -1;
	return (rel);
}

void		ouroboros(t_stack **snek, int argn)
{
	t_stack	*bottom;
	if (snek != (*snek)->head && (*snek)->next == NULL)
		bottom = (*snek);
	snek = (*snek)->head;
	(*snek)->prev = bottom;
	bottom->next = (*snek);
	return ;
}