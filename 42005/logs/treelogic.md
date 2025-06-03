[](../actual/decision/decision_tree.c)
[](../actual/decision/make_tree.c)

2025-03-04 15:29:36

TODO:
	documentation>>
	free-map>>

#	forest-algorithm

##	term explanation
###	tree
[`struct s_tree **tree`] a decision making tree, branching out after trying moves
-	needs a reference system to store keys for other vars.


###	trunk
[`short **trunk`] the stack as projected after current moves
-	needs functions to:
	change order of stack after a move is suggested
	handle stackA/stackB differences//supply two trunks

###	branch
[`char **branch`] a moveset, branching out
stored as strings of characters from a to i. maximum 5500 moves across 16 potentials

###	leaf
[`short **entropy`] entropy score, "which leaves get more light"
calculated based on the orderliness of the trunk

###	seed
[`char **seed`] output, selected movesets
(5500 bytes * 5 candidates)