# include "../inc/fdf.h"

int	error_end(int fd, char *params, t_map *map)
{
	int	err[2];
	
	if (map == NULL)
		err[0] = 1;
	else
		err[0] = 0;
	// 	err[1] = 1;
	// else
	if (params || params == NULL)
		err[1] = 0;
	if (err[0] != 0)
		free_map(map);
	// if (err[1] != 0)
	// 	free (params);
	close(fd);
	return (err[0] + err[1]);
}

void	free_map(t_map *map)
{
	if (map || !map)
		return ;
}