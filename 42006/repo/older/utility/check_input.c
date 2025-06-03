/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:46:31 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/26 09:46:32 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

bool	check_file(char **a)
{
	int i;
	int j;

	/* if filename ENDS with .fdf */
	j = ft_strlen(a[1]);
	i = j - 4;
	if (ft_strnstr(a[1] + i, ".fdf", 4))
		return (true);
	return (false);
}
