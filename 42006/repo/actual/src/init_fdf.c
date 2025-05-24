/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/23 11:49:01 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

//fdf->pro[fdf->y][fdf->x] = get_projection(fdf, fdf->x, fdf->y);
//
void	get_projection(t_fdf *fdf, t_pts **pts, t_pro *pro);
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
			get_projection(fdf, fdf->pts, &fdf->pro[fdf->y][fdf->x]);
			fdf->x++;
		}
		fdf->x = 0;
		fdf->y++;
	}
}

void	get_projection(t_fdf *fdf, t_pts **pts, t_pro *pro)
{
	pro->z = pts[fdf->y][fdf->x].z_height;
	pro->c =  pts[fdf->y][fdf->x].c_color;
	pro->x = (fdf->x - fdf->y) * (cos (fdf->dim->rotation));
	pro->y = (fdf->x + fdf->y) * (sin (fdf->dim->rotation)) - pro->z;
	if (fdf->x < fdf->dim->rows - 1)
		proj_next_row(fdf, pts, pro);
	if (fdf->y < fdf->dim->columns - 1)
		proj_next_col(fdf, pts, pro);
}

void	proj_next_row(t_fdf *fdf, t_pts **pts, t_pro *pro)
{
	pro->zx = pts[fdf->y][fdf->x + 1].z_height;
	pro->cx = pts[fdf->y][fdf->x + 1].c_color;
	pro->xx = ((fdf->x + 1) - fdf->y) * (cos (fdf->dim->rotation));
	pro->yx = ((fdf->x + 1) + fdf->y) * (sin (fdf->dim->rotation)) - pro->zx;
	pro->d = ft_abs(pro->xx) - ft_abs(pro->x);
	pro->dx = ft_abs(pro->yx) - ft_abs(pro->y);
	if (pro->xx > pro->x)
		pro->sx = 1;
	else
		pro->sx = -1;	
}

void	proj_next_col(t_fdf *fdf, t_pts **pts, t_pro *pro)
{
	pro->zy = pts[fdf->y + 1][fdf->x].z_height;
	pro->cy =  pts[fdf->y + 1][fdf->x].c_color;
	pro->xy = (fdf->x - (fdf->y + 1)) * (cos (fdf->dim->rotation));
	pro->yy = (fdf->x + (fdf->y + 1)) * (sin (fdf->dim->rotation)) - pro->zy;
	pro->dy = ft_abs(pro->yy) - ft_abs(pro->y);
	if (pro->yy > pro->y)
	pro->sy = 1;	
	else
		pro->sy = -1;
}
/* res.z -- `int` for height at x, y
res.zx -- `int` for height at x + 1, y
res.zy -- `int` for height at x, y + 1
res.c --  `int` fir color at x, y
res.cx --  `int` fir color at x + 1, y
res.cy --  `int` fir color at x, y + 1
res.x -- ((x - y) * (cos (30))) at x, y
res.xy -- ((x - (y + 1)) * (cos (30))) at x, y + 1
res.xx -- (((x + 1) - y) * (cos (30))) at x + 1, y
res.y --  ((x + y) * (sin (30))  at x, y
res.yx --  ((x + (y + 1)) * (sin (30))) at at x + 1, y
res.yy --  (((x + 1) + y) * (sin (30))) at  at x, y + 1
res.dx -- (ft_abs(xx) - ft_abs(x)) at x, y
res.dy -- (ft_abs(yx) - ft_abs(y)) at x, y + 1
res.dxy -- (ft_abs(yy) - ft_abs(y)) at x + 1, y
res.sx --
{
if (res.xx > res.x)
	res.sx = 1;
else
	res.sx = -1;	
}
res.sy --
{
if (res.yy > res.y)
	res.sy = 1;	
else
	res.sy = -1;
}

d	--	ft_abs(xx) - ft_abs(x)
dx	--	ft_abs(yx) - ft_abs(y)
dy	--	ft_abs(yy) - ft_abs(y)
*/
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