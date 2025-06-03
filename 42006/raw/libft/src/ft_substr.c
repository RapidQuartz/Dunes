/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:13:06 by akjoerse          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:17 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*null_string(void)
{
	char	*empty;

	empty = malloc(sizeof(char));
	if (!empty)
		return (NULL);
	empty[0] = '\0';
	return (empty);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*z;
	size_t	end;
	size_t	stl;

	stl = 0;
	end = 0;
	while (s[stl] != '\0')
		stl++;
	if (stl < start)
		return (null_string());
	if (start + len > stl)
		len = stl - start;
	z = malloc((len + 1) * sizeof(char));
	if (!z)
		return (NULL);
	while (end < len)
	{
		z[end] = s[start + end];
		end++;
	}
	z[end] = '\0';
	return (z);
}
