# include "../../FdF.h"

bool	check_file(char **a, int i, int j)
{
	/* if filename ENDS with .fdf */
	j = ft_strlen(a[1]);
	i = j - 4;
	if (ft_strnstr(a[1] + i, ".fdf", 4))
		return (true);
	return (false);
}

//	traverses the map and counts::
//	-	elements on the first line
//	-	number of lines
//	returns a structure `dimensions`::
//	-	x_limit
//	-	y_limit
/* t_dim	*get_dimensions(t_map *map)
{
	int	in_number;
	int	i;

	in_number = 0;
	i = -1;
	while (map->map_str[++i] != '\0')
	{
		if (map->map_str[i] == '\n')
			map->dimensions->y_lim++;
		else if (map->map_str[i] == ',')
			i += ft_ishex(map->map_str, i);
		else if (map->map_str[i] == ' ')
			i++;
		if (map->dimensions->y_lim == 0)
		{
			if (ft_isdigit(map->map_str[i]) && !in_number)
			{
				map->dimensions->x_lim++;
				in_number = 1;
			}
			else if (!ft_isdigit(map->map_str[i]))
				in_number = 0;
		}
	}
	return (map->dimensions);
} */

//	checks for color-codes associated with the coordinates
//	returns the offset from `i` to advance the iteration of the map str
int	ft_ishex(char *s, int i)
{
	int	j;
	
	j = 0;
	while (j < 3 && s[i + j] != '\0')
	{
		if ((j == 0 && s[i + j] == ',') ||  (j == 1 && s[i + j] == '0') \
		|| (j == 2 && s[i + j] == 'x'))
			j++;
		else
			return (0);
	}
	while (s[i + j] != '\0' && s[i + j] != '\n' && s[i + j] != ' ')
	{
		if (in_hexset(s[i + j]))
			j++;
		else
			return (0);
	}
	return (j);
}

//	checks if a character is a valid hex key
//	might be redundant, assuming the mapfile is valid
bool	in_hexset(char x)
{
	int	k;
	char	*hex_up;
	char	*hex_lo;

	k = 0;
	hex_up = ft_strdup("0123456789ABCDEF");
	hex_lo = ft_strdup("0123456789abcdef");
	while (hex_up[k] != '\0' && hex_lo[k] != '\0')
	{
		if (x == hex_up[k] || x == hex_lo[k])
			return (true);
		k++;
	}
	return (false);
}


////	TODO:modify `t_dim->s_width` && `t_dim->s_height`
//	this is a potential addition for the bonus::
//	provided there are 3 arguments:
//	//	-	program name
//	//	-	map file
//	//	-	parameters
//	//	it checks:
//	//	-	if the first character of the parameter is a flag '-'
//	//	-	if the parameters after the flag are valid:
//	valid parameters:
//	-	W0000 — window width in pixels
//	-	H0000 — window height in pixels
//	-	X0000 — special sauce/secret codes
//	if no parameters are provided, or if they are invalid
//	it defaults to a certain size window and mode
/*
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
} */