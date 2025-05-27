/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:52:18 by akjoerse          #+#    #+#             */
/*   Updated: 2025/05/27 12:00:57 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/fdf.h"

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
	char	*res;

	i = 0;
	j = 0;
	res = NULL;
	if (a != 2 || check_argument((const char *)v[1]) == NULL)
		return (3);
	while (i < a && v[i][j] != '\0')
	{
		while (v[i][j] != '\0')

			j++;
		i++;
	}
	char *map = ft_strrchr(v[1], '.');
	printf("%s", map);
	return (0);
}
