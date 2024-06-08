/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:07:58 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/08 16:51:23 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* temporary inclusions for testing */
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_printf(const char *format, ...);
char	*ft_strdup(const char *s);
static int		ft_ptfcha(char c);
static int		ft_ptfstr(const char *format);
static int		ft_vex(const char format, va_list ap);
static void		ft_ptfhex_put(unsigned int num, const char format);
static int		ft_ptfhex(unsigned int num, const char format);
static int		ft_ptfhex_len(unsigned int num);
static int		ft_ptfptr(unsigned long long ptr);
static int		ft_ptfint(int num);
static int		ft_ptfint_put(int num);
static int		ft_ptfuin(unsigned int num);
static int		ft_ptfnumlen(unsigned int num);
static char		*ft_uitoa(unsigned int num);

void	main(void)
{
	int		i;
	char	s;
	char	*str = "Take it off. Slow. Steady. Undress. Impress.";
	
	i = 0;
	while (i++ < 1)
		ft_printf(str);
	return ;
}

int		ft_vex(const char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_ptfcha(va_arg(ap, int));
	if (format == 's')
		len += ft_ptfstr(va_arg(ap, char*));
	if (format == 'p')
		len += ft_ptfptr(va_arg(ap, unsigned long long));
	if ((format == 'd') || (format == 'i'))
		len += ft_ptfint(va_arg(ap, int));
	if (format == 'u')
		len += ft_ptfuin(va_arg(ap, unsigned int));
	if ((format == 'x') || (format == 'X'))
		len += ft_ptfhex(va_arg(ap, unsigned int), format);
	if (format == '%')
		len += ft_ptfcha(va_arg(ap, int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	len = 0;
	i = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
			len += ft_vex(format[i + 1], ap);
		else
			len += ft_ptfcha(format[i]);
		i++;
	}
	return (len);
}

int	ft_ptfcha(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_ptfstr(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
		i += ft_ptfcha(format[i]);
	return (i);
}

static int		ft_ptfptr(unsigned long long ptr)
{
	
}

int			ft_ptfint(int	num)
{
	int	i;

	i = 0;
	if (num)
		ft_ptfint_put(num);
	else
		return (0);
	while (num)
	{	
		num /= 10;
		i++;
	}

	return (i);
}
int		ft_ptfint_put(int num)
{
	int				neg;
	unsigned int	nbr;
	
	neg = 1;
	if (num < 0)
		neg = -1;
	nbr = num * neg;
	while (num)
	{
		if (num <= 9)
			ft_ptfcha(num - '0');
		if (num > 9)
		{
			num = ft_ptfint_put(num % 10);
			num = ft_ptfint_put(num / 10);
		}
	}
}

static int		ft_ptfuin(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		
	}
}

static char	*ft_uitoa(unsigned int num)
{
	char	*nbr;
	int		len;
	
	len = ft_ptfnumlen(num);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (num)
	{
		nbr[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (nbr);
}

static int		ft_ptfnumlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int		ft_ptfhex(unsigned int num, const char format)
{
	if (num == 0)
		return (ft_ptfcha('0'));
	else
		ft_ptfhex_put(num, format);
	return (ft_ptfhex_len(num));
}

void	ft_ptfhex_put(unsigned int num, const char format)
{	
	if (num >= 16)
	{
		ft_ptfhex_put(format, num / 16);
		ft_ptfhex_put(format, num % 16);
	}
	else
	{
		if (num <= 9)
			ft_ptfcha((num + '0'));
		else
		{
			if (format == 'x')
				ft_ptfcha((num - 10) + 'a');
			if (format == 'X')
				ft_ptfcha((num - 10) + 'A');
		}
	}
}

int		ft_ptfhex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

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

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*d;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	d = malloc(len + 1);
	if (d == NULL)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int	ft_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
