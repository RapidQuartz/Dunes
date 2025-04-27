/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:10:59 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/27 20:43:25 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../FdF.h"

/* tasks:
-	verify input
-	deal with color
-	deal with mono
// */
/*	//made to get dimensions of map string, but might be useless
int	*get_dimensions(char **map_str)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	*coords;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	coords = ft_calloc(2, sizeof(int));
	while (map_str != NULL && map_str[i] != NULL && map_str[i][j] != '\0')
	{
		if (map_str[i][j] == ' ')
			x++;
		else if (map_str[i][j] == '\n')
			y++;
	}
} */
//	TODO: discover number of lines/elements from splitting
//	TODO:	parse map backwards::x++::y--;;
//	TODO: split string into ministrings split by ' ' for easier atoi.
void	parse_mono(char **map_str, int x_siz, int y_siz)
{
	char	**map_lines;
	int	**map_matrix;
	int	*map_array;
	int	col_num;

	col_num = 0;
	map_lines = NULL;
	map_matrix = malloc(sizeof(int *) * y_siz);
	if (!map_matrix || map_matrix == NULL)
		return ;
	while (map_str[y_siz] != NULL)
	{
		map_array = malloc(sizeof(int) * x_siz);
		if (!map_array || map_array == NULL)
			return ;
		while (map_lines[col_num] && ft_atoi(map_lines[col_num]))
		{
			map_array[col_num] = ft_atoi(map_lines[col_num]);
			col_num++;
		}
		map_matrix[y_siz] = map_array;
		y_siz--;
	}
}

void	parse_color(char **map_str, int x_siz, int y_siz)
{
	if (map_str != NULL || x_siz == 0 || y_siz == 0)
		return ;
	return ;
}

// t_map		*get_coords(char *map_string, int *map_key)
// {
// 	t_map		*map;
//
// 	map = NULL;
// 	return (map);
// }