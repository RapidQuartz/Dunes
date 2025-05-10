# include "../FdF.h"

t_data	*map_specs(char *raw, t_data *data);
void		*map_lines(char **lines, t_data *data, t_map **map);

void		parse_map(char *raw)
{
	t_data	*data;
	t_map		**map;
	char		**lines;
	int		i;
	
	i = 0;
	data = NULL;
	if (!raw || raw == NULL)
		return ;
	data = malloc(sizeof(*data));
	if (!data || data == NULL)
		return ;
	data = map_specs(raw, data);
	lines = ft_split(data->map_str, '\n');
	map = malloc(sizeof(map) * data->lim_y * data->lim_x);
	if (!map || map == NULL)
		return ;
	map_lines(lines, data, map);
}

t_map		*map_fill(char **line, t_map *map, int y)
{
	int	i;
	int	x;
	
	i = 0;
	x = 0;
	while (line[x] != NULL)
	{
		map->x = x;
		map->y = y;
		map->z = ft_atoi(line[x]);
		while (line[x][i] != '\0')
		{
			while (line[x][i] == '-' || ft_isdigit(line[x][i]))
				i++;
			if (line[x][i] == ',')
				map->c = ft_hextoi(ft_substr(line[x], i + 1, 8));

		}
	}
}
/* 
int		ft_hextoi(char *hex)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (hex[i] == '0' && hex[i + 1] == 'x')
	{
		if ()
	}
	return (n);
} */
void		*map_lines(char **lines, t_data *data, t_map **map)
{
	int	i;
	int	j;
	char 	**line;
	
	i = 0;
	j = 0;
	while (lines[j] != NULL)
	{
		line = ft_split(lines[j], ' ');
		map[j] = map_fill(line, map[j], j);
	}
}

t_data	*map_specs(char *raw, t_data *data)
{
	if (!raw || !data)
		return (NULL);
	data->map_str = raw;
	data->lim_x = count_columns(raw);
	data->lim_y = count_rows(raw);
	return (data);
}

void		read_map(int fd)
{
	char	*line;
	char	*raw_map;

	line = NULL;
	raw_map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			if (raw_map == NULL)
				raw_map = ft_strdup(line);
			else
				raw_map = ft_strjoin(raw_map, line);
		}
		else if (line == NULL)
			break;
	}
	parse_map(raw_map);
}
