/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/28 09:40:57 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

//fdf->pro[fdf->y][fdf->x] = get_projection(fdf, fdf->x, fdf->y);
//
void	null_pro(t_fdf *fdf, int x, int y);
void	set_pro(t_fdf *f, t_pts **p, t_pro **r);

//
void	init_mlx(t_fdf *fdf, int width, int height, char *title);
void	init_raw(t_fdf *fdf, char *map_file)
{
	t_raw	raw;
	
	fdf->raw = &raw;
	raw.map = open(map_file, O_RDONLY);
	raw.string = get_next_line(raw.map);
	while (raw.map != -1)
	{
		raw.line = get_next_line(raw.map);
		if (raw.line == NULL)
			break;
		raw.string = ft_strjoin(raw.string, raw.line);
	}
	raw.lines = ft_split(raw.string, '\n');
	while (raw.lines[fdf->y_lim])
		fdf->y_lim++;
	fdf->pts = malloc((sizeof(*fdf->pts) * fdf->y_lim));
	while (raw.lines[fdf->y])
	{
		raw.segments = ft_split(raw.lines[fdf->y], ' ');
		while (raw.segments[fdf->x_lim] && fdf->y == 0)
			fdf->x_lim++;
		fdf->pts[fdf->y] = meta_segments(fdf, fdf->y);
		free (raw.segments);
		fdf->y++;
	}
}

t_pts	*meta_segments(t_fdf *f, int y)
{
	t_pts	*p;
	char	**s;
	int	len;
	int	x;

	x = 0;
	p = malloc(sizeof(t_pts) * f->x_lim);
	if (!p || p == NULL)
		return (NULL);
	s = f->raw->segments;
	while (s[x])
	{
		len = get_lmn_len(s[x]);
		p[x].c = extract_color(s[x], ft_abs(len));
		p[x].z = get_height(s[x], ft_abs(len));
		p[x].x = (x - y * (cos (30)));
		p[x].y = (x + y * (sin (30)) - p[x].z);
		x++;
	}
	return (p);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	fdf->x_lim = 0;
	fdf->y_lim = 0;
	fdf->e = 0;
	fdf->b = 0;
	fdf->l = 0;
	fdf->t = 0;
	fdf->co = 0;
	fdf->si = 0;
	fdf->max = NULL;
	fdf->raw = NULL;
	fdf->map = NULL;
	fdf->dim = NULL;
	fdf->mlx = NULL;
	fdf->img = NULL;
	fdf->win = NULL;
	fdf->pts = NULL;
	fdf->pro = NULL;
}
// void	init_mlx(t_fdf *fdf, int width, int height, char *title);


void	init_mlx(t_fdf *fdf, int width, int height, char *title)
{
	fdf->mlx = mlx_init();
	//void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
	fdf->win = mlx_new_window(fdf->mlx, width, height, title);
}

// void	init_pts(t_fdf *fdf)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	fdf->pts = malloc(sizeof(t_pts *) * fdf->y_lim);
// 	while (y < fdf->y_lim)
// 	{
// 		x = 0;
// 		fdf->pts[y] = malloc(sizeof(t_pts) * fdf->x_lim);
// 		if (!fdf->pts[y] || fdf->pts[y] == NULL)
// 			end_fdf(fdf, 8);
// 		while (x < fdf->x_lim)
// 		{
// 			fdf->pts[y][x].src = NULL;
// 			fdf->pts[y][x].x_dst = NULL;
// 			fdf->pts[y][x].y_dst = NULL;
// 			x++;
// 		}
// 		y++;
// 	}
// 	// set_points(fdf->raw->elements, fdf, 0, 0);
// }
/* 
void	init_pro(t_fdf *fdf)
{
	int	y;

	y = 0;
	fdf->pro = malloc(sizeof(t_pro *) * fdf->y_lim);
	if (!fdf->pro || fdf->pro == NULL)
		end_fdf(fdf, 79);
	while (y < fdf->y_lim)
	{
		fdf->pro[y] = malloc(sizeof(t_pro) * fdf->x_lim);
		if (!fdf->pro[y] || fdf->pro[y] == NULL)
			end_fdf(fdf, 90);
		y++;
	}
	set_pro(fdf, fdf->pts, fdf->pro);
} */
// null_pro(fdf, fdf->pro[y], 0, 0);
// null_pro(fdf, 0, 0);

