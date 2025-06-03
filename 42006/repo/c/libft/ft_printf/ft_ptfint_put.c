/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfint_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:15:44 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/25 12:20:19 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfint_put(int num)
{
	int				neg;
	unsigned int	nbr;

	neg = 1;
	if (num == 0)
		return (ft_ptfcha('0'));
	if (num < 0)
	{
		neg = -1;
		ft_ptfcha('-');
	}
	nbr = num * neg;
	while (num)
	{
		if (num <= 9)
			return (ft_ptfcha(num + '0'));
		if (num > 9)
		{
			num = ft_ptfint_put(num % 10);
			num = ft_ptfint_put(num / 10);
		}
	}
	return (0);
}
