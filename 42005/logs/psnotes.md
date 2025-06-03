#	2025-03-04 12:44:11
##	DONE
explanation
for n numbers, m moves is max:
100	-	700
500	-	5500

so minimum 7x maximum 11x
could just go 11x right away?
so each moveset may have max 5500 + 5(leading zeroes and numbers) + 2 (x and y) = 5507 bytes



on memory:
each `array` representing stacks needs only 2 bytes/16 bits to store 500 values
a `short` variable is 16 bits and can store a range
from -32,768 to 32,767 (signed) or from 0 to 65,535 (unsigned)

so each 'stack image' would be a product of
-	how many movesets do we need?
	215 for the 'five steps'
		(5 'primaries', 30 'secondaries', 180 'tertiaries')
	??maybe some extras for 'deep moves' that require extensive rotation?
-	how much memory is involved?
	stack images:
		2 bytes per stack image
	movesets: (626 bytes)//662 with cover stages
		3 primer stages (push/swapping a number) 
			5 * 1 move/byte		+ 7 bytes = 5 + 7 bytes/40 + 56 = 96 bits
			30 * 2 moves/bytes	+ 7 bytes = 60 + 7 bytes/480 + 56 = 536 bits
			180 * 3 moves/bytes	+ 7 bytes = 540 + 7 bytes/4320 + 56 = 4376 bits
			
		2 cover stages (rotating up a number)
			6 * 1 move/byte		=	6
			6 * 2 moves/bytes		=	12
			6 * 3 moves/bytes		=	18 // + 36
		
		5 adopted movesets
			up to 500 * 5 * 
			
- started 'forest approach'
	- initialize a struct called tree
	- used to calculate options and compare
	- currently very basic, has `int` as well as `t_tree **roots` and `t_tree *next`
	- future will include `int*` arrays for encoding ops moves and costs
		-	encoding ops
			-available moves:
			-	`int *ops` (or maybe char array for easier copying?)
			-	`char **ops`
				0		-	default
				1		-	sa
				2		-	sb
				3		-	ss
				4		-	ra
				5		-	rb
				6		-	rr
				7		-	rra
				8		-	rrb
				9		-	rrr
				10		-	pa
				11		-	pb
		-	encoding moves
			-	`int *steps`
			-	`on step n`
				steps[n]
				//basic array, but could contain address to ops? or just a ref.
				//probably a superior array `tree[x][y][z]`
				//`array[variants][steps][ops]`
				//`tree[trunk][branch][leaf]`
			-	`int *ops`
			-	`do op m`
				ops[m]
		-	encoding costs
			-	hm. if tree structure contains this `***int`
				then... hm... could store the move count as an int at 0 in the list of instructions
				then at 1+ is the code for the move itself. (1-11 or abcdefghijk)
				[char **movestring]
				eg: [00024xafdefeyyyy]
				[leading zeroes]count-as-numstring[x to start]
				=
				24 [moves]
				[x as delimiter for start]
				sa rr ra rb rr rb
				[y as delimiter for end]
				0		-	default start of instruction (minimum 1, maximum 4 followed by a number)
				a		-	sa
				b		-	sb
				c		-	ss
				d		-	ra
				e		-	rb
				f		-	rr
				g		-	rra
				h		-	rrb
				i		-	rrr
				j		-	pa
				k		-	pb
				x		-	end of count/start of moves
				y		-	end of moves
				[how many moves?]
				would it make more sense to have a fixed length array and use more of them?
				encode the hook or whatever by not writing y before its done?
				maybe if the last char before null is z, its all done, and if its y then the next array also counts?
				if the array starts with y instead of x
				eg: [yfdefey]
				[encode moves as string]
				number count with leading zeroes (to potentially store thousands of moves)
				the number of arrays might vary. they should be deleted as newer/better move sets come around
				so in practice, even with a very long list of numbers, it might be few actual potential arrays.
				but the 'wrong moves' might be the same all along?
				should 'tried and found ineffective' be stored separately?
				how to avoid repetition?
				-	try moves in sequence
				how to try moves?
				-	never ra/rra or sa sa (redundant repetition)
				-	redundant combos: (unacceptable strings)
						aa
						bb
						cc
						dg
						gd
						eh
						he
						fi
						if
						jk
						kj
				
<!--	NAH			
				could also encode moves for B stack as CAPITALS ()
				0		-	default/count-as-numstring
				a		-	sa
				A		-	sb
				b		-	ss
				c		-	ra
				C		-	rb
				d		-	rr
				e		-	rra
				E		-	rrb
				f		-	rrr
				g		-	pa
				G		-	pb -->


