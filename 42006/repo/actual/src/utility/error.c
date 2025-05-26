/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:26:11 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/26 18:36:34 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

void	error(void)
{
	printf(RED"\n{{ERROR}}\n"DEF);////TODO:replace with libft
	exit (0);
}

int	end_fdf(t_fdf *fdf, int err)
{
	ft_printf(RED"///ERROR!///"
	BLU"\ncode: %d\n"
	GRN"free: %d"
	DEF, err, free_fdf(fdf));
	exit (0);
}
int	free_fdf(t_fdf *fdf)
{
	if (fdf->raw != NULL)
		free (fdf->raw);
	if (fdf->map != NULL)
		free (fdf->map);
	if (fdf->dim != NULL)
		free (fdf->dim);
	if (fdf->mlx != NULL)
		free (fdf->mlx);
	if (fdf->img != NULL)
		free (fdf->img);
	if (fdf->win != NULL)
		free (fdf->win);
	null_fdf(fdf, 0, 0);
	return (0);
}

void	null_fdf(t_fdf *fdf, int x, int y)
{
	fdf->x = 0;
	fdf->y = 0;
	fdf->e = 0;
	fdf->b = 0;
	fdf->l = 0;
	fdf->t = 0;
	fdf->raw = NULL;
	fdf->map = NULL;
	fdf->dim = NULL;
	fdf->mlx = NULL;
	fdf->img = NULL;
	fdf->win = NULL;
	while (fdf->pts[x] != NULL)
		free (fdf->pts[x++]);
	fdf->pts = NULL;
	while (fdf->pro[y] != NULL)
		free (fdf->pro[y++]);
	fdf->pro = NULL;
}
/*


fdf->x = 0;
fdf->y = 0;
fdf->e = 0;
fdf->b = 0;
fdf->l = 0;
fdf->raw = NULL;
fdf->map = NULL;
fdf->dim = NULL;
fdf->mlx = NULL;
fdf->img = NULL;
fdf->win = NULL;
fdf->pts = NULL;
fdf->pro = NULL;











*/
/* 
int	error_end(int fd, char *params, t_map *map)
{
	int	err[2];
	
	if (map == NULL)
		err[0] = 1;
	else
		err[0] = 0;
	// 	err[1] = 1;
	// else
	if (params || params == NULL)
		err[1] = 0;
	if (err[0] != 0)
		free_map(fdf);
	// if (err[1] != 0)
	// 	free (params);
	close(fd);
	return (err[0] + err[1]);
} */
