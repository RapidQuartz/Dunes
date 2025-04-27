/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:54:36 by akjoerse          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:15 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	t;

	i = 0;
	j = -1;
	t = (char) c;
	while (s[i] != 0)
	{
		if (s[i] == t)
			j = i;
		i++;
	}
	if (s[i] == t && t == '\0')
	{
		j = i;
		return ((char *)&s[j]);
	}
	if (j >= 0)
		return ((char *) &s[j]);
	else
		return (NULL);
}
