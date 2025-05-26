/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:16:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/26 18:44:52 by akjoerse         ###   ########.fr       */
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
typedef struct s_mlx
{
	void	*win;
	void	*mlx;
	int			len;
}	t_mlx;
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
	int			x;
	int			y;
	int			z;
	int			c;
	struct s_pro	*src;
	struct s_pro	*x_dst;
	struct s_pro	*y_dst;
}	t_pts;
//// PRO:  ////  ////container for projection data/////////////////////////////
typedef struct s_pro
{
	int		x[3];
	int		y[3];
	int		z[3];
	int		c[3];
	int		dx[3];
	int		dy[3];
	int		sx[3];
	int		sy[3];
}	t_pro;
//// DIM:  ////  ////container for image and window parameters/////////////////
typedef struct s_dim
{
	int		screen_width;
	int		screen_height;
	int		x_max;
	int		y_max;
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
	int		x_lim;
	int		y_lim;
	int		e;
	int		b;
	int		l;
	int		t;
	double	co;
	double	si;
	t_raw		*raw;
	t_map		*map;
	t_dim		*dim;
	void		*mlx;
	void		*img;
	void		*win;
	t_pts		**pts;
	t_pro		**pro;
}	t_fdf;
/* NEONEO */
/* NEONEO
typedef struct s_fdf
{
	void	*p;
	void	*p;
	void	*p;
	void	*p;
	void	*p;
	void	*p;
	void	*p;
	void	*p;
}	t_fdf;
*/
/* 
typedef struct s_fdf
{
	void	*p_img;
	void	*p_mlx;
	void	*p_win;
	int	a_a;
	int	*a_b;
	int	**a_c;
	bool	b_alt;
	bool	b_bon;
	bool	b_col;
	char	*c_string;
	char	**c_lines;
	char	***c_map;
	struct s_pos	*d_pos;
	struct s_pro	*d_pro;
	struct s_env	*d_env;
}	t_fdf; */
/* NEONEO */
/* typedef struct s_pos
{
	int	x;
	int	y;
	int	h;
	int	v;
}	t_pos; */
/* NEONEO *//* 
typedef struct s_pro
{
	int	**pt_z;
	int	**pt_c;
	int	orig_xyzc[4];
	int	hori_xyzc[4];
	int	vert_xyzc[4];
	int	diag_xyzc[4];
}	t_pro; */
/* NEONEO *//* 
typedef struct s_env
{
	int	fd;
	char	*str;
	char	*map;
	int	dim[2];
	int	scr[2];
	int	win[2];
	int	off[2];
}	t_env; */
/* NEONEO *//* 
typedef struct s_tri
{
	char			*a;
	char			*b;
	char			*c;
	int			*i;
	int			*ii;
	struct s_tri	*tri;
}	t_tri; */
#endif
//&$`~*@^%|header file for Fer De Fil project at 42berlin by akjoerse|%^@*~`$&//