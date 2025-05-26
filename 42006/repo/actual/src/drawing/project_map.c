/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:02:43 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/26 10:08:54 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

void	project_origin(t_fdf *fdf, t_pro *pro, int x, int y);
void	project_horizontal(t_fdf *fdf, t_pro *pro, int x, int y);
void	project_vertical(t_fdf *fdf, t_pro *pro, int x, int y);
void	project_origin(t_fdf *fdf, t_pro *pro, int x, int y)
{
	pro->z0 = fdf->pts[y][x].z;
	pro->x0 = (x - y) * cos(fdf->t);
	pro->y0 = (x + y) * sin(fdf->t) - pro->z0 * fdf->map->zoom;
	pro->c0 = fdf->pts[y][x].c;
}
void	project_horizontal(t_fdf *fdf, t_pro *pro, int x, int y)
{
	pro->c0 = fdf->pts[y][x].c;
	pro->z1 = fdf->pts[y][x].z;
	pro->x1 = (x - y) * cos(fdf->t);
	pro->y1 = (x + y) * sin(fdf->t) - pro->z1 * fdf->map->zoom;
	pro->hx = ft_abs(pro->x1 - pro->x0);
	pro->hy = ft_abs(pro->y1 - pro->y0);
	if (pro->x0 < pro->x1)
		fdf->iso->sx = 1;
	else
		fdf->iso->sx = -1;
	if (pro->y0 < pro->y1)
		fdf->iso->sy = 1;
	else
		fdf->iso->sy = -1;
	draw_line(fdf, pro, x, y);
}

void	project_vertical(t_fdf *fdf, t_pro *pro, int x, int y)
{
	pro->c0 = fdf->pts[y][x].c;
	pro->z2 = fdf->pts[y][x].z;
	pro->y2 = (x + y) * sin(fdf->t) - pro->z1 * fdf->map->zoom;
	pro->vx = ft_abs(pro->x1 - pro->x0);
	pro->vy = ft_abs(pro->y1 - pro->y0);
	if (pro->x0 < pro->x1)
		fdf->iso->sx = 1;
	else
		fdf->iso->sx = -1;
	if (pro->y0 < pro->y1)
		fdf->iso->sy = 1;
	else
		fdf->iso->sy = -1;
	draw_line(fdf, pro, x, y);
}
