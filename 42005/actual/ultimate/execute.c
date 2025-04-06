/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:31:51 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/06 19:39:55 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//		declarations
///	MAIN:C:
int		arg_check(int count, char *arg);
int		*arg_to_arr(int argn, char **argv);
t_stk		*arr_to_stk(int *arr);
bool		arg_duplicate(int	*arr);

///	UTIL:C:
void		ft_put(char *str);
void		error_end(t_stk **nexus);

//		take args. check them.
int		main(int argc, char **argv)
{
	int	i;
	int	argn;
	t_stk	*nexus;

	i = 0;
	argn = 0;
	if (!(argc >= 2 && argc <= 501))
		error_end(NULL);
	while (i++ < argc)
		argn += arg_check(argc, argv[i]);
	nexus = arr_to_stk(arg_to_arr(argn, argv));
	if (!nexus || nexus == NULL)
		error_end(nexus);
	push_swap(nexus);
	return (0);
}


int		arg_check(int count, char *arg)
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
			error_end(NULL);
	}
	return (argn);
}

int		*arg_to_arr(int argn, char **argv)
{
	int	i;
	int	j;
	int	*arr;

	arr = malloc(sizeof(int) * (argn + 1));
	if (!arr || arr == NULL)
		error_end(NULL);
	while (argn--)
	{
		arr[i] = arg_to_int(argv[i], j++);
	}
}


t_stk		*arr_to_stk(int *arr)
{
	
}

bool		arg_duplicate(int	*arr)
{
	int	i;
	int	j;
	int	sub;

	i = 0;
	while (arr[0] > i++)
	{
		j = 1;
		sub = arr[i];
		while (arr[0] > j++)
		{
			if (sub == arr[i] && i != j)
				return (true);
		}
	}
	return (false);	
}

////		UTIL:C:
//		converts arg to int
long int	arg_to_int(char *arg, int n)
{}
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