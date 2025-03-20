/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:42:07 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/20 11:26:25 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_arg(int argc, char **argv)
{
	int	i;
	int	num;
	int	argn;

	i = 0;
	argn = 0;
	while (++i < argc)
	{
		num = arg_counter(argv[i]);
		if (num == 0)
			return (0);
		argn += num;
	}
	return (argn);
}

int	arg_counter(char *args)
{
	int	index;
	int	argn;
	char	a;
	int	flag;

	argn = 0;
	index = 0;
	while (args[index] != '\0')
	{
		a = args[index];
		index++;
		flag = arg_checker(a, args[index]);
		if (!flag)
			return (0);
		else if (flag == 2)
			argn++;
	}
	return (argn);
}

int	arg_checker(char a, char b)
{
	if ((a == ' ') && \
	((b == ' ' || b == '-' || b == '+') || \
	(b >= '0' && b <= '9')) || \
	((a == '-' || a == '+') && (b >= '0' && b <= '9')))
			return (1);
	if (a <= '9' && a >= '0')
	{
		if (b >= '0' && b <= '9')
			return (1);
		if ((b == ' ') || (b == '\0'))
			return (2);
	}
	return (0);
}