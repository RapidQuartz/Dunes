**LOG FOR THE ALTERNATIVE STRAIN**

#																		       #
##																		      ##
###																		     ###
####	    The Norm asks you to create simple pieces of code,				####
#####	    where the unique task of each piece							   #####
######      can be clearly understood and verified,					      ######
#####	    and where the sequence of all the executed instructions		   #####
####	    leaves no doubt.												####
###																		     ###
##																		      ##
#																		       #

#####
#####

functions:

small
simple
cute
kawaii
well mannered

#####

#		  #
##		  ##
###		  ###
####	  ####	
#####	  #####	
######	  ######	
#####	  #####	
####	  ####	
###		  ###
##		  ##
#		  #

#####     #####
#####     #####
#####     #####
#####     #####
#####     #####
#####     #####
#####     #####
#####     #####
#####     #####
#####     #####
#####     #####

#####

/* introduction
:: purpose of this file and 'alt' project folder
-- to find a fresh start with push swap
-- to test different patterns or algorithms
:: 2025-01-29 16:47:17
__ requirements
:: useful header
:: struct with room to grow
:: way to sort ANY number combod
*/
//
/* process
::	2025-01-29 16:50:03
__ build header file
-- cost a/b in place of adjacency
-- higher/lower for crazy moves
__ log file alt.md in logs folder
__ rewrite? rewrite.
*/
//
/* main function
== same structure as before, argv and argc, but slightly different function.
-- difference is in how stack is produced, processed and operated separately
++ meaning, after each part of the project is built it should receive
   its own appropriate file + mentions in header and makefile
== start with something simple. copy your atoi.
*/

#####
##### the process of alt push swap
- main function takes a number of args
  - call arg validation (0/1) *
  - call stack maker function
	@ assign variable data
	- VALUE
    	-> call atoi
    		-> extract and return number **
	@	<- value of stack entry 
	- INDEX
    @	- iterating index counter 
	- POSITION
      - found by **traversing** stack 
	- COST_A
	- COST_B
	- * found how? counting adjacents? triplets? 
      - a measure of costliness to get number to stack
      - (but could obviously hold any number) 
      - a measure of costliness to get number to stack 
	- HIGHER
      - a pointer to the next higher value
	- LOWER
      - a pointer to the next lower value
	- PREV
      - a pointer to the next position "up" the stack
	- NEXT
      - a pointer to the next position "down" the stack
#####