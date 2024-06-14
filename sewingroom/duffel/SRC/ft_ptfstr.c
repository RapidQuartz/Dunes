/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:11:37 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/14 18:08:25 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/ft_printf.h"

int	ft_ptfstr(const char *format)
{
	int	i;

	i = 0;
	if (!format)
		return (0);
	while (format[i])
		i += ft_ptfcha(format[i]);
	return (i - 1);
}
