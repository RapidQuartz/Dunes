# include "../../FdF.h"

bool	check_file(char **a, int i, int j)
{
	/* if filename ENDS with .fdf */
	j = ft_strlen(a[1]);
	i = j - 4;
	if (ft_strnstr(a + i, ".fdf", 4))
		return (true);
	return (false);
}
bool	check_params(char **a, int i, int j)
{
	j++;
	while (a[2][0] == '-' && a[2][j] != '\0')
	{
		if (ft_toupper(a[2][j] == 'W') || ft_toupper(a[2][j] == 'H') \
		|| ft_toupper(a[2][j] == 'X'))
		{
			i = j + 1;
			if (!ft_isdigit(a[2][i]))
				return (false);
			while (ft_isdigit(a[2][i]))
			{
				if (a[2][i] == '\0')
					break ;
				i++;
			}
			j = i;
		}
	}
	return (true);
}