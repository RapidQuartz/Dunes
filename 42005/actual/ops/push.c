#include "../push_swap.h"
void	ft_pushto(t_snap *old, t_snap *new, int op);
void	ft_pushfrom(t_snap *old, t_snap *new, int op);

t_snap	*do_push(t_snap *new, t_ree *tree, int op)
{
	short			i;

	ft_pushto(tree->order, new, op);
	ft_pushfrom(tree->order, new, op);
	return (new);
}

void	ft_pushto(t_snap *old, t_snap *new, int op)
{
	int	i;
	unsigned short	*to;

	i = 0;
	if (op == 1)
	{
		to = new->a;
		to[0] = old->a[0] + 1;
		to[1] = old->b[1];
		while (++i < to[0])
			to[i] = old->a[i + 1];
		new->a = to;
	}
	if (op == 2)
	{
		to = new->b;
		to[0] = old->b[0] + 1;
		to[1] = old->a[1];
		while (++i < to[0])
			to[i] = old->b[i + 1];
		new->b = to;
	}
	return ;
}

void	ft_pushfrom(t_snap *old, t_snap *new, int op)
{
	int	i;
	unsigned short	*from;

	i = 0;
	if (op == 1)
	{
		from = new->b;
		from[0] = old->b[0] - 1;
		while (++i < from[0])
			from[i] = old->b[i + 1];
		new->b = from;
	}
	if (op == 2)
	{
		from = new->a;
		from[0] = old->a[0] - 1;
		while (i++ < from[0])
			from[i] = old->a[i + 1];
		new->a = from;
	}
	return ;
}
/* 	to[0] += 1;
	from[0] = - 1;
	i = to[0];
	to[1] = from[1];
	while (i-- > 1)
		to[i + 1] = to[i];
	while (i++ < from[0])
		from[i - 1] = from[i];
	from[i] = 0; */