/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:12:44 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/26 14:48:32 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int		isnum(char *str);
long		get_number(char *arg, int argn);

//printf("");
int	main(int argc, char **argv)
{
	int		i;
	long int	j;
	int		k;
	
	i = 1;
	j = 0;
	k = 0;
	if (argc == 3)
	{
		if (i == 1 && isnum(argv[1]))
		{
			j = get_number(argv[i], 1);
		}
		i++;
		while (++k <= j)
			printf("%s%d\n", argv[i], k);
	}
	return (0);
}

int	isnum(char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] == '\0' || (str[i] >= '9' || str[i] <= '0'))
		return (-1);
	while ((str[i] >= '0' && str[i] <= '9') && (str[i] != '\0'))
	{
		if (str[i] >= '9' || str[i] <= '0')
			return (0);
		i++;
	}
	return (1);
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