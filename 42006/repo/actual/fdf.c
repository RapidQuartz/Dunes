/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:40:43 by akjoerse          #+#    #+#             */
/*   Updated: 2025/06/03 16:33:00 by akjoerse         ###   ########.fr       */
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

void	fdf_exit(t_fdf *f)
{
	fdf_free(f);
	exit (0);
}

int	ptr_free(void *struct_ptr)
{
	if (struct_ptr || struct_ptr != NULL)
	{
		free (struct_ptr);
		return (1);
	}
	return (0);
}

int	fdf_free(t_fdf *f)
{
	int	ret;

	ret = 0;
	f->y = 0;
	while (f->y < f->y_lim)
	{
		ret += ptr_free(f->pts[f->y]);
		f->y++;
	}
	ret += ptr_free(f->pts);
	ret += ptr_free(f->pro);
	mlx_destroy_window(f->mlx->mlx, f->mlx->win);
	mlx_destroy_image(f->mlx->mlx, f->mlx->img);
	mlx_destroy_display(f->mlx->mlx);
	ret += ptr_free(f->mlx->mlx);
	ret += ptr_free(f->mlx);
	return (ret);
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
	fdf_exit(&fdf);
	return (0);
}
