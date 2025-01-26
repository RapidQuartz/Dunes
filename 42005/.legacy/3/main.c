/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:13:44 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/26 15:45:17 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
t_stack	*stack_maker(int ac, char **av);
t_stack	*new_stack_entry(int value, t_stack *prev);
t_stack	*find_stack_bottom(t_stack *stack);
void		add_to_bottom(t_stack **stack, t_stack *new);
void		give_stack_position(t_stack *stack, int size);
int		get_stack_size(t_stack *stack);
void		free_memory(t_stack **stack);
////	SORTING:
void		sort(t_stack **st_a, t_stack **st_b, int size);
////	END:
////	TODO:	make error funct


//OLD//
	//	int	iv_space_check(char a);
	//	int	iv_minplus_check(char a);
	//	int	iv_num_check(char a);


////	CALL:0:3:1:main()
////	TODO: make a thing
////	TODO: move to own file
void		push_swap(t_stack **st_a, t_stack **st_b)
{
	int		size;
/*DEBUG*/
	t_stack	*stt_a;
	t_stack	*stt_b;
	t_stack	*stt_t;
	
	stt_a = *st_a;
	stt_b = *st_b;
	stt_t = *st_a;
/*DEBUG*/
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
	sort(st_a, st_b, size);
	free_memory(st_a);
	free_memory(st_b);
}

////	FUNC:stack_maker()
////	:initializes stack, populates with values from arg, acquired from [HELPER]
////	TODO: make a thing
	//	new-stack-entry
	//	find-stack-bottom
	//	add-to-bottom
	//	give-stack-index
	//	find-stack-position
	//	give-stack-position
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
	}
	new->position = 0;
	new->adjacency = 0;
	new-> higher = NULL;
	new-> lower = NULL;
	new->prev = NULL;
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

////	CONSIDER:
////	using other variables to keep track of which argument is handled
////	if an = 3
////	then [juggle the values] -> send [1] to get_number()
////	use AC to store?
////	use NUM to store?
////	CHANGE:
////	moving [DEX] for index, to another place
////		ALTERNATIVELY:
////		send to indexer as part of make stack
////		ALTERNATIVELY:
////		send 'prev stack' to 'add to stack'
////		
////	

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



////	FUNC:arg_checker()
////	CALL:0:2:1:main()
////	TODO: <1>
////	TODO: <2>
////	TODO: <4>	make it count spaced args better
////	TODO: <5>	check for duplicates
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
////	FUNC:duplicate_checker()
////	DOES:checks for duplicates
void	duplicate_checker(t_stack **sss)
{
	t_stack	*t;
	t_stack	*p;
	int	d;
	int	i;

	t = (*sss);
	p = (*sss)->next;
	d = 0;
	i = 0;
	while (p != NULL)
	{
		i = t->value;
		while (d == 0 && p != NULL)
		{
			if (p->value == i)
				d++;
			else
				p = p->next;
			if (d > 0)
				error_handling(sss, NULL);
		}
		p = t->next->next;
		t = t->next;
	}
	return ;
}
////	FUNC:arg_counter()
////	CALL:
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



////	FUNC:iv_checker()
////	CONSIDER: returning meaningful values (if last state, add argument)
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

////	FUNC:main()
////	CALL:0:0:1:argc_dummy()// OLD
////	CALL:0:1:1:argv_dummy()// OLD
////	CALL:0:2:1:arg_checker()
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
	duplicate_checker(&stack_a);
	push_swap(&stack_a, &stack_b);////	CALL:0:3:1:main()
	return (0);
}
/*



















*/
/* OLD:14.01:11:57.
int	iv_checker(char a, char b)
{
	if ((b == ' ') && (a == ' ' || a == '-' || a == '+' || \
	(a >= '0' && a <= '9')))
			return (1);
	if ((b == '-' || b == '+') && (a >= '0' && a <= '9'))
			return (1);
	if ((b <= '9' && b >= '0') && ((a == ' ') || (a == '\0') || \
	(a >= '0' && a <= '9')))
			return (1);
	return (0);
}
int	iv_space_check(char a)
{
	if (a == ' ' || a == '-' || a == '+' || \
	(a >= '0' && a <= '9'))
		return (1);
	return (0);
}
////	:::	[space->space]
////	:::	[space->minus]
////	:::	[space->plus]
////	:::	[space->number]

int	iv_minplus_check(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}
////	:::	[minus->number]
////	:::	[plus->number]
int	iv_num_check(char a)
{
	if ((a == ' ') || (a == '\0') || (a >= '0' && a <= '9'))
		return (1);
	return (0);
}
////	:::	[number->space]
////	:::	[number->number]
////	:::	[number->'\0']
 */
////	DUMP:
////	:
	/*
		// if ((av[i] == ' ') && !iv_spacecheck(av[i + 1]))
		if (av[i] == ' ')
			f = 1;
		// if ((av[i] == '-' || av[i] == '+') && !(iv_pmcheck(av[i + 1])))
		if (av[i] == '-' || av[i] == '+')
			f = 2;
		// if ((av[i] <= '9' && av[i] >= '0') && !iv_numcheck(av[i + 1]))
		if (av[i] <= '9' && av[i] >= '0')
			f = 3; */
