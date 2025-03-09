/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:11:46 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/09 19:00:07 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* (int argc, char **argv, int argn, int *array) */
int		*arg_instigator(int argc, char **argv, int *array)
{
	int	index;
	int	num;
	int	argn;

	index = 1;
	argn = 0;
	while (index < argc)
	{
		if (argn > MAX_ARG || argc > MAX_ARG)
			return (NULL);
		num = arg_counter(argv[index]);
		if (num == 0 || argn > MAX_ARG || argc > MAX_ARG)
			return (NULL);
		argn += num;
		index++;
	}
	if (argn == 2)
		return (NULL);
	array = malloc(sizeof(int) * argn + 1);
	if (!array)
		return (NULL);
	array = arg_array(argc, argv, argn, array);
	return (array);
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

int		*arg_array(int argc, char **argv, int argn, int *array)
{
	short	index;
	short	iter;
	short	argi;
	short	count;
	long	num;

	index = 1;
	iter = 1;
	array[0] = argn;
	while (iter < argc)
	{
		argi = 0;
		count = arg_counter(argv[iter]);
		while (argi++ != count)
		{
			num = get_number(argv[iter], argi);
			check_minmax(num, NULL);
			array[index++] = num;
		}
		iter++;
	}
	return (array);
}
