/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:07:20 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/12 15:26:29 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//	External Inclusions
# include <math.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

//	Internal Inclusions
# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./libft/get_next_line/get_next_line.h"

//	MiniLibX	—	graphics library
# include "./mlx/mlx.h"

//	typedefs
typedef struct s_fdf
{
	int			fd;
	char			*fil;
	void			*mlx;
	void			*win;
	struct s_iso	*iso;
	struct s_img	*img;
	struct s_map	*map;//redu?
	struct s_mat	*mat;
	struct s_dim	*dim;
	struct s_pts	**pts;
}	t_fdf;

typedef struct s_img
{
	void	*ptr;
	char	*pix;
	int	bit;
	int	lin;
	int	end;
}	t_img;

//	redo this maybe i guess lol
typedef struct s_map
{
	struct s_pts	**points;
	struct s_dim	*dimensions;
	struct s_mat	*math;
	char			*map_raw;
	char			*map_str;
	char			**map_split;
	int			len;
}	t_map;

typedef struct s_mat
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	col;
} t_pos;

typedef struct s_dim
{
	int	x_lim;
	int	y_lim;
	int	w_scr;
	int	h_scr;
	int	tot_p;
	int	z_max;
	int	z_min;
	int	z_rng;
	int	zoom;
	int	theta;
} t_dim;

typedef struct s_pts
{
	int	z;
	int	c;
} t_pts;

//TODO:initialize values
typedef struct s_iso
{
	double	*i_x;
	double	*i_y;
	double	o_min;
	double	o_max;
	double	t_min;
	double	t_max;
}	t_iso;

//	check input
// t_dim	*get_dimensions(t_map *map);
void	get_dimensions(t_fdf *fdf);
int	ft_ishex(char *s, int i);
bool	in_hexset(char x);
bool	check_file(char **a, int i, int j);

//	helpers
int	ft_hextoi(char n);

//	initialization
// int	init_fdf(int f);
void	init_fdf(t_fdf *fdf);

//	map parsing
char	*read_map(int fd);
t_map	*parse_coordinates(t_map *map);
int	process_mapstring(t_map *map, int i);
int	store_coordinates(t_map *map, int i);
int	store_color(t_map *map, int i);

//	error handling
int	error_end(int fd, char *params, t_map *map);
void	free_map(t_map *map);

//	debugging
void	debug(char *m);


//
# define DEFCOL "0xFFFFFF"
# define DEFWID 800
# define DEFHEI 800
# define HEXSET "0123456789ABCDEFabcdef"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YLW "\033[1;33m"
# define BLU "\033[1;34m"
# define DEF "\033[0m"

//
/* unused structures

typedef struct s_pts
{
	int	*x;
	int	*y;
	int	*z;
	int	*c;	
} t_pts;

*/
/* unused functions

//// bool	check_params(char **a, int i, int j);
//// int	init_fdf(int f, char *p);

*/
#endif