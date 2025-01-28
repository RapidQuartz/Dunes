
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
void		fn_goldrush(t_stack **s);
static int	fn_singlet_check(t_stack **s);
static int	fn_doublet_check(t_stack **s);
static int	fn_triplet_check(t_stack **s);
static int	fn_goldpanning(t_stack **s);
////	:
static int	fn_checkcenter(int x, int y, int z, t_stack **s);
////	:


////	
////	goldrush looks for sing/doub/triplets in the stack
////	
////	and then dispatches the appropriate function
void		fn_goldrush(t_stack **s)
{
	// debug("");
	debug("inside goldrush");
	int		r;
	int		x;
	int		y;
	int		z;
	t_stack	*t;

	r = 0;
	if ((!s || !(*s)))
		error_handling(s, NULL);
	debug("not errored");
	t = find_stack_top(*s);
	debug("found stack top");
	if (!t || t->prev == NULL)
		debug("found stack top, it was really top");
	while (t->next != NULL)
	{
		if (t->prev == NULL)
		{
			t = t->next;
			debug("inside loop 1.0");
		}
		debug("inside loop 2");
		x = t->prev->position;
		debug("inside loop 3");
		y = t->position;
		debug("inside loop 4");
		z = t->next->position;
		debug("inside loop 5");
		debug("calling checkcenter");
		r += fn_checkcenter(x, y, z, &t);
		debug("inside loop 6");
		t = t->next;
		debug("inside loop 7");
	}
	debug("done with it!");
	printf("r: %d\n", r);
}

static int	fn_checkcenter(int x, int y, int z, t_stack **s)
{
	// debug("");
	debug("inside fn_checkcenter()");
	int		r;
	t_stack	*t;

	r = 0;
	if ((s == NULL) || ((*s) == NULL))
		return (0);////DEBUG: SHOULD I FREE HERE? OR CHECK IN CALLER?
	t = (*s);
	if ((y == (x - 1) || (y == (x + 1))) || (y == (z - 1) || (y == (z + 1))))
	{
		debug("doublet or triplet found! ...now what");
		if (y == (x - 1))
		{
			t->prev->adjacency = -1;
			debug("(y == (x - 1)) ---> (*s)->prev->adjacency = -1;");
		}
		else if (y == (z - 1))
		{
			t->adjacency = 1;
			debug("(y == (z - 1)) ---> (*s)->adjacency = 1;");
		}
		if (y == (x + 1))
		{
			t->prev->adjacency = 1;
			debug("(y == (x + 1)) ---> (*s)->prev->adjacency = 1;");
		}
		else if (y == (z + 1))
		{
			t->adjacency = -1;
			debug("(y == (z + 1)) ---> (*s)->adjacency = -1;");
		}
	}
	if (r == 0)
		debug("no match found");
	if (r == 1)
		debug("doublet found");
	if (r == 2)
		debug("triplet found");
	return (r);
}

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
	// debug("");
	debug("inside doublet check");
	int		r;
	t_stack	*t;
	int		x;
	int		y;
	int		z;

	t = (*s);
	r = 0;
	while (s && ((*s) != NULL) && (t->next != NULL))
	{
		debug("iterating through");
		t = t->next;
		x = t->prev->position;
		y = t->position;
			debug("doublet found!! ...now what?");
		if ((y == x + 1) || (y == x - 1))
				r++;
	}
	debug("made it to the end. huh");
	return (r);
}

////	
////	triplet check finds numerical meme gold for triplets
////	
////	a triplet is 3 numbers considered as a group
static int	fn_triplet_check(t_stack **s)
{
	// debug("");
	debug("inside triplet check");
	t_stack	*t;
	int		x;
	int		y;
	int		z;
	int		r;

	r = 0;
	t = (*s);
	if (!t || !(*s))
		return (0);
	if (t->prev == NULL)
		t = t->next;
	x = t->prev->position;
	y = t->position;
	z = t->next->position;
	if ((y == (x - 1) || (y == (x + 1))) && (y == (z - 1) || (y == (z + 1))))
	{
		debug("triplet found! ...now what");
		if (y == (x - 1) || (y == (z - 1)))
			r++;
		if (y == (x + 1) || (y == (z + 1)))
			r++;
	}
	return (r);
}

// static int	fn_triplet_check(t_stack **s)
// {
// 	// debug("");
// 	debug("inside triplet check");
// 	t_stack	*t;
// 	int		x;
// 	int		y;
// 	int		z;
// 	int		r;

// 	r = 0;
// 	t = (*s);
// 	if (!t || !(*s))
// 		return (0);
// 	if (t->prev == NULL)
// 		t = t->next;
// 	x = t->prev->position;
// 	y = t->position;
// 	z = t->next->position;
// 	if ((y == (x - 1) || (y == (x + 1))) && (y == (z - 1) || (y == (z + 1))))
// 	{
// 		debug("triplet found! ...now what");
// 		if (y == (x - 1) || (y == (z - 1)))
// 			r++;
// 		if (y == (x + 1) || (y == (z + 1)))
// 			r++;
// 	}
// 	return (r);
// }

