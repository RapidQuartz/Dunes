/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:17:38 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/14 18:10:48 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/ft_printf.h"

char	*ft_uitoa(unsigned int num)
{
	char	*nbr;
	int		len;

	len = ft_ptfnumlen(num);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (num)
	{
		nbr[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (nbr);
}
