/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/25 15:07:21 by akjoerse         ###   ########.fr       */
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
		end_fdf(fdf, 0);
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
		end_fdf(fdf, 0);
	fdf->map->fd = open(fdf->file, O_RDONLY);
	fdf->map->x = 0;
	fdf->map->y = 0;
	fdf->map->raw = NULL;
	fdf->map->str = NULL;
	fdf->map->lin = NULL;
	fdf->pos = NULL;
	read_map(fdf, fdf->map);
	
}
/* 
void	set_points(char ***lmn, t_fdf *fdf, int x, int y)
{
	int	lmn_len;
	char	*num;
	char	*col;

	lmn_len = 0;
	col = NULL;
	while (y < fdf->dim->y_lim)
	{
		lmn_len = get_lmn_len(lmn[y][x]);
		if (lmn_len < 0)
			col = extract_color(lmn[y][x], ft_abs(lmn_len));
		else if (lmn_len > 0)
			col = DEFCOL;
		num = get_height(lmn[y][x], ft_abs(lmn_len));
		fdf->pts[y][x].c_color = convert_color(col, lmn_len);
		fdf->pts[y][x].z_height = ft_atoi(num);
		free (num);
		x++;
		if (!lmn[y][x])
		{
			x = 0;
			y++;
		}
	}
	free_map(fdf);
} */

int	get_color(t_fdf *fdf, char *p, int l)
{
	char	*c;
	if (l < 0)
		c = extract_color(p, ft_abs(l));
	else
		c = DEFCOL;
	return (convert_color(p, l))
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
