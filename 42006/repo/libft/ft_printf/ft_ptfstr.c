/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptfstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:11:37 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/25 12:20:01 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfstr(const char *format)
{
	int	i;

	i = 0;
	if (!format)
		return (ft_ptfstr("(null)"));
	while (format[i])
		i += ft_ptfcha(format[i]);
	return (i);
}
