/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:25:25 by akjoerse          #+#    #+#             */
/*   Updated: 2025/06/03 13:32:17 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	proj_zoom(t_fdf *f)
{
	double	x_zoom;
	double	y_zoom;

	x_zoom = (double)DEFWID / (f->x_rng[1] - f->x_rng[0]);
	y_zoom = (double)DEFHEI / (f->y_rng[1] - f->y_rng[0]);
	if (x_zoom < y_zoom)
		f->zoom = round(x_zoom * 0.75);
	else
		f->zoom = round(y_zoom * 0.75);
}

void	set_pro(t_pts o, t_pts d, t_pro *p, t_fdf *f)
{
	p->x0 = round(((o.x) * f->zoom) + f->x_off);
	p->x1 = round(((d.x) * f->zoom) + f->x_off);
	p->y0 = round(((o.y) * f->zoom) + f->y_off) / 2;
	p->y1 = round(((d.y) * f->zoom) + f->y_off) / 2;
	p->dx = ft_abs(p->x1 - p->x0);
	p->dy = -ft_abs(p->y1 - p->y0);
	p->err = p->dx + p->dy;
	if (p->x0 < p->x1)
		p->sx = 1;
	else
		p->sx = -1;
	if (p->y0 < p->y1)
		p->sy = 1;
	else
		p->sy = -1;
}
