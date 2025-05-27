/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:09:50 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/25 12:23:11 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	num;

	if (nptr[0] == '\0')
		return (0);
	i = 0;
	num = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if ((nptr[i] == 45 || nptr[i] == 43))
	{
		if (nptr[i] == 45)
			neg = neg * (-1);
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
		num = ((num * 10) + (nptr[i++] - 48));
	return (num * neg);
}
