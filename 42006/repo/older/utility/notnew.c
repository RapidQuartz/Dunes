/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:33:42 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/26 18:40:10 by akjoerse         ###   ########.fr       */
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
	fdf.x = 0;
	fdf.y = 0;
	init_fdf(&fdf);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, DEFWID, DEFHEI, "Fer De Fil");
	fdf.bpp = 32;
	fdf.len = 0;
	prepare_image(&fdf);
	draw_image(&fdf);
	printf("just follow me\n");
}

void	free_map(t_fdf *fdf)
{
	int	i;
	int	j;
	t_dim	d;
	
	i = 0;
	d = *fdf->dim;
	while (i < fdf->y_lim)
	{
		j = 0;
		while (j < fdf->x_lim)
		{
			free(fdf->raw->elements[i][j]);
			j++;
		}
		free(fdf->raw->elements[i]);
		i++;
	}
	free (fdf->raw->elements);
	free (fdf->raw->string);
	fdf->raw->string = NULL;
}

////	TODO: move to separate `draw_map.c` file
/* void	prepare_image(t_fdf *fdf)
{
	int	z;
	char	*addr;

	fdf->img = mlx_new_image(fdf->mlx, fdf->dim->s_x, fdf->dim->s_y);//TODO:CHANGE STRUCT
	addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->len, &fdf->endian);
	while (fdf->y < fdf->y_lim - 1)
	{
		while (fdf->x < fdf->x_lim - 1)
		{
			project_origin(fdf, fdf->pro, fdf->x, fdf->y);
			if (fdf->x < fdf->x_lim - 1)
				project_horizontal(fdf, fdf->pro, fdf->x + 1, fdf->y);
				// calculate_points(fdf, fdf->x + 1, fdf->y);
			if (fdf->y < fdf->y_lim - 1)
				project_vertical(fdf, fdf->pro, fdf->x, fdf->y + 1);
				// calculate_points(fdf, fdf->x, fdf->y + 1);
			fdf->x++;
		}
		fdf->x = 0;
		fdf->y++;
	}
} */

////	TODO: move to separate `project_map.c` file
void	calculate_points(t_fdf *fdf, int x, int y, int big)
{
	int	theta;
	int	z[2];

	theta = fdf->t;
	z[0] = fdf->pts[y][x].z;
	z[1] = fdf->pts[y + 1][x + 1].z;
	fdf->iso->x0 = (x - y) * cos(fdf->t);
	fdf->iso->y0 = (x + y) * sin(fdf->t) - z[0] * fdf->map->zoom;
	fdf->iso->x1 = ((x + 1) - y) * cos(fdf->t);
	fdf->iso->y1 = ((x + 1) + y) * sin(fdf->t) - z1 * fdf->map->zoom;
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
	bresenham(fdf);
}

void	bresenham(t_fdf *fdf)
{
	fdf->map->err = fdf->iso->dx - fdf->iso->dy;
	while (fdf->iso->x0 != fdf->iso->x1 || fdf->iso->y0 != fdf->iso->y1)
	{
		
	}
}
/* ||*********************Created: 2025/05/12 21:33:42*********************|| */