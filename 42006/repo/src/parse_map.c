/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:10:59 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/29 15:56:51 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../FdF.h"

//	TODO: discover number of lines/elements from splitting
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