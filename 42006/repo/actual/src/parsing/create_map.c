/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:26:22 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/20 14:06:06 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

void	set_points(char ***lmn, t_fdf *fdf, int x, int y)
{
	int	lmn_len;
	char	*num;
	char	*col;

	lmn_len = 0;
	while (y < fdf->ymax)
	{
		lmn_len = get_lmn_len(lmn[y][x]);
		if (lmn_len < 0)
			col = extract_color(lmn[y][x], ft_abs(lmn_len));
		else if (lmn_len > 0)
			col = DEFCOL;
		num = get_height(lmn[y][x], ft_abs(lmn_len));
		fdf->pts[y][x].c = convert_color(col);
		fdf->pts[y][x].z = ft_atoi(num);
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
}