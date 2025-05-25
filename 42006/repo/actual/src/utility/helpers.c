/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:25:16 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/25 16:38:39 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

int	ft_hextoi(char n)
{
	if (n >= '0' && n <= '9')
		return (n - 48);
	else if (n >= 'A' && n <= 'F')
		return (n - 55);
	else if (n >= 'a' && n <= 'f')
		return (n - 87);
	return (-1);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	free_map(t_fdf *fdf)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < fdf->dim->y_lim)
	{
		x = 0;
		while (x < fdf->dim->x_lim)
		{
			free(fdf->pos[y][x]);
			x++;
		}
		free(fdf->pos[y]);
		y++;
	}
	free (fdf->pos);
	free (fdf->map->str);
	fdf->map->str = NULL;
}

void	end_fdf(t_fdf *fdf, int err_code)
{
	int	y;

	y = 0;
	if (!fdf)
		exit (err_code);
	if (fdf->map)
		free (fdf->map);
	if (fdf->mlx)
		free (fdf->mlx);
	while (fdf->dim && y < fdf->dim->m_y)
	{
		if (fdf->pro[y])
			free (fdf->pro[y]);
		if (fdf->pts[y])
			free (fdf->pts[y]);
		y++;
	}
	if (fdf->pts)
		free (fdf->pts);
	if (fdf->pro)
		free (fdf->pro);
	if (fdf->dim)
		free (fdf->dim);
	exit (err_code);
}

void	free_pro(t_pro )