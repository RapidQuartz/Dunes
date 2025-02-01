/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_inspector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:29:25 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/01 18:23:02 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//	takes: arguments and their count
//	returns: [int > 0 - no of valid arguments][0 - invalid arguments]

int		arg_inspector(int count, char **args)
{
	debug("in arg_inspector()");
	int	i;
	int	n;
	int	m;

	i = 1;
	m = 0;
	printf("_ac_: count = %d\n", count);
	while (i < count)
	{
		printf("_ac_: i = %d\n", i);
		printf("_ac_: args[i] = %s\n", args[i]);
		debug("_ac_: iterating...");
		n = arg_counter(args[i]);
		if (n == 0)
			return (0);
		m += n;
		i++;
	}
	return (m);
}

int	arg_checker(char a, char b)
{
	////	DEBUG:OUTPUT:
	debug("in arg_checker()");
	if ((b == ' ') && (a == ' ' || a == '-' || a == '+' || \
	(a >= '0' && a <= '9')))
			return (1);
	if ((b == '-' || b == '+') && (a >= '0' && a <= '9'))
			return (1);
	if (b <= '9' && b >= '0')
	{
		debug("in _ac_ loop");
		if ((a == ' ') || (a == '\0'))
			return (2);
		if (a >= '0' && a <= '9')
			return (1);
	}
	printf("char a: %c char b: %c\n", a, b);
	return (0);
}
////	this does double duty. TODO: move aroundw
int	arg_counter(char *args)
{
	////	DEBUG:OUTPUT:
	printf("inside arg_counter()\n");
	int	i;
	int	n;
	char	a;
	int	r;

	n = 0;
	i = 0;
	while (args[i] != '\0')
	{
		printf("args[i] = %c, i = %d\n", args[i], i);
		a = args[i];
		i++;
		r = arg_checker(args[i], a);
		printf("r = %d\n", r);
		if (!r)
			return (0);
		else if (r == 2)
			n++;
	}
	return (n);
}
