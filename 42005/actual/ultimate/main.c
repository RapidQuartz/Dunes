/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:24:06 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/07 11:08:09 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//		declarations
void		error_end_stk(t_stk **nexus);
void		ft_put(char *str);
int		*arg_check(char *arg, int *argn, int j);


//		take args. check them.
int		main(int argc, char **argv)
{
	int	i;
	int	argn;
	t_stk	*nexus;

	i = 0;
	argn = 0;
	if (!(argc >= 2 && argc <= 501))
		error_end_stk(NULL);
	while (i++ < argc)
		argn += arg_check(argc, argv[i]);
	nexus = arr_to_stk(arg_to_arr(argn, argv));
	if (!nexus || nexus == NULL)
		error_end_stk(nexus);
	push_swap(nexus);
	return (0);
}

////		ERROR:
//		attempt to free memory and exit
void		error_end_stk(t_stk **nexus)
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
////		UTIL:
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

int		*arg_check(char *arg, int *argn, int j)
{
	int	i;
	char	c;
	int	argn;
	int	in;


	i = 0;
	c = 0;
	argn = 0;
	in = 0;
	while (arg[i++])
	{
		c = arg[i];
		if (in == 1 && (c == ' ' || c == '\0'))
			in = 0;
		else if (in == 0 && (c == '+' || c == '-'))
			in = -1;
		else if (c >= '0' && c <= '9')
			in = 1;
		else if (in == 1 && (c == ' ' || c == '\0'))
			argn++;
		else if (in == -1 && !(c >= '0' && c <= '9'))
			error_end_stk(NULL);
	}
	return (argn);
}

int		arg_validator(char arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
}