//reverse order
	//always set x/y/z/c
	//always set pts->src
//check if x > 0
	// calculate xco for x - 1
	/* 
void	proj_last_row(t_fdf *fdf, t_pro src, t_pts pts)
{
	src.
}
void	proj_last_col(t_fdf *fdf, t_pro src, t_pts pts)
{
	src.
} */
//check if y > 0
	// calculate yco for y - 1
/* 
void	proj_line_horizontal(t_fdf *fdf, t_pro *src, t_pro *dst)
{
	dst->x = (((fdf->x + 1) - fdf->y) * (cos (fdf->t)));
	dst->y = (((fdf->x + 1) + fdf->y) * (sin (fdf->t)) - dst->z);
	src->x_dst->dx = ft_abs(src->x1 - src->x0);
	src->x_dst->dy = ft_abs(src->y1 - src->y0);
	if (src->x0 < src->x1)
		src->x_dst->sx = 1;
	else
		src->x_dst->sx = -1;
	if (src->y0 < src->y1)
		src->x_dst->sy = 1;
	else
		src->x_dst->sy = -1;
}
void	proj_line_vertical(t_fdf *fdf, t_pro *src, t_pro *dst)
{
	src->x1 = (((fdf->x) - fdf->y + 1) * (cos (fdf->t)));
	src->y1 = (((fdf->x) + fdf->y + 1) * (sin (fdf->t)) - dst->z);
	src->y_dst->dx = ft_abs(src->x1 - src->x0);
	src->y_dst->dy = ft_abs(src->y1 - src->y0);
	if (src->x0 < src->x1)
		src->y_dst->sx = 1;
	else
		src->y_dst->sx = -1;
	if (src->y0 < src->y1)
		src->y_dst->sy = 1;
	else
		src->y_dst->sy = -1;
} */
void	set_pro(t_fdf *fdf, t_pts **pts, t_pro **pro)
{
	t_pro c;

	while (fdf->y < fdf->y_lim - 1)
	{
		fdf->x = 0;
		while (fdf->x < fdf->x_lim - 1)
		{
			c = pro[fdf->y][fdf->x];
			c.z[0] = pts[fdf->y][fdf->x].z;
			c.x[0] = ((fdf->x - fdf->y) * (fdf->co));
			c.y[0] = ((fdf->x + fdf->y) * (fdf->si) - c.z[0]);
			if (fdf->x + 1 < fdf->x_lim - 1)
				proj_hori(fdf, &c);
			if (fdf->y + 1 < fdf->y_lim - 1)
				proj_vert(fdf, &c);
			fdf->x++;
		}
		fdf->y++;
	}
}
/* 	if (x_dst.x > src.x)
		src.sx = 1;
	else
		src.sx = -1; */
void	proj_hori(t_fdf *f, t_pro *c)
{
	c->z[1] = f->pts[f->y][f->x + 1].z;
	c->x[1] = ((f->x - f->y) * (f->co));
	c->y[1] = ((f->x + f->y) * (f->si) - c->z[1]);
	c->dx[0] = (ft_abs(c->x[1]) - ft_abs(c->x[0]));
	c->dy[0] = (ft_abs(c->y[1]) - ft_abs(c->y[0]));
	if (c->x[1] > c->x[0])
		c->sx[0] = 1;
	else
		c->sx[0] = -1;
	if (c->y[1] > c->y[0])
		c->sy[0] = 1;
	else
		c->sy[0] = -1;
}

