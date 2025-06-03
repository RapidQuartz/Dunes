/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:16:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/06/03 13:42:53 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "fdf.h"
//// MLX:  ////  ////the container for various mlx pointers and vars////////////
typedef struct s_mlx
{
	char	*adr;
	void	*win;
	void	*mlx;
	void	*img;
	int		len;
	int		bpp;
	int		end;
	int		err;
}	t_mlx;

//// RAW:  ////  ////the pure output from reading the mapfile///////////////////
typedef struct s_raw
{
	int		map;
	char	*line;
	char	*string;
	char	**lines;
	char	**segments;
	char	***elements;
}	t_raw;

//// PTS:  ////  ////projected map coordinates, color and altitude data/////////
typedef struct s_pts
{
	double	x;
	double	y;
	int		z;
	int		c;
}	t_pts;

//// PRO:  ////  ////projection information, slopes, destinations etc.//////////
typedef struct s_pro
{
	int	c;
	int	z;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	err;
}	t_pro;

//// FDF:  ////  ////mother function containing everything else lol ////////////
typedef struct s_fdf
{
	double	radians;
	double	cosine;
	double	sine;
	int		x;
	int		y;
	int		x_lim;
	int		y_lim;
	int		x_rng[2];
	int		y_rng[2];
	int		zoom;
	int		x_off;
	int		y_off;
	t_raw	*raw;
	t_mlx	*mlx;
	t_pts	**pts;
	t_pro	*pro;
}	t_fdf;
#endif
//&$`~*@^%|header file for Fer De Fil project at 42berlin by akjoerse|%^@*~`$&//