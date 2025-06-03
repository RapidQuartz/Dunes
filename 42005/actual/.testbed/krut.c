/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   krut.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:40:55 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/15 19:48:35 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	TODO								00002025-04-14 08:44:31 
teddybear picnic:R:babybear:next_bigger+/-next_smaller:

int	teddybear_picnic(t_stk *s);
int	teddybear_picnic(t_stk *s)
{

}
*/
int	teddybear_picnic(t_stk *s, int basket);
int	teddybear_picnic(t_stk *s, int basket)
{
	int	aaa;
	int	bbb;
	int	ccc;

	aaa = 0;
	bbb = 0;
	ccc = 0;
	aaa = find_next_bigger(s->a, basket);
	bbb = find_next_smaller(s->a, basket);
	if (aaa != 0 && bbb != 0)
	{
		
	}
	else if (aaa != 0 && bbb == 0)
		
	else if (aaa == 0 && bbb != 0)
		
	else if (aaa == 0 && bbb == 0)
		
	if (bbb == 0 || aaa < bbb)//
	return (-bbb);
	return (bbb);
}
int	bears_leave_home(t_stk *s)
{
	int	i;
	int	babybear;
	int	mamabear;

	i = 0;
	mamabear = 0;
	babybear = 0;
	if (s->b[1] != s->a[1] - 1)
	{
		babybear = teddybear_picnic(s, s->a[1]);
		while (i++ < s->b[0] && mamabear == 0)
		{
			if (s->b[i] == s->a[1] - 1)
				mamabear = i;
		}
		if (mamabear <= s->b_mid)
			mamabear = 1;
		else if (mamabear > s->b_mid)
			mamabear = -1;
	}
	return (mamabear);
}
