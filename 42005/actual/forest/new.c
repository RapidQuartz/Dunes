//42header
//this line intentionally left blank
#include "../push_swap.h"
#include "../push_swap.h"
////	MIND:	makefile/header location varies based on OS
////	MIND:	`new.h` header and `main` for testing only
////	INTRO:
// 
// new.c
// purpose:		implementation of ideas about using 2 bytes to store data
// design:		in a `struct s_byte`, store stack using `char a; char b;`
// outcome:		less resource intensive analysis and sort algorithm
// details:		more details to be stored in new.md, or blocs above code.
// what if they have the same value. i can use a trick to assume that two values means certain ranges.
// for instance if the top and bottom quartiles are more interesting (they are)
// i could make it represent the distance from top and bottom respectively
// and set another range of the numbers to represent the action.
// since the top and bottom numbers are the most interesting to operate on,
// other numbers can be used to store data.
// meaning, a specific value can be set to mean "next instruction at location x"
// or another could mean "last instructions target is this."
// 
// due to the sequential nature of a stack with next and prev, this could sturcture the arguments further
// 
// in other words, instructions above (in a) could mean |go up and do this when signaled|
// when followed by instructions below, and a stop signal above, the full command has been parsed.
// set a while condition to read the sbyte and proceed from there.
////	DEBUG:MAIN:

int		main(void)
{

	return (0);
}

////	DEBUG:STRUCT:
typedef	struct s_byte
{
	char	a;//null/pos[1-255]RA/RB/RR/RRA/RRB/RRR
	char	b;//{0-}pos[256-500]PushA/PushB/SwitchStacks
	/* data */
} t_byte;
