[]()
^^^^
leave this alone
================
[--]()
[--]()


[-tasks-](#TASKS)
[-log-](#LOG)
[-project history-](#BEGUN)
[-finalization-](#FINISHED)
###	OPEN TASKS:
*2025-03-24*
[-14:01:47-](cost.c#find_move) - dealing with MOVE assignment
{goal is to find "move that would let next number be correct"}
{help with move codes:

}
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

[-another one bytes the dust-](qs.md)
####	BEGUN:
####	2025-03-20 10:55:19
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