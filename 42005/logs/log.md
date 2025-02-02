## <:log7:<
###	log 2025-02-02 09:02:26
#	[suitcase lost](https://transportb.novafind.eu/home/transportb/BVG/app/lossrecords/BVG-K2025_003834?accessToken=PN3B3UG47WUHXMEC6S4D353YGMFAATHGSTBWN4LS6KKU7QTZZMAAIGWSXMI4AYHT&culture=en)
# what I have:
- makefile
- header
- stack initializing
- stack sort check
- assignment of "cost"
- simple operators
- probably lots of leaks.
[valgrind output: 40 bytes, 1 missing free/alloc pair](logbugs.md#2025-02-02)
- 
# what I need:
- translation from cost_a/_b to operations
- fix memory leak soooooner than later
- decide (soon) on whether to keep stamping the mud or to go for a turnkey solution
# cost counting + assignment of count
- =	purpose	:	if many members have same cost, one move can fix many.
- =	challenge	:	[iterating](TODO.md#targets)
- =	
[]()
# what to do:
- fix the rotate function:
- - 0 -> 1
- - 
- - 
- - 
- call some of the cost analysis with `members` to make it easier to allocate memory for registered costs?
- [X]	looks like the 'cost' association is failing again:
	-	i want: position - index
	-	i have: index - position
	-	target file:
- ?	recursive			?
- ?	split even further	?
- ?	minifunctions		?

























## >:log7:>

## <:log6:<
###	log 2025-01-25 14:24:46
fiddling with the algorithm.

trying to deal with relationships between two numbers.
## [NOTES](notes.md)
#### ONENESS
basically saying that if these are `1`
*"position b" - "position a"*
*"position c" - "position b"*
then the position b is adjacent to both.
if one is	1
	doublet
if both are	1
	triplet

#### BACKWARDNESS
,,negative if adjacent backwards,,code it in now not later,,
relationship::
index
position

(in stack A)
{{{}}}
{{{if index - position = 0 then number is sorted}}}
{{{if index - position > 0 then number is too early}}}
{{{if index - position < 0 then number is too late}}}
{{{}}}
{{{if y_position + 1 == z_position}}}   
{{{if x_position + 1 == y_position}}}
{{{}}}
{{{if y_position - 1 == z_position}}}
{{{if x_position - 1 == y_position}}}
{{{}}}





## >log6:>

## <:log5:<
#	[log 2025-01-23 15:27:45](logmakefile.md#log-2025-01-23-152745)
made log for bugs	[HERE](logbugs.md)
### log 2025-01-23 17:57:41
makefile makes now!
next up:
the "sorting algo" so called, is being rammed into the numbers and it aint workin.
make some small sort functions.
build on those.
progress. gradually.
## >log5:>
## <:log4:<
### log 2025-01-21 16:03:43
feel drained now
tired and restless
like i know what work to do and im avoiding it
like the work is tedious and not rewarding
as if that means something in the greater picture lool.
### log 2025-01-21 13:49:18
fueled and ready to go
targets:
-:0:-
0:push_swap
-:1:-
0:algorithm
1:cost
2:operation
3:M.V.P.
-0-'make a test rig'-
-1-'figure out makefile'-
## >log4:>
## <:log3<
### log 2025-01-20 11:32:07
todo:
:simple functions to:
:compare cost of processing top value:
:compare cost for both stacks:
:OK:
:locate stack position/locate index of smallest/next value:
:output as grid of stats/int*:
::
goal:
::
:make skeletons for all these:
:make them work for debug:
:produce one full module:
:produce all modules:
:decide it isnt worth it:
:change strategy:
:win:
::
reward:
:coffee:
:time:
:mmaah:
:shopping:
:gadgets:
:booze:
::
###	log 2025-01-20 14:31:11
it sorta works so far.
meaning this side quest is complete anyhow
i can now go up and down the stack
i have the number of moves forward necessary to "reveal a number"
###	log 2025-01-20 17:06:01
sticky slowly sticky sticky

gotta doooodle

1 2 3	-	abc
1 3 2	-	acb
2 1 3	-	bac
2 3 1	-	bca
3 1 2	-	bac
3 2 1	-	cba

### <%<:log3:>%%>		-	the backtrack bug
	instead of performing as desired, the function backtrack seems to not receive a usable stack of memory...
	the editor claims the type sent is wrong, but i am unaware of which type should be sent.
	rather not ask gpt but could.
	[SOLVED]: sending the right type of data helped.

[:TODO::][URGENT]: change default `adjacency` value to `0` to allow negative index
<!-- 

	020
	025
	001
	020 
	014
	031
+	011
_________
==	122

20
25
01
20 
14
31
11

20
25
01
20 
14
31
11
 -->
## >log3:>

### log 2025-01-19 18:01:59
## <:log2<

what to do now?
i come in and i am overwhelmed and confused

this is bothersome

but forward and onward we go always

next:

make a sort
dep:
stack is usable.
solve:
uncomplicate stack!

[2025-01-19 18:16:21]
fiddling a bit.
	plus:
	there IS a stack.
	it DOES work
	positions and indexes are given

	minus:
	the highest position gets two pointers to the same address
	the other pointers excepting next, are nil

	undone:
		adjacency count
		pointers to
			higher
			lower
			prev
		sorting
		cost
		operations
[2025-01-19 19:02:09]
had a break.	SUGAR
NEED
		SUGAR
	and
			CFOFFEEEVE
## >log2:>






































### log 2025-01-15 15:08:04
## <:log1<
[strategy for manipulating stack](ops.md#entropic)
	sort direction to determine operation
	listening to oceanic[?sic?] and his tutorial for p_s
	i might not copy everything but its nice to have on in the b/g

	'a struct is a container which contains data'
	'in a struct you can have elements of different sizes and types'
	'an array data struct wont work with differently sized elements'
	'every node has ptr to prev and next node'
	'?how to implement node? begin by investigating .h file'
	'typedef - auxiliary stuff to simplify'
	'container surrounded by {} "curly braces" can contain anything'
	'important:ptrs:to:prev,next:nodes'
	'declare all variables, at end typedef'
	'"shorthand" like naming it "t_stack"'
	'in main func:'
	'if just program name, return'
	'<,%%TODO:find-out-about-error-returns:%,>'
	''
	''
####	'make test file'
	'should be able to test components of program'
	'specifically just provide basic input that stack would process'
	'simplest structure possible'
	'used with pythontutor or whatevs'
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
	''
## >log1:>
### log 2025-01-15 13:46:39
//---------------------------------------------------------------------------//
## <:log0<
[passing argument 1 of ‘sort’ from incompatible pointer type [-Wincompatible-pointer-types]](main.c#L51)
		<old:<`sort(&st_a, &st_b);`>>
		<fix:<`sort(st_a, st_b);`>>
## >log0:>
