/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:31:53 by akjoerse          #+#    #+#             */
/*   Updated: 2025/06/03 16:38:10 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H
# include "struct.h"

///	fdf.c
int		main(int arg, char **param);
bool	check_file(char **a);
int	ptr_free(void *struct_ptr);
int	fdf_free(t_fdf *f);
void	fdf_exit(t_fdf *f);

/* <!-- ERROR HANDLING --> */

///	src/helpers.c
int		ft_abs(int num);
int		ft_hextoi(char n);
int		get_lmn_len(char *lmn);
/* <!-- MEMORY HANDLING --> */

///	src/parse.c
int		extract_color(char *col, int j);
t_pts	*meta_segments(t_fdf *f, int y);
void	get_range(t_pts **p, t_fdf *f);
void	set_points(t_fdf *f, t_pts **p, t_raw *raw);

///	src/project.c
void	proj_zoom(t_fdf *f);
void	set_pro(t_pts o, t_pts d, t_pro *p, t_fdf *f);

///	src/draw.c
void	put_pixel(int x, int y, int c, t_mlx *i);
void	draw_line(t_pts o, t_pts d, t_fdf *f);
int		keychain(int key, void *param);
int		close_handler(void *param);


///	src/init.c
void	init_img(t_fdf *f, t_mlx *m);
void	init_mlx(t_fdf *f);
void	init_raw(t_fdf *fdf, char *map_file);
void	init_fdf(t_fdf *fdf);
#endif
//&$`~*@^%|header file for Fer De Fil project at 42berlin by akjoerse|%^@*~`$&//