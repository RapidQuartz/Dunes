/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:36:32 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/26 16:44:53 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//				a test file to test c-tutor with stacks
#include "push_swap.h"
////	START:COPY:	DUMP:
////	FUNCTIONS:
int		validity_checker(char a, char b);
int		arg_checker(int ac, char **av);
int		argc_dummy(void);
char		**argv_dummy(void);
int		arg_counter(char *av);
void		push_swap(t_stack **st_a, t_stack **st_b);
long    	get_number(char *arg, int argn);
int		arg_counter(char *av);
////	STACKFUNC:
//<new 2025-01-15 16:15:38
int		sortvsize(t_stack *aaa, t_stack *bbb);
t_stack	*adjacency(t_stack *sss, int size);
int		getsize(t_stack *sss);

//>
t_stack	*stack_maker(int ac, char **av);
t_stack	*new_stack_entry(int value, t_stack *prev);
t_stack	*find_stack_bottom(t_stack *stack);
void		add_to_bottom(t_stack **stack, t_stack *new);
void		give_stack_position(t_stack *stack, int size);
int		get_stack_size(t_stack *stack);
void		free_memory(t_stack **stack);
////	SORTING:
void		sort(t_stack **st_a, t_stack **st_b, int size);
t_stack	*getnxtptr(t_stack *ptr, int size);
t_stack	*getprvptr(t_stack *ptr, int size);
////	OPERATIONS:
static void swap(t_stack *stack);
static void rotate(t_stack **stack);
static void reverse_rotate(t_stack **stack);
t_stack	*get_penultimate(t_stack *stack);
////	NAVIGATOR:
t_stack	*navigator(t_stack **st_a, t_stack **st_b, int size);
t_stack	*smolfind(t_stack *sss, int size);
void		prevfind(t_stack **sss, t_stack **smol, int size);
void		indexize(t_stack **sss, int adj);
void		backtracker(t_stack **sss, int siz);
////	:
void	negadjacent(t_stack **st, int	g);
void	negalizer(t_stack **st, int	g);
////	:



void		push_swap(t_stack **st_a, t_stack **st_b)
{
	int		size;
	t_stack	*stt_a;
	t_stack	*stt_b;
	t_stack	*stt_t;
	
	stt_a = *st_a;
	stt_b = *st_b;
	stt_t = *st_a;
	size = get_stack_size(*st_a);
	give_stack_position(*st_a, size);
/*DEBUG*/
	printf("[STACK_A-INITIAL]\n\n");
	while (st_a != NULL)
	{
		printf("value: %d\tindex: %d\tposition:%d\t"
"adjacency:%d\n\thigher:%p\tlower:%p\tprev:%p\tnext:%p\t\n\n", (*st_a)->value, \
		(*st_a)->index, (*st_a)->position, (*st_a)->adjacency, \
		(*st_a)->higher, (*st_a)->lower, (*st_a)->prev, (*st_a)->next);
		if ((*st_a)->next == NULL)
			break ;
		(*st_a) = (*st_a)->next;
	}
/*DEBUG*/
	sort(&stt_a, &stt_b, size);
	(*st_a) = stt_t;
	printf("[STACK_A-RESULT]\n\n");
	while (st_a != NULL)
	{
		printf("value: %d\tindex: %d\tposition:%d\t"
"adjacency:%d\n\thigher:%p\tlower:%p\tprev:%p\tnext:%p\t\n\n", (*st_a)->value, \
		(*st_a)->index, (*st_a)->position, (*st_a)->adjacency, \
		(*st_a)->higher, (*st_a)->lower, (*st_a)->prev, (*st_a)->next);
		if ((*st_a)->next == NULL)
			break ;
		(*st_a) = (*st_a)->next;
	}
	printf("[STACK_A-random]\n[st_a->prev = %lld(as long long int)]\n", (long long int)(*st_a)->prev);

/*DEBUG*/
	free_memory(st_a);
	free_memory(st_b);
}
void		sort(t_stack **st_a, t_stack **st_b, int size)
{
//	:0:	check sort vs size (small algo special)
		
		int	sort;//posi/nega//tive depending on sort direction
//	:1:	sort	(ask for help for godssakes)
//	:2:	sort vs size (a function)
//	::	()
		t_stack	*stack;
		
		stack = adjacency(*st_a, size);
		stack = navigator(st_a, st_b, size);
		*st_a = stack;
}

