[=readme=](README.md)

#	index

#	overview

##	turk algorithm

[0. instantiate stack](#instantiate-stack)
[1. check sort](#check-sort)
[2. push 2](#push-2)
[3. turk algo](#turk-algo)
[4. push back](#push-back)
[5. verify sort](#verify-sort)
[6. output instructions](#output-instructions)

###	instantiate stack
###	check sort
###	push 2
###	turk algo
0.	check if pushing back `solves`
	i.	stack A & B have only adjacent values
	-	`tail = a[a[0]]`
	-	`head = b[1]`
		->	adjacent if `if (tail == head + 1)`
		[musings on adjacency checking](#checking-adjacency)
-	*FOR STACK A*
	-	`head = a[i]`
	-	`while (i < a[0])`
	-	`i++`
	-	`tail = a[i]`
	-	`if (head == tail - 1)`
		-	`head = tail`
	-	`else`
		-	`flag: A is not sequential`
-	*FOR STACK B*
	-	`head = b[i]`
	-	`while (i < b[0])`
	-	`i++`
	-	`tail = b[i]`
	-	`if (head == tail + 1)`
		-	`head = tail`
	-	`else`
		-	`flag: B is not sequential`
	ii.	check if rotating stack A or B helps
	-	check sequence of A and B
		-	if A && B are sequential, find the `i` and `j` so that `((a[i] - 1) == b[j] 1)`
	iii.	check that top of A is a match for top of B
	iv.	return flag
	-	K.	`klar`
	-	U.	`unsorted`
	-	H.	`hexery`
1.	check cost of aligning stack/s to different pushed values
	i.	cost of pushing
		a.	a[1] without aligning b[1]
		((c[1] = 0))
		((d = 1))
		((e = 1))
		b.	a[1] by aligning b[j]
		((c[1] = steps +/- to rotate b[j]))
		((d = 1))
		((e = j))
		c.	a[i] without aligning b[1]
		((c[i] = 0))
		((d = i))
		((e = 1))
		d.	a[i] by aligning b[]
		((c[i] == steps +/- to rotate b[j]))
		((d = i))
		((e = j))
	ii.	store `cost`(*) at `c[i]`(**)
		((*) cost == steps to rotate b)
		((**) i == index of target (the one to be pushed))
	iii.	store `target index` at `d`
	iv.	verify that `d != 0`
	--	this way, multiple `candidates` can be evaluated
	--	the `a[index]` of the `winner` can be stored as `d`
	--	OR should it store the `value` of the target?
	--	the `b[index]` of the `target` can be stored as `e`
	--	OR should it store the `value` of the target?
2.	align stack/s
	i.	check cost quickly
		(reset invalid values/c[i] for i != d)
		--	if all c[i] except c[d] == 0
		(verify that `a[d]` is now the top)
			--	separate storage of number?
			--	run check->align->check->push
	-	 `'is the number at b[e] a fit for a[d]?'`
		(verify that `b[e]` is now the top)
			--	separate storage of number?
			--	run check->align->check->push
	-	 `'is the number at b[e] a fit for a[d]?'`
	ii.	is `a` aligned? (d == 1)
	iii.	is `b` aligned? (e = 1)
	iv.	[musings on negative values in `d/e`](#negative-de-values)
	v.	
3.	push
####	checking adjacency

if (i == a[0])
	if (a[1] == b[1] + 1)
-	--->		tops are adjacent

####	negative [d/e]-values
by storing the `negative` of the `value`
push-subject at `d`
push-target at `e`
if the d/e-value is POSITIVE
	it is the index of the subject/target
if the d/e-value is NEGATIVE
	it is the inverse value of the subject/target



###	push back
###	verify sort
###	output instructions
<!-- spitball first - ^^ -- vv - then copy -->