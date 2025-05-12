# include "../../FdF.h"

char	*read_map(int fd)
{
	debug("inside: read_map");
	char	*raw;
	char	*out;

	raw = NULL;
	out = NULL;
	while ((!raw && !out) || (raw && out))
	{
		raw = get_next_line(fd);
		if (!out)
			out = ft_strdup(raw);
		else if (out && raw)
			out = ft_strjoin(out, raw);
	}
	return (out);
}

t_map	*parse_coordinates(t_map *map)
{
	debug("inside: parse_coordinates");
	int	i;
	
	i = 0;
	map->dimensions = malloc(sizeof(map->dimensions));
	if (!map->dimensions || map->dimensions == NULL)
		return (NULL);
	map->dimensions->x_lim = 0;
	map->dimensions->y_lim = 0;
	map->dimensions = get_dimensions(map);
	map->math = malloc(sizeof(map->math));
	if (!map->math || map->math == NULL)
		return (NULL);
	map->points = malloc(sizeof(map->points));
	if (!map->points || map->points == NULL)
		return (NULL);
	while (map->map_str[i] != '\0')
	{
		i += process_mapstring(map, i);
	}
	return (map);
}

//	not fit:
//	needs to associate `map->points[y]` to the coordinates.
//
//
//
int	process_mapstring(t_map *map, int i)
{
	debug("inside: process_mapstring");
	int	j;
	int	num;
	int	col;
	char	*s;

	j = 0;
	num = 0;
	col = 0;
	s = map->map_str;
	while (s[i + j] == ' ')
		j++;
	if (ft_isdigit(s[i + j]))
		j += store_coordinates(map, i + j);
	if (ft_ishex(s, i + j))
		j += store_color(map, i + j);
	return (j);
}

int	store_color(t_map *map, int i)
{
	int	j;
	int	c;
	char	*s;

	j = 0;
	c = 0;
	s = map->map_str;
	while ((j == 0 && s[i + j] == ',' )|| (j == 1 && s[i + j] == 'x'))
		j++;
	while (s[i + j] != ' ' && s[i + j] != '\n')
	{
		c *= 16;
		c += ft_hextoi(s[i + j]);
		if (c == -1)
			exit (0);
		j++;
	}
	// map->points
	return (j);
}
int	store_coordinates(t_map *map, int i)
{
	int	j;
	int	y;
	int	z;

	j = 0;
	y = 0;
	z = 0;
	while (ft_isdigit(map->map_str[i + j]))
	{
		map->points[y] = malloc(sizeof(*map->points));
		if (!map->points[y] || map->points[y] == NULL)
			return (z);
	}
	return (j);
}