int		sortvsize(t_stack *aaa, t_stack *bbb)
{
	/*	operation:
	---	takes two stacks
	---	finds sizes
	---	finds ratio of sorting to size
		---	(smaller size + low entropy = GOOD)
		---	(higher size + high entropy = BAD)
		:a ratio from -10 to +10:
		:+5:if size is small:'[REFER TO DOCUMENTATION]':
		:-5:if size is large:'[REFER TO DOCUMENTATION]':
		:+5:if entropy is low:'numbers are adjacent':
		:-5:if entropy is great:'numbers are far apart':
		::
	---	
	*/
	return(0);
}

t_stack	*adjacency(t_stack *sss, int size)
{
	t_stack	*tmp;
	t_stack	*nxp;
	t_stack	*prp;

	tmp = sss;
	nxp = NULL;
	prp = NULL;
	while (size--)
	{
		while (sss && sss->next && (nxp == NULL && prp == NULL))
		{
			if (nxp == NULL)
				nxp = getnxtptr(sss, size);
			if (prp == NULL)
				prp = getnxtptr(sss, size - 1);
			if (sss->next == NULL)
				sss = tmp;
			else
				sss = sss->next;
		}
		sss->lower = prp;
		if (nxp != prp)
			sss->higher = nxp;
	}
	return(0);
}

t_stack	*getnxtptr(t_stack *ptr, int size)
{
	t_stack	*stack;
	
	stack = ptr;
	while (ptr->next != NULL)
	{
		if (size = ptr->position)
			break ;
		if (ptr->next == NULL)
			ptr = stack;
		else
			ptr = ptr->next;
	}
	return (ptr);
}
















/* 				if (sss->value == nxp->value)//TODO: condition for value isnt last
					sss = sss->next;
				if (sss->value < nxp->value)//move on if sorted {A STACK}
					sss = sss->next;
				else if (sss->value > nxp->value)//
					nxp = sss->value;
				if (1)
					;
				else if (sss->value < prp->value)
					;
 */
/*	getsize(t_stack *sss)[TODO:MAKE GETSIZE FUNCTION]
*/
int		getsize(t_stack *sss)
{
	int	size;
	t_stack	*stack;
	size = 1;
	
	stack = sss;
	if (!stack || stack->next == NULL)
		return (-1);//TODO: negative error return
	while (stack->next != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
/* 
int		getsize(t_stack *sss)
{
	int	i;
	t_stack	*stack;

	i = 0;
	stack = sss;
	if (!sss)
		return (0);//TODO: return-zero-check
	while (stack)
	{
		sss = stack->next;
		if (sss == NULL)
			return (i);
		stack = stack->next;
		i++;
	}
		//DEBUG//START
	printf("value:stack: %d\n", stack->value);
	printf("value:sss: %d\n", sss->value);
	printf("value:next:stack: %d\n", stack->next->value);
	printf("value:next:sss: %d\n", sss->next->value);
	printf("--\n");
		//DEBUG//END
	return (0);
} */


t_stack	*stack_maker(int ac, char **av)
{
	t_stack	*stack;
	long int	num;
	int		i;
	int		count;
	int		an;

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		count = 0;
		an = arg_counter(av[i]);
		while (count != an)
		{
			count++;
			num = get_number(av[i], count);
			if (i == 1 && count == 1)
				stack = new_stack_entry(num, NULL);
			else
				add_to_bottom(&stack, new_stack_entry(num, stack));
		}
		i++;
	}
	return (stack);
}

t_stack	*new_stack_entry(int value, t_stack *prev)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	if (prev == NULL)
		new->index = 1;
	if (prev != NULL)
	{
		while (prev->next != NULL)
		{
			prev = prev->next;
		}
		new->index = prev->index + 1;
		new->prev = prev;
	}
	new->position = 0;
	new->adjacency = -1;
	new->higher = NULL;
	new->lower = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*find_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);	
}

void	add_to_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bottom = find_stack_bottom(*stack);
	bottom->next = new;
}

void	give_stack_position(t_stack *stack, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (size > 0)
	{
		ptr = stack;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->position == 0)
				ptr->position = 1;
			if (ptr->value > value && ptr->position == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->position = size--;
	}

}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

