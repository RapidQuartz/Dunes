/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:25:38 by akjoerse          #+#    #+#             */
/*   Updated: 2025/06/03 13:54:03 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	extract_color(char *col, int j)
{
	int	i;
	int	hex;

	i = 2 + j;
	hex = 0;
	if (col[j] != ',')
		return (DEFCOL);
	while (col[i])
	{
		hex *= 16;
		hex += ft_hextoi(col[i]);
		i++;
	}
	return (hex);
}

int	get_height(char *num, int end)
{
	int		i;
	char	*height;

	i = 0;
	height = malloc(sizeof(char) * end + 1);
	if (!height || height == NULL)
		exit (0);//TODO:integrate into exit function;
	while (i < end)
	{
		height[i] = num[i];
		i++;
	}
	height[i] = '\0';
	i = ft_atoi(height);
	free (height);
	return (i);
}

t_pts	*meta_segments(t_fdf *f, int y)
{
	t_pts	*p;
	char	**s;
	int		len;
	int		x;

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
		p[x].x = ((x - y) * (f->cosine));
		p[x].y = (((x + y) * (f->sine)) / 2 - (p[x].z * SCALEZ));
		x++;
	}
	return (p);
}

void	get_range(t_pts **p, t_fdf *f)
{
	f->y = 0;
	while (f->y < f->y_lim)
	{
		f->x = 0;
		while (f->x < f->x_lim)
		{
			if (p[f->y][f->x].x < f->x_rng[0])
				f->x_rng[0] = p[f->y][f->x].x;
			if (p[f->y][f->x].x > f->x_rng[1])
				f->x_rng[1] = p[f->y][f->x].x;
			if (p[f->y][f->x].y < f->y_rng[0])
				f->y_rng[0] = p[f->y][f->x].y;
			if (p[f->y][f->x].y > f->y_rng[1])
				f->y_rng[1] = p[f->y][f->x].y;
			f->x++;
		}
		f->y++;
	}
}

void	set_points(t_fdf *f, t_pts **p, t_raw *raw)
{
	int	i;

	while (raw->lines[f->y])
	{
		i = 0;
		raw->segments = ft_split(raw->lines[f->y], ' ');
		free (raw->lines[f->y]);
		while (f->y == 0 && raw->segments[f->x_lim])
			f->x_lim++;
		p[f->y] = meta_segments(f, f->y);
		while (raw->segments[i])
		{
			free (raw->segments[i]);
			i++;
		}
		free (raw->segments);
		f->y++;
	}
	get_range(p, f);
	free (raw->lines);
	proj_zoom(f);
}
