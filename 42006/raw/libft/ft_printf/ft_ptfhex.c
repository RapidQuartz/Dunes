/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:19:04 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/14 18:07:19 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/ft_printf.h"

int	ft_ptfhex(unsigned long long int num, const char format)
{
	if (num == 0)
		return (ft_ptfcha('0'));
	ft_ptfhex_put(num, format);
	return (ft_ptfhex_len(num));
}
