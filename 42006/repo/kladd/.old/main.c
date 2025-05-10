/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:00:41 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/10 16:41:09 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FdF.h"

////	TEST:MAIN:
// int	main(void)
int	main(int a, char **c)
{
	int		fd;
	// t_data	*data;
	char		*file;
	char		*map_str;

	map_str = NULL;
	file = NULL;
	if (a != 2)
		leave_now();
	file = ft_strdup(c[1]);
	if (ft_strchr(file, '.') && \
	ft_strnstr(ft_strrchr(file, '.'), "fdf", 4) == NULL)
		leave_now();
	fd = open(file, O_RDONLY);
	read_map(fd);
	// if (data == NULL)
		// leave_now();
	// init_mlx_routine(data);
	return (0);
}

void	leave_now(void)
{
	exit (0);
	return ;
}