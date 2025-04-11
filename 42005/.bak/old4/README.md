[]()
^^^^
leave this alone
================
[=turk readme=](turk.md)
[--]()
[--]()


[-tasks-](#TASKS)
[-log-](#LOG)
[-project history-](#BEGUN)
[-details-](#details)
[--turk algorithm--](#turk-algorithm)
[--code path--](#code-path)
[--move codes--](#move-codes)
[-finalization-](#FINISHED)
###	OPEN TASKS:
*2025-03-26*
[-11:56:51-](push.c#L135)
- select_push_node (stack=0x7fffffffe050) at push.c:135
- TODO:
	create logic to select node to push::
		first:
			(if argn == 4)
				push 2	||	push 1
				sort A/swap	||	sort 3?
				sort B/swap
			(if argn > 4)
				push 2
				find cheapest fit for B


				rotate/reverse
###	rotate/reverse B
[find target top and align the B stack to target](turk.c#next_align)

				push cheapest
<!-- RESOLVED make errors 2025-03-26 11:37:48

cost.c:51:3: warning: implicit declaration of function 'get_cost' is invalid in C99 [-Wimplicit-function-declaration]
                get_cost(n_a, n_b, c_a, c_b);
                ^
cost.c:52:1: warning: non-void function does not return a value [-Wreturn-type]
}
^
cost.c:54:6: error: conflicting types for 'get_cost'
void    get_cost(t_n *node_a, t_n *node_b, t_c *cost_a, t_c *cost_b)
        ^
cost.c:51:3: note: previous implicit declaration is here
                get_cost(n_a, n_b, c_a, c_b);
                ^
cost.c:94:13: warning: incompatible pointer to integer conversion assigning to 'char' from 'char [2]' [-Wint-conversion]
                cost->stk = "A";
                          ^ ~~~
cost.c:146:7: error: conflicting types for 'find_move'
void            find_move(t_n **stack_a, t_n **stack_b)
                ^
./push_swap.h:50:7: note: previous declaration is here
void            find_move(t_n **stack);
                ^
cost.c:151:8: error: use of undeclared identifier 'stack'
        n = (*stack);
              ^
cost.c:158:32: error: use of undeclared identifier 'stack'
                n->c->mov = select_push_node(stack);
-->
[-09:34:25-](push.c)
- {untested} - fiddled with marking the stack name with a char
[-10:35:30-](cost.c#get_cost)
- {untested} - made separate cost_a/_b measures
- {untested} - changed init cost && find move to `void` functions
*2025-03-24*
[-14:01:47-](cost.c#find_move) - dealing with MOVE assignment
{goal is to find "move that would let next number be correct"}
[-10:43:59-](#2025-03-24-104432)
[-11:41:11-](push.c#L45) - needs some polishing
###	CLOSED TASKS:
*2025-03-24*
[-13:18:31-](util/debug.c#d_print_cost)
{need to fix assignment of "tgt pointer" and "values" for "first and last number in stack"}
*2025-03-20*
[-16:51:03-](../actual/init.c#init_stack_a)
something happens to the head pointer assignment, maybe split into a separate func?
[-13:02:15-](../actual/push_swap.c#push_b)
need to think about WHEN to 'make new stack'
by this logic i am seemingly not passing jack...
stack B could just be like... ONE node.
so in push b for instance, i could simply set the next-pointers
so that stack b is like... the node that was pushed.
and the next node in A is fine anyway right.
i just have to return that "a no longer contains the node that was set"
but its not that simple... 
aagh. time for a break right.
[-11:03:47-](../actual/arr.c#normalizer)
change from `stack/snap` - logic to `int array` logic
issue:	does not 'skip' already filled values, because it only deals with ONE array
prob need another array?
####	2025-03-20 11:00:48

###	LOG:
#####	

debug("");
#####	2025-03-26 09:34:25
1. decide on days tasks
	i. log tasks
2. measure progress
	i. if no progress in 1 hr, change
3. document daily work and prepare for next day
	i.	clear tasks
	ii.	note down stuff throughout
#####	2025-03-24 10:44:32
1. get an overview
2. work an hour or two
3. regroup
#####	2025-03-21 09:10:38
- back once again for the renegade master -  
- D4 Damager -  
- power to the people -  
what happens today?

*	1	see if i can fix the [ptr issue]()
*	
*	
*	
*	
*	
#####	2025-03-20 15:15:56
jeg kan klare dette
<3

[-another one bytes the dust-](../logs/qs.md)
####	BEGUN:
####	2025-03-20 10:55:19
##	details
###	turk algorithm
at its core, the mechanical turk algorithm has two main parts:
1. push to B
2. sort 3

initially, two numbers are pushed to B
the next number to be pushed has two traits:
1. it's the cheapest to push
	i.	number of moves to bring it to top of A
	ii.	number of moves to put to right place in B
2. it's placed at the right location in B
	i.	it will be above the highest if it is the smallest number thus far
	ii.	it will be between numbers if it is a middle number
		a.	since B is reverse-sorted (high-low) we need it to be
			BELOW the higher
			ABOVE the lower



###	code path
//// 3
//// ST_DEFS:
typedef	struct	s_stk
{
	int			*a;//a_stack
	int			*b;//b_stack
	int			*c;//cost
	int			d;//data
	int			e;//error
} t_stk;
//// 2
<>()[]{}
main
t_stk	*m_init
char	*m_init_arg
	bool	m_check_arg_valid
	int	m_check_arg_unique
	= {int argn}
ft	m_init_arr
[argn][args]
ft		m_init_stk
t_stack	*stk;
int		*arr;
ft			arr_to_stk
	

//// 1
<>()[]{}
- template: <file>(function){description}[returns:{}][line:ft_calls]{call meaning}
- <main.c>
	(int	main(int argc, char **argv)){base of ops}
	[returns:
	{-1	if fewer than 2 arguments}
	{TODO: more return states:
	{0	if succesfully run}
	{1	if other error}}]

	[25:argn = count_arg(argc, argv);]{{counts + verifies args}}
	-> <arg.c>
	(15:int	count_arg(int argc, char **argv))
		[returns:
		{0	if invalid}
		{argn	number of args in whole argv}]

	[25:num = arg_counter(argv[i]);]{counts + verifies args}
	(33:int	arg_counter(char *args))
		[returns:
		{0	if invalid}
		{argn	number of args in index `i` of argv}]

	[46:flag = arg_checker(a, args[index]);]{{verifies valid args}}
	(55:int	arg_checker(char a, char b))
		[returns:
		{0	if invalid}
		{1	if in additional arg}
		{2	if finished an arg or end}]

-	<- <main.c>

	[26:arr = make_arr(argc, argv, argn, arr);]{makes int array from args}
	-> <arr.c>
	(15:int	*make_arr(int argc, char **argv, int argn, int *arr))
	
	[25:arr = malloc(sizeof(int) * (argn + 1));]
	[32:count = arg_counter(argv[iter]);]
	[35:num = get_number(argv[iter], argi);]
	-	-> <utility.c>
		(15:long	get_number(char *arg, int argn))
	-	<- <arr.c>
	[36:check_minmax(num, NULL);]
-	<- <main.c>	

	[27:arr = arg_normalizer(arr, argn);]{normalizes array from 1 = argn}


<>()[]{}
###	move codes
0
1	-	push a
2	-	push b
3	-	swap a
4	-	swap b
5	-	swap both
6	-	rotate a
7	-	rotate b
8	-	rotate both
9	-	reverse rotate a
10	-	reverse rotate b
11	-	reverse rotate both
####	FINISHED:
####	2025-??-?? ??:??:??

<!-- void	push(t_n **stack_src, t_n **stack_dst)
{
	t_n	*src_info;
	t_n	*src_head;
	t_n	*dst_info;
	t_n	**dst_head;

	src_info = (*stack_src)->i;
	dst_info = (*stack_dst)->i;
	
	dst_head = src_info->h;
	src_head = (*dst_head)->h;
	dst_info->h = src_info->h;
	ft_push_src(stack_src, src_info);
	ft_push_src(stack_dst, dst_info);

} -->
<!--

/*______________________________________________________________*\
||                                                              ||
\*______________________________________________________________*/

-->
<!-- 
  ______________________________________________________________
||                                                              ||
||                                                              ||
||______________________________________________________________||
 -->