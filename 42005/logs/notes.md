[HERE](notes.md)

# 2025-02-17 10:17:41
-	issue: when libft.a exists, calling `make` results in `nothing to be done for all`

# 2025-02-17 11:02:58
-	issue: SEGFAULT when calling `find_bottom`
	-	related to trying to `sort 3`
	-	unsure where error occurs
		-	last sensible output in "find top"
		-	[X] seems to happen in `do_ra`
		-	[O] seems to happen in `do_rra`
			-	[](../alt/operations/rotate.c#L69)