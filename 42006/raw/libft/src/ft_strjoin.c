/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:15:56 by akjoerse          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:12 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	l = ft_strlen(s1);
	l += ft_strlen(s2);
	s3 = (char *)malloc(l + 1 * sizeof(*s3));
	if (s3 == NULL)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[j + i] = s2[j];
		j++;
	}
	s3[j + i] = '\0';
	return (s3);
}