[TODO:		make a `clue` file to avoid mess in sorter](../actual/sort/clue.c)
[TODO:	send 'rotation count' to `three_sort`](../actual/sort/stack_sorter.c#L33)
	/* rotation count
	considers `count` number of moves to sort a clue.
	adds 'number of reverse/rotations to access clue' to `count`
	performs move with:
		a. fewest added moves
		b. fewest total moves
		c. fewest rotations before default `count`
	*/
#	issues 2025-03-02 17:51:58

- ++	sort 2 and sort 3 works now!!! (not really)
- --	sort larger still undone
	proposed progression:
	-	part goals:
		-	add moves in global var?
		-	reverse/rotate based on which is closer
		-	get ready sorted numbers out of the way (clue = S)?
		-	push sorted numbers IF remaining sort takes more moves
				(2x numbers) so if remaining is > 2x moves to push
				otherwise rotate/swap
		-	implement RR, RRR, SS operations into algologic
-	-	start simple:
		sort individual numbers
			rotate/reverse to unsorted and either:
				swap
					if stack becomes MORE sorted
					if number becomes FULLY sorted
			||
				push
					if stack becomes LESS sorted
					if number becomes LESS sorted (higher cost)

-	-	move into wilder territory:
		sort the entire n > 10 stack with basic logic
		revisit cost/assay as you go

-	-	continue high concept:
		run stack_assay and sort_check after each sorting move
		cost assessment with more parameters (eg. dummy or test params)
			{if(`this` were position, implying another value/s change)
				what would then be cost?
			}

#	issues 2025-03-02 16:48:43
- OK	cost_s should NOT go low->high but head->tail


#	issues 2025-03-02 10:43:07
- OK	stack->head seems to disappear or something, and it's weird.
	happens after stack_maker, before ft_cost.
	-	after `print_stack`
- OK	`array` misrepresented values following: `*head = stack`
	issue was in not allocating memory for `head` before assigning
- OK	`cost_a` `cost_r` `cost_s` are not correct
	seems like abs cost "lags" (should be on next node, not first)
	seems like sum cost also lags (should be on next node, not first)
	last node got past node's values basically
	++	necessary for sorting

2025-03-02 15:49:15
#	DONE:
	made one_sort, still depends on cost_r/cost_a

#	TODO:
make a check-distance function:
		takes two nodes
		finds distance in steps
		returns as int
	MOVE said function elsewhere

make a mode in ft_cost/ft_comcost that allows 'sum' calls to return difference between head and subject




















// check for triplet
// (if st->prev->pos, st->pos, st->next->pos are all within 1)
// // if triplet >> `cost_a/cost_b` and `clue' for all is set
// // else if not triplet >>
// check for doublet
// (if st->prev->pos, st->pos are both within 1)
// // if doublet >> `cost_a/cost_b` and `clue' for both is set
// // else if not doublet
// check for singlet
// (how far to next adjacent -/+)
// // always >> `cost_a/cost_b` and `clue` set
[](README.md)
#	triplet arrangements and costs
	
0/abc = [a](sort3.md#abc)
1/bac = [b](sort3.md#bac)
3/acb = [c](sort3.md#acb)
4/bca = [d](sort3.md#bca)
4/cab = [e](sort3.md#cab)
7/cba = [f](sort3.md#cba)


some times, statistically speaking probably most times, there are no triplets
then, sorting must proceed according to other rules..

# cases for sorting

## triplet / three numbers in a row

#	cost benefit of triplet configurations	
-	each of these configurations takes a number of moves to sort.
-	it matters if another move is more effective.
-	it matters where in the stack they are, i.e. distance from head

	0/abc = a
	1/bac = b
	3/acb = c
	4/bca = d
	4/cab = e
	7/cba = f

## doublet / pair of numbers
-	factors to consider:
	* distance from head
	* presence of lower numbers (better to push them first)
	* benefit of sorting in single stack vs two stacks
	* will a double number become a triplet?
		- calculating this is tricky, needs to keep in mind moves before.
		- perhaps considering cost for various runs, then comparing them?
		- could use int array to store moves/costs

## singlet / single number
-	a single number essentially wants to be part of the largest structure possible
-	as long as this does not cost more than dealing with it alone.
	- lets say:
	STA = 6 4 9 5 10
	STB = 3 2 1
	cost_c = cost to push back to A
	here it makes sense to:
	+1	rotate A		STA = 4 9 5 10 6		cost_c	3
	+1	push to B		STB = 4 3 2 1		cost_c	4
	+1	rotate A		STA = 5 10 6 9		cost_c	4
	+1	swap A		STA = 10 5 6 9		cost_c	4
	+1	rotate A		STA = 5 6 9 10		cost_c	4
	+4	push to A		STA = 1 2 3 4 5 6 9 10	cost_c	0
	=9

	also could make sense to:
	+1	swap A		STA = 4 6 9 5 10		cost_c	3
	+1	push to B		STB = 4 3 2 1		cost_c	4
	+2	rotate A		STA = 5 10 6 9		cost_c	4
	+1	swap A		STA = 10 5 6 9		cost_c	4
	+1	rotate A		STA = 5 6 9 10		cost_c	4
	+4	push to A		STA = 1 2 3 4 5 6 9 10	cost_c	0
	=10

	trying to incorporate into triplet:
	-	456 is a potential triplet	STA = 6 4 9 5 10
		- but is +1 "hidden" and +1 "not ordered" (4 + 2 = 6)
	+2	rotate A				STA = 9 5 10 6 4
	+1	swap A				STA = 5 9 10 6 4
	+2	reverse A				STA = 6 4 5 9 10 //cab takes 4 moves
	+1	swap A				STA = 4 6 5 9 10
	+1	rotate A				STA = 6 5 9 10 4
	+1	swap A				STA = 5 6 9 10 4
	+1	reverse A				STA = 4 5 6 9 10
	+3	push to A				STA = 1 2 3 4 5 6 9 10
	=12

	if the 'next' numbers are on the surface of B, then triplet sorts are not as useful
	if numbers are chaotic, then it might.
	it seems a measure of entropy may be useful?

	high entropy - numbers are far from adjacent
		wrong stack - +1 for each number
		distance to next - +1 for each step (bonus for wrong stack? +1 extra for moves?)
	low entropy - numbers are close to adjacent
		same stack - -1 for each number adjacent	//A:cxd B:ba (pushB makes entropy -2 (right stack, ordered))
		distance to next - minimum 0 for "right number right orientation"	//abx
		distance to next - +1 for "next number right orientation"		//axb
		distance to next - +1 for "right number wrong orientation"		//bax
		distance to next - +2 for "next number wrong orientation"		//bxa

# process of finding which sort to use

## iterate from head -2 (to catch all triplets)
-	if a triplet (the middle number holds the clue) is buried
	- the cost of head->prev->clue is -2 b/c stack must be reversed two steps
	- the cost of head->clue -1 b/c stack must be reversed one step
	- the cost of head->next->clue is 0 b/c stack can be operated right away
-	if a triplet has a better cost
	- if index 1-3 is part of triplet with clue c and index 4-6 is part of triplet with clue a
	- clue c costs 2 more, so must be disadvantaged in favor of clue a etc
	- cost of triplet move includes cost benefit/disadvantage of accessing triplet move

###	search for doubles
-	A:ba (+1{wo/rs}) B:ba (+1{ro/ws}) A:ab (0{ro/rs}) B:ab (+1{ro/ws}) A:bxa (+2 {wo/rs/na}) B:bxa (+2{ro/ws/na})

###	search for completing singlets
-	A:bcxxa/ 

#	legend of symbols
ro	- right order
wo	- wrong order
ta	- truly adjacent
na	- not adjacent
rs	- right stack
ws	- wrong stack

2025-02-26 15:01:00
cost assessment (0)

2025-03-01 13:50:39
	--abandoning triplet approach--
	--attempting to use a function within the struct to calculate cost--
	--switching from `cost_a` and `cost_b`--
	--new: `cost_r` `cost_a` `cost_s`
- `cost_r` - `relative` cost, pos/neg tells direction, 0 = `in place`
- `cost_a` - `absolute` cost, always positive
- `cost_s` - `sum` of absolute cost, calculated when stack is observed

typedef struct s_stack
{
	int		val;
	int		pos;
	int		ind;
	char		clu;
	int		cost_r;
	int		cost_a;
	t_stack	**head;
	t_stack	*low;
	t_stack	*hig;
	t_stack	*prev;
	t_stack	*next;
	int		(*cost_s)(struct t_stack);
} t_stack;

new->cost_s = ft_cost(stack);

int		ft_cost(t_stack *stack);
int		ft_cost(t_stack *stack)
{
	int
			break ;
		cost++;
}