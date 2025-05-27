/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfhex_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:17:11 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/25 12:20:28 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptfhex_put(unsigned long long int num, const char format)
{
	if (num >= 16)
	{
		ft_ptfhex_put(num / 16, format);
		ft_ptfhex_put(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_ptfcha((num + '0'));
		else
		{
			if (format == 'x')
				ft_ptfcha((num - 10) + 'a');
			if (format == 'X')
				ft_ptfcha((num - 10) + 'A');
		}
	}
}
