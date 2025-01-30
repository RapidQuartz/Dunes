/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_inspector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:29:25 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/30 16:26:28 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//	takes: arguments and their count
//	returns: [int > 0 - no of valid arguments][0 - invalid arguments]

int		arg_inspector(int count, char **args)
{
	int	i;
	int	n;
	int	m;

	i = 1;
	m = 0;
	while (args[i][0] != '\0' && i != count)
	{
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
		if ((a == ' ') || (a == '\0'))
			return (2);
		if (a >= '0' && a <= '9')
			return (1);
	}
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
		a = args[i];
		i++;
		r = arg_checker(args[i], a);
		if (!r)
			return (0);
		else if (r == 2)
			n++;
	}
	return (n);
}

// returns: [1 - if arg is duplicate][0 - if no duplicate found]
int	arg_duplicate(char *arg, char **mem)
{
		return (1);//TODO:stuff
}


////	OLD:CODE:
// 
/* 
int	arg_checker(int ac, char **av)
{
////	DEBUG:OUTPUT:
	debug("inside arg_checker()");
	int	i;
	int	n;
	int	j;
	char	p;

	i = 1;
	while(i != ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			p = av[i][j];
			j++;
			if (!validity_checker(av[i][j], p))
				return (0);
		}
		i++;
	}
	return (1);
}

void	duplicate_checker(t_stack **sss)
{
	////	DEBUG:OUTPUT:
	printf("inside duplicate_checker()\n");
	t_stack	*t;
	t_stack	*p;
	int	d;
	int	i;

	t = (*sss);
	p = (*sss)->next;
	d = 0;
	i = 0;
	while (p != NULL)
	{
		i = t->value;
		while (d == 0 && p != NULL)
		{
			if (p->value == i)
				d++;
			else
				p = p->next;
			if (d > 0)
				error_handling(sss, NULL);
		}
		p = t->next->next;
		t = t->next;
	}
	return ;
}

int	arg_counter(char *av)
{
	////	DEBUG:OUTPUT:
	printf("inside arg_counter()\n");
	int	i;
	int	n;
	char	p;
	int	r;

	n = 0;
	i = 0;
	while (av[i] != '\0')
	{
		p = av[i];
		i++;
		r = validity_checker(av[i], p);
		if (!r)
			return (0);
		else if (r == 2)
			n++;
	}
	return (n);
}

int	validity_checker(char a, char b)
{
	////	DEBUG:OUTPUT:
	debug("in validity_checker()");
	if ((b == ' ') && (a == ' ' || a == '-' || a == '+' || \
	(a >= '0' && a <= '9')))
			return (1);
	if ((b == '-' || b == '+') && (a >= '0' && a <= '9'))
			return (1);
	if (b <= '9' && b >= '0')
	{
		if ((a == ' ') || (a == '\0'))
			return (2);
		if (a >= '0' && a <= '9')
			return (1);
	}
	return (0);
} */
// 