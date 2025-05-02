/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:36:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/02 18:51:44 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../FdF.h"

// void	init_mlx_routine(void)
void	init_mlx_routine(t_map *map)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	if (!mlx)
		return ;
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello FdF!");
	if (!win)
		return ;
	mlx_key_hook(win, get_keystroke, NULL);
	mlx_hook(win, 17, 0, get_exit, NULL);
	scratch_map(mlx, win, map);
	mlx_pixel_put(mlx, win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF);
	mlx_loop(mlx);
}
/* void	init_mlx_routine(t_map *map)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	if (!mlx)
		return ;
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello FdF!");
	if (!win)
		return ;
	mlx_key_hook(win, get_keystroke, NULL);
	mlx_hook(win, 17, 0, get_exit, NULL);
	mlx_loop(mlx);
} */

int	get_keystroke(int key, void *param)
{
	(void)param;
	if (key == 65307)
		exit (0);
	return (0);
}

int	get_exit(void *param)
{
	(void)param;
	exit (0);
	return (0);
}