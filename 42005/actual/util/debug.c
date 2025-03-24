/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:10:06 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/24 13:15:46 by akjoerse         ###   ########.fr       */
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

void		d_print_stack(t_n **sta)
{
	int	i;
	t_n	*s;
	
	i = 0;
	s = (*sta);
	s = (*(s->h));
	while (i++ < s->i->v)
	{
		printf("node # %d:\t%d\n", i, s->v);
		s = s->n;
	}
}
void		d_print_cost(t_c **cst)
{
	int	i;
	int	z;
	t_c	*c;
	t_n	*n;
	
	i = 0;
	c = (*cst);
	n = (*c->cap);
	z = n->i->v;
	while (i < z)
	{
		printf("cost for node: %d\t" \
			"#\t%p#\t%p#\t%p  #\t%d#\t%d#\t%d#\t%d#\t\n" \
			"\t\t\t\tc->cap#\t\tc->ego#\t\tc->tgt  #" \
			"\tc->dif#\tc->dis#\tc->rot#\tc->rev\n", \
		n->v, c->cap, c->ego, c->tgt, c->dif, c->dis, c->rot, c->rev);
		if (i++ < z)
		{
			n = n->n;
			c = n->c;
		}
	}
}


void		d_print_array(int *arr)
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