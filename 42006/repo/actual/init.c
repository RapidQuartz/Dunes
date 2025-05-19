/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:52:37 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/19 12:02:52 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->pts = malloc(sizeof(t_pts));
	fdf->map = malloc(sizeof(t_map));
	fdf->dim = malloc(sizeof(t_dim));
	fdf->iso = malloc(sizeof(t_iso));
	fdf->pos = malloc(sizeof(t_pos));
	if (!fdf->map || !fdf->dim || !fdf->iso || !fdf->pos)
		error();
	init_null_dim(fdf);
	read_mapfile(fdf);
	fdf->map->elements = malloc(sizeof(*fdf->map->elements) * fdf->dim->max_y);
	if (!fdf->map->elements || fdf->map->elements == NULL)
		error ();
	split_map_str(fdf);
}

void	init_null_pts(t_fdf *fdf)
{
	
	//TODO: initialize map->points to the right size.
}
void	init_null_dim(t_fdf *fdf)
{
	fdf->dim->max_x = 0;
	fdf->dim->max_y = 0;
	fdf->dim->s_x = -1;
	fdf->dim->s_y = -1;
	fdf->dim->z_x = -1;
	fdf->dim->z_y = -1;
}

void	read_mapfile(t_fdf *fdf)
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
		fdf->dim->max_y++;
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
	split_map = malloc(sizeof(char *) * fdf->dim->max_y);
	if (!split_map || split_map == NULL)
		error ();
	split_map = ft_split(fdf->map->raw_str, '\n');
	while (split_map[l])
	{
		j = 0;
		fdf->map->elements[l] = ft_split(split_map[l], ' ');
		while (l == 0 && fdf->map->elements[l][fdf->dim->max_x])
			fdf->dim->max_x++;
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
	while (map[j][i])
	{
		if (ft_isdigit(map[j][i]) || map[j][i] == '-')
		{
			k = 0;
			while (ft_isdigit(map[j][i]) || map[j][i] == '-')
				i++;
			set_map_point(fdf, i, j, l);
		}
		if (map[j][i] == ',')
			set_map_color(map[j], i + 3);
		else
			set_map_color(NULL, 0);
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
	// fdf->map->points[l][r] = numb;
}
void	set_map_color(char *map, int i)
{
	int	j;
	int	k;

	j = i;
	k = 0;
	//color should be only color portion of map string
	char	*color;
	if (i == 0 || map == NULL)
		color = DEFCOL;
	else
	{
		while (map[j] != ' ' && map[j] != '\n' && map[j] != '\0')
			j++;
		color = malloc(sizeof(char) * (j - i + 1));
		if (!color || color == NULL)
			exit (0);//TODO:integrate into exit function
		while (i < j)
			color[k] = map[i++];
		color[i] = '\0';
	}
}
