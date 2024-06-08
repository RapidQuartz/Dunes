/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:49:41 by akjoerse          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:16 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isitin(char it, char const *in)
{
	size_t	i;

	i = 0;
	while (in[i] != '\0')
	{
		if (in[i] == it)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (s1[start] != '\0' && ft_isitin(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isitin(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
