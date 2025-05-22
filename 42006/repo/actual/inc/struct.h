/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:16:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/22 15:07:18 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "fdf.h"
//// ////  ////  //////////////////////////////////////////////////////////////
//// PAL:  ////  ////the old structures for the FDF project////////////////////
//// ////  ////  //////////////////////////////////////////////////////////////
// typedef struct s_pts
// {
// 	int	z;
// 	int	c;
// }	t_pts;

// typedef struct s_dim
// {
// 	int	max_x;
// 	int	max_y;
// 	int	s_x;
// 	int	s_y;
// 	int	z_x;
// 	int	z_y;
// }	t_dim;

// typedef struct s_iso
// {
// 	int		offset;
// 	double	x0;
// 	double	y0;
// 	double	x1;
// 	double	y1;
// 	int		dx;
// 	int		dy;
// 	int		sx;
// 	int		sy;
// }	t_iso;

// typedef struct s_pos
// {
// 	int	dx;
// 	int	dy;
// 	int	x;
// 	int	y;
// }	t_pos;

// typedef struct s_map
// {
// 	int		err;
// 	int		zoom;
// 	int		tiles;
// 	int		theta;
// 	char	***elements;
// 	char	**space_split;
// 	char	*raw_str;
// 	void	*win;
// 	void	*mlx;
// }	t_map;

// typedef struct s_drw
// {
// 	int	x;
// 	int	y;
// }	t_drw;

// typedef struct s_pro
// {
// 	int	x0;
// 	int	x1;
// 	int	y0;
// 	int	y1;
// 	int	y2;
// 	int	z0;
// 	int	z1;
// 	int	z2;
// 	int	c0;
// 	int	c1;
// 	int	c2;
// 	int	hx;
// 	int	hy;
// 	int	vx;
// 	int	vy;
// }	t_pro;

// typedef struct s_fdf
// {
// 	int		fd;
// 	int		x;
// 	int		y;
// 	int		theta;
// 	int		endian;
// 	int		xmax;
// 	int		ymax;
// 	int		bpp;
// 	int		len;
// 	void	*img;
// 	void	*mlx;
// 	void	*win;
// 	t_pro	*pro;
// 	t_map	*map;
// 	t_dim	*dim;
// 	t_iso	*iso;
// 	t_pos	*pos;
// 	t_pts	**pts;
// }	t_fdf;

//// ////  ////  //////////////////////////////////////////////////////////////
//// NEO:  ////  ////the new structures for the FDF project////////////////////
//// ////  ////  //////////////////////////////////////////////////////////////
//// RAW:  ////  ////the pure output from reading the mapfile//////////////////
typedef struct s_raw
{
	int		map;
	char	*line;
	char	*string;
	char	**lines;
	char	***elements;

}	t_raw;
//// MAP:  ////  ////the processed map file converted into data points/////////
typedef struct s_map
{
	t_raw	 *raw;
	int	 width;
	int	 height;
	int	 offset;
	int	 tile_size;
	int	 rotation;
	int	 zoom;
}	t_map;
//// PTS:  ////  ////container for the map coordinates' values/////////////////
typedef struct s_pts
{
	int	z_height;
	int	c_color;
}	t_pts;
//// PRO:  ////  ////container for projection data/////////////////////////////
typedef struct s_pro
{
	int		x;
	int		xx;
	int		y;
	int		yx;
	int		yy;
	int		z;
	int		zx;
	int		zy;
	int		c;
	int		cx;
	int		cy;
	int		dx;
	int		dy;
}	t_pro;
//// DIM:  ////  ////container for image and window parameters/////////////////
typedef struct s_dim
{
	int		screen_width;
	int		screen_height;
	int		map_width;
	int		map_height;
	int		screen_offset;
	int		tile_size;
	int		rotation;
	int		zoom;
	int		rows;
	int		columns;
	int		total_elements;
}	t_dim;
//// FDF:  ////  ////container for all data in FDF project/////////////////////
typedef struct s_fdf
{
	int		x;
	int		y;
	int		width;
	int		height;
	t_raw	*raw;
	t_map	*map;
	t_dim	*dim;
	t_pts	**pts;
	t_pro	**pro;
}	t_fdf;
#endif
//&$`~*@^%|header file for Fer De Fil project at 42berlin by akjoerse|%^@*~`$&//