/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/20 14:30:03 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void	init_fdf(t_fdf *fdf)
{
	int	i;

	i = 0;
	init_map(fdf->map);
	init_iso(fdf->iso);
	init_pro(fdf->pro);
	read_mapfile(fdf);
	split_map_str(fdf);
	init_pts(fdf->pts, fdf->xmax, fdf->ymax);
	while (i < fdf->ymax)
	{
		fdf->pts[i] = malloc(sizeof(t_pts) * fdf->xmax);
		if (!fdf->pts[i] || fdf->pts[i] == NULL)
			exit (0);//TODO:integrate into exit function
		i++;
	}
	set_points(fdf->map->elements, fdf, 0, 0);
}

void	init_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (!map || map == NULL)
		exit (0);//TODO:integrate into exit function
	map->raw_str = NULL;
	map->space_split = NULL;
	map->elements = NULL;
}

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

void	init_pro(t_pro *pro)
{
	pro = malloc(sizeof(t_pro));
	if (!pro || pro == NULL)
		exit (0);//TODO:integrate into exit function
	pro->x0 = 0;
	pro->x1 = 0;
	pro->y0 = 0;
	pro->y1 = 0;
	pro->y2 = 0;
	pro->z0 = 0;
	pro->z1 = 0;
	pro->z2 = 0;
	pro->c0 = 0;
	pro->c1 = 0;
	pro->c2 = 0;
	pro->hx = 0;
	pro->hy = 0;
	pro->vx = 0;
	pro->vy = 0;
}
