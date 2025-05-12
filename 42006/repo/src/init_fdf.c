# include "../FdF.h"

//	init_fdf is the first contact with the mapfile
//	its purpose is to engage all the structures
//	-	to find dimensions for the map
//	//	-	map->dimensions->x_limit
//	//	-	map->dimensions->y_limit
//	-	to allocate memory for structures
//	//	depending on size::
//	//	-	map->points = malloc(sizeof(*map->points) * map->dimensions->y_limit)
//	//	-	map->points[y] = malloc(sizeof(**map->points) *  map->dimensions->x_limit)
//	-	to supply the `points` structure with coordinates
//	//	-	X—AXIS
//	//	-	Y—AXIS
//	//	-	
//	//	-	
//	-	
//	
///	if using parameters:
///int	init_fdf(int f, char *p)
int	init_fdf(int f)
{
	t_map		*map;

	debug("inside \"init_fdf\"");
	map = NULL;
	// if (p != NULL)
	map = malloc(sizeof(map));
	if (!map || map == NULL)
		return (0);
	map->map_str = read_map(f);
	map = parse_coordinates(map);
	if (!map->map_str || map->map_str == NULL)
		return (error_end(f, NULL, map));
	debug(map->map_str);
	return (0);
}