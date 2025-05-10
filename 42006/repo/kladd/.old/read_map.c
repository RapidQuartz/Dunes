/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:58:04 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/10 16:54:47 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../FdF.h"

//	MOVE TO .h or leave here
// char	*read_map(int fd);
t_map	*init_map(t_map **head, t_map *tmp);
t_map	*parse_map_str(char *map_str);
int	count_columns(char *map);

//
int	map_section(char *chart, int j);
// //
// t_map	*init_map(t_map **head, t_map *tmp)
// {
// 	t_map	*map;

// 	map = malloc(sizeof(*map));
// 	if ((!map || map == NULL) && (!tmp || tmp == NULL))
// 		return (NULL);
// 	else if ((tmp && tmp != NULL) && (!map || map == NULL))
// 		free_map(tmp);
// 	else if ((map && map != NULL) && (!head || *head == NULL))
// 	{
// 		head = malloc(sizeof(**head));
// 		if (!head || head == NULL)
// 			free_map(tmp);
// 		*head = map;
// 	}
// 	if (head && *head != NULL)
// 		map->head = head;
// 	if (tmp && tmp != NULL)
// 		tmp->next = map;
// 	return (map);
// }

//
// // char	*read_map(int fd)
// char	*read_map(int fd)
// {
// 	char		*line;
// 	char		*map_str;
// 	size_t	num_lines;
// 	int		i;

// 	i = 0;
// 	line = NULL;
// 	map_str = NULL;
// 	num_lines = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		if (num_lines == 1)
// 		{
// 			map_str = ft_strdup(line);
// 			xy_lim[0] = count_columns(map_str);
// 		}
// 		else if (num_lines > 1)
// 			map_str = ft_strjoin(map_str, line);
// 	}
// 	xy_lim[1] = count_rows(map_str);
// 	free (line);
// 	return (map_str);
// }

int	count_columns(char *map)
{
	int	i;
	int	columns;
	bool	in_coord;
	
	i = 0;
	columns = 0;
	in_coord = false;
	while (map[i] != '\0')
	{
		if (ft_isdigit(map[i]))
		{
			columns++;
			while (map[i] != ' ' && map[i] != '\n')
				i++;
			if (map[i] == '\n')
				break ;
		}
		i++;
	}
	return (columns);
}
int	count_rows(char *map)
{
	int	i;
	int	rows;
	bool	in_coord;

	i = 0;
	rows = 0;
	in_coord = false;
	while (map[i] != '\0')
	{
		if (!in_coord && ft_isdigit(map[i]))
			in_coord = true;
		while (in_coord && map[i] != ' ' && map[i] != '\n')
			i++;
		if (map[i] == ' ' || map[i] == '\n')
			in_coord = false;
		if (map[i] == '\n')
			rows++;
		i++;
	}
	return (rows);
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

// void	free_map(t_map *map)
// {
// 	t_map	*tmp;

// 	tmp = NULL;
// 	while (map != NULL)
// 	{
// 		if (map->next != NULL)
// 		{
// 			tmp = map->next;
// 			free (map);
// 			map = tmp;
// 		}
// 		else if (map->next == NULL)
// 		{
// 			free (map);
// 			leave_now();
// 		}
// 	}
// }

// t_map	*do_map(t_map *map, char **lines, int l_num, int r_num)
// {
// 	t_map	**head;
// 	t_map	*tmp;
// 	int	i;
	
// 	i = 0;
// 	head = NULL;
// 	tmp = NULL;
// 	while (i < l_num)
// 	{
// 		map = init_map(head, tmp);
// 		map->map_line = ft_split(lines[i], ' ');
// 		map->l_num = i++;
// 		map->next = NULL;
// 		if (l_num > i)
// 			tmp = map;
// 		map->x_size = r_num;
// 		map->y_size = l_num;
// 		head = map->head;
// 	}
// 	return ((*map->head));
// }
// //takes a string of `\n` separated lines of numbers
// t_map	*parse_map_str(char *map_str)
// {
// 	t_map		*map;
// 	char 		**chart;
// 	int		i;
// 	int		j;

// 	map = NULL;
// 	chart = NULL;
// 	i = 0;
// 	j = 0;
// 	chart = ft_split(map_str, '\n');
// 	free (map_str);
// 	while (chart[i][j] != '\0')
// 		j++;
// 	while (chart[i] != NULL)
// 		i++;
// 	map = do_map(map, chart, i, j);
// 	return (map);
// }

// int	map_section(char *chart, int j)
// {
// 	if (chart || j)
// 		return (0);
// 	return (0);
// }
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
/* 
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
} */
/* 
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
} */
