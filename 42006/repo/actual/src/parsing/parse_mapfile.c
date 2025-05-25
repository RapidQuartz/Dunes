/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:04:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/25 16:39:11 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

void	read_map(t_fdf *fdf, t_map *map, t_pts **pts)
{
	while (map->fd != -1)
	{
		map->raw = get_next_line(map->fd);
		if (!map->raw)
			break ;
		if (map->str)
			map->str = ft_strjoin(map->str, map->raw);
		else
			map->str = ft_strdup(map->raw);
		free (map->raw);
	}
	map->lin = ft_split(map->str, '\n');
	free (map->str);
	split_map_str(fdf, map, 0, 0);
	fdf->pts = malloc(sizeof(t_pts *) * map->y);
	if (!fdf->pts || fdf->pts == NULL)
		end_fdf(fdf, 0);
	while (fdf->y < map->y)
	{
		fdf->pts[fdf->y] = malloc(sizeof(t_pts) * map->x);
		if (!fdf->pts[fdf->y] || fdf->pts[fdf->y] == NULL)
			end_fdf(fdf, 0);
	}
	set_points(fdf, map, fdf->pts, 0);
}

void	split_map_str(t_fdf *fdf, t_map *map, int x, int y)
{

	while (map->lin[map->y])
		map->y++;
	fdf->pos = malloc(sizeof(*fdf->pos) * map->y);
	if (!fdf->pos || fdf->pos == NULL)
		end_fdf(fdf, 0);
	while (map->lin[y])
	{
		fdf->pos[y] = ft_split(map->lin[y], ' ');
		while (y == 0 && fdf->pos[y][x])
			x++;
		y++;
	}
	map->x = x;
	free (map->lin);
}

void	set_points(t_fdf *fdf, t_map *map, t_pts **pts, int len)
{
	char	*p;
	t_pts	*s;

	fdf->x = 0;
	fdf->y = 0;
	while (fdf->y < map->y)
	{
		s = fdf->pts[fdf->y];
		p = map->pts[fdf->y][fdf->x];
		len = get_lmn_len(p);
		s[fdf->x].c = get_color(fdf, p, len);
		s[fdf->x].z = get_height(fdf, p, ft_abs(len));
		fdf->x++;
		if (fdf->x == map->x)
		{
			fdf->x = 0;
			fdf->y++;
		}
	}
	len = 0;
	while (map->pts[len])
		free (map->pts[len++]);
	free (map->pts);
}
