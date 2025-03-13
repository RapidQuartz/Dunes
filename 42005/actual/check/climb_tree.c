/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climb_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:42:53 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/13 16:37:03 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	on moveset penalties and pruning[]
//	if a moveset is found more expensive, it receives a penalty
//	the penalty is stored in the `t_ree->probation[]` array for that index
//	penalties contribute to the decision of pruning branches
//	values are compared branch-by-branch at a certain iteration level
//	once enough penalties accumulate, the whole branch is pruned
//	the threshold for when to prune should be based on the memory allocated
//	or another factor of performance
//	the goal is breadth first/depth later */
/*	setting probation[]
if more than one moveset exists
and the [i]th moveset has lower delta than the [j]th moveset
then the [j]th moveset is marked with a higher penalty
the movesets with cumulatively higher deltas over time are pruned
*/

/*	purpose and description
`climb_tree` will attempt to traverse along as many branches as possible
during this traversal, the delta costs for all branches is compared
this is used to select prospects and delinquents {HOW}
when the sum of numbers concerned reaches ??
when the memory sum??
at a certain level??

*/
void		chop_tree(t_ree *chop);
void		chop_branch(t_snap *branch);
void		prune_branch(t_snap *crimscum);
void		compare_branch(t_ree *root);
void		compare_branch(t_ree *root)
{
	int	i;
	t_ree	*tree;
	int	sheriff;

	i = 0;
	sheriff = -1;
	tree = root;
	while (i++ < 11)
		tree->probation[i] = climb_tree(tree, i);
	while (--i > 1)
	{
		if (tree->probation[i] > sheriff)
			sheriff = i;
	}
	if (tree->moves[sheriff] != NULL)
	{
		if (tree->moves[sheriff]->penalty >= 1000)
			prune_branch(tree->moves[sheriff]);
		else
			tree->moves[sheriff]->penalty += 100;
	}
}

int		climb_tree(t_ree *tree, int i)
{
	int	j;
	int	sum_delta;

	j = 0;
	sum_delta = 0;
	while (j++ < 11)
	{
		if (tree->moves[j] != NULL)
		{
			sum_delta += climb_tree(tree->moves[j]->tree, j);

		}
	}
	return (sum_delta);
}

void	prune_branch(t_snap *crimscum)
{
	int		j;
	t_snap	*branch;

	j = 0;
	while (j++ < 11)
	{
		if (crimscum->tree->moves[j] != NULL)
		{
			prune_branch(crimscum->tree->moves[j]);
			free (crimscum->tree->moves[j]);
		}
	}
	free (crimscum->tree);
}
