/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:26:22 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/19 12:03:12 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"
/* 
void	split_map_color(char **map, int l, t_fdf *fdf)
{
	int	i;
	int	j;
	int	k;
	
	i = 0;
	j = 0;
	while (map[j][i])
	{
		if (ft_isdigit(map[j][i]) || map[j][i] == '-')
		{
			set_map_point(fdf, i, j, l);
		}
		if (map[j][i] == ',')
			set_map_color(map[j], i + 3);
		else
			set_map_color(NULL, 0);
		j++;
		i = 0;
	}
}

void	set_map_point(t_fdf *fdf, int k, int r, int l)
{
	char	*lmnt;
	int	numb;
	int	i;
	
	i = -1;
	lmnt = malloc(sizeof(char) * k);
	if (!lmnt || lmnt == NULL)
		error();
	while (++i < k)
		lmnt[i] = fdf->map->elements[l][r][i];
	numb = ft_atoi(lmnt);
	fdf->map->pts[l][r] = numb;
} */