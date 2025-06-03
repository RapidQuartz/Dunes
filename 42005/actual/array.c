/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:24:54 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/22 17:41:42 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_make_null_arr(int n)
{
	int	i;
	int	*arr;

	i = -1;
	arr = NULL;
	if (n <= 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr || arr == NULL)
		return (NULL);
	while (++i < n)
		arr[i] = 0;
	return (arr);
}

int	*ft_argn_map(int *argn_map, int argc, char **argv)
{
	int		i;
	int		*argn;

	i = 0;
	argn = NULL;
	argn_map = ft_make_null_arr(argc + 1);
	if (!argn_map || argn_map == NULL)
		error_end_arr(argn_map);
	argn = argn_map;
	while (++i < argc)
		argn_map = arg_count(argv[i], argn_map, i);
	if (argn_map == NULL)
		free (argn);
	return (argn_map);
}
