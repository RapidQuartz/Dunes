#include "../push_swap.h"
void	ft_pushto(t_snap *old, t_snap *new, t_ops op);
void	ft_pushfrom(t_snap *old, t_snap *new, t_ops op);

t_snap	*do_push(t_snap *new, t_ree *tree, t_ops op)
{
	short			i;

	ft_pushto(tree->order, new, op);
	ft_pushfrom(tree->order, new, op);
	return (new);
}

void	ft_pushto(t_snap *old, t_snap *new, t_ops op)
{
	int	i;
	unsigned short	*to;

	i = 0;
	if (op == PA)
	{
		to = new->a;
		to[0] = old->a[0] + 1;
		to[1] = old->b[1];
		while (i++ < to[0])
			to[i + 1] = old->a[i];
		new->a = to;
	}
	if (op == PB)
	{
		to = new->b;
		to[0] = old->b[0] + 1;
		to[1] = old->a[1];
		while (i++ < to[0])
			to[i + 1] = old->b[i];
		new->b = to;
	}
	return ;
}

void	ft_pushfrom(t_snap *old, t_snap *new, t_ops op)
{
	int	i;
	unsigned short	*from;

	i = 0;
	if (op == PA)
	{
		from = new->b;
		from[0] = old->b[0] - 1;
		while (i++ < old->b[0])
			from[i] = old->b[1 + i];
		new->b = from;
	}
	if (op == PB)
	{
		from = new->a;
		from[0] = old->a[0] - 1;
		while (i++ < old->a[0])
			from[i] = old->a[1 + i];
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