/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:12:01 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/26 16:37:12 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_checker(int ac, char **av)
{
////	DEBUG:OUTPUT:
	printf("debug: arg_checker()\n");
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
				return (0);////	CALL:0:2:1:RETURN:0:main()
		}
		i++;
	}
	return (1);////	CALL:0:2:1:RETURN:n:main()
}

void	duplicate_checker(t_stack **sss)
{
	////	DEBUG:OUTPUT:
	printf("debug: duplicate_checker()\n");
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
	printf("debug: arg_counter()\n");
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
	printf("debug: validity_checker()\n");
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