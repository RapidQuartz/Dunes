/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:13:09 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/14 18:07:59 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/ft_printf.h"

int	ft_ptfint(int num)
{
	int	i;

	i = 0;
	if (num == -2147483648)
	{
		ft_ptfstr("-2147483648");
		return (11);
	}
	if (num)
		num = ft_ptfint_put(num);
	else
		return (0);
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}
