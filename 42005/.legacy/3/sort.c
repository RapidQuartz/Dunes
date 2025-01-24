#include "push_swap.h"
////	FUNC:
int		is_sorted(t_stack *stack);
void		sort(t_stack **st_a, t_stack **st_b, int size);

//-----------------------------------------------------------------------------
void		sort(t_stack **st_a, t_stack **st_b, int size)
{
//	:0:	check sort vs size (small algo special)
//	:1:	sort	(ask for help for godssakes)
	if (!is_sorted(*st_a))
		sorter(st_a, st_b, size);
	else
		return ;
}
////	HELPER:
//is_sorted
int		is_sorted(t_stack *stack)
{
	t_stack	*check;
	
	while (stack)
	{
		check = stack;
		stack = stack->next;
		if (stack && stack->value < check->value)
			return (0);
	}
	return (1);
}
////	HELPER:
//position_delta

////	HELPER:
////	HELPER:

//-----------------------------------------------------------------------------
////	HELPER: