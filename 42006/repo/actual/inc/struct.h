#ifndef STRUCT_H
# define STRUCT_H

# include "fdf.h"
typedef struct s_pts
{
	int	z;
	int	c;
}	t_pts;

typedef struct s_dim
{
	int	max_x;
	int	max_y;
	int	s_x;
	int	s_y;
	int	z_x;
	int	z_y;
}	t_dim;

typedef struct s_iso
{
	int		offset;
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	int		sx;
	int		sy;
}	t_iso;

typedef struct s_pos
{
	int	dx;
	int	dy;
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int	err;
	int	zoom;
	int	tiles;
	int	theta;
	char	***elements;
	char	**space_split;
	char	*raw_str;
	void	*win;
	void	*mlx;
	int	bpp;
	int	endian;
}	t_map;

typedef struct s_drw
{
	int	x;
	int	y;
}	t_drw;

typedef struct s_fdf
{
	int	fd;
	void	*img;
	t_map	*map;
	t_dim	*dim;
	t_iso	*iso;
	t_pos	*pos;
	t_pts	**pts;
}	t_fdf;
#endif
//&$`~*@^%|header file for Fer De Fil project at 42berlin by akjoerse|%^@*~`$&//