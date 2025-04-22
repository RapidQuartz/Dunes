/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:02:21 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/19 16:21:36 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


bool	is_valid(char *a, int j)
{
	if (j == 0)
	while (a[j] == ' ' && a[j] != '\0')
		j++;
	if (is_end(a[j]) || (!is_num(a[j]) && !is_negpos(a[j])) \
	|| (is_negpos(a[j])) && !is_num(a[j + 1]))
		return (false);
	else if (!is_negpos(a[j] && !))
		j++;
	}
	if (is_num(a[j]));
	{
		while (is_num(a[j++]))
		{
			if (is_end(a[j]))
				return (true);
			else
				return (false);
		}
	}
	else if (is_negpos(a[j]));
	else if (is_end(a[j]));
}

bool	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);		
}

bool	is_negpos(char c)
{
	if (c == '+' || c == '-')
		return (true);
	else
		return (false);		
}

bool	is_end(char c)
{
	if (c == ' ' || c == '\0')
		return (true);
	else
		return (false);		
}
