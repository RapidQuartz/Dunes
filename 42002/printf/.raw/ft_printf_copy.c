/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:07:58 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/08 20:10:32 by akjoerse         ###   ########.fr       */
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
static void		ft_ptfhex_put(unsigned long long int num, const char format);
static int		ft_ptfhex(unsigned long long int num, const char format);
static int		ft_ptfhex_len(unsigned long long int num);
static int		ft_ptfptr(unsigned long long ptr);
static int		ft_ptfint(int num);
static int		ft_ptfint_put(int num);
static int		ft_ptfuin(unsigned int num);
static int		ft_ptfnumlen(unsigned int num);
static char		*ft_uitoa(unsigned int num);

////TESTER: to test the original function of printf.

// cspdiuxX%
int	main(void)
{
	int				max;
	char			c;
	char			*s = "this is a friendly string";
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
	char			*p;
	
	max = -2147483648;
	c = 'q';
	d = max;
	i = 0;
	u = 4294967295;
	x = 0xaaaaaaaa;
	X = 0xFFFFFFFF;
	p = s;
	ft_printf("0: %c\n", c);
	printf("-+-%d\n", ft_printf("-0: %c\n", c));
	printf("--%d\n", printf("-0: %c\n", c));
	ft_printf("1: %s\n", "this is a friendly string");
	printf("-+-%d\n", ft_printf("-1: %s\n", "this is a friendly string"));
	printf("--%d\n", printf("-1: %s\n", "this is a friendly string"));
	ft_printf("2: %s\n", s);
	printf("-+-%d\n", ft_printf("-2: %s\n", s));
	printf("--%d\n", printf("-2: %s\n", s));
	ft_printf("3: %d\n", d);
	printf("-+-%d\n", ft_printf("-3: %d\n", d));
	printf("--%d\n", printf("-3: %d\n", d));
	ft_printf("4: %i\n", i);
	printf("-+-%d\n", ft_printf("-4: %i\n", i));
	printf("--%d\n", printf("-4: %i\n", i));
	ft_printf("5: %u\n", u);
	printf("-+-%d\n", ft_printf("-5: %u\n", u));
	printf("--%d\n", printf("-5: %u\n", u));
	ft_printf("6: %x\n", x);
	printf("-+-%d\n", ft_printf("-6: %x\n", x));
	printf("--%d\n", printf("-6: %x\n", x));
	printf("-6-: %x\n", x);
	ft_printf("7: %X\n", X);
	printf("-+-%d\n", ft_printf("-7: %X\n", X));
	printf("--%d\n", printf("-7: %X\n", X));
	printf("-7-: %X\n", X);
	ft_printf("8: %p\n", &p);
	printf("-+-%d\n", ft_printf("-8: %p\n", &p));
	printf("--%d\n", printf("-8: %p\n", &p));
	printf("-8-: %p\n", &p);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_vex(format[i + 1], ap);
			i++;
		}
		else
			len += ft_ptfcha(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

int		ft_vex(const char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		return (len += ft_ptfcha(va_arg(ap, int)));
	if (format == 's')
		return (len += ft_ptfstr(va_arg(ap, char*)));
	if (format == 'p')
		return (len += ft_ptfptr(va_arg(ap, unsigned long long)));
	if ((format == 'd') || (format == 'i'))
		return (len += ft_ptfint(va_arg(ap, int)));
	if (format == 'u')
		return (len += ft_ptfuin(va_arg(ap, unsigned int)));
	if ((format == 'x') || (format == 'X'))
		return (len += ft_ptfhex(va_arg(ap, unsigned int), format));
	if (format == '%')
		return (len += ft_ptfcha(va_arg(ap, int)));
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
	if (!format)
		return (0);
	while (format[i])
		i += ft_ptfcha(format[i]);
	return (i - 1);
}

// this thing eh? i guess it just outputs a pointer address.
static int		ft_ptfptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (0);
	else
	{
		ft_ptfstr("0x");
		len += 2;
	}
	len += ft_ptfhex(ptr, (const char) 'x');
	return (len);
}

int			ft_ptfint(int num)
{
	int	i;

	i = 0;
	if (num == -2147483648)
	{
		ft_ptfstr("-2147483648");
		return (11);
	}
	if (num)
		num = ft_ptfint_put(num);
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
	if (num == 0)
		return (ft_ptfcha('0'));
	if (num < 0)
	{
		neg = -1;
		ft_ptfcha('-');
	}
	nbr = num * neg;
	while (num)
	{
		if (num <= 9)
			return (ft_ptfcha(num + '0'));
		if (num > 9)
		{
			num = ft_ptfint_put(num % 10);
			num = ft_ptfint_put(num / 10);
		}
	}
}

//WORK IN PROGRESS
////TODO: reverse numbers I guess. use the uitoa son.
static int		ft_ptfuin(unsigned int num)
{
	int		i;
	char	c;

	i = ft_ptfstr(ft_uitoa(num));
	return (i);
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

int		ft_ptfhex(unsigned long long int num, const char format)
{
	if (num == 0)
		return (ft_ptfcha('0'));
	ft_ptfhex_put(num, format);
	return (ft_ptfhex_len(num));
}

void	ft_ptfhex_put(unsigned long long int num, const char format)
{	
	if (num >= 16)
	{
		ft_ptfhex_put(num / 16, format);
		ft_ptfhex_put(num % 16, format);
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

int		ft_ptfhex_len(unsigned long long int num)
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
