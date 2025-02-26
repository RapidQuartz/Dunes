/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:40:49 by akjoerse          #+#    #+#             */
/*   Updated: 2025/02/26 18:23:08 by akjoerse         ###   ########.fr       */
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

int	*ft_nzero(int *s, size_t n)
{
	size_t			i;
	int				*c;
	
	i = 0;
	c = s;
	c = malloc(sizeof(int) * n);
	if (!c)
		return (NULL);
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
	s = c;
}
