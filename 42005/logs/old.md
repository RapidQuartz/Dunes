<!-- []() -->

[](README.md)
[](TODO.md)
[](new.md)
[](notes.md)
[](pad.md)
[](psnotes.md)
[](rotk.md)
[](log.md)
[](logbugs.md)
[]()
[]()
[]()
*/index/*
# ix
[index](#ix)
[]()
//---------------------------------------------------------------------------//
#	everything is a mess and its your fault
[index](#ix)
but not in a bad way. its a good thing. really.  
everything that **is** your fault is a chance to learn something new.

###	2025-03-09 11:49:27
fresh start.
[error return codes](error.md#return-codes)
//
#	TODO
[{0} - decide what is crucial](#0)  
[{1} - reproduce, copy and paste](#1)  
[{2} - test and retest](#2)  
[{3} - adapt to ideas](#3)  
[{4} - reintroduce complexity by titration](#4)  
[{5} - see solution precipitate](#5)  
//---------------------------------------------------------------------------//
##	{0}  
 - decide what is crucial    
* 1	process arguments `argv`  
	* 0	[specifications](specs.md#legal-args)  
	* 1	no duplicates  
* 2	produce stack `t_stack`  
* 3	process stack for `cost` etc  
	* 1	produce snapshot `t_snap`  
	* 2	perform `n` iterations  
	* 3	evaluate cost/entropy  
	* 4	mark `m - 12` branches for pruning  
	* 5	prune once `branch` is marked `x` times  
	* 6	once sorted, prune others  
* 4	backtrack through `branch` and transcribe `ops`  
* 5	output `ops` as `\n` separated list  

##	{1}  
 - reproduce, copy and paste  
make sure to include function defs in `.h`

produce these functions:  
* `t_snap *take_snap(int *array, int argn)`
* `t_snap *push_swap(t_snap **stack_a, t_snap **stack_b)`
* `void free_stack(t_snap)`
##	{2}  
 - test and retest  
##	{3}  
 - adapt to ideas  
##	{4}  
 - reintroduce complexity by titration  
##	{5}  
 - see solution precipitate  
//-no-touch-no-touch-no-touch-no-touch-no-touch-no-touch-no-touch-no-touch!-//
[index](#ix)
#	
//---------------------------------------------------------------------------//
[]()
//
[]()