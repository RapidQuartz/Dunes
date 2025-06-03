/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:40:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/26 14:55:03 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/fdf.h"

void	fdf_count_lin(char **lin, int *col, int i)
{
	
}

void	fdf_count_col(char **lin, int *col, int i)
{
	while (lin[i])
		i++;
	(*col) = i;
}

void	fdf_init(t_fdf *fdf, t_env *env, t_pos *pos, t_pro *pro)
{
	env_init(fdf, env);
	fdf->c_lines = ft_split(env->map, '\n');
	fdf_count_lin(fdf->c_lines, &env->dim[1], 0);
	while (fdf->c_lines[env->dim[1]])
		env->dim[1]++;
	fdf->c_map = malloc(sizeof(*fdf->c_map) * env->dim[1]);
	while (env->dim[0])
		fdf_count_col(fdf->c_lines[0], &env->dim[0], 0);
}
void	env_init(t_fdf *fdf, t_env *env)
{
	t_env	e;

	e = *env;
	e.str = get_next_line(e.fd);
	e.map = ft_strdup(e.str);
	free (e.str);
	while (e.fd != -1)
	{
		e.str = get_next_line(e.fd);
		e.map = ft_strjoin(e.map, e.str);
		free (e.str);
	}
	e.dim[0] = 0;
	e.dim[1] = 0;
	fdf->d_env = &e;
}

int	main(int a, char **v)
{
	t_env	env;
	t_fdf	fdf;
	t_pro	pro;
	t_pos	pos;
	int	fd;

	if (a != 2)
		return (-1);
	env.fd = open (v[1], O_RDONLY);
	fdf_init(&fdf, &env, &pro, &pos);
	fdf.d_env = &env;
	return (0);
}

