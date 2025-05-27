/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:38:07 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/25 12:23:48 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	lil;

	i = 0;
	if (little[i] == '\0')
		return ((char *) big);
	lil = ft_strlen(little);
	while (((big[i] != '\0') && (i < len)) && \
		(!(little[0] == '\0' && big[i + l] == '\0')))
	{
		l = 0;
		while (big[i] != '\0' && l < lil)
		{
			if ((lil == l && little[l] == '\0') || (big[i + l] != little[l]))
				break ;
			else if (big[i + l] == little[l])
				l++;
		}
		if (i + l <= len && (lil == l))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
