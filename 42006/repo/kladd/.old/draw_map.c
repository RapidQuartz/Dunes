/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:34:02 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/10 16:38:09 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../FdF.h"

// void	draw_map(t_map **map);//change map struct to array of coords::
/*	NEW MAP STRUCT DESIGN::

typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	c;
}	t_map;

then generate map thus:
*/
void	draw_map(t_map *map);
void	fill_map(char *map_str, t_map **map);

// void	draw_map(t_map *map)
// {
// 	int	lim[2];
// }
/* 
int	*map_parser(char *map_str, int lim_x, int lim_y)
{
	int	elements;
	int	columns;
	int	rows;
	int	i;
	char	**map_draft;
	
	i = 0;
	elements = 0;
	columns = 0;
	rows = 0;
	malc
	while (map_str[i] != '\0')
	{
		rows++;
		while (columns == 0)
		{
			if (map_str[i] == '\n')
				columns = elements;
			else
				i++;
		}
	}
}
 */