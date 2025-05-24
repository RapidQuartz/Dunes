/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/24 17:55:30 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	init_dim(fdf);
	init_map(fdf, fdf->dim, fdf->x, fdf->y);

	init_img(fdf);
}

void	init_dim(t_fdf *fdf)
{
	fdf->dim = malloc(sizeof(t_dim));
	if (!fdf->dim || fdf->dim == NULL)
		exit (0);//TODO:integrate into exit function
	fdf->dim->s_x = DEFWID;
	fdf->dim->s_y = DEFHEI;
	fdf->dim->m_x = 0;
	fdf->dim->m_y = 0;
	fdf->dim->x_lim = 0;
	fdf->dim->y_lim = 0;
	fdf->dim->zoom = 1;
}

void	init_map(t_fdf *fdf, t_dim *dim, int x, int y)
{
	fdf->map = malloc(sizeof(t_map));
	if (!fdf->map || fdf->map == NULL)
		exit (0);//TODO:integrate into exit function
	fdf->map->fd = open(fdf->file, O_RDONLY);
	fdf->map->line = NULL;
	fdf->map->string = NULL;
	fdf->map->lines = NULL;
	fdf->map->elements = NULL;
	read_raw_map(fdf);
	split_map_str(fdf, fdf->map, x, y);
	fdf->pts = malloc(sizeof(t_pts *) * dim->y_lim);
	if (!fdf->pts || fdf->pts == NULL)
		exit (0);//TODO:integrate into exit function
	while (y < dim->y_lim)
	{
		fdf->pts[y] = malloc(sizeof(t_pts) * dim->x_lim);
		if (!fdf->pts[y] || fdf->pts[y] == NULL)
			exit (0);//TODO:integrate into exit function
		y++;
	}
	set_points(fdf->map->elements, fdf, fdf->x, fdf->y);
}

void	init_img(t_fdf *fdf)
{
	
	fdf->pro = malloc(sizeof(t_pro *) * fdf->dim->y_lim);
	if (!fdf->pro || fdf->pro == NULL)
		exit(0);//TODO:REPLACE
	while (fdf->y < fdf->dim->y_lim)
	{
		fdf->pro[fdf->y] = malloc(sizeof(t_pro) * fdf->dim->x_lim);
		if (!fdf->pro[fdf->y] || fdf->pro[fdf->y] == NULL)
			exit(0);//TODO:REPLACE
		while (fdf->x < fdf->dim->x_lim)
		{
			get_projection(fdf, fdf->pts, &fdf->pro[fdf->y][fdf->x]);
			fdf->x++;
		}
		fdf->x = 0;
		fdf->y++;
	}
}

void	init_mlx(t_fdf *fdf)
{
	char	*addr;
	t_mlx	*mlx;

	fdf->mlx = malloc(sizeof(t_mlx));
	if (!fdf->mlx || fdf->mlx == NULL)
		exit (0);//TODO:integrate into exit function
	mlx = fdf->mlx;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr,
		fdf->dim->s_x, fdf->dim->s_y, "Bonjour FdF");
	mlx->img = mlx_new_image(mlx->ptr, fdf->dim->s_x, fdf->dim->s_y);
	if (!mlx->img)
		end_fdf(fdf, 1);
	addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->len, &mlx->end);
	mlx->addr = addr;
	mlx_key_hook(mlx->win, key_handler, fdf);
	mlx_hook(mlx->win, 17, 0, close_handler, fdf);
}
