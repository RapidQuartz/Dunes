/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:07:20 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/10 16:36:07 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
////	External Inclusions
# include <math.h>
////	MiniLibX	—	graphics library
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./libft/get_next_line/get_next_line.h"
//
////	definitions
///	window dimensions
#ifndef HEIGHT
# define HEIGHT 480
#endif
#ifndef WIDTH
# define WIDTH 480
#endif
//
////	typedefs
///	structs
	////	s_map::stores map:
	///	`int	x;`	:: maximum `width x`
	///	`int	y;`	:: maximum `height y`
	///	`int **z`	:: height value stored at `x,y`
	///	`char **g`	:: color value stored at `x,y`
/* typedef struct	s_map
{
	int	x_max;
	int	y_max;
	char	**map_lines;
	int	**map_values;
	int	**map_colors;
}	t_map;
*/
typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	c;
}	t_map;

typedef struct s_data
{
	char	*map_str;
	int	lim_x;
	int	lim_y;
	t_map	**map;
}	t_data;
// t_data	*parse_map(int fd);
void		parse_map(char *raw);
int	count_columns(char *map);
int	count_rows(char *map);

/* 
typedef struct	s_map
{
	int			l_num;
	int			x_size;
	int			y_size;
	char			**map_line;
	struct s_map	**head;
	struct s_map	*next;
}	t_map;

typedef struct s_dimensions
{
	int	lim_x;
	int	lim_y;
	int	pos_x;
	int	pos_y;
	int	line_x;
	int	line_y;
	int	edge_offset_x;
	int	edge_offset_y;
}	t_dimensions;
 */
///	enums
//
////	funcs
///	main.c
// int	main(int a, char **c);
void	leave_now(void);
///	src/
//	draw_map.c
void	draw_map(t_map *map);
//	scratch_map.c
void	scratch_map(void *mlx, void *win, t_map *map);
void	ft_draw_map(t_map *map, void *mlx, void *win);
// void	ft_draw_line(t_map *map, t_dimensions *dim, void *mlx, void *win);
// void	ft_draw_segment_x(t_map *map, t_dimensions *dim, void *mlx, void *win);
// void	ft_draw_segment_y(t_map *map, t_dimensions *dim, void *mlx, void *win);
// void	ft_set_dimensions(t_map *map, t_dimensions *dim);
//	init_mlx.c
void	init_mlx_routine(t_map *map);
int	get_keystroke(int key, void *param);
int	get_exit(void *param);
//	map_matrix.c
void	map_matrix(char *c, t_map **map);
//	read_map.c
// char	*read_map(int fd);
void		read_map(int fd);
void	free_map(t_map *map);
// t_map	*init_map(t_map **blank, int y_max, int x_max);
t_map	*parse_map_str(char *map_str);
void	populate_map(t_map *map, char *map_str, char *chart);
//	parse_map.c
void	parse_color(char **map_str, int x_siz, int y_siz);
void	parse_mono(char **map_str, int x_siz, int y_siz);
//	fdf_util.c
int	fdf_countlines(char *str);
int	fdf_countrows(char *str);
int	fdf_countelem(char *str);

//
#endif