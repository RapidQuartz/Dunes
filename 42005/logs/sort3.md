# sort 3

# [rotk log for this](rotk.md#sort-3)
##	TODO: reference sort3 in header
-	if argn is 3
	->	if n0 > n1 && n0 > n2
	->	if n0 > n1 && n0 < n2
	->	if n0 < n1 && n0 > n2
	->	if n0 < n1 && n0 > n2

		generalized (just using `n` to represent relative index)
				definition
					x = n + 0
					y = n + 1
					z = n + 2
		
					(should have done xyz)
		abc
		if x < y && x < z && y < z
	end	0
	
		acb
		if x < y && x < z && y > z
		swap y and z
			rotate
			swap
			reverse rotate
	end	3
	
		cab
		if x > y && x > z && y < z
		swap x and y
			swap
		swap y and z
			rotate
			swap
			reverse rotate
	end	4
	
		cba
		if x > y && x > z && y > z
		swap y and z
			rotate
			swap
			reverse rotate
		swap x and y
			swap
		swap y and z
			rotate
			swap
			reverse rotate
	end	7
	
		bca
		if x < y && x > z && y > z
		swap y and z
			rotate
			swap
			reverse rotate
		swap x and y
			swap
	end	4
	
		bac
		if x > y && x < z && y < z
		swap x and y
			swap
	end	1
