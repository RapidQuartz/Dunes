# include "../inc/fdf.h"

bool	check_file(char **a, int i, int j)
{
	/* if filename ENDS with .fdf */
	j = ft_strlen(a[1]);
	i = j - 4;
	if (ft_strnstr(a[1] + i, ".fdf", 4))
		return (true);
	return (false);
}