void	proj_vert(t_fdf *f, t_pro *c)
{
	c->z[2] = f->pts[f->y + 1][f->x].z;
	c->x[2] = ((f->x - f->y) * (f->co));
	c->y[2] = ((f->x + f->y) * (f->si) - c->z[2]);
	c->dx[1] = (ft_abs(c->x[2]) - ft_abs(c->x[0]));
	c->dy[1] = (ft_abs(c->y[2]) - ft_abs(c->y[0]));
	if (c->x[2] > c->x[0])
		c->sx[1] = 1;
	else
		c->sx[1] = -1;
	if (c->y[2] > c->y[0])
		c->sy[1] = 1;
	else
		c->sy[1] = -1;
}
/* 
	t_pts	o;
	t_pts x;
	t_pts y;
	fdf->co = cos (fdf->t);
	fdf->si = sin (fdf->t);
	while (fdf->y < fdf->y_lim - 1)
	{
		fdf->x = 0;
		while (fdf->x < fdf->x_lim - 1)
		{
			o = p[fdf->y][fdf->x];
			o.src->x = ((fdf->x - fdf->y) * (fdf->co));
			o.src->y = ((fdf->x + fdf->y) * (fdf->si) - o.z);
			if (fdf->x + 1 < fdf->x_lim - 1)
			{
				o.x_dst->x = (((fdf->x + 1) - fdf->y) * (cos (fdf->t)));
				o.x_dst->y = (((fdf->x + 1) + fdf->y) * (sin (fdf->t)));
				proj_line_horizontal(fdf, &o.src, &o.x_dst);
			}
			x = p[fdf->y][fdf->x + 1];
			if (fdf->y + 1 < fdf->y_lim - 1)
			{
				o.y_dst = &p[fdf->y + 1][fdf->x];
				y = p[fdf->y + 1][fdf->x];
				proj_line_vertical(fdf, &o.src, &o.y_dst);
			}
		}
		
	}
}
 *//* 
void	set_pro(t_fdf *fdf)
{
	t_dim	d;
	t_pro	src;
	int	*y;
	int	*x;

	y = &fdf->y;
	x = &fdf->x;
	d = *fdf->dim;
	while (fdf->y < fdf->y_lim)
	{
		fdf->x = 0;
		while (fdf->x < fdf->y_lim)
		{
			get_projection(fdf, fdf->pts, fdf->pro);
			src = fdf->pro[fdf->y][fdf->x];
			if (fdf->y < fdf->x_lim - 2)
				proj_next_row(fdf, fdf->pts, src);
			if (fdf->x < fdf->y_lim - 2)
				proj_next_col(fdf, fdf->pts, src);
			fdf->x++;
		}
		fdf->y++;
	}
} */
/* 
void	null_pro(t_fdf *fdf, int x, int y)
{
	int	i;

	y = 0;
	while (y < fdf->y_lim)
	{
		x = 0;
		while (x < fdf->x_lim)
		{
			i = 0;
			while (i < 3)
			{
				fdf->pro[y]->dx[i] = 0;
				fdf->pro[y]->dy[i] = 0;
				fdf->pro[y]->sx[i] = 0;
				fdf->pro[y]->sy[i] = 0;
				fdf->pro[y]->x[i] = 0;
				fdf->pro[y]->y[i] = 0;
				fdf->pro[y]->z[i] = 0;
				i++;
			}
			x++;
		}
		y++;
	}
} */

/*
thing is, I basically have to retroactively apply the slope stuff

see, this is how it goes:

if::::
	x is within bounds && y is within bounds
then:::
:if::
	x is greater than 0
::then:
	calculate::::
		x-x-destination for x - 1
		y-x-destination for x - 1
		dx-distance for x - 1
		dy-distance for x - 1
:if::
	y is greater than 0
::then:
	calculate::::
		x-y-destination for y - 1
		y-y-destination for y - 1
		dx-distance for y - 1
		dy-distance for y - 1
then:
	increase x
if::
	x is not within bounds
:then:
	increase y
	set x = 0
if::
	y is not within bounds
then:
	finish
else:
	loop
	
	

*/
/* 
void	proj_last_col(t_fdf *fdf, t_pts pre, t_pts cur, t_pro src)
{
	t_pro	x_dst;
	
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

// void	proj_last_row(t_fdf *fdf, t_pts **pts, t_pro src)
void	proj_last_row(t_fdf *fdf, t_pts pre, t_pts cur, t_pro src)
{
	t_pro	y_dst;
	
	y_dst.x = (fdf->x - (fdf->y)) * (cos (fdf->t));
	y_dst.y = (fdf->x + (fdf->y)) * (sin (fdf->t)) - cur.z;
	y_dst.dx = ft_abs(y_dst.x) - ft_abs(src.x);
	y_dst.dy = ft_abs(y_dst.y) - ft_abs(src.y);
	if (y_dst.x > src.x)
		src.sy = 1;
	else
		src.sy = -1;
	pre.y_dst = &y_dst;
} */
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