////	:
//
	/* 

		// {
		// 	// if ((av[i] == ' ') && !iv_spacecheck(av[i + 1]))
		// 	if (av[i] == ' ')
		// 		f = 1;
		// 	// if ((av[i] == '-' || av[i] == '+') && !(iv_pmcheck(av[i + 1])))
		// 	if (av[i] == '-' || av[i] == '+')
		// 		f = 2;
		// 	// if ((av[i] <= '9' && av[i] >= '0') && !iv_numcheck(av[i + 1]))
		// 	if (av[i] <= '9' && av[i] >= '0')
		// 		f = 3;

		// }
 */
////	:
////	:

////	HELPER: is_valid
////	: returns 1 if string is valid
////	::	order
////		::	first character:
////	:a:		[space]
////	:b:		[minus]
////	:c:		[plus]
////	:d:		[number]
////	:d:		['\0']
////	:e:		[other]
////		::	next character
//:a:[space]
//:b:[minus]
//:c:[plus]
//:d:[number]
//:e:['\0']
//:f:[other]
//		[VALID]
//		{INVALID}
////	HELPER: valid_helper
// int	valid_helper(int flag, char *av, int i)
// {

// }
////	HELPER: isnum
////	: returns 0 if "is not number"
////	: returns 1 if "is number"
// int	is_num(char a)
// {

// }

////	DO:NOT:USE::TEMP:
////	:takes:string from argv:::
////	:iterates:through this and checks each byte:::
////	:returns::1:valid::0:invalid:::
int	is_valid(char *av)
{
	int	i;
	int	f;
	char	p;

	f = 0;
	while (av[i] != '\0')
	{
		p = av[i];
		i++;
		if (!validity_checker(av[i], p))
			return (0);
	}
	return (1);
}
////	HELPER: isminpluspa
////	HELPER: isspace
////	HELPER: atoi
////	HELPER: argcounter
////	IDEA: save index of number in another value


////	:doodlings on valid sequences:
////	::a:		[space]
//:a::a://		[VALID]
//:a::b://		[VALID]
//:a::c://		[VALID]
//:a::d://		[VALID]
//:a::e:		{INVALID}
//:a::f:		{INVALID}
////	:::b:		[minus]
//:b::a:		{INVALID}
//:b::b:		{INVALID}
//:b::c:		{INVALID}
//:b::d:		[VALID]
//:b::e:		{INVALID}
//:b::f:		{INVALID}
////	:::c:		[plus]
//:c::a:		{INVALID}
//:c::b:		{INVALID}
//:c::c:		{INVALID}
//:c::d:		[VALID]
//:c::e:		{INVALID}
//:c::f:		{INVALID}
////	:::d:		[number]
//:d::a:		[VALID]
//:d::b:		{INVALID}
//:d::c:		{INVALID}
//:d::d:		[VALID]
//:d::e:		[VALID]
//:d::f:		{INVALID}
////	:::e:		['\0']
//:e::a:		{INVALID}
//:e::b:		{INVALID}
//:e::c:		{INVALID}
//:e::d:		{INVALID}
//:e::e:		{INVALID}
//:e::f:		{INVALID}
////	:::f:		[other]
//:f::a:		{INVALID}
//:f::b:		{INVALID}
//:f::c:		{INVALID}
//:f::d:		{INVALID}
//:f::e:		{INVALID}
//:f::f:		{INVALID}
////	:
////	: returns 0 if string is invalid
////	::
////	::
////	:::a:		[space->]
//[space->space] :a::a://		[VALID]
//[space->minus] :a::b://		[VALID]
//[space->plus] :a::c://		[VALID]
//[space->number] :a::d://		[VALID]
////	:::b:		[minus->]
//[minus->number] :b::d:		[VALID]
////	:::c:		[plus->]
//[plus->number] :c::d:			[VALID]
////	:::d:		[number->]
//[number->space] :d::a:		[VALID]
//[number->number] :d::d:		[VALID]
//[number->'\0'] :d::e:			[VALID]
////	::
////	::there are 9 valid sequences:
////	:::	[space->space]
////	:::	[space->minus]
////	:::	[space->plus]
////	:::	[space->number]
////	:::	[minus->number]
////	:::	[plus->number]
////	:::	[number->space]
////	:::	[number->number]
////	:::	[number->'\0']
////	::
////	::if value is on one of 5 spots it is valid if one of the states is true
////	::4 checks for space
////	::1 check for minus
////	::1 check for plus
////	::3 checks for number

////	TODO: <1>: consider removing ac argument, or use for max/index
////	TODO: <2>: make arg check return the arg num, using ac to limit traversal, and returning number of valid arguments, or negative/zero if invalid.
////	TODO: <3>: consider moving `argn` to within stack maker
	//		too many params to send both argn and argc to stack maker
////	TODO: <>: 