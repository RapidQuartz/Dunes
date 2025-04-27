/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:00:41 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/27 16:35:46 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FdF.h"

void	leave_now(void);

////	TEST:MAIN:
int	main(int a, char **c)
{
	t_map	*map;
	char	*file;
	char	*map_str;
	int	fd;

	map_str = NULL;
	file = NULL;
	map = NULL;
	if (a != 2)
		leave_now();
	file = ft_strdup(c[1]);
	fd = open (file, O_RDONLY);
	map_str = read_map(fd);
	if (map_str == NULL)
		leave_now();
	map = parse_map_str(map_str);
	init_mlx_routine();
	return (0);
}

void	leave_now(void)
{
	exit (0);
	return ;
}