/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:42:23 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/05 19:42:36 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../new.h"

/* process:


*/
//debug("");
//::001
void		forest(t_stack **stack_a, t_stack **stack_b)
{
	debug("once upon a time there was a forest");
 	t_byte	*tree;
	 debug("and in that forest there lay an acorn");
	short		acorn;
	
	acorn = (12 + (*stack_a)->size);
	debug("the acorn was just the right size");
	tree = NULL;
	tree = worldtree(tree, acorn);
	debug("a new sapling stood in a clearing in the forest");
	if (!tree)
	{
		debug("and no tree grew from the acorn");
		return ;
	}
	debug("and the sapling grew familiar with the world");
	baumschule(&tree, acorn, stack_a);
}

t_byte	*worldtree(t_byte *tree, short acorn)
{
	debug("and one day, it began to grow");
	t_byte	*ygg;
	t_byte	*dra;
	t_byte	*sil;
	debug("the acorn shot its root into the ground");
	ygg = malloc(sizeof(*ygg));
	if (!ygg)
	{
		debug("but it died before it could grow into a tree")	;
		return (NULL);
	}
	debug("and the root found fertile soil");
	dra = ygg;
	debug("more shoots started to sprout");
	ygg->a = malloc(sizeof(char) * (acorn / 2)+(acorn % 2));
	if (!ygg->a)
	{
		debug("but the first branch died before it could grow");
		return (NULL);
	}
	debug("and the first branch took form");
	ygg->b = malloc(sizeof(char) * (acorn / 2));
	if (!ygg->b)
	{
		debug("but the second died before it could grow");
		return (NULL);
	}
	debug("the acorn had now grown into a sapling");
	return (ygg);
}

void		baumschule(t_byte	**tree, short acorn, t_stack **stack)
{
	debug("and it found fertile soil in which to grow");
	//transcription
	
	//sort state
	//cost eval
	//operation dispatch
}

t_byte	*imprinting(t_byte	**tree, short acorn, t_stack **stack)
{
	t_byte	*sproot;

	sproot = (*tree);
	return (NULL);
}