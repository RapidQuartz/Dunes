/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:52:37 by akjoerse          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:19 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
