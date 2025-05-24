/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:53:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/24 17:58:09 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

void	draw_image(t_fdf *fdf, t_pro *pro)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < fdf->dim->y_lim)
	{
		x = 0;
		while (x < fdf->dim->x_lim)
		{
			if (x < fdf->dim->x_lim - 1)
				draw_horizontal(fdf, pro);
			if (y < fdf->dim->y_lim - 1)
				draw_vertical(fdf, pro);
			x++;
		}
		y++;
	}
}

void	draw_horizontal(t_fdf *fdf, t_pro *pro)
{
	int	err;
ft_printf(RED"Drawing from[%d][%d] to [%d][%d]\n"DEF, pro->x, pro->y, pro->xx, pro->xy);
	err = pro->d / 2;
	while (pro->x != pro->xx)
	{
		put_pixel(fdf, pro->x, pro->y, pro->c);
		err -= pro->dx;
		if (err < 0)
		{
			pro->y += pro->sy;
			err += pro->d;
		}
		pro->x += pro->sx;
	}
}

void	draw_vertical(t_fdf *fdf, t_pro *pro)
{
	int	err;
ft_printf(BLU"Drawing from[%d][%d] to [%d][%d]\n"DEF, pro->x, pro->y, pro->xx, pro->yy);
	err = pro->dy / 2;
	while (pro->y != pro->yy)
	{
		put_pixel(fdf, pro->x, pro->y, pro->c);
		err -= pro->d;
		if (err < 0)
		{
			pro->x += pro->sx;
			err += pro->dy;
		}
		pro->y += pro->sy;
	}
}

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	len;
	int	bpp;
	int	width;
	int	height;
	char	*pix;

	len = fdf->mlx->len;
	bpp = fdf->mlx->bpp;
	width = fdf->dim->s_x;
	height = fdf->dim->s_y;
	if (x < 0 || y < 0 || x > width || y > height)
		return ;
	pix = fdf->mlx->addr + (y * len + x * (bpp / 8));
	*(unsigned int *)pix = (unsigned int)color;
}
