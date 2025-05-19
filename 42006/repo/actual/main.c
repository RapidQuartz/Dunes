/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:33:42 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/19 16:28:28 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"


int	main(int arg, char **param)
{
	t_fdf	fdf;
	void	*win;

	if (arg != 2)
		return (1);
	fdf.fd = open(param[1], O_RDONLY);
	init_fdf(&fdf);
	init_map(&fdf);
	init_pos(&fdf);
	fdf.map->mlx = mlx_init();
	win = mlx_new_window(fdf.map->mlx, DEFWID, DEFHEI, "Fer De Fil");
	fdf.map->win = win;
	fdf.map->bpp = 32;
	draw_image(&fdf);
	printf("just follow me\n");
}

void	free_map(t_map *map, t_dim *dim)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < dim->max_y)
	{
		j = 0;
		while (j < dim->max_x)
		{
			free(map->elements[i][j]);
			j++;
		}
		free(map->elements[i]);
		i++;
	}
	free (map->elements);
	free (map->raw_str);
	map->raw_str = NULL;
}

void	init_pos(t_fdf *fdf)
{
	fdf->pos->x = 0;
	fdf->pos->y = 0;
}
////	TODO: move to separate `draw_map.c` file
void	draw_image(t_fdf *fdf)
{
	int	z;
	char	*addr;
	
	fdf->img = mlx_new_image(fdf->map->mlx, fdf->dim->s_x, fdf->dim->s_y);
	addr = get_data_addr(fdf->img);
	while (fdf->pos->y < fdf->dim->max_y - 1)
	{
		while (fdf->pos->x < fdf->dim->max_x - 1)
		{
			if (fdf->pos->x < fdf->dim->max_x - 1)
				calculate_points(fdf, fdf->pos->x + 1, fdf->pos->y);
			if (fdf->pos->y < fdf->dim->max_y - 1)
				calculate_points(fdf, fdf->pos->x, fdf->pos->y + 1);
			fdf->pos->x++;
		}
		fdf->pos->x = 0;
		fdf->pos->y++;
	}
}
////	TODO: move to separate `project_map.c` file
void	calculate_points(t_fdf *fdf, int x, int y)
{
	int	theta;
	int	z1;
	int	z2;

	theta = fdf->map->theta;
	z1 = fdf->pts[y][y].z;
	fdf->iso->x0 = (x - y) * cos(theta);
	fdf->iso->y0 = (x + y) * sin(theta) - z1 * fdf->map->zoom;
	fdf->iso->x1 = ((x + 1) - y) * cos(theta);
	fdf->iso->y1 = ((x + 1) + y) * sin(theta) - z1 * fdf->map->zoom;
	fdf->pos->dx = ft_abs(fdf->iso->x1 - fdf->iso->x0);
	fdf->pos->dy = ft_abs(fdf->iso->y1 - fdf->iso->y0);
	if (fdf->iso->x0 < fdf->iso->x1)
		fdf->iso->sx = 1;
	else
		fdf->iso->sx = -1;
	if (fdf->iso->y0 < fdf->iso->y1)
		fdf->iso->sy = 1;
	else
		fdf->iso->sy = -1;
	bresenham()
}

void	projection(t_fdf *fdf, int x, int y)
{
	t_drw	s;
	t_drw	g;
	int	z0;
	int	z1;
	int	theta;

	z0 = fdf->pts[y][x].z;
	z0 = fdf->pts[y + 1][x + 1].z;
	theta = fdf->map->theta;
	s.x = (x - y) * cos(theta);
	s.y = (x + y) * sin(theta) - z0 * fdf->map->zoom;
	g.x = ((x + 1) - y) * cos(theta);
	g.y = ((x + 1) + y) * sin(theta) - z1 * fdf->map->zoom;
	bresenham(fdf, s, g);
}
char	*get_data_addr(void *img)
{
	int	len;
	int	endian;
	int	bpp;
	char	*addr;

	addr = mlx_get_data_addr(img, &bpp, &len, &endian);
	return (addr);
}
void	bresenham(t_fdf *fdf, t_drw s, t_drw g)
{
	while (fdf->iso->x0 != fdf->iso->x1 || fdf->iso->y0 != fdf->iso->y1)
	{
		
	}
}
/* ||*********************Created: 2025/05/12 21:33:42*********************|| */