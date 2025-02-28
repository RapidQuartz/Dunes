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
/* triplet arrangements and costs
	0/abc = a
	1/bac = c
	3/acb = b
	4/bca = d
	4/cab = e
	7/cba = f
*/
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
		same stack - -1 for each number adjacent
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



2025-02-26 15:01:00
cost assessment (0)