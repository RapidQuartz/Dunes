/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:57:45 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/05 15:46:18 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	main(void)
{
	float	n = 420.220112333;
	int		i = 321;
	char	*s="flying in the sky";
	printf("Hello World\n% .3f\n% d\n%s\n", n, i, s);
	return (0);
}

//// FUNCPUTNBR:

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

//// FUNCPUTCHAR:

int	ft_ptfcha(char c)
{
	write (1, &c, 1);
	return (1);
}

//// FUNCPUTSTR:

int	ft_ptfstr(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
		ft_ptfcha(format[i++]);
	return (i);
}

//// FUNCPUTHEX:

void	ft_ptfhex(const char *format, unsigned int num)
{
	char c;
	int	neg;
	
	if (num >= 16)
	{
		ft_ptfhex(format, num / 16);
		ft_ptfhex(format, num % 16);
	}
	if (num <= 9)
		ft_ptfcha((num + '0'));
	else
	{
		if (format == 'x')
			ft_putchar_fd((num - 10) + 'a', 1);
		if (format == 'X')
			ft_putchar_fd((num - 10) + 'A', 1);
	}
}

//// FUNCPUTPTR:

int	ft_ptfptr(const char *format, va_list ap)
{
	
}