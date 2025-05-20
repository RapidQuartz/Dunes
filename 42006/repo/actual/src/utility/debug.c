# include "../inc/fdf.h"

void	debug(char *m)
{
	if (m)
		ft_printf(RED"%s\n"DEF, m);
	return ;
}

void	debug_strs(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_printf(BLU"%s\n"DEF, s[i++]);
	}
}