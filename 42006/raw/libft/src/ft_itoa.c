/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:49:22 by akjoerse          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:05 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	filler(int i, int len, char *str, int n)
{
	int	j;

	j = len - 1;
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (i < len)
	{
		str[j] = (n % 10) + '0';
		n /= 10;
		j--;
		i++;
	}
	str[len] = '\0';
}

static int	counter(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			i;
	int			len;
	char		*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = counter(n);
	i = 0;
	if (n < 0)
	{
		len++;
		i = 1;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	filler(i, len, str, n);
	return (str);
}
