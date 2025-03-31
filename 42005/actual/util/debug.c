/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:10:06 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/31 14:23:33 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		debug(char *str)
{
	int	i;
	char	c;

	i = 0;
	if (!str || str[0] == '\0')
		return ;
	write (1, "\n{debug:\n", 8);
	while (str[i] != '\0')
	{
		c = str[i];
		write (1, &c, 1);
		i++;
	}
	write (1, "}\n", 2);
}

void		d_end(void)
{
	exit (2);
}
/* 
void		d_print_stack(t_n **sta)
{
	int	i;
	t_n	*s;
	
	i = 0;
	s = (*sta);
	s = (*(s->h));
	while (i++ < s->i->v)
	{
		printf("node # %d:\t%d\n", i, s->v);
		s = s->n;
	}
} */
void		d_print_cost(t_c *cst)
{
	int	i;
	int	z;
	t_c	*c;
	t_n	*n;
	
	i = 0;
	c = cst;
	n = (*c->cap);
	z = n->i->v;
	while (i < z)
	{
		printf("cost for node: %d\t" \
			"#\t%p#\t%p#\t%p  #\t%d#\t%d#\t%d#\t%d#\t\n" \
			"\t\t\t\tc->cap#\t\tc->ego#\t\tc->tgt  #" \
			"\tc->dif#\tc->dis#\tc->rot#\tc->rev\n", \
		n->v, c->cap, c->ego, c->tgt, c->dif, c->dis, c->rot, c->rev);
		if (i++ < z)
		{
			n = n->n;
			c = n->c;
		}
	}
}


void		d_print_array(int *arr)
{
	int	i;
	char	n;


	i = 0;
	while (i <= 3)
	{
		printf("%d ==", arr[i]);
		i++;
	}
	printf("\n == ");
	i = 0;
	write (1, "\n{debug:arrayprint:\n", 20);
	while (i++ < arr[0])
	{
		n = arr[i] + 48;
		write (1, &n, 1);
		write (1, " ", 1);
	}
	write (1, "}\n", 2);
}

void	d_print_twostack_values(t_n **sta, t_n **stb, int mode)
{
	int	aflag = 0;
	int	bflag = 0;
	int	iflag = 0;
	int	sflag = 0;
	t_n *a = NULL;
	t_n *b = NULL;
	t_n *ap = NULL;
	t_n *bp = NULL;
	t_n *an = NULL;
	t_n *bn = NULL;
	t_n *ai = NULL;
	t_n *bi = NULL;
	t_n **ah = NULL;
	t_n **bh = NULL;
	int	av = 0;
	int	bv = 0;
	int	apv = 0;
	int	bpv = 0;
	int	anv = 0;
	int	bnv = 0;
	int	aiv = 0;
	int	biv = 0;
	int	ahv = 0;
	int	bhv = 0;
	
if ((*sta) != NULL)
{
	a = (*sta);
	av = a->v;
	if (a->p != NULL)
	{
		ap = a->p;
		apv = ap->v;
	}
	if (a->n != NULL)
	{
		an = a->n;
		anv = an->v;
	}
	if (a->i != NULL)
	{
		ai = a->i;
		aiv = ai->v;
		sflag += aiv;
	}
	if (a->h != NULL && (*a->h) != NULL)
	{
		ah = a->h;
		ahv = (*ah)->v;
	}
}
if ((*stb) != NULL)
{
	b = (*stb);
	bv = b->v;
	if (b->p != NULL)
	{
		bp = b->p;
		bpv = bp->v;
	}
	if (b->n != NULL)
	{
		bn = b->n;
		bnv = bn->v;
	}
	if (b->i != NULL)
	{
		bi = b->i;
		biv = bi->v;
		sflag += biv;
	}
	if (b->h != NULL && (*b->h) != NULL)
	{
		bh = b->h;
		bhv = (*bh)->v;
	}
}
	printf("a = %p. b = %p. ap = %p. bp = %p. an = %p. bn = %p. ai = %p. bi = %p. ah = %p. bh = %p.\n"
	"av = %d. bv = %d. apv = %d. bpv = %d. anv = %d. bnv = %d. aiv = %d. biv = %d. ahv = %d. bhv = %d.\n",
	a, b, ap, bp, an, bn, ai, bi, ah, bh, av, bv, apv, bpv, anv, bnv, aiv, biv, ahv, bhv);
	while (mode > 0 && iflag < sflag && aflag + bflag < 2)
	{
		printf("<%d>\t", iflag++);
		if (aflag == 0 && aiv > 0)
		{
			printf("a: %d\t", a->v);
			if (a->n != NULL && a->n != (*a->h))
				a = a->n;
		}
		else if (aiv == 0 || (b != NULL && a->n == (*a->h)))
		{
			printf("a: (empty)\t");
			aflag = 1;
		}
		if (bflag == 0 && biv > 0)
		{
			printf("b: %d\n", b->v);
			if (b->n != NULL && b->n != (*b->h))
				b = b->n;
		}
		else if (biv == 0 || (b != NULL && b->n == (*b->h)))
		{
			printf("b: (empty)\n");
			bflag = 1;
		}
		fflush(stdout);
	}
}
