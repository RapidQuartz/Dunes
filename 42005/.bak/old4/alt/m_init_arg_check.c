/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_init_arg_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:21:26 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/31 11:37:43 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alt.h"

int		m_check_args(int a, char **b);
static int	check_arg_valid(int a, char **b);
static int	check_arg_unique(int a, char **b);

int	m_check_args(int a, char **b)
{
	if (check_arg_valid(a, b))
		return (check_arg_unique(a, b));
	else
		return (NULL);
}
