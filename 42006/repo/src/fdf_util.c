/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:52:07 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/29 15:56:16 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../FdF.h"

int	fdf_countlines(char *str)
{
	int	i;
	int	n;
	
	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n' || str[i] == '\0')
			n++;
		if (str[i] != '\0')
			i++;
	}
	return (n);
}

// int	fdf_countrows(char *str)
int	fdf_countrows(char *str, t_map *map)
{
	int	i;
	int	set;
	int	past;

	i = 0;
	set = 0;
	past = 0;
	while (*str != '\0')
	{
		i++;
		set = countrows_set(*str);
		if (set <= 0)
			str++;
		else if (set == 1)
			str = set_number(*str, map, i);
		else if (set == 2)
			str = color_mode(*str, map, i);
		else if (set == 3)
			str = line_end(*str, map, i);
		else if (set == 4)
			str = map_end(*str, map, i);
	}
}
// char *set_number(char *str, t_map *map, int i);
char *set_number(char *str, t_map *map, int i)
{
	int	i;
	int	num;
	
	i = 0;
	if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
	{
		while (str[i] >= '0' && str[i] <= '9')
			num += ft_atoi(str)
	}
}
// char *color_mode(char *str, t_map *map, int i);
char *color_mode(char *str, t_map *map, int i, int l)
{
	int	m;
	
	m = i;
	while (str[i] != '\0')
	{
		if (color_set(str, i))
			i++;
		else
			break ;
	}
	map->map_colors[l][]
}
bool	color_set(char *str, int i)
{
	if (str[i] == ',')
	{
		while (str[i] != '\0')
		{
			if (color_set(str, i))
				i++;
			else
				break ;
		}
		
	}
	
}
char *line_end(char *str, t_map *map, int i);
char *map_end(char *str, t_map *map, int i);

int	countrows_set(char c)
{
	if (c == ' ')
		return (0);
	if (c >= '0' && c <= '9')
		return (1);
	if (c == ',')
		return (2);
	if (c == '\n')
		return (3);
	if (c == '\0')
		return (4);
	else
		return (-1);
}
/* 
int	fdf_countrows(char *str)
{
	int	i;
	int	r;
	int	m;
	
	i = 0;
	r = 0;
	m = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			r++;
			while (str[i] == ' ')
				i++;
		}
		while (str[i] != ' ' && str[i] != '\n')
			i++;
		if (str[i] == '\n' && r > m)
		{
			m = r;
			r = 0;
		}
		i++;
	}
	return (m);
} */
/* 
int	fdf_countelem(char *str)
{
	int	i;
	int	l;
	int	m;

	i = 0;
	l = 0;
	m = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
			while (str[i] != ' ' || str[i] != '\n' || str[i] != '\0')
				i++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			l++;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else if (str[i] == '\n' || str[i] == '\0')
		{
			if (l > m)
				m = l;
			l = 0;
		}
	}
	return (m);
}
*/

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
