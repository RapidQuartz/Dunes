/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:46:36 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/27 12:12:26 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "fdf.h"
typedef struct s_pos
{
	int	c;
	int	z;
}	t_pos;
typedef struct s_pts
{
	int	x;
	int	y;
}	t_pts;
typedef struct s_map
{
	char	*str;
	char	*raw;
	char	**lines;
	char	***map;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*img;
	void	*win;
	t_pts	**map;
	t_pos	**pos;
	t_map	**raw;
	int	err;
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	win_x;
	int	win_y;
}	t_fdf;
#endif