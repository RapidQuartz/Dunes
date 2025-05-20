/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:26:11 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/20 08:58:10 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/fdf.h"

void	error(void)
{
	printf(RED"\n{{ERROR}}\n"DEF);////TODO:replace with libft
	exit (0);
}

int	error_end(int fd, char *params, t_map *map)
{
	int	err[2];
	
	if (map == NULL)
		err[0] = 1;
	else
		err[0] = 0;
	// 	err[1] = 1;
	// else
	if (params || params == NULL)
		err[1] = 0;
	if (err[0] != 0)
		free_map(map, );
	// if (err[1] != 0)
	// 	free (params);
	close(fd);
	return (err[0] + err[1]);
}
