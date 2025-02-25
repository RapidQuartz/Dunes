/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:40:49 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/25 14:15:48 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
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

int	**ft_nzero(int **s, size_t n, size_t m)
{
	size_t			i;
	size_t			j;
	int				**c;
	
	j = 0;
	c = s;
	c = malloc(sizeof(int*) * n);
	while (j < n)
	{
		i = 0;
		c[j] = malloc(sizeof(int) * m);
		if (!c[j])
			return (NULL);
		while (i < m)
		{
			c[j][i] = 0;
			i++;
		}
		j++;
	}
	s = c;
}
