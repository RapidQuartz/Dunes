# include "../FdF.h"

//
int	init_fdf(int f, char *p)
{
	t_map		*map;

	map = NULL;
	// if (p != NULL)
	map->map_string = read_map(f);
	return (error_end(f, p, map));
	return (0);
}