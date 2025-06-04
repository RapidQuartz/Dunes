/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:25:49 by akjoerse          #+#    #+#             */
/*   Updated: 2025/06/03 16:19:58 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	put_pixel(int x, int y, int c, t_mlx *i)
{
	char	*pix;

	if (x < 0 || x >= DEFWID || y < 0 || y >= DEFHEI)
		return ;
	pix = i->adr + (y * i->len + x * (i->bpp / 8));
	*(unsigned int *)pix = c;
}

void	draw_line(t_pts o, t_pts d, t_fdf *f)
{
	t_pro	*p;
	int		e2;

	set_pro(o, d, f->pro, f);
	p = f->pro;
	while (1)
	{
		put_pixel(p->x0, p->y0, o.c, f->mlx);
		if (p->x0 == p->x1 && p->y0 == p->y1)
			break ;
		e2 = 2 * p->err;
		if (e2 >= p->dy)
		{
			p->err += p->dy;
			p->x0 += p->sx;
		}
		if (e2 <= p->dx)
		{
			p->err += p->dx;
			p->y0 += p->sy;
		}
	}
}

int	keychain(int key, void *param)
{
	if (key == 65307 || !param)
		close_handler(param);
	return (0);
}

int	close_handler(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	// mlx_destroy_window(fdf->mlx->mlx, fdf->mlx->win);
	fdf_exit(param);// fdf_free(param);
	return (0);
}
