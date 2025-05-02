/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scratch_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:51:59 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/02 19:26:25 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FdF.h"

int	*proportional_offset(t_map *map, int x_ratio, int y_ratio)
{
	
}

//	a basic scratchpad attempt at drawing something
//	please tell me you replaced this before submitting
void	scratch_map(void *mlx, void *win, t_map *map)
{
	int	i;
	int	j;
	int	x[2];
	int	y[2];

	i = 0;
	j = 0;
	while (map)
	{
		
		/* while (map->map_line[i][j + 1] != NULL)
		{
			if (map->map_line[i][j] < map->map_line[i][j + 1])
			{
				x[0] = -1;
				x[1] = 1;
				y[0] = -1;
				y[1] = 1;
			}
			else if (map->map_line[i][j] > map->map_line[i][j + 1])
			{
				x[0] = 1;
				x[1] = -1;
				y[0] = 1;
				y[1] = -1;
			}
			else if (map->map_line[i][j] = map->map_line[i][j + 1])
			{
				x[0] = 0;
				x[1] = 0;
				y[0] = 0;
				y[1] = 0;
			}
			// mlx_pixel_put(mlx, win, WIDTH)
		} */
	}
}

