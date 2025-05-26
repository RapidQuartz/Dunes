# include "../../inc/fdf.h"

////	HEXTOI:
//	if `n` is a number '0'-'9' —> (48 - 57)
//	//	return (n - 48)
//	//	//	—> return (0 - 9)
//	if `n` is a letter 'A'-'F' —> (65 - 70) —>
//	//	return (n - 55)
//	//	//	—> return (10 - 15)
//	if `n` is a letter 'a'-'f' —> (97 - 102) —>
//	//	return (n - 87)
//	//	//	—> return (10 - 15)
int	ft_hextoi(char n)
{
	if (n >= '0' && n <= '9')
		return (n - 48);
	else if (n >= 'A' && n <= 'F')
		return (n - 55);
	else if (n >= 'a' && n <= 'f')
		return (n - 87);
	return (-1);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	free_map(t_fdf *fdf)
{
	int	i;
	int	j;
	t_dim	d;
	char	***e;
	char	*s;
	
	i = 0;
	d = *fdf->dim;
	e = fdf->raw->elements;
	s = fdf->raw->string;
	while (i < d.y_max)
	{
		j = 0;
		while (j < d.x_max)
		{
			free(e[i][j]);
			j++;
		}
		free(e[i]);
		i++;
	}
	free (e);
	e = NULL;
	free (s);
	s = NULL;
}
