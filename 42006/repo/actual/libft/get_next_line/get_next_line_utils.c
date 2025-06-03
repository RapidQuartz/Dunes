/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:05:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/23 19:14:12 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strnl(char	*str)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			n = i + 1;
	}
	return (n);
}

size_t	gnl_strlen(char *first)
{
	size_t	len;

	len = 0;
	while (first && first[len])
		len++;
	return (len);
}

char	*gnl_strjoin(char *first, char *second)
{
	size_t	la;
	size_t	lb;
	char	*out;

	if (first == NULL || !first)
	{
		first = gnl_calloc(1, 1);
		out = first;
	}
	la = (gnl_strlen(first));
	lb = (gnl_strlen(second));
	out = gnl_calloc(1, (la + lb) + 1);
	if (!out)
	{
		free (first);
		return (NULL);
	}
	if (!first || !second)
		return (NULL);
	out = gnl_strcpy(first, second, out, 0);
	return (out);
}

char	*gnl_strcpy(char *first, char *second, char *out, size_t index)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!second || !out)
		return (NULL);
	while (first && first[i])
	{
		out[i] = first[i];
		i++;
	}
	while (second[j + index])
	{
		out[i + j] = second[j + index];
		if (second[j + index] != '\0')
			j++;
	}
	out[i + j] = '\0';
	if (first)
		free (first);
	return (out);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	void	*cpy;
	size_t	i;

	i = nmemb * size;
	ptr = (void *)malloc(i);
	if (!ptr)
		return (NULL);
	cpy = ptr;
	while (i--)
		*(unsigned char *)ptr++ = '\0';
	return (cpy);
}
