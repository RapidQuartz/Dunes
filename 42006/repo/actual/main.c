/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:33:42 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/24 17:37:53 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/fdf.h"


int	main(int arg, char **param)
{
	t_fdf	fdf;
		
	if (arg != 2)
		return (1);
	check_params(arg, param);
	fdf.file = param[1];
	init_fdf(&fdf);
	init_mlx(&fdf);
	draw_image(&fdf, *fdf.pro);
	//put img to screen stuff
	//TODO:	check if need to insert an offset
	mlx_put_image_to_window(fdf.mlx->ptr, fdf.mlx->win, fdf.mlx->img, 0, 0);//replace `0, 0` with `o_x, o_y` for `offset_x` and `offset_y`
	mlx_loop(fdf.mlx->ptr);
}

int	key_handler(int key, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (key == 65307)
	{
		close_handler(fdf);
		exit (0);//TODO:integrate into exit function
	}
	return (0);
}

int	close_handler(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	mlx_destroy_window(fdf->mlx->ptr, fdf->mlx->win);
	exit (0);
	return (0);
}

////	TODO: check for map size/zoom/misc params
void	check_params(int arg, char **param)
{
	if (arg < 2 || !param)
		exit (0);//TODO:integrate into exit function
	return ;
}


/* ||*********************Created: 2025/05/12 21:33:42*********************|| */