/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:04:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/24 17:47:51 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

void	read_raw_map(t_fdf *fdf)
{
	char		*raw;

	while (fdf->map->fd != -1)
	{
		fdf->map->line = get_next_line(fdf->map->fd);
		if (!fdf->map->line)
			break ;
		if (raw)
			raw = ft_strjoin(raw, fdf->map->line);
		else
			raw = ft_strdup(fdf->map->line);
		free (fdf->map->line);
	}
	fdf->map->string = malloc(sizeof(raw));
	if (!fdf->map->string || fdf->map->string == NULL)
		exit (0);//TODO:integrate into exit function
	fdf->map->string = ft_strdup(raw);
	free (raw);
}

void	split_map_str(t_fdf *fdf, t_map *map, int x, int y)
{
	char	**split_map;

	split_map = ft_split(map->string, '\n');
	while (split_map[y])
		y++;
	fdf->dim->y_lim = y;
	map->elements = malloc(sizeof(*map->elements) * y);
	if (!map->elements || map->elements == NULL)
		exit (0);//TODO:integrate into exit function
	y = 0;
	while (split_map[y])
	{
		map->elements[y] = ft_split(split_map[y], ' ');
		while (y == 0 && map->elements[y][x])
			x++;
		y++;
	}
	fdf->dim->x_lim = x;
	free (split_map);
}
