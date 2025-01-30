/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:36:09 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/30 16:59:59 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Return values	::	[0 - all well][1 - too few args][2 - too many args]
// order of business::	[copy atoi][copy PARTS of makestack][select mode fwd]
int	main(int count, char **arg)
{
	int	members;
	t_stack	*stack;
	
	if (count < 2)
		return (1);
	if (count > 100)
		return (2);
	members = arg_inspector(count, arg);
	stack = stack_maker(count, arg);
	
	return (0);
}

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