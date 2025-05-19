/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/19 14:58:20 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"
char	*extract_color(char *col, int start);
void	init_points(char ***lmn, t_fdf *fdf, int x, int y);
int	get_lmn_len(char *lmn);
t_pts	plot_point(char *hei, char *col, t_pts pts);
int	convert_color(char *col);
char	*extract_height(char *num, int end);

void	init_fdf(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->map = malloc(sizeof(t_map));
	fdf->dim = malloc(sizeof(t_dim));
	fdf->iso = malloc(sizeof(t_iso));
	fdf->pos = malloc(sizeof(t_pos));
	if (!fdf->map || !fdf->dim || !fdf->iso || !fdf->pos)
		error();
	init_null_dim(fdf);
	read_mapfile(fdf);
	split_map_str(fdf);
	fdf->pts = malloc(sizeof(t_pts *) * fdf->dim->max_y);
	if (!fdf->pts || fdf->pts == NULL)
		exit (0);//TODO:integrate into exit function
	while (i < fdf->dim->max_y)
	{
		fdf->pts[i] = malloc(sizeof(t_pts) * fdf->dim->max_x);
		if (!fdf->pts[i] || fdf->pts[i] == NULL)
			exit (0);//TODO:integrate into exit function
		i++;
	}
	init_points(fdf->map->elements, fdf, 0, 0);
	free_map(fdf->map, fdf->dim);
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

void	init_points(char ***lmn, t_fdf *fdf, int x, int y)
{
	int	i;
	int	lmn_len;
	char	*num;
	char	*col;

	lmn_len = 0;
	while (y < fdf->dim->max_y)
	{
		i = 0;
		lmn_len = get_lmn_len(lmn[y][x]);
		if (lmn_len < 0)
			col = extract_color(lmn[y][x], -lmn_len);
		else if (lmn_len > 0)
			col = DEFCOL;
		lmn_len = ft_abs(lmn_len);
		num = extract_height(lmn[y][x], lmn_len);
		fdf->pts[y][x] = plot_point(num, col, fdf->pts[y][x]);
		x++;
		if (!lmn[y][x])
		{
			x = 0;
			y++;
		}
	}
}
t_pts	plot_point(char *hei, char *col, t_pts pts)
{
	pts.c = convert_color(col);
	pts.z = ft_atoi(hei);
	return (pts);
}

int	convert_color(char *col)
{
	int	i;
	int	hex;
	
	i = 2;
	hex = 0;
	while (col[i])
	{
		hex *= 16;
		hex += ft_hextoi(col[i]);
		i++;
	}
	return (hex);	
}

char	*extract_height(char *num, int end)
{
	int	i;
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
	return (height);
}

char	*extract_color(char *col, int start)
{
	int	len;
	int	i;
	char	*out;
	
	i = 0;
	len = ft_strlen(col + start);
	out = malloc(sizeof(char) * len + 1);
	if (!out || out == NULL)
		return (NULL);
	while (col[start + i] != '\0' && i < len)
	{
		out[i] = col[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

int	get_lmn_len(char *lmn)
{
	int	i;
	
	i = 0;
	while (lmn[i])
	{
		if (lmn[i] == ',')
			return (-i);
		i++;
	}
	return (i);
}