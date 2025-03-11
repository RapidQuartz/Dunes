#include "../push_swap.h"

unsigned short	*ft_aswap(unsigned short *obj);


t_snap	*do_swap(t_ree *tree, int op)
{
	t_snap		*new;
	unsigned short	*obj;
	short			swap;

	new = tree->moves[op];
	//sa//ss
	if (op == 3 || op == 5)
	{
		obj = new->a;
		swap = obj[1];
		obj[1] = obj[2];
		obj[2] = swap;
		new->a = obj;
	}
	//sb//ss
	if (op == 4 ||  op == 5)
	{
		obj = new->b;
		swap = obj[1];
		obj[1] = obj[2];
		obj[2] = swap;
		new->b = obj;
	}
	return (new);
}
