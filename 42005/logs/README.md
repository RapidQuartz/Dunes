#	readme-index
[readme-index](README.md#readme-index)
[strategy-log](README.md#strategy-log)
[sub-strategic-breakdown](README.md#sub-strategic-breakdown)
[todo-learn-1](README.md#todofind-out-about-error-returns)
[-log-files-](README.md#log-files)
[-options-](README.md#options)
[-pad-](TODO.md#pad)
[=NOTES=](notes.md)
[=LOG=](log.md)
[](old.md)
[]()


#	2025-03-11 15:10:11
#	tree formation
:0; receive `int argc char **argv`
::: convert into `int* array`
:::: check `*array` sort
::: produce `t_snap *stack` from `*array`
:::: set `stack->delta`
::: produce `t_ree *root` structure
:::: associate `stack->tree` and `root->order`

:1; check `stack` sort
;:; return `stack` if sorted

:2; branch out into `root->moves`
::: set `root->moves[i]` while `i < 11`
;::: `NULL` for illegal moves
;::: produce `t_snap *moves` for legal moves
;:::: set `root->moves[i] = moves`

:3; compare all legal movesets
;:: set `root->probation += root->moves->delta`

:4; produce `t_ree *tree` structure
:::: associate `moves->tree` and `tree->order`

:1;check

:2;branch

:3;compare
;v; `int sum_delta = 0`
;t; `t_ree tree`
;s; `t_snap active`
;b; `int branch = 0`

:b: `while branch++ < 11`
:s:: `active = tree->moves[branch]`
:v:; `sum_delta += active->delta`
:;I; if `active->up != NULL`
:s:; `active = active->up`
:;E; else
:v:: `probation[branch] = sum_delta`
:v;; `sum_delta = 0`

;i; `int i = 0`
;i; `int j = 1`
::: `while i++ < 10`
:::: `while j++ < 11`
:I::: if `probation[i] > probation[j]`
::::: `tree->moves[i]->penalty += probation[i] - probation[j]`
:EI:: else if `probation[i] < probation[j]`
::::: `tree->moves[i]->penalty -= probation[j] - probation[i]`

:::: ``
:4;grow


:: return to divergence point

*/




#	strategy-log
[readme-index](#readme-index)
[strategy-log](#strategy-log)
[-'using index'-](#)
[-'send clean/temp variable'-](test.c#adjacent-operation)

##	sub-strategic-breakdown
////	OVERVIEW:

////	OPERATION:
////	PROCESS:
////	METHOD:

////	FUNCTIONS:
////	TODO:URGENT:
////	DUMP:TIMEWASTE:
////	EVALUATION:
////	TESTING:DEBUG:

////	CHECKER:
////	COMPARING:
////	NORME:

////	COMPLETION:










# <,%%TODO:find-out-about-error-returns:%,>
[readme-index](#readme-index)
[todo-learn-1](#todofind-out-about-error-returns)
:discover:
:considering:error-messages:'Error\n':
:what errors:
:is this only message:
:outlier cases;
:write:strategy-log:including:'instructions from youtube tutorial':
--from algorithm.c
////	:sorting
/* the gentle art of sorting 	*/
/* we have this information: 
:distance to next
::how far _forward_
:how to navigate
::up and down
:::where is lower number
::::and
:::where is higher number
 					*/
/* from this we can perform:
:if distance is greater than:
size (-) index
then:
number is BEHIND
eg:size 6
v-i-p---d
3-5-3----
2-6-2---5
v-i-p---d
3-3-3----
2-4-2---5
then the number
'index(higher) (-) own index'
will be negative

//
hold on.

 					*/
--








#	log-files
[readme-index](#readme-index)
[-log-files-](README.md#log-files)
[/README.md/](README.md#readme-index)
[/TODO.md/](TODO.md#index)
[/ops.md/](ops.md#index)
[//](#)
[--]()
[--]()
[--]()










#	test-file
[-test-file-](README.md#test-file)
[readme-index](#readme-index)
[:make:](TODO.md#make-test-file)
()[]










#	options
[readme-index](#readme-index)
'the turk'
'radix'
:buckets
1	31	11	32
<1>	<1>	<1>	<2>
1	31	11	32
<1>	<3>	<2>	<4>
'in binary code this is done'
'gives a new index number'
'sorts based on binary index'
:denotes placement in memory:
{way more efficient than turk}
{turk performs better in eval}
'put ideas into pseudocode,later structure'
''
''
''








#
[readme-index](#readme-index)