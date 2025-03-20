/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:10:06 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/20 12:31:41 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		debug(char *str)
{
	int	i;
	char	c;

	i = 0;
	if (!str || str[0] == '\0')
		return ;
	write (1, "\n{debug:\n", 8);
	while (str[i] != '\0')
	{
		c = str[i];
		write (1, &c, 1);
		i++;
	}
	write (1, "}\n", 2);
}

void		d_end(void)
{
	exit (2);
}

void		d_arrayprint(int *arr)
{
	int	i;
	char	n;


	i = 0;
	while (i <= 3)
	{
		printf("%d ==", arr[i]);
		i++;
	}
	printf("\n == ");
	i = 0;
	write (1, "\n{debug:arrayprint:\n", 20);
	while (i++ < arr[0])
	{
		n = arr[i] + 48;
		write (1, &n, 1);
		write (1, " ", 1);
	}
	write (1, "}\n", 2);
}