#						new


#	all is lost
2025-03-09 19:19:56 i give up. this was a fools errand.  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  




the new project is a result of a long journey through the backyard of c  
it carries the legacy of the triplet endeavour much beloved for its originality  
furthermore it signifies a veritable metropolis of a rabbit warren  
so hang on tight  
it might get bumpy  
#		index
###	[ix](#ix)
####	what it is
this index is meant to keep key concepts under wraps
####	why it is
because documentation makes it easier to unfuck your code
####	how it is
a tad on the neurotic side but otherwise maybe almost functional *sometimes*
###	[	' -data- 		'](new.md#data)  
###	[	' -ent- 		'](new.md#enterprise)  
###	[	' -lore- 		'](new.md#lore)  
### 	[	' -legacy-		'](new.md#legacy-intro)  
### 	[	' -states-		'](new.md#states-of-ab)  
### 	[	' -legend-		'](new.md#legend)  
### 	[	' -stakops-		'](new.md#operations)  
### 	[	' -classin-		'](new.md#classification)  
### 	[	' -helpers-		'](new.md#helpers-and-operations)  
### 	[	' -instructions-	'](new.md#s_byte-instructions-detailed)  
### 	[	' -s_byte index-	'](new.md#s_byte-index-explanation)  
### 	[	' -candidates-	'](new.md#candidate-paths)  
###	[	' -clmx- 		'](new.md#climax)  
###	[	' -debug- 		'](new.md#debug)  
###	[	' -notes- 		'](new.md#notes)  
####	[	' -things to do-	'](new.md#things-to-do)  
####	[	' -scratchpad-	'](new.md#scratchpad)  
###	[	' -refs- 		'](new.md#referents)  
###	[	' -error- 		'](new.md#error)  
###	[	' -map- 		'](new.md#map)  
###	

