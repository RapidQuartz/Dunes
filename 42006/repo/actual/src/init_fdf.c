/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/26 11:37:11 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

//fdf->pro[fdf->y][fdf->x] = get_projection(fdf, fdf->x, fdf->y);
//
void	get_projection(t_fdf *fdf, t_pts **pts, t_pro **pro);
void	null_pro(t_fdf *fdf, t_pro *pro, int x);

//
void	init_mlx(t_fdf *fdf, int width, int height, char *title);
void	init_raw(t_fdf *fdf, char *map_file)
{
	t_raw	raw;

	if (fdf && fdf->raw != NULL || !map_file)
		end_fdf(fdf, 9);
	raw.map = open(map_file, O_RDONLY);
	raw.line = NULL;
	raw.string = NULL;
	raw.lines = NULL;
	raw.elements = NULL;
	fdf->raw = &raw;
}

void	init_fdf(t_fdf *fdf)
{

	
	init_mlx(fdf, fdf->dim->screen_width,
		fdf->dim->screen_height, "Bonjour FdF");
}
// void	init_mlx(t_fdf *fdf, int width, int height, char *title);

void	init_dim(t_fdf *fdf)
{
	t_dim	dim;
	
	if (fdf->dim != NULL)
		return ;
	dim.screen_height = DEFWID;
	dim.screen_height = DEFHEI;
	dim.screen_offset = 0;
	dim.y_max = 0;
	dim.y_max = 0;
	dim.tile_size = 0;
	dim.rotation = 30;
	dim.zoom = 1;
	fdf->dim = &dim;
}

void	init_mlx(t_fdf *fdf, int width, int height, char *title)
{
	fdf->mlx = mlx_init();
	//void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
	fdf->win = mlx_new_window(fdf->mlx, width, height, title);
}

void	init_pts(t_fdf *fdf)
{
	int	x;
	int	y;
	t_dim	d;
	int	i;
	
	i = 0;
	x = 0;
	y = 0;
	d = *fdf->dim;
	fdf->pts = malloc(sizeof(t_pts *) * d.y_max);
	while (y < d.y_max)
	{
		fdf->pts[y] = malloc(sizeof(t_pts) * d.x_max);
		if (!fdf->pts[y] || fdf->pts[y] == NULL)
			end_fdf(fdf, 8);
		while (x < d.x_max)
		{
			fdf->pts[y][x].src = NULL;
			fdf->pts[y][x].dst = NULL;
			x++;
		}
		y++;
	}
	set_points(fdf->raw->elements, fdf, 0, 0);
}

void	init_pro(t_fdf *fdf)
{
	t_dim	d;
	int	y;
	int	x;

	y = 0;
	fdf->pro = malloc(sizeof(t_pro *) * fdf->dim->y_max);
	if (!fdf->pro || fdf->pro == NULL)
		end_fdf(fdf, 79);
	while (y < d.y_max)
	{
		fdf->pro[y] = malloc(sizeof(t_pro) * d.x_max);
		if (!fdf->pro[y] || fdf->pro[y] == NULL)
			end_fdf(fdf, 90);
		null_pro(fdf, fdf->pro[y], 0);
		y++;
	}
	set_pro(fdf);
}


void	set_pro(t_fdf *fdf)
{
	t_dim	d;
	t_pro	src;
	int	*y;
	int	*x;

	y = &fdf->y;
	x = &fdf->x;
	d = *fdf->dim;
	while ((*y) < d.y_max)
	{
		(*x) = 0;
		while ((*x) < d.y_max)
		{
			get_projection(fdf, fdf->pts, fdf->pro);
			src = fdf->pro[(*y)][(*x)];
			if ((*y) < fdf->dim->x_max - 2)
				proj_next_row(fdf, fdf->pts, &src);
			if ((*x) < fdf->dim->y_max - 2)
				proj_next_col(fdf, fdf->pts, &src);
			(*x)++;
		}
		(*y)++;
	}
}

void	null_pro(t_fdf *fdf, t_pro *pro, int x)
{
	while (x >= 0 && x < fdf->dim->x_max)
	{
		pro->x = 0;
		pro->y = 0;
		pro->z = 0;
		pro->c = 0;
		pro->dx = 0;
		pro->dy = 0;
		pro->sx = 0;
		pro->sy = 0;
		x++;
	}
	if (x < 0)
	{
		pro->dx = 0;
		pro->dy = 0;
		pro->sx = 0;
		pro->sy = 0;
	}
}

void	get_projection(t_fdf *fdf, t_pts **pts, t_pro **pro)
{
	t_pro	src;
	t_pts	nts;
	
	nts = pts[fdf->y][fdf->x];
	src = pro[fdf->y][fdf->x];
	nts.src = &src;
	src.z = nts.z_height;
	src.c =  nts.c_color;
	src.x = (fdf->x - fdf->y) * (cos (fdf->t));
	src.y = (fdf->x + fdf->y) * (sin (fdf->t)) - src.z;
}

void	proj_next_col(t_fdf *fdf, t_pts **pts, t_pro *src)
{
	t_pro	src;
	t_pro	x_dst;
	t_pts	pre;
	t_pts	cur;
	
	pre = pts[fdf->y][fdf->x];
	cur = pts[fdf->y][fdf->x + 1];
	src = *pre.src;
	x_dst.x = ((fdf->x + 1) - fdf->y) * (cos (fdf->t));
	x_dst.y = ((fdf->x + 1) + fdf->y) * (sin (fdf->t)) - cur.z_height;
	x_dst.dx = ft_abs(x_dst.x) - ft_abs(src.x);
	x_dst.dy = ft_abs(x_dst.y) - ft_abs(src.y);
	if (x_dst.x > src.x)
		src.sx = 1;
	else
		src.sx = -1;
	pre.x_dst = &x_dst
}

void	proj_next_row(t_fdf *fdf, t_pts **pts, t_pro *src)
{
	t_pro	src;
	t_pro	y_dst;
	t_pts	pre;
	t_pts	cur;
	
	pre = pts[fdf->y][fdf->x];
	cur = pts[fdf->y + 1][fdf->x];
	src = *pre.src;
	y_dst.x = ((fdf->y + 1) - fdf->y) * (cos (fdf->t));
	y_dst.y = ((fdf->y + 1) + fdf->y) * (sin (fdf->t)) - cur.z_height;
	y_dst.dx = ft_abs(y_dst.x) - ft_abs(src.x);
	y_dst.dy = ft_abs(y_dst.y) - ft_abs(src.y);
	if (y_dst.x > src.x)
		src.sy = 1;
	else
		src.sy = -1;
	pre.y_dst = &y_dst;
}
/* 
void	proj_next_row(t_fdf *fdf, t_pts **pts)
{
	t_pro	dst;
	t_pts	nts;
	
	dst = pro[fdf->y + 1][fdf->x];
	nts = pts[fdf->y + 1][fdf->x];
	dst.z = pts[fdf->y][fdf->x + 1].z_height;
	dst.c = pts[fdf->y][fdf->x + 1].c_color;
	dst.x = ((fdf->x + 1) - fdf->y) * (cos (fdf->t));
	dst.y = ((fdf->x + 1) + fdf->y) * (sin (fdf->t)) - pro->z;
	pro->dx = ft_abs(dst.x) - ft_abs(pro->x);
	pro->dy = ft_abs(dst.y) - ft_abs(pro->y);
	if (dst.x > pro->x)
		pro->sx = 1;
	else
		pro->sx = -1;
} */
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