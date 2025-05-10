/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scratch_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:51:59 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/10 17:02:20 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FdF.h"

// void	ft_draw_map(t_map *map, void *mlx, void *win)
// {
// 	t_dimensions	*dim;

// 	dim = malloc(sizeof(dim));
// 	if (!dim || dim == NULL)
// 		return ;
// 	ft_set_dimensions(map, dim);
// 	ft_draw_line(map, dim, mlx, win);
// }

// void	ft_draw_line(t_map *map, t_dimensions *dim, void *mlx, void *win)
// {
// 	int	mode;

// 	if ((!map || map == NULL) || (!mlx || mlx == NULL) || (!win || win == NULL))
// 		return ;
// 	mode = 1;
// 	ft_printf("%d %d %d %d %d", dim->edge_offset_x, dim->edge_offset_y, (HEIGHT - dim->edge_offset_y), dim->pos_x, dim->pos_y);
// 	sleep (3);
// 	while (dim->pos_y < (HEIGHT - dim->edge_offset_y))
// 	{
// 		while (dim->pos_x <= (WIDTH - dim->edge_offset_x))
// 		{
// 			if (mode == 1 && dim->pos_x <= (WIDTH - dim->edge_offset_x))
// 				mlx_pixel_put(mlx, win, dim->pos_x++, dim->pos_y, 0xFFFFFF);
// 			else if (mode == 1 && dim->pos_x == (WIDTH - dim->edge_offset_x))
// 				mode = 2;
// 			else if (mode == 2 && dim->pos_x < dim->lim_x)
// 				dim->pos_x++;
// 			else if (mode == 2 && dim->pos_x == dim->lim_x)
// 			{
// 				mlx_pixel_put(mlx, win, dim->pos_x++, dim->pos_y, 0xFFFFFF);
// 				dim->lim_x += dim->line_x;
// 			}
// 		}
// 	}
// }
// void	ft_draw_segment_x(t_map *map, t_dimensions *dim, void *mlx, void *win)
// {
// 	if ((!map || map == NULL) || (!mlx || mlx == NULL) || (!win || win == NULL))
// 		return ;
// 	while (dim->pos_x < (WIDTH - dim->edge_offset_x))
// 	{
// 		dim->pos_x++;
// 	}
// 	dim->pos_x = dim->edge_offset_x;
// 	dim->lim_x = dim->edge_offset_x;
// 	if (map)
// 		return ;
// }

// void	ft_draw_segment_y(t_map *map, t_dimensions *dim, void *mlx, void *win)
// {
// 	if (!(dim->pos_y < (HEIGHT - dim->edge_offset_y)))
// 		return ;
// 	else
// 		dim->lim_y = dim->pos_y + dim->line_y;
// 	while (dim->pos_y < dim->lim_y)
// 	{
// 		dim->pos_y += 1;
// 		while (dim->pos_x < (WIDTH - dim->edge_offset_x))
// 		{
// 			if (dim->pos_x < dim->lim_x)
// 				dim->pos_x += 1;
// 			else if (dim->pos_x == dim->lim_x)
// 			{
// 				mlx_pixel_put(mlx, win, dim->pos_x, dim->pos_y, 0xFFFFFF);
// 				dim->lim_x += dim->line_x;
// 			}
// 		}
// 		dim->pos_x = dim->edge_offset_x;
// 	}
// 	if (map)
// 		return ;
// }

// void	ft_set_dimensions(t_map *map, t_dimensions *dim)
// {	
// 	dim->edge_offset_x = (WIDTH / 10);;
// 	dim->edge_offset_y = (HEIGHT / 10);;
// 	dim->pos_x = 0 + dim->edge_offset_x;
// 	dim->pos_y = 0 + dim->edge_offset_y;
// 	dim->line_x = (WIDTH - dim->edge_offset_x) / map->x_size;
// 	dim->line_y = (HEIGHT - dim->edge_offset_y) / map->y_size;
// }


// int	*proportional_offset(t_map *map, int x_ratio, int y_ratio)
// {
	
// }

//	a basic scratchpad attempt at drawing something
//	please tell me you replaced this before submitting
/* void	scratch_map(void *mlx, void *win, t_map *map)
{
	ft_printf("\n\nDEBUG: {{IN SCRATCH MAP}}\n\n");
	int	i;
	int	j;
	int	x[2];
	int	y[2];

	i = 0;
	j = 0;
	while (map)
	{
		
		while (map->map_line[i][j + 1] != NULL)
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
		}
	}
} */

