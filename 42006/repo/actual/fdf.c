/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:40:43 by akjoerse          #+#    #+#             */
/*   Updated: 2025/06/03 13:35:39 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

bool	check_file(char **a)
{
	int	i;
	int	j;

	j = ft_strlen(a[1]);
	i = j - 4;
	if (ft_strnstr(a[1] + i, ".fdf", 4))
		return (true);
	return (false);
}

int	main(int arg, char **param)
{
	t_fdf	fdf;

	if (arg != 2 || !check_file(param))
		return (1);
	init_fdf(&fdf);
	init_raw(&fdf, param[1]);
	init_mlx(&fdf);
	init_img(&fdf, fdf.mlx);
	mlx_hook(fdf.mlx->win, 17, 0, close_handler, &fdf);
	mlx_key_hook(fdf.mlx->win, keychain, &fdf);
	mlx_put_image_to_window(fdf.mlx->mlx, fdf.mlx->win, fdf.mlx->img, 0, 0);
	mlx_loop(fdf.mlx->mlx);
}
