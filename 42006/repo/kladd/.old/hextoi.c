# include "../FdF.h"
//cc -g hextoi.c -L../libft -lft

int		ft_ishex(char x)
{
	char	*hex;
	int	i;

	i = 0;
	hex = ft_strdup("ABCDEF");
	while (hex[i] != '\0')
	{
		if (x == hex[i] || x == ft_tolower(hex[i]))
			return (1);
		i++;
	}
	return (0);
}

int		ft_hextoi(char *hex)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (hex[i] != '\0')
	{
		if (ft_isdigit(hex[i]))
			n += hex[i] - 48;
		else if (ft_ishex(hex[i]))
		{
			while (hex[i] != )
		}
	}
	return (n);
}

int	main(void)
{
	char	*str;
	char	*stx;
	int	hex;
	int	i;

	str = ft_strdup("0,0xFFFFFF");
	while (*str != ' ')
	{
		if (*str == ',')
		{
			stx = ft_strdup(str + 3);
			while (stx[i] != '\0')
			{
				stx[i] = ft_toupper(stx[i]);
				i++;
			}
			hex = ft_hextoi(str + 3);
			break ;
		}
		str++;
	}
	ft_printf("%d,,%s\n", hex, stx);
	return (0);
}