#		lore
###	[ix](#ix)
##	what it is
this is the push swap project for [42 Berlin](https://42berlin.de) (2025.03.05)
##	why it is
complexity breeds in uncertainty and self made obsession rises from its ashes
##	how it is
using two structs and some convoluted logic a list of numbers will be sorted
###	legacy intro
###	[ix](#ix)
<!-- 		legacy intro
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
// set a while condition to read the sbyte and proceed from there. -->
#		data
###	[ix](#ix)
##	what it is
info about the arguments provided and relevant analysis for decision algorithms
##	why it is
main struct carries most data and para-struct carries projection for algorithms
##	how it is
see own files but suffice to say it aint pretty
#		enterprise
###	[ix](#ix)
to finish this project as soon as possible while completing development of self

###		states of ab
###	[ix](#ix)
the index of the `char *a` & `char *b` matters.  
assuming an original stack of 9 members  
21 indices will be reserved
indices 0-4 are reserved  
indices 1-2 info about the stack snapshot  
indices 3-4 instructions for the decider  
in a:  
indices 5-9 hold the first 5 members' positions  
in b:  
indices 5-8 hold the last 4 members' positions  
the final 12 indices hold instructions on how to operate on the stack

<!--/*	states:

				a	b		a	b	
0	[empty]		0	0		0	0	[empty]	0
A	[0>m<251]		m	m		m	m	[size]	A
B	[0>m<251]	 	m	0		0	m	[num]		C
D	[0>m<251]		m	n	[251]	n	m	[op]		I
E	[0>m<251]		m	o	[252]	o	m	[op]		J
F	[0>m<251]		m	p	[253]	p	m	[op]		K
G	[0>m<251]		m	q	[254]	q	m	[op]		L
H	[0>m<251]		m	r	[255]	r	m	[op]		M
==										
N	[n = 251]		n	n	[op]
O	[o = 252]		o	o	[op]
P	[p = 253]		p	p	[op]
Q	[q = 254]		q	q	[op]
R	[r = 255]		r	r	[op]
 -->
###		operations
###	[ix](#ix)
/*	ops:  
**pa**	*only relevant for* **top**  
**pb**	*only relevant for* **top**  
**sa**	*only relevant for* **top**  
**sb**	*only relevant for* **top**  
**ss**	*only relevant for* **top**  
**ra**	*mutually relevant*  
**rb**	*mutually relevant*  
**rr**	*mutually relevant*  
**rra**	*most relevant for* **bottom**  
**rrb**	*most relevant for* **bottom**  
**rrr**	*most relevant for* **bottom**  
*/
####		legal operations
1///A//pa//LEGAL if tree->a[1] == 252 || tree->a[1] == 253
2///B//pb//LEGAL if tree->a[1] == 251 || tree->a[1] == 253
3///C//sa//LEGAL if tree->a[1] == 251 || tree->a[1] == 253
4///D//sb//LEGAL if tree->a[1] == 252 || tree->a[1] == 253
5///E//ss//LEGAL if tree->a[1] == 253
6///F//ra//LEGAL if tree->a[1] == 251 || tree->a[1] == 253
7///G//rb//LEGAL if tree->a[1] == 252 || tree->a[1] == 253
8///H//rr//LEGAL if tree->a[1] == 253
9///I//rra//LEGAL if tree->a[1] == 251 || tree->a[1] == 253
10//J//rrb//LEGAL if tree->a[1] == 252 || tree->a[1] == 253
11//K//rrr//LEGAL if tree->a[1] == 253
###		legend
###	[ix](#ix)
<!--/*	legend:
cod	ind	category		ch_a	nom	ch_b	description
0	i	[null/sorted]	-0-	{}	-0-	"null value/spacer"
A	ii	[size/division]	-m-	{}	-m-	"stack size [eg. 2 1 = 3 total]"
B	iii	[num	-	top]	-m-	{}	-0-	"element position for 1st half of stack"
C	iv	[num	-	bot]	-0-	{}	-m-	"element position for 2nd half of stack"
D	v	[op	-	top]	-m-	{pa}	-251-	"Push -m- to stack A"
E	vi	[op	-	top]	-m-	{pb}	-252-	"Push -m- to stack B"
F	vii	[op	-	top]	-m-	{sa}	-253-	"Swap -m- in stack A"
G	viii	[op	-	top]	-m-	{sb}	-254-	"Swap -m- in stack B"
H	ix	[op	-	top]	-255-	{ss}	-255-	"Swap both stacks"
I	x	[info	-	st_A]	-251-	{AAA}	-0-	"STACK A"
J	xi	[info	-	st_B]	-252-	{BBB}	-0-	"STACK B"
K	xii	[op	-	rra]	-253-	{rra}	-m-	"Reverse Rotate stack A"
L	xiii	[op	-	rrb]	-254-	{rrb}	-m-	"Reverse Rotate stack B"
M	xiv	[op	-	rrr]	-255-	{rrr}	-m-	"Reverse Rotate both A&B"
N	xv	[inst	-	STA]	-0-	{STA}	-251-	"start reading instructions"
O	xvi	[inst	-	END]	-0-	{END}	-252-	"stop reading instructions"
P	xvii	[op	-	bot]	-253-	{ra}	-253-	"Rotate stack A"
Q	xviii	[op	-	bot]	-254-	{rb}	-254-	"Rotate stack B"
R	xix	[op	-	bot]	-255-	{rr}	-255-	"Rotate both A&B"
*/ -->
####		glossary
###		classification
###	[ix](#ix)
<!--/*	classification:
	index:	node[i]:	code:
ab	i		-0><4-	{0}
ab	ii		-1-		{A}
a-	iii		-<size/2-	{B}
-b	iv		->size/2-	{C}
a-	v		-4+-		{D}
-b	vi		-4+-		{E}
a-	vii		-4+-		{F}
-b	viii		-4+-		{G}
ab	ix		-4+-		{H}
ab	x		-2-		{I}
ab	xi		-2-		{J}
a-	xii		-4+-		{K}
-b	xiii		-4+-		{L}
ab	xiv		-4+-		{M}
ab	xv		-3+-		{N}
ab	xvi		-4+-		{O}		-ii-
a-	xvii		-4+-		{P}		-ee-
b-	xviii		-4+-		{Q}
ab	xix		-4+-		{R}
*/-->
###		helpers and operations:
###	[ix](#ix)
pa	--		b[0] = 65
pb	--		b[0] = 66
sa	--		b[0] = 67
sb	--		b[0] = 68
ss	--		b[0] = 69
ra	--		b[0] = 70
rb	--		b[0] = 71
rr	--		b[0] = 72
rra	--		b[0] = 73
rrb	--		b[0] = 74
rrr	--		b[0] = 75

<!--/*	helpers and operations:
begin instruction	-ii-		{==}	"start recording instructions"
end instruction	-ee-		{==}	"finish recording instructions"
copy chars		-cc-		{==}	"copy char at ab[c]"
paste chars		-pp-		{==}	"paste char at ab[c]"
move chars +	-mm-		{==}	"move all chars in ab in by c[+]"
move chars -	-nn-		{==}	"move all chars in ab in by c[-]"
delete chars	-dd-		{==}	"remove char at ab[c]"
count size		-zz-		{==}	"count size of stack ab"
update count	-uu-		{==}	"update count of stack ab with c[->0<+]"
*/ --> 
####		helper functions


	//transcription	-	transcribe stack to s_byte  
					-	inscribe s_byte with information  
	//sort state	-	perform calculations on s_byte  
	//cost eval		-	evaluate calculation saliency  
					-	prune inadequate paths  

	//operation dispatch
####		s_byte complex operations
###	[ix](#ix)
**begin instruction**	*-ii-*	**"start recording instructions"**  
**end instruction**	*-ee-*	**"finish recording instructions"**  
**copy chars**		*-cc-*	**"copy char at ab[c]"**  
**paste chars**		*-pp-*	**"paste char at ab[c]"**  
**move chars +**		*-mm-*	**"move all chars in ab in by c[+]"**  
**move chars -**		*-nn-*	**"move all chars in ab in by c[-]"**  
**delete chars**		*-dd-*	**"remove char at ab[c]"**  
**count size**		*-zz-*	**"count size of stack ab"**  
**update count**		*-uu-*	**"update count of stack ab with c[->0<+]"**  
####		s_byte index explanation  
###	[ix](#ix)  
index	name			a		b	-	description  
0	iteration	-	0-255		0-255 -	(a[0]) + (b[0] * 255)  
1	stack/ops	-	a/b/c		ops	-  	(a[1]: a, b, c) (b[1]: 1-11)
2	contents:a	-	n		m	-  	(n members of stack A in *a, m members of stack A in *b)
3	contents:b	-	n		m	-  	(n members of stack B in *a, m members of stack B in *b)
4	entropy?	-	0-255		0-255 -	(a[4]: a-stack entropy) + (b[4]: b-stack entropy) (0 is empty, 1 is ordered)  
5	numbers	-	0-255		0-255 -  
x	delimiter	-	0		0	-  	if a[1] == a or a[1] == b, no delimiter. otherwise it shows where a-stack stops and b-stack begins
x	end		-	255		255	-	end of stack in this char*





<!-- /*	s_byte operation process
process:	/{}[]/
pa	--		{ii{mm}[aa+1]/{cc}[bb#1]{pp}[aa#1]/{mm}[bb-1]/{uu}[aa+1]{uu}[bb-1]ee}
pb	--		{ii{mm}[bb+1]/{cc}[aa#1]{pp}[bb#1]/{mm}[aa-1]/{uu}[aa-1]/{uu}[bb-1]ee}/
sa	--		{ii/{cc}[aa#2]/{cc}[aa#1]/{pp}[aa#1]/{pp}[aa#2]//ee}
sb	--		{ii/{cc}[bb#2]/{cc}[bb#1]/{pp}[bb#1]/{pp}[bb#2]/ee}
ss	--		{ii/{sa}/{sb}/ee}
ra	--		{ii/{cc}[aa#1]/{mm}[aa-1]/{pp}[aa#L]/ee}
rb	--		{ii/{cc}[bb#1]/{mm}[bb-1]/{pp}[bb#L]/ee}
rr	--		{ii/{ra}/{rb}/ee}
rra	--		{ii/{cc}[aa#L]/{mm}[aa+1]/{pp}[aa#1]/ee}
rrb	--		{ii/{cc}[bb#L]/{mm}[bb+1]/{pp}[bb#1]/ee}
rrr	--		{ii/{rra}/{rrb}/ee}
*/


////	DEBUG:STRUCT:
//MOVED TO .h
/* typedef	struct s_byte
{
	char			a;
	char			b;
	struct s_byte	*next;
} t_byte; */ -->
####		s_byte instructions detailed
//push_a requires all A-stack values move +1
//start by moving into the buffer at the end of *a
//then move into buffer at end of *b
//then copy buffer from end of *a to start of *b
//increase `a_count` +1
//decrease `b_count` +1
//place delimiter 0-0 or similar at end of A, wherever that is.
//

<!-- /*	s_byte instructions detailed
detailed instructions:
n	 	=	1-250
o		=	251
v		=	252
w		=	253
x		=	254
z		=	255

node[#]	case	a-b			outcome
0		q	0-0			{entropy}[new]
0		p	n-n			{entropy}{score}
0		o	o-o			{entropy}{not measured}
0		v	v-v			{entropy}{measurement underway}
0		w	w-w			{entropy}{measured, not applied}
0		x	x-x			{entropy}{applied solution, need new measure}
0		z	z-z			{entropy}{ordered}
1		w	251-0			[this represents ONLY stack A] -
2		w	A-B			{A holds A & B}
3		w	0-0			{B holds none}
1		e	252-0			[this represents ONLY stack B]
2		w	0-0			{A holds none}
3		e	A-B			{B holds A & B}
1		r	253-0			[this represents BOTH stack A & B]
2		r	A-B			{A holds A & B}
3		l	A-B			{B holds A & B}
1		t	254-num		[this represents MOSTLY stack A]
2		t	A-B			{A holds A & B}
3		l	A-B			{B holds A & B}
1		y	255-num		{this represents MOSTLY stack B}
2		y	A-B			{A holds A + B}
3		l	A-B			{B holds A + B}
<4		q	0-0			{placeholder to proceed to next valid}
<4		q	0-0			{placeholder to proceed to next valid}
>4		j	0-252			{execute instructions then reevaluate}
*/ -->
##### 	candidate paths
###	[ix](#ix)
{==}	one of several attempted trees  
-							{==}	
#						climax
###	[ix](#ix)
when project makes and runs and performs as desired without crash at evaluation
#		debug
###	[ix](#ix)
see own files but suffice to say it aint pretty
#		notes
###	[ix](#ix)
//	circular array
//	merge/chunk sort
<!-- EXT//two stacks bisected
top/bottom for both

4 divisions to send numbers dependent on values

received in top array
go thru nums
divide to max,mid,min


top A empty
iterate through areas
repeat
 -->
<!-- splitting stacks
////	DEBUG:MAIN:

int		main(void)
{

	return (0);
}

/* top and bottom quartile of the stack are most relevant
max 500 numbers, probably less

divide stack into top and bottom -->
####		things to do
####		scratchpad
{==}	
{==}	
{==}	
{==}	
{==}	
{==}	
{==}	
{==}	
{==}	
#		referents
###	[ix](#ix)
see own files but suffice to say it aint pretty
#		error
###	[ix](#ix)
see own files but suffice to say it aint pretty
#						map
###	[ix](#ix)

['README'](README.md)
['TODO'](TODO.md)