/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:52:18 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/27 13:05:46 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/fdf.h"
/* char	*check_argument(const char *v)
{
	char	*res;
	
	res = ft_strrchr(v, '.');
	if (res && ft_strncmp(res, ".fdf", 4) == 0)
		return (res);
	return (NULL);
} */
/* 

char	*get_height(char *num, int end)
{
	int	i;
	char	*height;
	
	i = 0;
	height = malloc(sizeof(char) * end + 1);
	if (!height || height == NULL)
		exit (0);//TODO:integrate into exit function;
	while (i < end)
	{
		height[i] = num[i];
		i++;
	}
	height[i] = '\0';
	return (height);
}

char	*extract_color(char *col, int start)
{
	int	len;
	int	i;
	char	*out;
	
	i = 0;
	len = ft_strlen(col + start);
	out = malloc(sizeof(char) * len + 1);
	if (!out || out == NULL)
		return (NULL);
	while (col[start + i] != '\0' && i < len)
	{
		out[i] = col[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
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
int	convert_color(char *col)
{
	int	i;
	int	hex;
	
	i = 2;
	hex = 0;
	while (col[i])
	{
		hex *= 16;
		hex += ft_hextoi(col[i]);
		i++;
	}
	free (col);
	return (hex);	
} */

/* 
void	set_points(char ***lmn, t_fdf *fdf, int x, int y)
{
	int	lmn_len;
	char	*num;
	char	*col;

	lmn_len = 0;
	while (y < fdf->y_lim)
	{
		lmn_len = get_lmn_len(lmn[y][x]);
		if (lmn_len < 0)
			col = extract_color(lmn[y][x], ft_abs(lmn_len));
		else if (lmn_len > 0)
			col = DEFCOL;
		num = get_height(lmn[y][x], ft_abs(lmn_len));
		fdf->pts[y][x].src->c[0] = convert_color(col);
		fdf->pts[y][x].src->z[0] = ft_atoi(num);
		free (num);
		x++;
		if (!lmn[y][x])
		{
			x = 0;
			y++;
		}
	}
	free_map(fdf);
} 
}
*/
int	get_lmn_len(char *lmn)
{
	int	i;
	
	i = 0;
	while (lmn[i])
	{
		if (lmn[i] == ',')
			return (-i);
		i++;
	}
	return (i);
}
void	convert_position(t_fdf *f, char **c, t_pos *p)
{
	int	i;
	char	*c;
	char	*z;
	
	while (c[i])
	{
		p->c = hex_tractor(c[i], get_lmn_len(c[i]));
		p->z = zee_tractor(c[i], get_lmn_len(c[i]));
	}
}

// char	*convert_color(char *col, int start, int i, int j)
int	hex_tractor(char )
{
	char	*c;
	char	*z;
	
	if (start < 0)
		col = DEFCOL;
	j = ft_strlen(col + ft_abs(start));
	c = malloc(sizeof(char) * j + 1);
	if (!c || c == NULL)
		return ;
	while (col[ft_abs(start) + i] != '\0' && i < j)
	{
		c[i] = col[ft_abs(start) + i];
		i++;
	}
	c[i] = '\0';
	i = 0;
	len = 0;
	while (c[i])
	{
		len *= 16;
		len += ft_hextoi(c[i]);
		i++;
	}
	return (c);
}
int	convert_color(char *col)
{
	
}
	/* 
	t_pos	o;
	t_map m;
	char	*c;

	if (ft_(m.map[f->x]))
	o.c =  m.map[f->x];
} */
void	convert_map(t_fdf *f)
{
	t_map	m;

	m.raw = get_next_line(f->err);
	while (f->err != -1)
	{
		m.str = get_next_line(f->err);
		m.raw = ft_strjoin(m.raw, m.str);
		free (m.str);
	}
	m.lines = ft_split(m.raw, '\n');
	free (m.raw);
	close (f->err);
	while (m.lines[f->max_y])
		f->max_y++;
	m.map = malloc(sizeof(*m.map) * f->max_y);
	f->pos = malloc(sizeof(*f->pos) * f->max_y);
	while (f->y < f->max_y)
	{
		m.map[f->y] = ft_split(m.lines[f->y], ' ');
		convert_position(f, m.map[f->y], f->pos[f->y]);
		f->y++;
	}
}
char	*check_argument(const char *v)
{
	char	*res;
	
	res = ft_strrchr(v, '.');
	if (res && ft_strncmp(res, ".fdf", 4) == 0)
		return (res);
	return (NULL);
}
int	main(int a, char **v)
{
	int	i;
	int	j;
	t_fdf	f;

	i = 0;
	j = 0;
	if (a != 2 || check_argument((const char *)v[1]) == NULL)
		return (3);
	f.err = open(v[1], O_RDONLY);
	f.x = 0;
	f.y = 0;
	if (f.err)
		convert_map(&f);
	printf("%s", "it will be ok :)\n");
	return (0);
}
