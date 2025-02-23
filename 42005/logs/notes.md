[HERE](notes.md)

# 2025-02-23 18:58:54
-	issue: args ending with ' ' and containing multiple/repeating spaces parse wrong

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
			-	issues with find top seems it.
			-	this line particularly: while (top && top->prev != NULL)
			-	tried to fix by looking at index, that was dumb
			-	could solve by iterating through each time and switching index based on Rules
			-	could ignore and consider that index is 'before sort'
			but this might break the other sort rules later.
			-	seems safer to iterate and change, even if its cumbersome.
	-	TODO:	make index-iterator.
	-	TODO:	use pointers (next/prev = NULL instead of index to navigate)

# 2025-02-17 14:58:05
<!-- ==156045== 
==156045== HEAP SUMMARY:
==156045==     in use at exit: 40 bytes in 1 blocks
==156045==   total heap usage: 4 allocs, 3 frees, 1,144 bytes allocated
==156045== 
==156045== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==156045==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==156045==    by 0x4028B8: arg_stacker (stack_maker.c:59)
==156045==    by 0x402787: stack_filler (stack_maker.c:48)
==156045==    by 0x402690: stack_maker (stack_maker.c:20)
==156045==    by 0x4011ED: main (introduction.c:32)
==156045== 
==156045== LEAK SUMMARY:
==156045==    definitely lost: 40 bytes in 1 blocks
==156045==    indirectly lost: 0 bytes in 0 blocks
==156045==      possibly lost: 0 bytes in 0 blocks
==156045==    still reachable: 0 bytes in 0 blocks
==156045==         suppressed: 0 bytes in 0 blocks
==156045== 
==156045== Use --track-origins=yes to see where uninitialised values come from
==156045== For lists of detected and suppressed errors, rerun with: -s
==156045== ERROR SUMMARY: 11 errors from 11 contexts (suppressed: 0 from 0)
 -->