/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:10:59 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/10 17:02:46 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../FdF.h"

t_map		**generate_map(char *map_str, int lim_x, int lim_y);
t_map		**fill_map(char *map_str, t_map **map, int x, int y);
// t_map		fill_map(char *map_str, t_map **map);

// t_data	parse_map(int fd)
// {
// 	t_data	data;

// 	data.map_str = read_map(fd);
// 	data.lim_x = count_columns(data.map_str);
// 	data.lim_y = count_rows(data.map_str);
// 	data.map = generate_map(data.map_str, data.lim_x, data.lim_y);
// 	if (data.map == NULL)
// 		leave_now();
// 	return (data);
// }

//	TODO::MOVE TO OWN FILE
t_map		**generate_map(char *map_str, int lim_x, int lim_y)
{
	int	x;
	int	y;
	t_map	**map;
	
	x = 0;
	y = 0;
	*map = malloc(sizeof(map) * lim_y);
	while (x++ <= lim_x)
		map = malloc(sizeof(map) * lim_x);
	if ((!map || map == NULL) || (!*map || *map == NULL))
		return (NULL);
	map = fill_map(map_str, map, lim_x, lim_y);
}

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