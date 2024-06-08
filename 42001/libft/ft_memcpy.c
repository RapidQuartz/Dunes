/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:05:13 by akjoerse          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:06 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				m;

	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	if (dest == src || n == 0)
		return (dest);
	m = 0;
	while (m < n)
	{
		d[m] = s[m];
		m++;
	}
	return (dest);
}
