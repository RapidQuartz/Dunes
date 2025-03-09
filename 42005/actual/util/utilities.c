/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:37:20 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/09 20:16:36 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
unsigned short	get_delta(t_snap *snap);
t_snap *take_snap(unsigned short *array, int argn)
{
	int		i;
	t_snap	*snap;

	i = 0;
	snap = malloc(sizeof(*snap));
	if (!snap)
		return (NULL);
	snap->a = malloc(sizeof(unsigned short) * argn + 1);
	snap->b = malloc(sizeof(unsigned short) * argn + 1);
	snap->c = malloc(sizeof(unsigned short) * argn + 1);
	snap->prev = NULL;
	if (!(snap->a || snap->b || snap->c))
		return (NULL);
	snap->size = array[0];
	snap->a[0] = snap->size;
	snap->b[0] = 0;
	while (i++ < argn)
		snap->a[i] = array[i];
	snap->c = get_delta(snap);
	return (snap);
}

unsigned short	*get_delta(t_snap *snap)
{
	unsigned short	coll;
	unsigned short	delta;
	unsigned short	size;
	int			i;
	
	i = 1;
	coll = 0;
	delta = 0;
	size = snap->size;
	while (i < size)
	{
		coll = snap->a[i];
		if (coll < i)
			coll = i - coll;
		else if (coll > i)
			coll = coll - i;
		delta += coll;
		snap->c[i] = delta;
		i++;
	}
	return (snap->c);
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
