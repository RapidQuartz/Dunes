/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:24:03 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/10 21:47:35 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../FdF.h"

hallo hallo

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc < 2)
		return (1);
	while (argv[i][j] != '\0')
	{
		while (argv[i][j] != '\0')

			j++;
		i++;
	}
	return (0);
}

int	*h_proj(int map_x, int map_y, int map_z, int theta);
int	*v_proj(int map_x, int map_y, int map_z, int theta);

int	*h_proj(int map_x, int map_y, int map_z, int theta)
{
	int	xy[4];

	xy[0] = ((map_x - map_y) * cos(theta));
	xy[1] = (((map_x + 1) - map_y) * cos(theta));
	xy[2] = ((map_x + map_y) * sin(theta) - map_z);
	xy[3] = (((map_x + 1) + map_y) * sin(theta) - map_z);
	return (xy);
}

int	*v_proj(int map_x, int map_y, int map_z, int theta)
{
	int	xy[4];

	xy[0] = ((map_x - map_y) * cos(theta));
	xy[1] = ((map_x - (map_y + 1)) * cos(theta));
	xy[2] = ((map_x + map_y) * sin(theta) - map_z);
	xy[3] = ((map_x + (map_y + 1)) * sin(theta) - map_z);
	return (xy);
}