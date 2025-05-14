/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:52:37 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/14 14:35:54 by akjoerse         ###   ########.fr       */
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
	int	l;
	int	j;

	l = 0;
	j = 0;
	split_map = malloc(sizeof(char *) * fdf->dim->m_y);
	if (!split_map || split_map == NULL)
		error ();
	split_map = ft_split(fdf->map->raw_str, '\n');
	while (split_map[l])
	{
		j = 0;
		fdf->map->elements[l] = ft_split(split_map[l], ' ');
		while (l == 0 && fdf->map->elements[l][fdf->dim->m_x])
			fdf->dim->m_x++;
		while (fdf->map->elements[l][j])
			printf("[%s]", fdf->map->elements[l][j++]);
		split_map_color(fdf->map->elements[l], l, fdf);
		printf("\n");
		l++;
	}
}

void	split_map_color(char **map, int l, t_fdf *fdf)
{
	int	i;
	int	j;
	int	k;
	
	i = 0;
	j = 0;
	while (map[j][i]);
	{
		if (ft_isdigit(map[j][i]) || map[j][i] == '-')
		{
			k = 0;
			while (ft_isdigit(map[j][i]) || map[j][i] == '-')
				i++;
			set_map_point(fdf, i, j, l);
		}
		if (map[j][i] == ',')
			set_map_color(map, j, i + 3, fdf);
		else
			set_map_color(NULL, j, 0, fdf);
		j++;
		i = 0;
	}
}
void	set_map_point(t_fdf *fdf, int k, int r, int l)
{
	char	*lmnt;
	int	numb;
	int	i;
	
	i = -1;
	lmnt = malloc(sizeof(char) * k);
	if (!lmnt || lmnt == NULL)
		error();
	while (++i < k)
		lmnt[i] = fdf->map->elements[l][r][i];
	numb = ft_atoi(lmnt);
	fdf->map->points[l][r] = numb;
}
void	set_map_color(char **map, int j, int i, t_fdf *fdf)
{
	
	char	*color;
	if (i == 0 || map == NULL)
		color = DEFCOL;
	else
		color = ft_strdup
}