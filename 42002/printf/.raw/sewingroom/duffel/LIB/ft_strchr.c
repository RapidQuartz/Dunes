/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:18:28 by akjoerse          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:10 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	t;

	i = 0;
	t = (char) c;
	while (s[i] != 0)
	{
		if (s[i] == t)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == t && t == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
