/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:25:44 by akjoerse          #+#    #+#             */
/*   Updated: 2025/06/03 13:31:29 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

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

//SUPERFLUOUS?
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
