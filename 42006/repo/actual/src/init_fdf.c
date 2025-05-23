/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/23 09:53:28 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

//fdf->pro[fdf->y][fdf->x] = get_projection(fdf, fdf->x, fdf->y);
//
t_pro	get_projection(t_fdf *fdf, t_pts **pts, int x, int y);
//
void	init_mlx(t_fdf *fdf, int width, int height, char *title);
void	init_raw(t_fdf *fdf, char *map_file)
{
	fdf->raw = malloc(sizeof(t_raw));
	if (!fdf->raw || fdf->raw == NULL)
		exit (0);//TODO:integrate into exit function
	fdf->raw->map = open(map_file, O_RDONLY);
	fdf->raw->line = NULL;
	fdf->raw->string = NULL;
	fdf->raw->lines = NULL;
	fdf->raw->elements = NULL;
	read_raw_map(fdf);
}

void	init_fdf(t_fdf *fdf)
{
	int	i;
	
	i = 0;
	init_dim(fdf);
	// init_iso(fdf->iso);
	split_map_str(fdf);
	init_pro(fdf->pro);
	init_pts(fdf->pts, fdf->dim->map_height, fdf->dim->map_height);
	while (i < fdf->dim->map_height)
	{
		fdf->pts[i] = malloc(sizeof(t_pts) * fdf->dim->map_height);
		if (!fdf->pts[i] || fdf->pts[i] == NULL)
		exit (0);//TODO:integrate into exit function
		i++;
	}
	set_points(fdf->raw->elements, fdf, 0, 0);
	init_mlx(fdf, fdf->dim->screen_width,
		fdf->dim->screen_height, "Bonjour FdF");
}
// void	init_mlx(t_fdf *fdf, int width, int height, char *title);

void	init_dim(t_fdf *fdf)
{
	fdf->dim = malloc(sizeof(t_dim));
	if (!fdf->dim || fdf->dim == NULL)
	exit (0);//TODO:integrate into exit function
	fdf->dim->screen_height = DEFWID;
	fdf->dim->screen_height = DEFHEI;
	fdf->dim->screen_offset = 0;
	fdf->dim->map_height = 0;
	fdf->dim->map_height = 0;
	fdf->dim->tile_size = 0;
	fdf->dim->rotation = 30;
	fdf->dim->zoom = 1;
}

void	init_mlx(t_fdf *fdf, int width, int height, char *title)
{
	fdf->mlx = mlx_init();
	//void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
	fdf->win = mlx_new_window(fdf->mlx, width, height, title);
}

void	init_pts(t_pts **pts, int xmax, int ymax)
{
	int	y;
	
	y = 0;
	pts = malloc(sizeof(t_pts *) * ymax);
	if (!pts || pts == NULL)
	exit (0);//TODO:integrate into exit function
	while (y < ymax)
	{
		pts[y] = malloc(sizeof(t_pts) * xmax);
		if (!pts[y] || pts[y] == NULL)
		exit (0);//TODO:integrate into exit function
		y++;
	}
}

void	init_pro(t_fdf *fdf)
{
	fdf->pro = malloc(sizeof(t_pro *) * fdf->dim->rows);
	if (!fdf->pro || fdf->pro == NULL)
		exit(0);//TODO:REPLACE
	while (fdf->y < fdf->dim->rows)
	{
		fdf->pro[fdf->y] = malloc(sizeof(t_pro) * fdf->dim->columns);
		if (!fdf->pro[fdf->y] || fdf->pro[fdf->y] == NULL)
			exit(0);//TODO:REPLACE
		while (fdf->x < fdf->dim->columns)
		{
			fdf->pro[fdf->y][fdf->x] = get_projection(fdf, fdf->x, fdf->y);
			fdf->x++;
		}
		fdf->x = 0;
		fdf->y++;
	}
}

t_pro	get_projection(t_fdf *fdf, t_pts **pts, int x, int y)
{
	t_pro	res;

	res.z = pts[y][x].z_height;
	res.zx = pts[y][x + 1].z_height;
	res.zy = pts[y + 1][x].z_height;
	res.c =  pts[y][x].c_color;
	res.cx = pts[y][x + 1].c_color;
	res.cy =  pts[y + 1][x].c_color;
	res.x = (x - y) * (cos (fdf->dim->rotation));
	res.xx = ((x + 1) - y) * (cos (fdf->dim->rotation));
	res.y = (x + y) * (sin (fdf->dim->rotation)) - res.z;
	res.yx = ((x + 1) + y) * (sin (fdf->dim->rotation)) - res.zx;
	res.yy = (x + (y + 1)) * (sin (fdf->dim->rotation)) - res.zy;
	res.dx = ft_abs(res.xx);
	res.dy = ft_abs();
	return (res);
}

/* 
	dx = ft_abs(x1 - x0)
	dy = ft_abs(y1 - y0)

	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	
	if (y0 < y1)
		sy = 1;
	else
		sy = -1; */


//TODO: move to projection file



/* //DEPRECATED
void	init_iso(t_iso *iso)
{
	iso = malloc(sizeof(t_iso));
	if (!iso || iso == NULL)
		exit (0);//TODO:integrate into exit function
	iso->offset = 0;
	iso->x0 = 0;
	iso->y0 = 0;
	iso->x1 = 0;
	iso->y1 = 0;
	iso->dx = 0;
	iso->dy = 0;
	iso->sx = 0;
	iso->sy = 0;
} */