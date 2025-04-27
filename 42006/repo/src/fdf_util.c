/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:52:07 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/27 20:45:56 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../FdF.h"

int	fdf_countlines(char *str)
{
	int	i;
	int	n;
	
	i = 1;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

int	fdf_countelem(char *str)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		else if (!(str[i] >= '0' && str[i] <= '9'))
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			l++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (l);
}

int	**fdf_joinarr(int **brr, int *dim)
{
	int	**mat;
	int	*rix;
	int	lines;
	int	columns;
	int	index;

	columns = dim[0];
	lines = dim[1];
	index = 0;
	mat = NULL;
	while (brr && brr[index] != NULL)
		index++;
	*mat = malloc(sizeof(int *) * lines);
	if (!mat || mat == NULL)
		return (NULL);
	while (lines-- > 0)
	{
		rix = malloc(sizeof(int) * columns);
		if (!rix || rix == NULL)
			return (NULL);
		mat[index] = rix;
		index++;
	}
	if (brr != NULL)
		free (brr);
	return (mat);
}
