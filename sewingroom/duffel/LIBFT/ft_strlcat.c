/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:12:14 by akjoerse          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:12 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			l;
	size_t			s;

	i = 0;
	l = 0;
	s = 0;
	s = ft_strlen(src);
	l = ft_strlen(dst);
	if (size == 0)
		return (s);
	if (l > size && size > 0)
		return (s + size);
	if (l + 1 < size)
	{
		while (src[i] != '\0' && i + l + 1 < size)
		{
			dst[i + l] = src[i];
			i++;
		}
	}
	dst[i + l] = '\0';
	return (l + s);
}
