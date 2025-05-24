/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:23:44 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/24 16:24:04 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

////	TODO: make this make sense
bool	check_file(char **a, int i, int j)
{
	/* if filename ENDS with .fdf */
	j = ft_strlen(a[1]);
	i = j - 4;
	if (ft_strnstr(a[1] + i, ".fdf", 4))
		return (true);
	return (false);
}
