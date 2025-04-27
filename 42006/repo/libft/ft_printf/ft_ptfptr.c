/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:12:11 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/25 12:20:05 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_ptfstr("(nil)"));
	else
	{
		ft_ptfstr("0x");
		len += 2;
	}
	len += ft_ptfhex(ptr, (const char) 'x');
	return (len);
}
