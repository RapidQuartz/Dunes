/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfuin_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:29:41 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/25 12:19:56 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfuin_put(unsigned int num)
{
	int		len;
	char	*nbr;

	len = 0;
	if (num == 0)
		return (ft_ptfcha('0'));
	else
	{
		nbr = ft_uitoa(num);
		len += ft_ptfstr(nbr);
		free (nbr);
	}
	return (len);
}
