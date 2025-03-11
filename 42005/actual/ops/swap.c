#include "../push_swap.h"

unsigned short	*ft_aswap(unsigned short *obj);


t_snap	*do_swap(t_snap *new, t_ree *tree, int op)
{
	short			swap;

	new = transcribe_snap(tree->order, new);
	//sa//ss
	if (op == 3 || op == 5)
	{
		swap = new->a[1];
		new->a[1] = new->a[2];
		new->a[2] = swap;
	}
	//sb//ss
	if (op == 4 ||  op == 5)
	{
		swap = new->b[1];
		new->b[1] = new->b[2];
		new->b[2] = swap;
	}
	return (new);
}

t_snap	*transcribe_snap(t_snap *snap, t_snap *new)
{
	int	i;

	i = -1;
	while (snap->a[0] > 0 && ++i <= snap->a[0])
		new->a[i] = snap->a[i];
	while (snap->b[0] > 0 && ++i <= snap->b[0])
		new->b[i] = snap->a[i];
	return (new);
}