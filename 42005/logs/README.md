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
[debugging](#degubging)
[]()

# 2025-03-12 19:18:44
# degubging
p {*new->a@5, *new->b@5}
p {*old->a@5, *old->b@5}
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
#	freeing and pruning

##	freeing
freeing should happen once solution is found, or when a branch is pruned.

since branches are recursive, the freeing function should:
:while moves[i] is not NULL::
	;: call itself with tree->moves[i]
		;; repeat until tree->moves[i] is NULL.
	;; free tree->moves[i]

##	pruning
pruning is how to keep calculations limited.
once a certain level of complexity is reached, the less fortunate are culled.
in practice this is an optimization that might be unhelpful.
in theory it is crucial. a compromise must be found

#	compare branch

produces an aggregate measure of delta/entropy for an entire branch

:1: does the branch diverge?
:1:1:	what is the sum of delta for the entire branch?
:2: what is the delta for the snap?
:3:
:4:


<!-- /*	logix
		what should 'delta' or 'a_cost' even symbolize?
			::	how many moves from being in its right place, is a given member?
		for a number in first half, 
			if it belongs to first half
				then it is 'pos - i'
					ex:

				pos	1 3 5 2 4
				ind	1 2 3 4 5
				
				by this logic the '5' would be treated as 'first half'
					it is '5 - 3 = 2' away
					or in machine terms 'ac[i] = a[i] - i'
				lets do '3'
					it is '3 - 2 = 1' away
					or 'ac[i] = a[i] - i'
				what about '2'
					'2 - 4 = -2'
				what about aggregates?
					having several '-' like values should incentivize 'rotate' type moves
					having several '+' like values should incentivize 'reverse' type moves
				what about accumulation?
					a total sum of the absolute values of cost could be given to the 'delta'
					OR a directional delta could be added
					maybe a median value?
					
			if it does not belong to first half
		for a number in second half,
			if it belongs to second half
			if it does not belong to second half

			the first/second half stuff is really only useful to determine if one direction is better than another

			i still need to 
				'know'
			that for:
			pos	5 3 1 4 2
			ind	1 2 3 4 5
			it is sensible to think of '5' as having '-1' as value, not '+4'
				which is greater:
			[O]		pos - ind = 4
			[X]		ind - pos = -4
			instead, it should calculate position as ratio of size.
				here, '5' is a 1/1 of size
				
				also, for 'ind 1' it can also be thought of as
				'size + 1'
					or
				'index 6'
				if the distance to the right index FORWARD is greater than BACKWARD

				if i do 'if number is in first half and belongs in second' -> 'delta = size - index - pos == 5 - 1 - 5 == -1'
				if i do 'if number is in first half and belongs in first' -> 'delta = pos - index == 3 - 2 == 1'
			it is sensible to think of '2' as having '+1' as value, not '-3'
				if i do 'if number is in second half and belongs in first' -> 'delta = size - index + pos == 5 - 5 + 2 == 2'
				if i do 'if number is in second half and belongs in second' -> 'delta = pos - index == 4 - 4 == 0'

			is this consistent?

			relative delta
				1/2
					delta = size - index - pos
				2/2
					delta = size - index + pos
			absolute delta
				1/2
					if (delta < 0) delta *= -1

				
		*/ -->

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