long    get_number(char *arg, int argn)
{
	int		i;
	int		neg;
	long int	num;

	i = 0;
	while (argn && arg[i] != '\0')
	{
		neg = 1;
		num = 0;
		if (argn == 1 && arg[i] == '-')
			neg *= -1;
		if (arg[i] == '+' || arg[i] == '-' || arg[i] == ' ')
			i++;
		while (arg[i] <= '9' && arg[i] >= '0')
		{
			if (argn == 1)
				num += (arg[i] - '0');
			i++;
			if ((arg[i] != '\0') && (arg[i] != ' ') && argn == 1)
				num *= 10;
		}
		if (arg[i] == ' ' || arg[i] == '\0')
			argn--;
	}
	return (num * neg);
}	

int	arg_checker(int ac, char **av)
{
	int	i;
	int	n;
	int	j;
	char	p;

	i = 1;
	while(i != ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			p = av[i][j];
			j++;
			if (!validity_checker(av[i][j], p))
				return (0);////	CALL:0:2:1:RETURN:0:main()
		}
		i++;
	}
	return (1);////	CALL:0:2:1:RETURN:n:main()
}

int	arg_counter(char *av)
{
	int	i;
	int	n;
	char	p;
	int	r;

	n = 0;
	i = 0;
	while (av[i] != '\0')
	{
		p = av[i];
		i++;
		r = validity_checker(av[i], p);
		if (!r)
			return (0);
		else if (r == 2)
			n++;
	}
	return (n);
}

int	validity_checker(char a, char b)
{
	if ((b == ' ') && (a == ' ' || a == '-' || a == '+' || \
	(a >= '0' && a <= '9')))
			return (1);
	if ((b == '-' || b == '+') && (a >= '0' && a <= '9'))
			return (1);
	if (b <= '9' && b >= '0')
	{
		if ((a == ' ') || (a == '\0'))
			return (2);
		if (a >= '0' && a <= '9')
			return (1);
	}
	return (0);
}

void	free_memory(t_stack **stack)
{
	t_stack	*mem;
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		mem = (*stack)->next;
		free (*stack);
		*stack = mem;
	}
	*stack = NULL;
}
//	\/\/\/\/\/\/\/\/\/	<OLD MAIN	\/\/\/\/\/\/\/\/\/
int	main(int ac, char **av)
{
	// char *str[] = {"a.out", "1 2", "3", "4", "5", "6"};
	// char *str[] = {"a.out", "5", "6", "3", "2", "1 4"};
	char *str[] = {"a.out", "90", "91", "30", "0", "-10 70"};
	t_stack *stack_a;
	t_stack *stack_b;
	
	if (ac < 2)
	{
		ac = 6;
		av = str;
		//return (1);
	}
	if (!arg_checker(ac, av))////	CALL:0:2:1
		return (0);
	stack_b = NULL;
	stack_a = stack_maker(ac, av);//// CONSIDER: moving this to main()
	push_swap(&stack_a, &stack_b);////	CALL:0:3:1:main()
	return (0);
}
//	\/\/\/\/\/\/\/\/\/	OLD MAIN>	\/\/\/\/\/\/\/\/\/*/
////	END:	COPY:	DUMP:

////	OPERATIONS:START:DUMP:

static void swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
	temp = stack->position;
	stack->position = stack->next->position;
	stack->next->position = temp;
}

static void rotate(t_stack **stack)
{
	t_stack	*temporary_stack;
	t_stack	*bottom;

	temporary_stack = *stack;
	*stack = (*stack)->next;
	bottom = find_stack_bottom(*stack);
	temporary_stack->next = NULL;
	bottom->next = temporary_stack;
}


static void reverse_rotate(t_stack **stack)
{
	t_stack	*temporary_stack;
	t_stack	*penultimate;
	t_stack	*bottom;

	temporary_stack = *stack;
	bottom = find_stack_bottom(*stack);
	*stack = bottom;
	(*stack)->next = temporary_stack;
	penultimate = get_penultimate(*stack);
	penultimate->next = NULL;
}

