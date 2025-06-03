the KRAKEN algorithm:

two basic structures

[Circles](#Circles-contain)

[Triangles](#triangles-contain)

# Circles contain:
a snapshot of the stack/s
a pointer to a triangle
a pointer to the parent permutation

# Triangles contain:
up to 11 permutations of the circles
a pointer to the parent permutation

So far:
it runs. sort of
it branches and permutates
it checks sort degree "delta"
it sorts up to 3 numbers. some times
it can return and traverse the solution to reproduce the operations.

Missing:
normalization of arguments
branch pruning and strategy for such

Agenda:
[normalize arguments](#normalize)
develop strategy for branch pruning
test and debug strategy

#	normalize

goal:
for `n` numbers
smallest number is `1`
largest number is `n`

procedure:
`highest = INT_MIN`
`lowest = 0`
iterate through `new->a[i]` until values are normalized in `new->b`
set `highest` to any `a[i]` higher than last highest number
--	set `new->b[i]` to 1
--	iterate through `new->b[j]` looking for a bigger value
--	`if ((new->b[j] > new->b[i]) && (new->b[j] != new->b[i])`
--	--	then `new->b[j]++`
--	`else if ((new->b[j] < new->b[i]) && (new->b[j] != new->b[i])`
--	--	then `new->b[i]++`



