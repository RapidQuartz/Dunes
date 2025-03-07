/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:42:23 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/07 14:55:18 by akjoerse         ###   ########.fr       */
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
	
	acorn = ((*stack_a)->size);
	debug("the acorn was just the right size");
	tree = NULL;
	tree = worldtree(tree, acorn + 12);
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
	t_byte	*yggdrasil;
	
	debug("the acorn shot its root into the ground");
	yggdrasil = malloc(sizeof(*yggdrasil));
	if (!yggdrasil)
	{
		debug("but it died before it could grow into a tree")	;
		return (NULL);
	}
	debug("and the root found fertile soil");
	debug("more shoots started to sprout");
	yggdrasil->a = malloc(sizeof(char) * acorn);
	if (!yggdrasil->a)
	{
		debug("but the first branch died before it could grow");
		return (NULL);
	}
	debug("and the first branch took form");
	yggdrasil->b = malloc(sizeof(char) * acorn);
	if (!yggdrasil->b)
	{
		debug("but the second died before it could grow");
		return (NULL);
	}
	if (tree && tree != NULL)
	{
		debug("the branch tried to be set right");
		tree->next = yggdrasil;
	}
	debug("and it seemed to work");
	debug("the branch looked naked without any shoots");
	yggdrasil->next = NULL;
	debug("the acorn had now grown into a sapling");
	return (yggdrasil);
}

void		baumschule(t_byte	**tree, short acorn, t_stack **stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	debug("and it found fertile soil in which to grow");
	//transcription
	debug("its genetic material informed it how to grow");
	init_sbyte(tree, acorn);
	debug("hollow paths from its ancestors where sap would flow");
	transcribe_sbyte(tree, acorn, stack);
	debug("its creator had a hard look at the sapling");
	while (i < acorn + 12)
	{
		printf("a:\t%d-%d\t:b\t {==} %d\n", (*tree)->a[i], (*tree)->b[i], i);
		i++;
	}
	debug("and the sapling was perfectly formed and ready to grow further");
	plant_tree(tree, acorn);
	while ((*tree) != NULL)
	{
		i = 0;
		printf("%d iteration of tree\n", j);
		while (i < acorn + 12)
		{
			printf("a:\t%d-%d\t:b\t {==} %d\n", (*tree)->a[i], (*tree)->b[i], i);
			i++;
		}
		if ((*tree)->next == NULL)
			break ;
		(*tree) = (*tree)->next;
		j++;
	}
	//sort state
	//cost eval
	//operation dispatch
}

void		init_sbyte(t_byte **tree, short acorn)
{
	if ((*tree)->next == NULL)
	{
		(*tree)->a[0] = 0;
		(*tree)->b[0] = 0;
	}
	(*tree)->a[1] = 251;
	(*tree)->b[1] = 251;
	(*tree)->a[2] = (acorn / 2)+(acorn % 2);
	(*tree)->b[2] = (acorn / 2);
	(*tree)->a[3] = 0;
	(*tree)->b[3] = 0;
	(*tree)->a[4] = 0;
	(*tree)->b[4] = 0;
}
void		transcribe_sbyte(t_byte	**tree, short acorn, t_stack **stack)
{
	int		i;

	i = 5;
	while (i - 5 < ((*tree)->a[2]))
	{
		(*tree)->a[i] = (*stack)->pos;
		(*stack) = (*stack)->next;
		i++;
	}
	i = 5;
	while (i - 5 < (*tree)->b[2])
	{
		(*tree)->b[i] = (*stack)->pos;
		(*stack) = (*stack)->next;
		i++;
	}
}

t_byte	*imprinting(t_byte **tree, short acorn, t_stack **stack)
{
	t_byte	*sproot;

	sproot = (*tree);
	return (NULL);
}

//
/*	pad
	debug("");

	int		i;

	i = 0;
	while ()
*/