/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:07:43 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/25 12:23:48 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	int				neg;
	unsigned int	nbr;

	neg = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		neg = -1;
	}
	nbr = (n * neg);
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	if (nbr < 10)
	{
		c = nbr + 48;
		ft_putchar_fd(c, fd);
	}
	return ;
}
