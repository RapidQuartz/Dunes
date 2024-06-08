/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:07:58 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/07 18:48:08 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* temporary inclusions for testing */
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//// TEMP:
/* temporary or borrowed functions go here */
//strdup
char	*ft_strdup(const char *s);

//// STATIC:
/* static functions go here */
static int		ft_ptfcha(char c);
static int		ft_ptfstr(const char *format);
static int		ft_vex(const char format, va_list ap);
static void		ft_ptfhex_put(unsigned int num, const char format);
static int		ft_ptfhex(unsigned int num, const char format);
static int		ft_ptfhex_len(unsigned int num);
static int		ft_ptfptr(unsigned long long ptr);
static int		ft_ptfint(int num);
static void		ft_ptfint_put(int num)
static int		ft_ptfuin(unsigned int num);
static int		ft_ptfnumlen(unsigned int num);
static char		*ft_uitoa(unsigned int num);


//// FUNCTIONS:
/* main printf function */
/* operation:
0.	call function
1.	parse input
2.	produce output
*/
/* detailed operation
0.0.	ft_printf(const char *format, ...)
1.0.	what flags?
static int		ft_vex(const char format, va_list ap);
takes the character at the current dooblydoo and the list dooblydoo ap.
decides if any of the flags are relevant
calls the next function to print the appropriate data type

1.1.	hex?
ft_ptfhex(format, num)
1.1.0	is number larger than or equal to 16?
YES:	ft_ptfhex(format, num / 16)
NO:		ft_ptfhex(format, num % 16)
1.1.1	is number less than or equal to 9?
YES:	ft_ptfcha((num + '0'))
NO:		{continue}
1.1.2	is format == x or X?
1.1.3	format == x
		ft_ptfcha((num - 10) + 'a')
1.1.4	format == X
		ft_ptfcha((num - 10) + 'A')

1.2.	dec?
ft_ptfint(int num)
;calls the function to print the number;
ft_ptfint_put(int num)
;and counts the length of the number itself;
;before returning that length as an int;
		
1.3.	str?
ft_ptfstr(char* format)

;before returning that length as an int;
1.4.	char?
ft_ptfcha(char format)
;before returning that length as an int;
1.5.	%?
ft_ptfcha(char format)
;before returning that length as an int;
1.6.	bonus?
[how does the main even know if it should use the bonus??]

[should the original vex pass to bonus if indicated?]
[would be done after running `make bonus`]
[this seems to mean that I need to put those ft in a different dir]
[specifically a file _bonus.c or _bonus.h]
[do they mean that this is a suffix? or the actual one file?]
[if so, bonuses are very constrained, one file, five functions etc]
[otherwise it means ft_ptfutil_bonus.c etc]

2.0.	
*/
//// FTVEX:
/* ft_vex(const char *format, va_list ap)
[hello i find out which is which]
[i take format, ap]
[then I send the right info to the right handler]
our selection today:
c	-	(int)					//	print char
s	-	(char*)					//	print string
p	-	(unsigned long long)			//	print pointer
d/i	-	(int)					//	print int
u	-	(unsigned int)				//	print unsigned
x/X	-	(unsigned int)				//	print hex
[B]	-	(bonuscheck? individual functions?) 	//	(if bonus make flag)

[then we send info to that function, it seems the return is always int, for clear reasons]
[just be careful, there are many functions from before to use.]

*/
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

//// MAIN:

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

//// FTPTFCHA:
int	ft_ptfcha(char c)
{
	write (1, &c, 1);
	return (1);
}
/*
ft_ptfcha()

[from libft]
ft_putchar_fd()

//// FUNCPUTCHAR:

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
*/

//// FUNCPUTSTR:

int	ft_ptfstr(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
		i += ft_ptfcha(format[i]);
	return (i);
}
//// FTPTFSTR:
/*
ft_ptfstr()

[from libft]
ft_putstr_fd()

//// FUNCPUTSTR:

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		ft_putchar_fd(s[i++], fd);
}
*/

//// FTPTFPTR:
/*
ft_ptfptr()

[suggested]
write a hex

{DEF}[hexlen]
int	len;
hexlen = 0;
while (num)
{
	hexlen++;
	num /= 16
}
return (hexlen)

{DEF}[puthex]{input: uint num, const char *format}
while (num)
{
	if (num >= 16)
		[puthex](num / 16, format)
		[puthex](num % 16, format)
	if (num <= 9)
		[put] = num + 48;
	else
	{
		if (format == x)
			[putchar] (num - 10) + a
		if (format == X)
			[putchar] (num - 10) + A
	}
}
*/
static int		ft_ptfptr(unsigned long long ptr)
{
	
}

//// FTPTFINT:
///
///
///
/*
ft_ptfint()

[suggested]
putnbr

[from libft]
ft_putnbr_fd()

[issue with this]
doesnt return the length. Should call this from a root function.
*/
/// this is the main function that gets called, calls the printer and returns a numlen.
int			ft_ptfint(int	num)
{
	int	i;

	i = 0;
	while (num)
	{
		ft_ptfint_put(num);
	}
	while (true)
	{	
		num /= 10;
		i++;
	}

	return (i);
}


/* 
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
*/
////	FTPTFINTPUT:
//this needs to be called from another function.
//my first step is to change its name to include a _put suffix
void		ft_ptfint_put(int num)
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
			//here could be called another function, or something
			ft_ptfcha(num - '0');
		if (num > 9)
		{
			num = ft_ptfint_put(num % 10);
			num = ft_ptfint_put(num / 10);
		}
	}
}
//// FTPTFUIN:
/*
ft_ptfuin()

//OBS//
needs an 'itoa' type called 'uitoa'
//OBS//


[suggested]
why is this differnt from the other one? bigger max I guess?
*/
static int		ft_ptfuin(unsigned int num)
{
	//output lots of good stuff
	int	i;

	i = 0;
	while (num != 0)
	{
		
	}
}

//// FTPTFUITOA:

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

//// FTPTFNUMLEN:
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

//// FUNCPUTHEX:

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
//// OBS: remove before sub
//// FTPITOA:

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
//// TEMP: remove before sub
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

//// FTPTFHEX:
/*
ft_ptfhex()

{	new approach

send va_arg, unsigned int, format to the hex main

hexmain
	if the number is truly zero
		it writes 0 and returns with putcha
	else
		the hex main calls 'hexput'
	return
		result of hexlen

hexlen
	while the number is not zero
		len++
		num/=16
	return len
hexput
	if the number is greater than or equal to 16
		it recurses
			hexput num / 16
			hexput num % 16
	if the number is smaller than or equal to 9
		it outputs
			putcha num + '0'
	if the number is bigger than 9 but less than 16
		and format is 'x'
			it outputs
				putcha num - 10 + a
		and format is 'X'
			it outputs
				putcha num - 10 + A

the hex main returns 'hexlen'


	
}

[suggested]
write a case-sensitive hex
[similar to]
putnbr hex/putnbr base
*/

/*  */
/* va list pseudo sandbox
ap
argument pointer
va_list
va_start
va_arg
va_end
*/
/*
begin by initializing:
`va_list ap`
then start
`va_start(ap, format)`
//initializes `ap` to point to 'first unnamed argument'
`char* va_arg(ap, char*)` //??//I think this is the format//??//
//returns one argument, steps ap to next, takes data type
*/
/* messy sandbox

why is this so hard for me??

basically:

the va_ stuff is there to help
it goes backwards?

//read about the va_stuff no?

so if we find the % we know it's a flag


but how do we sort the order of
	%'s and connect them with the order of variables?



*/
