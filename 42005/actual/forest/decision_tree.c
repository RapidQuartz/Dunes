/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:20:57 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/04 18:42:56 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* PSEUDO: */

//	purpose:	initializes the decision tree
t_tree	**tree_planter(t_stack **sta, t_stack **stb, t_tree **tree)
{
	int		i;
	t_stack	*s;

	if (tree == NULL)
		*tree = make_tree(tree, sta);
	s = (*(*sta)->head);
	trunk_alloc(sta, tree);
	branch_alloc(tree);
	leaf_alloc(tree);
	seed_alloc(tree);
	return (tree);
}

//	purpose:	copy stacks to `short **trunk`
void		trunk_alloc(t_stack **stack_a, t_tree **tree)
{
	int		i;
	short		size;
	short		**trunk;

	i = 0;
	size = 2 * ((*stack_a)->size + 1);
	// 215 because i have that many after all first tests
	*trunk = malloc(sizeof(short *) * 215);
	if (!trunk || trunk == NULL)
		debug("ERR: trunk_alloc didnt <1>");//
	while (i < 215)
	{
		trunk[i] = malloc(sizeof(short) * size);
		if (!trunk || trunk == NULL)
			debug("ERR: trunk_alloc didnt <2>");//
		i++;
	}
	(*tree)->trunk = trunk;
	trunk_init(stack_a, tree);
	return ;	
}

//	purpose:	moveset generation
void		branch_alloc(t_tree **tree)
{
	int		i;
	char		**branch;
	
	i = 0;
	//16 lets me have 5 aspiring candidates (or more), and 11 sets.
	*branch = malloc(sizeof(char *) * 16);
	if (!branch || branch == NULL)
			debug("ERR: branch_alloc didnt <1>");//
	while (i < 16)
	{
		branch[i] = malloc(sizeof(char *) * MAX_MOVES);
		if (!*branch || *branch == NULL)
			debug("ERR: branch_alloc didnt <2>");//
		branch[i][0] = '\0';
		i++;
	}
	(*tree)->branch = branch;
	return ;
}

//	purpose:	entropy score generation and evaluation
void		leaf_alloc(t_tree **tree)
{
	int		i;
	short		**leaf;

	i = 0;
	*leaf = malloc(sizeof(short *) * 16);
	if (!*leaf || leaf == NULL)
		debug("ERR: leaf_alloc didnt <1>");//
	while (i < 16)
	{
		leaf[i] = malloc(sizeof(short));
		if (!leaf || leaf == NULL)
			debug("ERR: leaf_alloc didnt <1>");//
		leaf[i][0] = 0;
		i++;
	}
	(*tree)->leaf = leaf;
	return ;
}

//	purpose:	transfer moveset `branch` after seleciton
void		seed_alloc(t_tree **tree)
{
	int		i;
	t_stack	*s;
	char		**seed;

	i = 0;
	*seed = malloc(sizeof(char *) * 5);
	if (!*seed || seed == NULL)
		debug("ERR: seed_alloc didnt <1>");//
	while (i < 5)
	{
		seed[i] = malloc(sizeof(char) * MAX_MOVES);
		if (!seed || seed == NULL)
			debug("ERR: leaf_alloc didnt <1>");//
		seed[i][0] = '\0';
		i++;
	}
	(*tree)->seed = seed;
	return ;
}

//// DEBUG:
/* :PSEUDO */