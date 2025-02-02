/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:56:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/02 09:51:54 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_number(char *arg, int argn)
{
	//debug("in get_number()");
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

void	check_minmax(long int value, t_stack **stack)
{
	//debug("in check_minmax()");
	if (value > INT_MAX || value < INT_MIN)
	{
		if (stack || (*stack) != NULL)
			error_handling(stack, NULL);
		else
			error_handling(NULL, NULL);
	}
}

t_stack	*get_penultimate(t_stack *stack)
{
	//debug("in get_penultimate()");
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

int		get_absolute(int rel)
{
	//debug("in get_absolute()");
	if (rel < 0)
		rel *= -1;
	return (rel);
}