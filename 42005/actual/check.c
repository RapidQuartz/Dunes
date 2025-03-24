/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:22:40 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/20 16:30:20 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_n *sta)
{
	sta = (*sta->h);
	while (sta != sta->i->p)
	{
		if (sta->v > sta->n->v)
			return (0);
		sta = sta->n;
	}
	return (1);
}
