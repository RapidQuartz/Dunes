
////
////
////		[		new and improved algorithm		]
////
////
#include "push_swap.h"
////[sub-strategic-breakdown](README.md#sub-strategic-breakdown)
// static void fn_(t_stack **s);
// 
// 
static void fn_goldrush(t_stack **s);
static int fn_singlet_check(t_stack **s);
static int fn_doublet_check(t_stack **s);
static int fn_triplet_check(t_stack **s);
static int fn_goldpanning(t_stack **s);


////	
////	goldrush looks for sing/doub/triplets in the stack
////	
////	and then dispatches the appropriate function
static void fn_goldrush(t_stack **s)
{
	int		r;
	t_stack	*t;
	int		x;
	int		y;
	int		z;

	if ((s == NULL) || ((*s) == NULL))
		return ;////DEBUG: SHOULD I FREE HERE? OR CHECK IN CALLER?
	t = (*s);
	r = -1;
	if (t->prev == NULL)
		t = t->next;
	x = t->prev->position;
	y = t->position;
	z = t->next->position;
	if (x <= 0 || y <= 0 || z <= 0)
		return ;
	if ((y == (x - 1) || (y == (x + 1))) && (y == (z - 1) || (y == (z + 1))))
		r = fn_triplet_check(s);
	else if ((y == (x - 1) || (y == (x + 1))) || (y == (z - 1) || (y == (z + 1))))
		r = fn_doublet_check(s);
	if (r <= 0)
		r = fn_goldpanning(s);
	return ;
}
static int fn_goldpanning(t_stack **s)
{
	return (0);////DEBUG:
}

/* 
	//
	if (!fn_triplet_check(s) && !fn_doublet_check(s) && !fn_singlet_check(s))
		r = goldpanning(s)
		r = fn_doublet_check(s);
		if (fn_doublet_check(s))
		if (r && triplet_check(s))
			r += fn_triplet_check(s);
	if (fn_doublet_check(s) > 0)
	if (fn_triplet_check(s) > 0)
		r = fn_triplet_check(s);
	if (r)
	{
	
			fn_singlet_check(s);

			if (y == (z - 1) || (y == (z + 1)))
			{
				if (y == (z - 1) ||	(y == (z + 1)))
					fn_triplet_check(s);
				else
					fn_doublet_check(s);
			}
			else
				return ;

	
	}
} */

////	TODO:URGENT:RETURNVALUE:ZEROFORDEFAULT:INTFORNUMBEROFADJACENTS:
////	singlet check finds numerical meme gold for singlets
////	
////	a singlet is 1 number considered alone
////	this time its not about relative numbers, but positional index
////	if no doublets or triplets (2-3 adjacent numbers) are found 
////	this function sees if any of the numbers are favorably placed
////	considering the index to position relationship
////	based on this, a value 'r' is returned, indicating the quality
////	since doublets and triplets also return an integer,
////	the sort of number returned is significant
////	there are many sizes of stacks possible, but in any case there
////	is a practical limit to how delayed this would make it....
////	:operations:
////	::walks through whole stack and observes index and position:
////	:::advances forwards initially:
////	:::compares ratio between [[stack->index]&&[stack->position]]:
////	::::if (stack->index > stack->position)
////	:::: [if(STACK A = ---)][if(STACK B = +++)]
////	::::if (stack->index < stack->position)
////	:::: [if(STACK A = ---)][if(STACK B = +++)]
////	::::if (stack->index == stack->position)
////	:::: [if(STACK A = +++)][if(STACK B = ---)]
////	::::
////	::::for stack A that means the fewer 'steps away' from ideal
////	::::{so.. the `CLOSER` to the proportional index, the better}
////	::::for stack B that means the more 'steps away' from ideal
////	::::{so.. the `CLOSER` to the inverse index, the better}
////	::::the average of the sum of these relationships can be given
////	::::as a predictable number, like a percentage
////	::::and from this percentage, entropy unmasks, at least once.
////	::::
////	::::
////	:::
////	:::
////	::OR::
////	::::saves relationship between `i` and `p` in `subtotal` {w/e}:
////	:::reverses backwards:
////	:::
////	:::
////	:assumed:
////	::[max_index == max_position]::
////	::stack has appropriate variables to populate::
////	::::
////	:results:
////	:::
////	::
////	:::
////	
////	
////	
////	
static int	fn_singlet_check(t_stack **s)
{
	t_stack	*t;
	int		x;
	int		y;
	int		z;

	t = (*s);
	if (t->prev == NULL)
		t = t->next;
	x = t->prev->position;
	y = t->position;
	z = t->next->position;
	if (s && ((*s) != NULL))
	{
		while (t->next != NULL)
		{
		}
		while (t->prev != NULL)
		{
			if (y == (x + 1))
				return (1);
			if (y == (x - 1))
				return (1);
		}
	}
	return (0);
}

////	
////	doublet check finds numerical meme gold for doublets
////	
////	a doublet is 2 numbers considered as a group
static int	fn_doublet_check(t_stack **s)
{
	int		r;
	t_stack	*t;
	int		x;
	int		y;
	int		z;

	t = (*s);
	r = 0;
	while (s && ((*s) != NULL) && (t->next != NULL))
	{
		t = t->next;
		x = t->prev->position;
		y = t->position;
		z = t->next->position;
		if (((y == z + 1) || (y == z - 1)) || ((y == x + 1) || (y == x - 1)))
		{
			
		}
////	THIS:IS:GOOD:DONT:ACTUALLY:RETURN:
			// return ;
		while (t->prev != NULL)
		{
			if (y == (x + 1))
				return (0);
			if (y == (x - 1))
				return (0);
		}
		while (t->next != NULL)
		{
			if (y > z)
				return (0);
			if (y < z)
				return (0);
		}
	}
	return (r);
}

////	
////	triplet check finds numerical meme gold for triplets
////	
////	a triplet is 3 numbers considered as a group
static int	fn_triplet_check(t_stack **s)
{
	t_stack	*t;
	int		x;
	int		y;
	int		z;

	t = (*s);
	if (!t || !(*s))
		return (0);
	if (t->prev == NULL)
		t = t->next;
	x = t->prev->position;
	y = t->position;
	z = t->next->position;
	if (x == 0 || y == 0 || z == 0)
		return (0);
	if (y == (x - 1) ||	(y == (x + 1)) || y == (z - 1) || (y == (z + 1)))
		if (y == (x - 1))
			;
		if (y == (x + 1))
			;
		if (y == (z - 1))
			;
		if (y == (z + 1))
			;
	return (0);
}

