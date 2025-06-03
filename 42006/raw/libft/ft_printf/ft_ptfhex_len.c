/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfhex_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:21:41 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/14 18:08:54 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/ft_printf.h"

int	ft_ptfhex_len(unsigned long long int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}
