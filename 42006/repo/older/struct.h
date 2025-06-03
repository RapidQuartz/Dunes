/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:16:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/06/02 18:25:42 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "fdf.h"
//// RAW:  ////  ////the pure output from reading the mapfile//////////////////
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
//// MAP:  ////  ////the processed map file converted into data points/////////
/* typedef struct s_map
{
	struct s_raw	 *raw;
	int	 width;
	int	 height;
	int	 offset;
	int	 tile_size;
	int	 rotation;
	int	 zoom;
}	t_map; */
//// PTS:  ////  ////container for the map coordinates' values/////////////////
/* typedef struct s_pts
{
	double		x;
	double		y;
	int			z;
	int			c;
	struct s_pro	*src;
	struct s_pro	*x_dst;
	struct s_pro	*y_dst;
}	t_pts; */
/* typedef struct s_max
{
	struct s_fdf	**fdf;
	int	z;
	int	c;
}	t_max; */

//// PRO:  ////  ////container for projection data/////////////////////////////
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
typedef struct s_raw
{
	int		map;
	char	*line;
	char	*string;
	char	**lines;
	char	**segments;
	char	***elements;
}	t_raw;
typedef struct s_pts
{
	double	x;
	double	y;
	int		z;
	int		c;
}	t_pts;
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
typedef struct s_fdf
{
	double	radians;
	double	cosine;
	double	sine;
	int		x;
	int		y;
	int		x_lim;//width in members
	int		y_lim;//height in members
	int		x_range[2];//screen offsets
	int		y_range[2];//screen offsets
	int		z_range[2];//screen offsets
	int		zoom;
	int		x_zoom;
	int		y_zoom;
	int		x_off;//screen offsets
	int		y_off;//screen offsets
	t_raw		*raw;//ptr for map in chars
	t_dim		*dim;//ptrs//dimensions of canvas/window etc
	t_mlx		*mlx;// mlx ptr for mlx mlxing
	void		*win;// window ptr for mlx mlxing
	t_pts		**pts;//[y]/[x] = {z, c} // for height and color
	t_pro		*pro;
}	t_fdf;
/* NEONEO */
/* old stuff
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
/* typedef struct s_pro
{
	int		x[3];
	int		y[3];
	int		z[3];
	int		c[3];
	int		dx[3];
	int		dy[3];
	int		sx[3];
	int		sy[3];
}	t_pro; */
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