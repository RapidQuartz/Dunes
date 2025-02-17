# sort n

# [rotk log for this](rotk.md#sort-n)

[]()
[cost.c](../alt/cost/cost.c)

-	process in triplets `abc`
	-	consider `ab/c`
	-	consider `a/bc`
-	if non-3-divisible?

-	store information in struct variables
	-	revive `hi/lo` pointers to numbers !!much work?
		-	run comparison of n and n->hi and n->lo
			-	compare index (of n and n->hi and n->lo)
				-	if index is off by one for both, its a triplet
	-	cost variable
		-	individual:	difference between index and position
		-	collective:	distance to adjacent value(s)
			-	option: only count up
				that way, the value says "how far to next higher value?"
				consider the aforementioned processing `abc//ab/c//a/bc`
					abc/	perfect early triplet
					ab/c	early broken triplet
					a/bc	late broken triplet
					/abc	perfec late triplet

	an issue:
	in the ab/c and a/bc cases, the true order is cab/bca
		but they are still treated like other sort-3 cases
	in the abc/ and /abc cases, the numbers are ordered
		in the /abc case, reverse rotate is all that's needed

