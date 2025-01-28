#	INDEX

[--](#)
[-pad-](#pad)
[-index-](#index)
[-cost-](#cost)
[-calculation-](#calculation)
[-quality-](#quality)
[-metrics-](#metrics)
[-OPERATIONS-](#OPERATIONS)
[-TO ADD](#-TO ADD)
[-pa-](#pa)
[-pb-](#pb)
[-push-](#push)
[-sa-](#sa)
[-sb-](#sb)
[-ss-](#ss)
[-swap-](#swap)
[-ra-](#ra)
[-rb-](#rb)
[-rr-](#rr)
[-rotate-](#rotate)
[-rra-](#rra)
[-rrb-](#rrb)
[-rrr-](#rrr)
[-reverse_rotate-](#reverse_rotate)

#	pad
[-index-](#index)
[--](#)
<::>
			::
			:;:
				::

													:










#	cost
[-index-](#index)
[-entropic stack-](#entropic)
[--](#)
<:description:<
cost is a measure of:	**the number of moves**
that it takes to:		*place a stack entry*
:				**SO THAT IT BECOMES SORTED**
this is sensitive to:	**THE CURRENT STACK**						<
:	or:			*the current order of the stack*
:specifically, the current order of both of the stacks:

		
:the stack is:		ascending
:if:there are more ascending values than descending



:the stack is:		entropic
:if:there is an equal-ish number of ascending and descending values				
				
				
				
:the stack is:		descending
:if:there are more descending values than ascending
													>
depending on **the nature of the stack**:							<
:a different algorithm may be used
:the operations may be reversed or changed
:the cost is calculated separately
													>
:if:the stack in general is::this means:
###		ascending:
		:the first items are lower than the last items
		:strategy:
			::push-first:
			:because pushing back will leave stack sorted
			::

###		entropic:
		:there is an even mix of asc/descending values
		:strategy:
			::divide-and-conquer
			:find pockets of sorting, decrease scope each time:
			:meaning:
				:if:there are 12 items::
				:first no pattern is found on all 12:
				:then a pattern is searched for in 2 sets of 6:
				:then a pattern is searched for in 3 sets of 4:
				:then a pattern is searched for in 4 sets of 3:
				:then a pattern is searched for in 6 sets of 2:
				:depending:on the outcome, either asc/desc is chosen:::
			::
				::

			::

###		descending:
		:the last items are lower than the first items
		:strategy:
			::push-last:
			:stack must be rotated before it can be pushed back
			:example:
			:a stack:A:has:4 values:
			:{1, 3, 2, 4}:
			:two values adjacent:3/2
			:two values in right place:1/4
			:value;distance to adjacent/next value up:down::
			:forward:
			:1;2:0:
			:3;2:1:
			:2;3:2:
			:4;0:2:
			::sum::
			:;7:5:
			::
			:backward:
			:1;2:0:
			:3;2:3:
			:2;1:2:
			:4;0:2:
			::sum::
			:;5:7:
			::
		:notes:
			::identical result
				;could be "3*4"
			::should be more free flow
			::could use c tutor/pythontutor:
			:for better visualization of stack ops:
			:for testing of project components:
####			::TODO:mf:
			::make:testing-file::
			::
:
				
example:
**WORKING IN STACK A**
**WORKING IN STACK B**
**WORKING IN STACK A**
**WORKING IN STACK B**
:				**
:>>










#	calculation
[-index-](#index)











#	quality
[-index-](#index)











#	metrics
[-index-](#index)













#	OPERATIONS
[-index-](#index)

[push](#push)

[push a](#pa)
[push b](#pb)

[swap](#swap)
[swap a](#sa)
[swap b](#sb)
[swap both](#ss)

[rotate](#rotate)
[rotate a](#ra)
[rotate b](#rb)
[rotate both](#rr)

[reverse rotate](#reverse_rotate)
[reverse rotate a](#rra)
[reverse rotate b](#rrb)
[reverse rotate both](#rrr)










## TO ADD
[-index-](#index)
t_stack	*find_penultimate(t_stack *stack)

void execute_pa(t_stack **st_a, t_stack **st_b)
void execute_pb(t_stack **st_b, t_stack **st_a)

static void push(t_stack **from, t_stack **to)

static void swap(t_stack *stack)

static void rotate(t_stack **stack)
static void reverse_rotate(t_stack **stack)











### pa
[-index-](#index)
void execute_pa(t_stack **st_a, t_stack **st_b)











### pb
[-index-](#index)
void execute_pb(t_stack **st_b, t_stack **st_a)











### push()
[-index-](#index)
static void push(t_stack **from, t_stack **to)

take *STACK A* and *STACK B* as param
[NULLCHECK]
t_stack	*temporary_stack
temporary_stack = (*from)->next;
(*from)->next = *to;
*to = *from;
*from = *temporary_stack;











### sa
[-index-](#index)
void	execute_sa()











### sb
[-index-](#index)
void	execute_sb()











### ss
[-index-](#index)
void	execute_ss()











### swap()
[-index-](#index)
static void swap(t_stack *stack)

int	temp;

if (stack == NULL || stack->next == NULL)
	return ;
temp = stack->value;
stack->value = stack->next->value;
stack->next->value = temp;
temp = stack->index;
stack->index = stack->next->index;
stack->next->index = temp;
temp = stack->position;
stack->position = stack->next->position;
stack->next->position = temp;











### ra
[-index-](#index)
void	execute_ra()











### rb
[-index-](#index)
void	execute_rb()











### rr
[-index-](#index)
void	execute_rr()











### rotate()
[-index-](#index)
static void rotate(t_stack **stack)
{
	t_stack	*temporary_stack;
	t_stack	*bottom;

	temporary_stack = *stack;
	*stack = (*stack)->next;
	bottom = find_stack_bottom(*stack);
	temporary_stack->next = NULL;
	bottom->next = temporary_stack;
}











### rra
[-index-](#index)
void	execute_rra()











### rrb
[-index-](#index)
void	execute_rrb()











### rrr
[-index-](#index)
void	execute_rrr()











### reverse_rotate()
[-index-](#index)
static void reverse_rotate(t_stack **stack)
{
	t_stack	*temporary_stack;
	t_stack	*penultimate;
	t_stack	*bottom;

	temporary_stack = *stack;
	bottom = find_stack_bottom(*stack);
	*stack = bottom;
	(*stack)->next = temporary_stack;
	penultimate = find_penultimate(*stack);
	penultimate->next = NULL;
}
t_stack	*find_penultimate(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}









