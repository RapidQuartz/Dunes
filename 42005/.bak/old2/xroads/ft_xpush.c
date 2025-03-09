/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:33:27 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/08 18:30:51 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_byte	*ft_xpush(t_byte *snap, t_byte *new, char op)
{
	int		i;
	int		j;
	int		k;

	i = 5;
	new = iter_count(snap, new, op);
	if (snap->a[2] > snap->b[2])
		j = 1;
	else if (snap->a[2] == snap->b[2])
		j = 2;
	if (snap->a[3] > snap->b[3])
		k = 1;
	else if (snap->a[3] == snap->b[3])
		k = 2;
	new = ft_pscount(snap, new, j, k);
	if (op == 'A')
		new = ft_paiter(snap, new, op);
	else if (op == 'B')
		new = ft_pbiter(snap, new, op);
	return (new);
}

/*	how does pushing work??

PA
a: copy top of B found at i = a[2] + 5
0 1 2 3 4 5 6 7 8 9 10
i s A B 0 a a 0 b b

ex;
0 1 2 3 4 5 6 7 8 9 10
i s 3 2 0 a a 0 b b 0

[origin:	set operation at b[1]
size is known and programmed to a[2] a[3] b[2] b[3]
operation is known and programmed to b[1]
a
0 1 2 3 4 5 6 7 8 9 10
i s 2 2 0 a a 0 b b 0

b
0 1 2 3 4 5 6 7 8 9 10
i o 1 1 0 a 0 b 0
]

[prep:	change a[2] a[3] b[2] b[3] {keep balanced or +1 on [2]}
a
0 1 2 3 4 5 6 7 8 9 10
i s 2 1 0 a a 0 b b 0

b
0 1 2 3 4 5 6 7 8 9 10
i o 2 1 0 a 0 b 0
]

[exec:	move values
a
0 1 2 3 4 5 6 7 8 9 10
i s 2 1 0 b a 0 b 0

b
0 1 2 3 4 5 6 7 8 9 10
i o 2 1 0 a a 0 b 0
]
1. copy a[a[2] + 6] to a[5]
2. replace a[a[2] + 6] with a[a[2] + 7]
{if was odd but now even}
	3. copy a[a[2] + 4] to b[b[2] + 5]
{if was even but now odd}
	3. copy a[a[2] + 4] to 

	honestly it seems much easier to do this backwards lmao.
	but i dont wanna keep the 'acorn' value all the time.
	so the trick is:
		both *a and *b are a[2] a[3] b[2] b[3] + 12 size.
		meaning, for a[2] = 2, a[3] = 2, b[2] = 1, b[3] = 1,
	we have 6 numbers. adding + 5 gives us the value at a known number index
		so we can safely move back from i == 11
			{if was odd but now even}
			this always means either
				a[] loses one member
				or
				b[] gets a new member
			{if was even but now odd}
			this always means either
				a[] gains one member
				or
				b[] loses one member
			compare prev->a[2] etc to curr->a[2] etc
			consider operation.
	in push A
		{if was odd but now even}
			one of the B members of a[] moves to b[]
		{if was even but now odd}
			one of the A members of a[] moves to b[]
	in push B
		{if was odd but now even}
		
		{if was even but now odd}
				

	
	meaning, for a[2] = 2, a[3] = 2, b[2] = 2, b[3] = 2,

	
4. iterate until b[i] = 0
4. copy from b[b[2] + b[3] + 5] to b[b[2] + b[3] + 6]
5. iterate backwards till b[5]

a: values shift +1 until the limit set by pscount {to balance}

*/
t_byte	*ft_paiter(t_byte *snap, t_byte *new, char op)
{
	int	i;
	int	m;

	i = 5;
	m = snap->a[2] + 5;
	new->a[i] = snap->a[m];
	while (i++ < m)
		new->a[i] = snap->a[i - 1];
	new->a[i + 1] = 0;
	while (snap->a[++i] != 0)
		new->a[i] = snap->a[i - 1];
	m = snap->b[2] + 5;
	i = 5;
	new->b[i] = snap->a[m];
	while (i++ < m)
		new->b[i] = snap->a[i - 1];
	return (new);
}

t_byte	*ft_pbiter(t_byte *snap, t_byte *new, char op)
{
	return (new);
}



	/* if there is an imbalance, it should stop when reaching `i - 5 == snap->a[2]` and then proceed in snap->b
		scenarios:
1	2	snap->a[2] > snap->b[2]
			PA				
				snap->a[2] stays	
				snap->b[2] + 1	
			PB				
				snap->a[2] - 1	
				snap->b[2] stays	
3	4	snap->a[2] == snap->b[2]
			PA				
				snap->a[2] + 1	
				snap->b[2] stays	
			PB				
				snap->a[2] stays	
				snap->b[2] - 1	
1	4	snap->a[3] > snap->b[3]
			PA				-
				snap->a[3] - 1	
				snap->b[3] stays	
			PB				-
				snap->a[3] stays	
				snap->b[3] + 1	
2	3	snap->a[3] == snap->b[3]
			PA				-
				snap->a[3] stays	
				snap->b[3] - 1	
			PB				-
				snap->a[3] + 1	
				snap->b[3] stays	
		*/
				/*
1,1	1	snap->a[2] > snap->b[2] && snap->a[3] > snap->b[3]
			PA				
				snap->a[2] stays	
				snap->b[2] + 1	
				snap->a[3] - 1	
				snap->b[3] stays		
			PB				
				snap->a[2] - 1	
				snap->b[2] stays				
				snap->a[3] stays	
				snap->b[3] + 1	
				
1,2	2	snap->a[2] > snap->b[2] && snap->a[3] == snap->b[3]
			PA				
				snap->a[2] stays	
				snap->b[2] + 1	
				snap->a[3] stays	
				snap->b[3] - 1	
			PB				
				snap->a[2] - 1	
				snap->b[2] stays
				snap->a[3] + 1	
				snap->b[3] stays	
				
2,1	3	snap->a[2] == snap->b[2] && snap->a[3] > snap->b[3]
			PA				
				snap->a[2] + 1	
				snap->b[2] stays	
				snap->a[3] - 1	
				snap->b[3] stays
			PB				
				snap->a[2] stays	
				snap->b[2] - 1	
				snap->a[3] stays	
				snap->b[3] + 1	
				
2,2	4	snap->a[2] == snap->b[2] && snap->a[3] == snap->b[3]
			PA				
				snap->a[2] + 1	
				snap->b[2] stays
				snap->a[3] stays	
				snap->b[3] - 1	
			PB				
				snap->a[2] stays	
				snap->b[2] - 1
				snap->a[3] + 1	
				snap->b[3] stays	
				
				*/
		

t_byte	*ft_pscount(t_byte *snap, t_byte *new, int mode_a, int mode_b)
{
	if (new->b[1] == 'A')
	{
		if (mode_a == 1)
			new->b[2] = snap->b[2] + 1;
		if (mode_b == 1)
			new->a[3] = snap->a[3] - 1;
		if (mode_a == 2)
			new->a[2] = snap->a[2] + 1;
		if (mode_b == 2)
			new->b[3] = snap->b[3] - 1;
	}
	else if (new->b[1] == 'B')
	{
		if (mode_a == 1)
			new->a[2] = snap->a[2] - 1;
		if (mode_b == 1)
			new->b[3] = snap->b[3] + 1;
		if (mode_a == 2)
			new->b[2] = snap->b[2] - 1;
		if (mode_b == 2)
			new->a[3] = snap->a[3] + 1;
	}
	return (new);
}