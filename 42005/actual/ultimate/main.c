/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:24:06 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/05 22:41:01 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//		take args. check them.
int		main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (!(argc >= 2 && argc <= 501))
		error_end(NULL);
}

//		attempt to free memory and exit
void		error_end(t_stk **nexus)
{
	if (!nexus)
		exit (2);
	else
		terminate_nexus(nexus);
	if (nexus)
		ft_put("Error: <terminate nexus>");
	else
		ft_put("Error");
	exit (2);
}

//		outputs a string and a newline
void		ft_put(char *str)
{
	int	i;
	char	c;

	i = 0;
	c = i + '0';
	while (str[i] != '\0')
	{
		c = str[i++];
		write (1, &c, 1);
	}
	write (1, '\n', 1);
}