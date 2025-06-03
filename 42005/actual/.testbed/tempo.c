#include "push_swap.h"

int	*realign_stack(int *s)
{
	int	i;
	int	m;
	int	n;

	if (s[0] > 0)
	{
		i = s[0];
		m = s[i];
		s[i] = 0;
		while (i-- != 1)
		{
			n = s[i];
			s[i] = m;
			m = n;
		}
	}
	else
		s[1] = 0;
	s[0]--;
	return (s);
}
t_stk	*push_a(int *a, int *b, t_stk *c)
{
	int	i;
	int	m;
	int	n;

	i = 0;
	a[0]++;
	b[0]--;
	m = b[1];
	while (i++ < a[0])
	{
		n = a[i];
		a[i] = m;
		m = n;
	}
	i = b[0];
	m = b[i];
	b[i] = 0;
	while (i > 0)
	{
		n = b[i];
		b[i] = m;
		m = n;
	}
	write (1, "pa\n", 3);
	return (c);
}
// s = a[0];
// b = realign_stack(b);
t_stk	*push_b(int *a, int *b, t_stk *c)
{
	int	i;
	int	m;
	int	n;

	i = 0;
	b[0]++;
	a[0]--;
	m = a[1];
	while (i++ < b[0])
	{
		n = b[i];
		b[i] = m;
		m = n;
	}
	i = a[0];
	m = a[i];
	a[i] = 0;
	while (i > 0)
	{
		n = a[i];
		a[i] = m;
		m = n;
	}
	write (1, "pb\n", 3);
	return (c);
}
// s = b[0];
// a = realign_stack(a);