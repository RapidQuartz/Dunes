/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:16:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/25 16:39:34 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "fdf.h"

//// ////  ////  //////////////////////////////////////////////////////////////
//// NEO:  ////  ////the new structures for the FDF project////////////////////
//// ////  ////  //////////////////////////////////////////////////////////////
typedef struct s_mlx
{
	void	*win;
	void	*ptr;
	void	*img;
	int			bpp;
	int			len;
	int			end;
	char	*addr;
}	t_mlx;
typedef struct s_map
{
	int		fd;
	int		x;
	int		y;
	char	*raw;
	char	*str;
	char	**lin;
	char	***pts;
}	t_map;
//// MAP:  ////  ////the processed map file converted into data points/////////
// typedef struct s_map
// {
// 	t_raw	 *raw;
// 	int	 width;
// 	int	 height;
// 	int	 offset;
// 	int	 tile_size;
// 	int	 rotation;
// 	int	 zoom;
// }	t_map;
//// PTS:  ////  ////container for the map coordinates' values/////////////////
typedef struct s_pts
{
	int	x;
	int	y;
	int	z;
	int	c;
}	t_pts;
//// PRO:  ////  ////container for projection data/////////////////////////////
typedef struct s_pro
{
	t_pts	start;
	t_pts	end;
}	t_pro;
// typedef struct s_pro
// {
// 	int		x;
// 	int		y;
// 	int		xx;
// 	int		xy;
// 	int		yx;
// 	int		yy;
// 	int		z;
// 	int		zx;
// 	int		zy;
// 	int		c;
// 	int		cx;
// 	int		cy;
// 	int		d;
// 	int		dx;
// 	int		dy;
// 	int		sx;
// 	int		sy;
// }	t_pro;
typedef struct s_pro
{
	int		x;
	int		y;
	int		xx;
	int		xy;
	int		yx;
	int		yy;
	int		z;
	int		zx;
	int		zy;
	int		c;
	int		cx;
	int		cy;
	int		d;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
}	t_pro;
//// DIM:  ////  ////container for image and window parameters/////////////////
typedef struct s_dim
{
	int		s_x;
	int		s_y;
	int		m_x;
	int		m_y;
	int		rotation;//BONUS
	int		zoom;//BONUS
	int		y_lim;
	int		x_lim;
	int		total_elements;//UNUSED
}	t_dim;
//// FDF:  ////  ////container for all data in FDF project/////////////////////
typedef struct s_fdf
{
	int		x;
	int		y;
	char		*file;
	char		***pos;
	t_pro	**start;
	t_pro	**end;
	t_dim	*dim;
	t_map	*map;
	t_mlx	*mlx;
	t_pts	**pts;
	t_pro	**pro;
}	t_fdf;
#endif
//&$`~*@^%|header file for Fer De Fil project at 42berlin by akjoerse|%^@*~`$&//