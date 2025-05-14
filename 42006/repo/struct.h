#ifndef STRUCT_H
# define STRUCT_H
typedef struct s_map
{
	int	err;
	int	zoom;
	int	theta;
	int	**points;
	int	**color_split;
	char	***elements;
	char	**space_split;
	char	*raw_str;
	void	*fdfwin;
	void	*fdfmlx;
}	t_map;
typedef struct s_dim
{
	int	m_x;
	int	m_y;
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
typedef struct s_fdf
{
	int	fd;
	t_map	*map;
	t_dim	*dim;
	t_iso	*iso;
	t_pos	*pos;
}	t_fdf;
#endif
//&$`~*@^%|header file for Fer De Fil project at 42berlin by akjoerse|%^@*~`$&//