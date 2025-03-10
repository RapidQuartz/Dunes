#include "../push_swap.h"

t_snap	*do_push(t_ree *tree, int op)
{
	t_snap	*new;
	unsigned short		*from;
	unsigned short		*to;
	short		i;

	new = tree->moves[op];
	if (op == 1)
		from = new->b;
	if (op == 1)
		to = new->a;
	if (op == 2)
		from = new->a;
	if (op == 2)
		to = new->b;
	to[0] += 1;
	from[0] -= 1;
	i = to[0];
	to[1] = from[1];
	while (i-- > 1)
		to[i + 1] = to[i];
	while (i++ < from[0])
		from[i - 1] = from[i];
	from[i] = 0;
	return (new);
}
