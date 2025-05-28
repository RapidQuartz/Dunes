/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:33:42 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/28 09:38:29 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/fdf.h"
//
void	derive_trig(t_pts o, t_pts d, t_img *i)
{
	i->dx = ft_abs(d.x - o.x);
	i->dy = -ft_abs(d.y - o.y);
	i->err = i->dx + i->dy;
	if (o.x < d.x)
		i->sx = 1;
	else
		i->sx = -1;
	if (o.y < d.y)
		i->sy = 1;
	else
		i->sy = -1;
}
//
void	draw_line(t_pts o, t_pts d, t_img *i)
{
	derive_trig(o, d, i);
	while (1)
	{
		put_pixel(o.x, o.y, o.c, i);
		if (o.x == d.x && o.y == d.y)
			break ;
		if (2 * i->err >= i->dy)
		{
			i->err += i->dy;
			o.x += i->sx;
		}
		if (2 * i->err <= i->dx)
		{
			i->err += i->dx;
			o.y += i->sy;
		}
	}
}

void	put_pixel(int x, int y, int c, t_img *i)
{
	char	*pix;

	if (x < 0 || x >= DEFWID || y < 0 || y >= DEFHEI)
		return ;
	pix = i->addr + (y * i->len + y * (i->bpp / 8));
	*(unsigned int *)pix = c;
}
//
void	init_img(t_fdf *f, t_img *i, t_pts **p)
{
	i->addr = mlx_get_data_addr(i, &i->bpp, &i->len, &i->endian);
	while (f->y < f->y_lim)
	{
		f->x = 0;
		while (f->x < f->x_lim)
		{
			if (f->x + 1 < f->x_lim)
				draw_line(p[f->y][f->x + 1], p[f->y][f->x], i);
			if (f->y + 1 < f->y_lim)
				draw_line(p[f->y + 1][f->x], p[f->y][f->x], i);
			f->x++;
		}
		f->y++;
	}
}

int	keychain(int key, void *par)
{
	if (key == 65307 || !par)
		exit(0);
	return (0);
}

int	close_handler(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit (0);
	return (0);
}
//
int	main(int arg, char **param)
{
	t_fdf	fdf;
	t_img	*img;

	if (arg != 2 || !check_file(param))
		return (1);
	init_fdf(&fdf);
	init_raw(&fdf, param[1]);
	init_dim(&fdf);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, DEFWID, DEFHEI, "Fer De Fil");
	img = malloc(sizeof(t_img));
	img->img = mlx_new_image(fdf.mlx, DEFWID, DEFHEI);
	fdf.img = img;
	fdf.x = 0;
	fdf.y = 0;
	init_img(&fdf, fdf.img, fdf.pts);
	mlx_hook(fdf.win, 17, 0, close_handler, &fdf);
	mlx_key_hook(fdf.win, keychain, &fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img->img, 0, 0);
	mlx_loop(fdf.mlx);
	printf(RED"just follow me\n"DEF);
}

/* ||*********************Created: 2025/05/12 21:33:42*********************|| */