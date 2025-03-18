/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:59:58 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/10 12:58:13 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		freecursive(t_snap *snap);

void	check_minmax(long int value, t_snap **stack)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		if (stack || (*stack) != NULL)
			error_handling(stack, NULL);
		else
			error_handling(NULL, NULL);
	}
}

void	error_handling(t_snap **one, t_snap **other)
{
	//debug("in error handling");
	if (one == NULL  || (*one) != NULL)
	{
		debug("freeing one");
		// free_stack(one);
		one = NULL;
	}
	if (other == NULL  || (*other) != NULL)
	{
		debug("freeing other");
		// free_stack(other);
		other = NULL;
	}
	//ft_putstr("Error\n");
	printf("Error\n");
	exit (2);
}
/* 
void		free_stack(t_snap **stack)
{
	t_snap	*node;
	t_snap	*mem;
	int		size;
	int		i;
	
	i = 0;
	node = (*stack);
	while (i < 12)
	{
		if (node-> != NULL)
		{
			freecursive(node->c[i]);
			mem = node->c[i];
			free (mem);
		}
		i++;
	}
	*stack = NULL;
} */
/* 
void		freecursive(t_snap *snap)
{
	int		i;
	t_snap	*node;
	
	i = 0;
	node = NULL;
	while (i < 12)
	{
		if (snap->c[i] != NULL)
		{
			node = snap->c[i];
			freecursive(node->c[i]);
		}
		free (snap->a);
		free (snap->b);
		free (snap->c[i]);
		i++;
	}
	if (snap != NULL)
		free (snap);	
} */

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