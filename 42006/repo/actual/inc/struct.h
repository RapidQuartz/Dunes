#ifndef STRUCT_H
# define STRUCT_H

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
	int	offset;
	int	proj;
}	t_iso;

typedef struct s_pos
{
	int	dx;
	int	dy;
}	t_pos;

typedef struct s_map
{
	int	err;
	int	zoom;
	int	theta;
	char	***elements;
	char	**space_split;
	char	*raw_str;
	void	*fdfwin;
	void	*fdfmlx;
}	t_map;

typedef struct s_fdf
{
	int	fd;
	t_map	*map;
	t_dim	*dim;
	t_iso	*iso;
	t_pos	*pos;
	t_pts	**pts;
}	t_fdf;
#endif
//&$`~*@^%|header file for Fer De Fil project at 42berlin by akjoerse|%^@*~`$&//