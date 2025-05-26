/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:04:13 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/26 09:51:24 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

void	read_raw_map(t_fdf *fdf)
{
	char		*raw;
	char		*line;

	while (fdf->raw->map != -1)
	{
		fdf->raw->line = get_next_line(fdf->raw->map);
		if (!line)
			break ;
		if (raw)
			raw = ft_strjoin(raw, line);
		else
			raw = ft_strdup(line);
		free (line);
	}
	fdf->raw->string = malloc(sizeof(raw));
	if (!fdf->raw->string || fdf->raw->string == NULL)
		exit (0);//TODO:integrate into exit function
	fdf->raw->string = ft_strdup(raw);
	free (raw);
}

void	split_raw_map(t_fdf *fdf)
{
	char	**split_map;
	int	n;
	int	l;
	int	r;

	n = 0;
	l = 0;
	r = 0;
	split_map = ft_split(fdf->raw->string, '\n');
	while (split_map[n])
		n++;
	fdf->dim->y_max = n;
	fdf->raw->elements = malloc(sizeof(*fdf->raw->elements) * n);
	if (!fdf->raw->elements || fdf->raw->elements == NULL)
		exit (0);//TODO:integrate into exit function
	while (split_map[l])
	{
		fdf->raw->elements[l] = ft_split(split_map[l], ' ');
		while (l == 0 && fdf->raw->elements[l][r])
			r++;
		l++;
	}
	fdf->dim->y_max = r;
	free (split_map);
}
