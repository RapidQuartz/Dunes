/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:04:54 by akjoerse          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:06 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				m;
	const unsigned char	*s;
	unsigned char		*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	m = 0;
	if (d < s)
	{
		while (m < n)
		{
			d[m] = s[m];
			m++;
		}
	}
	else if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
