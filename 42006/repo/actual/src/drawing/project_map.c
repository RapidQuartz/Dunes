/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:02:43 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/24 17:57:08 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

void	get_projection(t_fdf *fdf, t_pts **pts, t_pro *pro)
{
	pro->z = pts[fdf->y][fdf->x].z_height;
	pro->c =  pts[fdf->y][fdf->x].c_color;
	pro->x = (fdf->x - fdf->y) * (cos (fdf->dim->rotation));
	pro->y = (fdf->x + fdf->y) * (sin (fdf->dim->rotation)) - pro->z;
	if (fdf->x < fdf->dim->x_lim - 1)
		proj_next_col(fdf, pts, pro);
	if (fdf->y < fdf->dim->y_lim - 1)
		proj_next_row(fdf, pts, pro);
}
void	proj_next_col(t_fdf *fdf, t_pts **pts, t_pro *pro)
{
	pro->zx = pts[fdf->y][fdf->x + 1].z_height;
	pro->cx = pts[fdf->y][fdf->x + 1].c_color;
	pro->xx = ((fdf->x + 1) - fdf->y) * (cos (fdf->dim->rotation));
	pro->xy = ((fdf->x + 1) + fdf->y) * (sin (fdf->dim->rotation)) - pro->zx;
	pro->d = ft_abs(pro->xx) - ft_abs(pro->x);
	pro->dx = ft_abs(pro->yx) - ft_abs(pro->y);
	if (pro->xx > pro->x)
		pro->sx = 1;
	else
		pro->sx = -1;
}

void	proj_next_row(t_fdf *fdf, t_pts **pts, t_pro *pro)
{
	pro->zy = pts[fdf->y + 1][fdf->x].z_height;
	pro->cy =  pts[fdf->y + 1][fdf->x].c_color;
	pro->yx = (fdf->x - (fdf->y + 1)) * (cos (fdf->dim->rotation));
	pro->yy = (fdf->x + (fdf->y + 1)) * (sin (fdf->dim->rotation)) - pro->zy;
	pro->dy = ft_abs(pro->yy) - ft_abs(pro->y);
	if (pro->yy > pro->y)
		pro->sy = 1;
	else
		pro->sy = -1;
}
