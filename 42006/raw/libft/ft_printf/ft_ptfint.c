/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:13:09 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/18 15:44:47 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/ft_printf.h"

int	ft_ptfint(int num)
{
	char	*nbr;
	int		len;

	len = 0;
	if (num == -2147483648)
	{
		ft_ptfstr("-2147483648");
		return (11);
	}
	if (num == 0)
		return (ft_ptfcha('0'));
	else
	{
		nbr = ft_itoa(num);
		len += ft_ptfstr(nbr);
		free (nbr);
	}
	return (len);
}
