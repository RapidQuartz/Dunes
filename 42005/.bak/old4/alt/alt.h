#ifndef ALT_H
# define ALT_H
//// INC_DEFS:
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
//// ST_DEFS:
typedef	struct	s_stk
{
	int			*a;//a_stack
	int			*b;//b_stack
	int			*c;//cost
	int			d;//data
	int			e;//error
} t_stk;
//// FT_DEFS:
t_stk		*m_init(int a, char **b);
//// :

//// :
#endif