/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:02:43 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/27 15:52:51 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"
/* 
void	prepare_image(t_fdf *fdf)
{
	int	z;
	char	*addr;
	t_pro	*pix;

	fdf->img = mlx_new_image(fdf->mlx, fdf->dim->screen_width,
		fdf->dim->screen_height);
	addr = mlx_get_data_addr(fdf->img, &fdf->b, &fdf->l, &fdf->e);
	while (fdf->y < fdf->y_lim - 1)
	{
		pix = &fdf->pro[fdf->y][fdf->x];
		while (fdf->x < fdf->x_lim - 1)
		{
			if (pix->x)
			fdf->x++;
		}
		fdf->x = 0;
		fdf->y++;
	}
} */