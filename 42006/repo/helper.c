/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:12:49 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/14 11:14:20 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

size_t	ft_countelem(char **arr)
{
	size_t	elem;

	elem = 0;
	while (arr[elem])
		elem++;
	return (elem);
}