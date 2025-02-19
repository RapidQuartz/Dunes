/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_inspector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:29:25 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/19 15:13:25 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//	takes: arguments and their count
//	returns: [`int > 0` - no of valid arguments][`0` - invalid arguments]

int		arg_inspector(int argc, char **argv)
{
	int	index;
	int	num;
	int	argn;

	index = 1;
	argn = 0;
	while (index < argc)
	{
		num = arg_counter(argv[index]);
		if (num == 0)
			return (0);
		argn += num;
		index++;
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

//	takes two consecutive characters, allows for whitespace and symbols
//	returns `1` for valid characters
//	returns `2` for valid end of number
//	returns `0` for invalid characters
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
