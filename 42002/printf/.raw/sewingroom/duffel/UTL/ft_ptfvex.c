/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfvex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:09:13 by codespace         #+#    #+#             */
/*   Updated: 2024/06/11 11:09:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vex(const char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		return (len += ft_ptfcha(va_arg(ap, int)));
	if (format == 's')
		return (len += ft_ptfstr(va_arg(ap, char*)));
	if (format == 'p')
		return (len += ft_ptfptr(va_arg(ap, unsigned long long)));
	if ((format == 'd') || (format == 'i'))
		return (len += ft_ptfint(va_arg(ap, int)));
	if (format == 'u')
		return (len += ft_ptfuin(va_arg(ap, unsigned int)));
	if ((format == 'x') || (format == 'X'))
		return (len += ft_ptfhex(va_arg(ap, unsigned int), format));
	if (format == '%')
		return (len += ft_ptfcha(va_arg(ap, int)));
}