t_stack	*get_penultimate(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
////	OPERATIONS:END:DUMP:
////	PUSH:START:DUMP:
void	push(t_stack **st_from, t_stack **st_to)
{
	t_stack	*stt_t;
	
	if (*st_from == NULL)
		return ;
	stt_t = (*st_from)->next;
	(*st_from)->next = *st_to;
	*st_from = stt_t;
}
////	PUSH:END:DUMP:
////	NAVIGATOR:START:DUMP:

/* specific designations:
	//1:locate stack position/locate index of smallest/next value:
		-[later used to find cost of sorting by index directly]
		-[#CHANGED to PREVIOUS VALUE cus NEXT IS KNOWN]
		-[bro chill i meant like next index]
		-[#OK then maybe suggest using same logic ok sorry]
		-[all good lets add it]
			//t_stack	indexer
			//t_stack	previndex
			//t_stack	nextindex
	//2:compare cost of processing top value:
	//3:compare cost for both stacks:
	//4:output as grid of stats/int*:
*/

t_stack	*navigator(t_stack **st_a, t_stack **st_b, int size)
{
	int		i;
	t_stack	*stack;
	t_stack	*smol;
	t_stack	*prev;

	stack = *st_a;
	smol = smolfind(*st_a, size);
	prevfind(st_a, &smol, size);
	// negalizer(st_a, size);
	// backtracker(&stack, size);
	
	i = 0;
	return (stack);
}

t_stack	*smolfind(t_stack *sss, int size)
{
	t_stack	*smol;
	
	smol = sss;
	while (smol->next != NULL)
	{
		if (smol->position == 1)
			break;
		else if (smol->position != 1)
			smol = smol->next;
	}
	return (smol);
}

void	prevfind(t_stack **sss, t_stack **smol, int size)
{
	int		i;
	t_stack	*stack;
	t_stack	*prev;
	
	stack = *smol;//set stack to smallest position of stack
	prev = *smol;//set previous-smallest
	while (stack->position < size)
	{
		i = 0;//??what am i finding here
		while (i < size && stack->position != (prev->position + 1))
		{
			if (stack->next == NULL)
				stack = *sss;
			else
				stack = stack->next;
			i++;
		}
		if (prev->position == (stack->position) - 1)
		{
			prev->higher = stack;//the next index {make test for size}
			stack->lower = prev;
		}
		indexize(&stack, i);
		prev = stack;//new smaller index
	}
	return ;
}

void		indexize(t_stack **sss, int adj)
{
	t_stack	*stack;
	
	stack = *sss;
	stack->adjacency = adj;
	if (stack->higher != NULL)
		negadjacent(&stack, adj);
}
/* TEST */

void	negalizer(t_stack **st, int	g)
{
	int	i;

	i = 0;
	while (i < g)
	{
		if ((*st)->adjacency > (g - (*st)->index))
			negadjacent(st, g);
		(*st) = (*st)->next;
		i++;
	}
}
void	negadjacent(t_stack **st, int	g)
{
	int	d;//distance
	int	i;
	int	e;//index(own)
	int	f;//index(higher)
	t_stack	*h;

	h = *st;
	i = 0;
	e = h->index;
	f = h->higher->index;
	d = h->adjacency;
	if (d == -1)
	{
		h->adjacency = 0;
		return ;
	}
	if(e + d > g)
	{
		h->adjacency = (f-e);
	}
}
/* TEST */
void		backtracker(t_stack **sss, int siz)
{
	int		i;
	t_stack	*stack;
	t_stack	*bottom;
	
	i = 0;
	bottom = find_stack_bottom(*sss);
	stack = *sss;
	while (stack->position != siz)
	{
		if (stack->next == NULL)
			stack = *sss;
		stack = stack->next;
	}
	*sss = stack;
	while (--siz)
	{
		i = 0;
		while (siz && stack->position != siz)
		{
			if (stack->prev == NULL)
				stack = bottom;
			else
				stack = stack->prev;
			i++;
		}
		if (i < stack->adjacency && stack->lower != NULL)
			stack->adjacency = (i * - 1);
	}	
}
////	NAVIGATOR:END:DUMP:

//	\/\/\/\/\/\/\/\/\/	<NEW MAIN	\/\/\/\/\/\/\/\/\/
/* int	main(void)
{
	char		*str[] = {"push_swap", "1", "3", "2", "4"};
	int		*num[] = {'0', '1', '3', '2', '4'};
	int		cnt = 5;
	t_stack	*aaa;
	t_stack	*bbb;

	bbb = NULL;
	aaa = convertor(num, cnt);
	
} */
//	\/\/\/\/\/\/\/\/\/	NEW MAIN>	\/\/\/\/\/\/\/\/\/


