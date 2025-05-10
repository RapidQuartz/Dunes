/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:07:20 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/10 23:55:47 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
////	External Inclusions
# include <math.h>
////	Internal Inclusions
# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./libft/get_next_line/get_next_line.h"
////	MiniLibX	—	graphics library
# include "./mlx/mlx.h"
//	typedefs
typedef struct s_map
{
	struct s_pts	*points;
	struct s_dim	*dimensions;
	struct s_pos	*position;
	char			*map_string;
}	t_map;
typedef struct s_pos
{
	int	placeholder;
} t_pos;
typedef struct s_dim
{
	int	x_limit;
	int	y_limit;
	int	s_width;
	int	s_height;
} t_dim;
typedef struct s_pts
{
	int	*x;
	int	*y;
	int	*z;
	int	*c;	
} t_pts;
//	check input
bool	check_file(char **a, int i, int j);
bool	check_params(char **a, int i, int j);
//	initialization
int	init_fdf(int f, char *p);
//	map parsing
char	*read_map(int fd);
//	error handling
int	error_end(int fd, char *params, t_map *map);
//
#endif