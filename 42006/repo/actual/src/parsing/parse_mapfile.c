# include "../../inc/fdf.h"

void	read_mapfile(t_fdf *fdf)
{
	char		*raw;
	char		*line;

	raw = NULL;
	line = NULL;
	while (fdf->fd != -1)
	{
		line = get_next_line(fdf->fd);
		if (!line)
			break ;
		if (raw)
			raw = ft_strjoin(raw, line);
		else
			raw = ft_strdup(line);
		free (line);
	}
	fdf->map->raw_str = malloc(sizeof(raw));
	if (!fdf->map->raw_str || fdf->map->raw_str == NULL)
		exit (0);//TODO:integrate into exit function
	fdf->map->raw_str = ft_strdup(raw);
	free (raw);
}

void	split_map_str(t_fdf *fdf)
{
	char	**split_map;
	int	l;
	int	r;

	l = 0;
	r = 0;
	split_map = ft_split(fdf->map->raw_str, '\n');
	while (split_map[l])
		l++;

	fdf->dim->max_y = l;
	fdf->map->elements = malloc(sizeof(*fdf->map->elements) * l);
	if (!fdf->map->elements || fdf->map->elements == NULL)
		exit (0);//TODO:integrate into exit function
	l = 0;
	while (split_map[l])
	{
		fdf->map->elements[l] = ft_split(split_map[l], ' ');
		while (l == 0 && fdf->map->elements[l][r])
			r++;
		l++;
	}
	fdf->dim->max_x = r;
	free (split_map);
}
