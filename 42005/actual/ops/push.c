#include "../push_swap.h"
void	ft_pushto(t_snap *old, t_snap *new, unsigned short *to, int op);
void	ft_pushfrom(t_snap *old, t_snap *new, unsigned short *from, int op);

t_snap	*do_push(t_ree *tree, int op)
{
	t_snap		*new;
	unsigned short	*from;
	unsigned short	*to;
	short			i;

	new = tree->moves[op];
	to = malloc(sizeof(unsigned short) * new->size);
	from = malloc(sizeof(unsigned short) * new->size);
	if ((!to || to == NULL) || (!from || from == NULL))
		return (NULL);
	ft_pushto(tree->order, new, to, op);
	ft_pushfrom(tree->order, new, from, op);
	return (new);
}

void	ft_pushto(t_snap *old, t_snap *new, unsigned short *to, int op)
{
	int	i;

	i = 0;
	if (op == 1)
	{
		to[0] = old->a[0] + 1;
		to[1] = old->b[1];
		while (++i < to[0])
			to[i] = old->a[i + 1];
		new->a = to;
	}
	if (op == 2)
	{
		to[0] = old->b[0] + 1;
		to[1] = old->a[1];
		while (++i < to[0])
			to[i] = old->b[i + 1];
		new->b = to;
	}
	free (to);
	return ;
}

void	ft_pushfrom(t_snap *old, t_snap *new, unsigned short *from, int op)
{
	int	i;

	i = 0;
	if (op == 1)
	{
		from[0] = old->b[0] - 1;
		while (++i < from[0])
			from[i] = old->b[i + 1];
		new->a = from;
	}
	if (op == 2)
	{
		from[0] = old->a[0] - 1;
		while (i++ < from[0])
			from[i] = old->a[i + 1];
		new->b = from;
	}
	free (from);
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