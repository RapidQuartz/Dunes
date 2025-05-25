/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/25 16:45:22 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	init_map(fdf, fdf->x, fdf->y);
	// init_dim(fdf);
	init_img(fdf, fdf->map, fdf->);
}

void	init_pro(t_fdf *fdf, t_map *map, t_pro **pro)
{
	int	x;
	int	y;
	t_pts	s;

	x = 0;
	y = 0;
	pro = malloc(sizeof(t_pro *) * map->y);
	if (!pro || pro == NULL)
		end_fdf(fdf, 0);
	while (y < map->y)
	{
		while (x < map->x)
		{
			
		}
	}
}
// void	init_dim(t_fdf *fdf)
// {
// 	fdf->dim = malloc(sizeof(t_dim));
// 	if (!fdf->dim || fdf->dim == NULL)
// 		end_fdf(fdf, 0);
// 	fdf->dim->s_x = DEFWID;
// 	fdf->dim->s_y = DEFHEI;
// 	fdf->dim->m_x = 0;
// 	fdf->dim->m_y = 0;
// 	fdf->dim->x_lim = 0;
// 	fdf->dim->y_lim = 0;
// 	fdf->dim->zoom = 1;
// }

void	init_map(t_fdf *fdf, int x, int y)
{
	fdf->map = malloc(sizeof(t_map));
	if (!fdf->map || fdf->map == NULL)
		end_fdf(fdf, 0);
	fdf->map->fd = open(fdf->file, O_RDONLY);
	fdf->map->x = 0;
	fdf->map->y = 0;
	fdf->map->raw = NULL;
	fdf->map->str = NULL;
	fdf->map->lin = NULL;
	fdf->pos = NULL;
	read_map(fdf, fdf->map, fdf->pts);
}

void	init_img(t_fdf *fdf, t_map *map)
{
	fdf->end = malloc(sizeof(t_pro *) * map->y);
	if (!fdf->start || fdf->start == NULL || !fdf->end || fdf->end == NULL)
		end_fdf(fdf, 0);
	while (fdf->y < map->y)
	{
		fdf->pro[fdf->y] = malloc(sizeof(t_pro) * map->x);
		if (!fdf->pro[fdf->y] || fdf->pro[fdf->y] == NULL)
			end_fdf(fdf, 0);
		while (fdf->x < map->x)
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
		end_fdf(fdf, 0);
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
