# include "FdF.h"

int	main(int a, char **v)
{
	int	i;
	int	j;
	int	fd;
	char	*file;
	char	*params;

	i = 0;
	j = 0;
	file = NULL;
	params = NULL;
	if (((a < 2 || a > 3) || (a == 2 && !check_file(v, i, j))) \
	|| (a == 3 && (!check_file(v, i, j) || !check_params(v, i, j))))
		return (1);
	file = ft_strdup(v[1]);
	if (a == 3)
		params = ft_strdup(v[2]);
	fd = open(file, O_RDONLY);
	free (file);
	return (init_fdf(fd, params));
}
