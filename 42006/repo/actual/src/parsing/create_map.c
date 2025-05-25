/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:26:22 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/25 16:28:48 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/fdf.h"

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

int	get_height(t_fdf *fdf, char *num, int end)
{
	int	i;
	char	*height;
	
	i = 0;
	height = malloc(sizeof(char) * end + 1);
	if (!height || height == NULL)
		end_fdf(fdf, -10);
	while (i < end)
	{
		height[i] = num[i];
		i++;
	}
	height[i] = '\0';
	return (ft_atoi(height));
}

int	get_color(t_fdf *fdf, char *p, int l)
{
	char	*c;
	if (l < 0)
		c = extract_color(fdf, p, ft_abs(l));
	else
		c = DEFCOL;
	return (convert_color(p, l));
}

char	*extract_color(t_fdf *fdf, char *col, int start)
{
	int	len;
	int	i;
	char	*out;
	
	i = 0;
	len = ft_strlen(col + start);
	out = malloc(sizeof(char) * len + 1);
	if (!out || out == NULL)
		end_fdf(fdf, -11);
	while (col[start + i] != '\0' && i < len)
	{
		out[i] = col[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

int	convert_color(char *col, int mode)
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
	if (mode < 0)
		free (col);
	return (hex);	
}