[switchboard](execute.c)  
[construction](MAKEFILE)  
[main](push_swap.c)  
[header](push_swap.h)  
[here](README.md)  
[structure](#how-is-a-readme-structured)  
[how to](#how-to-build-push-swap)  
[>makefile](#makefile)  
[optional commands](#optional-commands)  
###	How is a README structured?
the readme exists to provide crucial and pertinent information to the user     
it should be extremely compressed with minimal bloat and feature **creep**
#	How to build Push Swap
enter the `following` on the command line:

	`make`  
	
	
if successful `BUILD COMPLETE` will appear in green  
if not, `Error` will appear in red, followed by a prompt to view any issues  
#	How to use Push Swap
enter between two and five hundred integers on the command line  
- no duplicates
- within MIN/MAX limits for `int`

###	optional commands
	flag		mode
	-v 			`verbose`   
	-d 			`diagnostic`  
	-x			`test`


####	makefile
the `MAKEFILE` contains machine instructions to create necessary files  


##	chatgpt

Come on Daedalus, show me the updraft and I'll try to stay within earshot.

You're good at stroking my ego. 'too good' as you prompted me to say heheheheh....
Okay brass tacks and O-rings, baby.

issues:
rewriting from scratch, i need to make a lot of basic functions before i can even start sniffing at the 'algorithm'. However, before my last fit of Phoenician immolatory therapy, i feel i got quite close with the 'mechanical turk' algorithm, which you may find online, related search terms follow: {"42", "push_swap"}.

as i understand it, the basic operation is as follows (bear in mind this isnt what im currently working on, as you remember that i was still trying to allocate the very first array to handle the arguments which later must face the sorter, or segfault trying.)

0. arguments `int argc, char **argv` are checked:
a. `argc` (we need minimum 2 since `argv[1]` is our program name, but they may be provided as "positive or negative ints separated by spaces" in addition to "one pos/neg int per argument string"). return an error if `argc < 2`

b. `argv**` is examined, as mentioned we need to make sure that:

i. each space-or-index-separated argument must be within INT_/MIN/MAX.
ii. a single `+` or `-` may be present before the digits
iii. whitespace in the form of ' ' spaces, may exist before or after or between arguments but not within them
iv. no letters or symbols are permitted apart from: {"0-9", "+/-", "\0", " "}
v. no duplicates may exist, including '0'/'000'/'0000'

c. the function to check `argv` returns `int argn` for number of args (to disambiguate from `argc` which counts by other means.). argn is used (as you saw a sneak preview of) to allocate memory for the arrays which hold the stack.

d. a modified/cobbled together/homebrew 'atoi' function places each `int` into `int *arr`. `arr[0]` is set to `argn` for two reasons:

i. to save the number of arguments to sort in a variable that will be handled frequently, and remove need for specific counting-variable
ii. to keep the indices 'clean', meaning the `arr[argn]` or `arr[1]` represent the last and first numbers, in order to improve legibility (im not as used to zero-indexing as you)

e. this `int *arr` with `argn` at `arr[0]` is "NORMALIZED" (numbers range from 1 to argn) and put into the structure `struct s_stk{...}t_stk;`. A quick overview:
`t_stk->(int)*a`
the a-stack
`t_stk->(int)*b`
the b-stack
`t_stk->(int)**c`
the storage of cost and operations (more on this later.)

f. the `t_stk *nexus` is at last passed to a function`void push_swap(t_stk **nexus)`, which will call and trigger various sorting processes. firstly depending on the count of arguments {nexus->a[0] == (i = [2], ii = [3], iii = [>3])} and secondly depending on its sortedness. (more on this later)

i. if (nexus->a[1] > nexus->a[2]) --> swap them and return
ii. {a separate, hardcoded function `t_stk *sort_three(t_stk *nexus)`}
iii. the turk algorithm.

g. the turk algorithm will:

i. pushes up to 2 (until a has minimum 3 arguments left) arguments from stack a to stack b. (meaning, since we're dealing with stacks, the formerly first argument becomes the bottom of b, and the second becomes the top.)
(if/when) stack a has 3 members, it will be sent to "sort-three" before b is pushed back. (more on that later)
ii. compare the fitment of the remaining arguments in `stk->a`.
iii. rotate either stk->a or stk->b until the most beneficial/fewest moves can be made to push numbers, increasing degrees of order.
iv. once 3 numbers remain, the now-descending b-stack is pushed back to a.
v. sorting degree is checked, and if it is not perfect, the process repeats.

("more on that later:")
(0. cost)
(1. operations)
(2. sortedness)
(3. sort 3 -> push back)

0. cost is seen as 'number of operations to sort a number by pushing it to the other stack'
i. the minimum is 1 (PUSH) for the top number to sit neatly on top of stack b, without manipulation
ii. when a numbers index is past the halfway count of its stack, we reverse it to grab it from the bottom.
iii. we check `stk->a[1]` first, then while `i = 2, j = size` check `stk->a[i++]` and `stk->a[j--]`
iv. first we traverse all of a[] to try and fit with b[1].
v. then we try to iterate through b[] thus: `a[i++]//a[j--] ---> b[k]//b[l]` incrementing k/l when i/j meet in the middle. (maybe better to do it simultaneously? i dunno dude, this is already getting overwhelming.)

1. operations either need to be stored, or printed immediately. storing them is my current approach. A challenge remains. up to 5500 of them may be necessary/permitted, for the maximum amount of arguments (500 args - 5500 ops)//(100 args - 700 ops). This means im worried about allocating the cost/arrays.
the first few indices `c[1][i]``c[2][j]` etc. will store the 'cost' as mentioned above:
i. `c[1][i]` cost of pushing from `a[i]` to `b[c[3][i]]` (storing 'target for a-index `i`' as 'the b with index stored at c[3][a-index]')
ii. `c[2][j]` cost of pushing from `b[j]` to `b[c[4][j]]` (storing 'target for b-index `i`' as 'the a with index stored at c[4][a-index]')

2. sortedness is measured by two main factors, and a few subfactors.
the entire stack is `sorted` when all numbers are present in A, none in B, and all ascending from `1` to `size`.
i. sequence A - all numbers in A are adjacent and ascending, `a[i] + 1 == a[i + 1]`.
ii. sequence B - all numbers in B are adjacent and descending, `b[j] - 1 == b[j + 1]`.
iii. tops - `a[1] -1 == b[1]`
once all three are TRUE, it is safe to push all of B back to A without modifications.

--

this is an unholy mix of fantasy and fact. some of what i described is merely ideated, and not implemented. I need a lot of help, a lot of motivation, and a lot of time. I have access to all, but my fleshy brain often makes it hard to embody silicon sentience and patience.

thanks for reading. I want to stay accountable, and hope you can help me with this. I'm very happy so far.