/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/20 08:55:30 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void	init_fdf(t_fdf *fdf)
{
	int	i;

	i = 0;
	init_map(fdf->map);
	init_iso(fdf->iso);
	read_mapfile(fdf);
	split_map_str(fdf);
	init_pts(fdf->pts, fdf->xmax, fdf->ymax);
	fdf->pts = malloc(sizeof(t_pts *) * fdf->ymax);
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

void	init_pts(t_pts **pts, int xmax, int ymax, int y)
{
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
