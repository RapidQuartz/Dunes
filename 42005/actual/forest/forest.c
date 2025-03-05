/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:42:23 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/05 15:16:09 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* process:


*/
//::001
void		forest(t_stack **stack_a, t_stack **stack_b)
{
	t_byte	**tree;

}

t_byte	*worldtree(t_byte	**tree)
{
	t_byte	*ygg;
	t_byte	*dra;
	t_byte	*sil;

	ygg = malloc(sizeof(t_byte *));
	if (!ygg)
		debug("ERROR::001");
	dra = ygg;
	ygg->a = malloc(sizeof(char) * 256);
	if (!ygg->a)
		debug("ERROR::002");
	ygg->b = malloc(sizeof(char) * 256);
	if (!ygg->b)
		debug("ERROR::003");
}
