/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climb_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:42:53 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/11 18:44:36 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_snap	*penalizer(t_snap *snap, int delta);
int		**branch_array(int **b);

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
this is used to select prospects and delinquents

*/
void		compare_branch(t_ree *root);
void		compare_branch(t_ree *root)
{
	int	i;
	t_ree	*tree;

	i = 0;
	tree = root;
	while (i++ < 11)
		tree->probation[i] = climb_tree(tree, i);
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
			sum_delta += climb_tree(tree->moves[i]->tree, j);
	}
	return (sum_delta);
}