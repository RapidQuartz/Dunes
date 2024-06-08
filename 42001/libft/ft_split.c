/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:24:14 by akjoerse          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:09 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static			size_t	ft_words(char const *s, char c);
static			size_t	ft_strings(char const *s, char c, size_t i);
static char		**ft_copycat(char **a, char const *s, char c, size_t i);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	**a;

	i = 0;
	j = 0;
	if (*s && c == '\0')
		n = 2;
	else
		n = ft_words(s, c);
	a = (char **)malloc(n * sizeof(char *));
	if (!a)
		return (NULL);
	while (i + 1 < n && *s)
	{
		j = ft_strings(s, c, i);
		a[i] = (char *)malloc(j * sizeof(char));
		a = ft_copycat(a, s, c, i);
		i++;
	}
	a[i] = NULL;
	return (a);
}

static	size_t	ft_words(char const *s, char c)
{
	int		i;
	size_t	j;

	j = 0;
	i = 1;
	while (s[j] && i > 0)
	{
		if (s[j] == c)
			j++;
		if (s[j] && s[j] != c)
			i = 0;
	}
	j = 0;
	while (*s && i == 0)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
			s++;
		j++;
		while (*s == c)
			s++;
	}
	return (j + 1);
}

static size_t	ft_strings(char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (*s && j < i)
	{
		if (*s != c)
			j++;
		while (*s != c)
			s++;
		while (*s == c)
			s++;
	}
	while (*s && *s == c)
		s++;
	if (*s && j == i)
	{
		j = 0;
		while (*(s + j) && *(s + j) != c)
			j++;
	}
	return (j + 1);
}

static char	**ft_copycat(char **a, char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (*s && j < i)
	{
		if (*s != c)
			j++;
		while (*s != c)
			s++;
		while (*s == c)
			s++;
	}
	if (*s && j == i)
	{
		j = 0;
		while (*s == c)
			s++;
		while (*(s + j) && *(s + j) != c)
		{
			a[i][j] = *(s + j);
			j++;
		}
		a[i][j] = '\0';
	}
	return (a);
}
