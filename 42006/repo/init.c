/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:52:37 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/14 13:08:24 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->map = malloc(sizeof(t_map));
	fdf->dim = malloc(sizeof(t_dim));
	fdf->iso = malloc(sizeof(t_iso));
	fdf->pos = malloc(sizeof(t_pos));
	if (!fdf->map || !fdf->dim || !fdf->iso || !fdf->pos)
		error();
	init_null_dim(fdf);
	read_map_file(fdf);
	fdf->map->elements = malloc(sizeof(*fdf->map->elements) * fdf->dim->m_y);
	if (!fdf->map->elements || fdf->map->elements == NULL)
		error ();
	split_map_str(fdf);
}

void	init_null_dim(t_fdf *fdf)
{
	fdf->dim->m_x = 0;
	fdf->dim->m_y = 0;
	fdf->dim->s_x = -1;
	fdf->dim->s_y = -1;
	fdf->dim->z_x = -1;
	fdf->dim->z_y = -1;
}

void	read_map_file(t_fdf *fdf)
{
	char		*raw;
	char		*line;

	raw = NULL;
	line = NULL;
	while (fdf->fd != -1)
	{
		line = get_next_line(fdf->fd);
		if (!line)
			break ;
		fdf->dim->m_y++;
		if (raw)
			raw = ft_strjoin(raw, line);
		else
			raw = ft_strdup(line);
		free (line);
	}
	fdf->map->raw_str = malloc(sizeof(raw));
	if (!fdf->map->raw_str || fdf->map->raw_str == NULL)
		error();
	fdf->map->raw_str = ft_strdup(raw);
	free (raw);
}

void	split_map_str(t_fdf *fdf)
{
	char	**split_map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	split_map = malloc(sizeof(char *) * fdf->dim->m_y);
	if (!split_map || split_map == NULL)
		error ();
	split_map = ft_split(fdf->map->raw_str, '\n');
	while (split_map[i])
	{
		j = 0;
		fdf->map->elements[i] = ft_split(split_map[i], ' ');
		while (i == 0 && fdf->map->elements[i][fdf->dim->m_x])
			fdf->dim->m_x++;
		while (fdf->map->elements[i][j])
			printf("[%s]", fdf->map->elements[i][j++]);
		printf("\n");
		i++;
	}
}
