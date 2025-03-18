/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:29:54 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/18 16:30:09 by akjoerse         ###   ########.fr       */
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