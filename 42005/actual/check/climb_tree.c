/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climb_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:42:53 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/17 22:06:17 by akjoerse         ###   ########.fr       */
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
	int	best;
	int	worst;
	short	delta;

	i = 0;
	delta = -1;
	best = -1;
	worst = -1;
	tree = root;
	if (tree != NULL)
	{
		while (i++ < 11)
		{
			best = find_bestdelta(tree);
			if (best > 0 && tree->moves[best] != NULL)
				grow_branch(tree->moves[best]);
			worst = find_worstdelta(tree);
			if (worst > 0 && tree->moves[worst] != NULL)
				prune_branch(tree->moves[worst]);
			if (i != worst)
				tree->probation[i] = climb_tree(tree, i);
		}
	}
}

void	grow_branch(t_snap *best)
{
	best->tree = branch_tree(best);
	//grow the most promising branch
	//delete the others?
	//or just keep them on retainer
}
int		find_worstdelta(t_ree *sub)
{
	int	i;
	int	j;
	int	d;

	i = 0;
	if (sub->order != NULL)
	{
		d = sub->order->delta;
		while (i++ < 11)
		{
			if (sub->moves[i] != NULL && sub->moves[i]->delta > d)
			{
				d = sub->moves[i]->delta;
				j = i;
			}
		}
		if (d == sub->order->delta)
			return (0);
		else
			return (j);
	}
}

int		find_bestdelta(t_ree *sub)
{
	int	i;
	int	j;
	int	d;

	i = 0;
	if (sub->order != NULL)
	{
		d = sub->order->delta;
		while (i++ < 11)
		{
			if (sub->moves[i] != NULL && sub->moves[i]->delta < d)
			{
				d = sub->moves[i]->delta;
				j = i;
			}
		}
		if (d == sub->order->delta)
			return (0);
		else
			return (j);
	}
}
int		climb_tree(t_ree *tree, int i)
{
	int	sum_delta;
	int	j;

	j = 0;
	sum_delta = 0;
	if (tree->moves[i] != NULL && tree->moves[i]->tree != NULL)
	{
		while (j++ < 11)
		{
			if (tree->moves[j]->tree != NULL)
				sum_delta += climb_tree(tree->moves[j]->tree, j);
		}
		sum_delta += tree->moves[i]->delta;
	}
	return (sum_delta);
}

void	prune_branch(t_snap *worst)
{
	int		j;
	t_snap	*branch;

	j = 0;
	while (j++ < 11)
	{
		if (worst->tree->moves[j] != NULL)
		{
			prune_branch(worst->tree->moves[j]);
			free (worst->tree->moves[j]);
		}
	}
	free (worst->tree);
}
