/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:12:11 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/14 18:08:17 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/ft_printf.h"

int	ft_ptfptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (0);
	else
	{
		ft_ptfstr("0x");
		len += 2;
	}
	len += ft_ptfhex(ptr, (const char) 'x');
	return (len);
}
