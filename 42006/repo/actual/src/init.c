/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:25:32 by akjoerse          #+#    #+#             */
/*   Updated: 2025/06/03 13:49:52 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_img(t_fdf *f, t_mlx *m)
{
	t_pts	**p;

	p = f->pts;
	f->pro = malloc(sizeof(t_pro));
	if (!f->pro || f->pro == NULL)
		exit (0);//TODO:integrate into exit function
	m->adr = mlx_get_data_addr(m->img, &m->bpp, &m->len, &m->end);
	f->x_off = (DEFWID - (f->x_rng[1] - f->x_rng[0])) / 2 - f->x_rng[0];
	f->y_off = (DEFHEI - (f->y_rng[1] - f->y_rng[0])) / 2 - f->y_rng[0];
	f->y = 0;
	while (f->y < f->y_lim)
	{
		f->x = 0;
		while (f->x < f->x_lim)
		{
			if (f->x + 1 < f->x_lim)
				draw_line(p[f->y][f->x], p[f->y][f->x + 1], f);
			if (f->y + 1 < f->y_lim)
				draw_line(p[f->y][f->x], p[f->y + 1][f->x], f);
			f->x++;
		}
		f->y++;
	}
}

void	init_mlx(t_fdf *f)
{
	t_mlx	*m;

	m = malloc(sizeof(t_mlx));
	if (!m || m == NULL)
		exit (0);//TODO:integrate into exit function
	m->win = NULL;
	m->mlx = NULL;
	m->img = NULL;
	m->adr = NULL;
	m->len = 0;
	m->bpp = 0;
	m->err = 0;
	m->end = 0;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, DEFWID, DEFHEI, "Fer De Fil");
	m->img = mlx_new_image(m->mlx, DEFWID, DEFHEI);
	f->mlx = m;
}

void	init_raw(t_fdf *fdf, char *map_file)
{
	t_raw	raw;
	char	*tmp;

	tmp = NULL;
	fdf->raw = &raw;
	raw.map = open(map_file, O_RDONLY);
	raw.string = get_next_line(raw.map);
	while (raw.map != -1)
	{
		raw.line = get_next_line(raw.map);
		if (raw.line == NULL)
			break ;
		tmp = raw.string;
		raw.string = ft_strjoin(tmp, raw.line);
		free (tmp);
		free (raw.line);
	}
	raw.lines = ft_split(raw.string, '\n');
	free (raw.string);
	while (raw.lines[fdf->y_lim])
		fdf->y_lim++;
	fdf->pts = malloc((sizeof(*fdf->pts) * fdf->y_lim));
	if (!fdf->pts || fdf->pts == NULL)
		exit (0);//TODO:integrate into exit function
	set_points(fdf, fdf->pts, &raw);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	fdf->x_lim = 0;
	fdf->y_lim = 0;
	fdf->x_off = 0;
	fdf->y_off = 0;
	fdf->raw = NULL;
	fdf->mlx = NULL;
	fdf->pts = NULL;
	fdf->pro = NULL;
	fdf->radians = (ANGLE * PI) / 180.0;
	fdf->cosine = cos(fdf->radians);
	fdf->sine = sin(fdf->radians);
	fdf->x_rng[0] = 0;
	fdf->x_rng[1] = 0;
	fdf->y_rng[0] = 0;
	fdf->y_rng[1] = 0;
}
