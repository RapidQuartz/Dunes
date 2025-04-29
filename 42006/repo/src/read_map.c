/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:58:04 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/29 16:07:58 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../FdF.h"

//	MOVE TO .h or leave here
char	*read_map(int fd);
t_map	*init_map(t_map **blank, int y_max, int x_max);
t_map	*parse_map_str(char *map_str);

char	*read_map(int fd)
{
	char		*line;
	char		*map_str;
	size_t	num_lines;

	line = NULL;
	map_str = NULL;
	num_lines = 0;
	while (++num_lines)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (num_lines == 1)
			map_str = ft_strdup(line);
		else if (num_lines > 1)
			map_str = ft_strjoin(map_str, line);
	}
	free (line);
	return (map_str);
}
/* 
//takes a string of `\n` separated lines of numbers
t_map	*parse_map_str(char *map_str)
{
	t_map		*map;
	char 		**chart;
	char 		*lines;
	int		i;

	map = NULL;
	chart = NULL;
	i = 0;
	chart = ft_split(map_str, '\n');
	map = init_map(&map, fdf_countlines(map_str), fdf_countrows(map_str));
	populate_map(map, map_str, chart);
	return (map);
} */

//takes a string of `\n` separated lines of numbers
t_map	*parse_map_str(char *map_str)
{
	t_map		*map;
	char 		**chart;
	int		i;
	int		j;
	int		k;

	map = NULL;
	chart = NULL;
	i = 0;
	j = 0;
	k = 0;
	chart = ft_split(map_str, ' ');
	while (chart[i] != NULL)
	{
		k = map_section(chart[i], j);
		map = data_divider(chart, i, j, map);
		
	}
	if (k == 1)
	map = init_map(&map, fdf_countlines(map_str), fdf_countrows(map_str));
	populate_map(map, map_str, chart);
	return (map);
}
int	map_section(char *chart, int j)
{
	
}
/* t_map	*parse_map_str(char *map_str)
{
	t_map	*map;
	char	**lines;
	int	dimensions[2];

	map = NULL;
	dimensions[0] = fdf_countelem(map_str);
	dimensions[1] = fdf_countlines(map_str);
	lines = ft_split(map_str, '\n');
	if (ft_strchr(*lines, ','))
		parse_color(lines, dimensions[0], dimensions[1]);
	else
		parse_mono(lines, dimensions[0], dimensions[1]);
	// if ',' detected or not
	// OR
	// make robust algo regardless, so ',' or ' ' both trigger responses
		// ',' — store <- number in **int, -> color in **int, 
		// ' '

	return (map);
} */
void	populate_map(t_map *map, char *map_str, char *chart)
{
	int	i;
	
	i = 0;
	map->map_lines = ft_split(map_str, '\n');
	while (i < map->y_max)
	{
		if (map->map_lines[i] != NULL)
			printf("line number: %d exists\n", i);
		else 
			printf("line number: %d is NULL\n", i);
		i++;
	}
	chart = NULL;
}

t_map	*init_map(t_map **blank, int y_max, int x_max)
{
	t_map	*map;

	map = NULL;
	if (y_max && x_max)
		map = malloc(sizeof(*map));
	if (!map || map == NULL)
		return (NULL);
	map->y_max = y_max;
	map->x_max = x_max;
	map->map_lines = malloc(sizeof(char *) * y_max);
	if (!map->map_lines || map->map_lines == NULL)
		return (NULL);
	map->map_values = malloc(sizeof(int *) * y_max);
	if (!map->map_values || map->map_values == NULL)
		return (NULL);
	map->map_colors = malloc(sizeof(char *) * y_max);
	if (!map->map_colors || map->map_colors == NULL)
		return (NULL);
	(*blank) = map;
	return (*blank);
}
