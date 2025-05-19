/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:26:22 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/19 15:57:28 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

void	init_map(t_fdf *fdf)
{
	int	tile;
	int	factor;
	int	screen;

	fdf->dim->s_x = DEFWID;//TODO:BONUS: if param offered, change to this
	fdf->dim->s_y = DEFHEI;//TODO:BONUS: if param offered, change to this
	if (fdf->dim->s_x < fdf->dim->s_y)
		screen = fdf->dim->s_x;
	else
		screen = fdf->dim->s_y;
	fdf->iso->offset = 40;//should this be editable or depend?
	fdf->map->err = 0;
	fdf->map->theta = 30;//TODO: offer alternative theta?
	if (fdf->dim->max_x < fdf->dim->max_y)
		factor = fdf->dim->max_x;
	else
		factor = fdf->dim->max_y;
	fdf->map->tiles = (screen - (2 * fdf->iso->offset)) / factor;//choose smaller of two depending on window size	
	fdf->map->zoom = 1;//TODO:BONUS: offer input to change zoom
	fdf->map->endian = 0;
}
