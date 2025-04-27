/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:58:04 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/27 20:44:25 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../FdF.h"

//	MOVE TO .h or leave here
char	*read_map(int fd);
t_map	*init_map(char *map_str, int x_max, int y_max);
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
	return (map_str);
}

t_map	*parse_map_str(char *map_str)
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
	/* if ',' detected or not
	OR
	make robust algo regardless, so ',' or ' ' both trigger responses
		',' — store <- number in **int, -> color in **int, 
		' '
	*/
	return (map);
}

t_map	*init_map(char *map_str, int x_max, int y_max)
{
	if(map_str == NULL || x_max == 0 || y_max == 0)
		return (NULL);
	else
		return (NULL);
}
