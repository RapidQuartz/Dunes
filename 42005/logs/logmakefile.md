# [log about the makefile](logmakefile.md)

####	log 2025-01-23 15:27:45
*	copied fn names to .h file
*	reduced functions that are unused
-	makefile test:
-	:	makefile should be able to produce something
-	:	provided compilation works
-	:	during compilation errors and bugs will appear
-	:	following makefile test, smallsort will be made
-	:	or if i get bored tbh


#	FUNCTIONS
#	[push_swap.h](push_swap.h)
void		dd(void (*f)(t_stack **, t_stack **), t_stack **fs);
void		do_double(void (*f)(t_stack **), t_stack **fst);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_swap(t_stack **stack);
void		do_sa(t_stack **stack);
void		do_sb(t_stack **stack);
int		analyzer(t_stack **stack);
void		sorter(t_stack **stack_a, t_stack **stack_b, int size);
void		dosort_abc(t_stack **stack, t_stack **kcats, int flag);
void		dosort_def(t_stack **stack, t_stack **kcats, int flag);
int		issorted(t_stack **stack_a);
void		push_swap(t_stack **st_a, t_stack **st_b);
t_stack	*stack_maker(int ac, char **av);
t_stack	*new_stack_entry(int value, t_stack *prev);
t_stack	*find_stack_bottom(t_stack *stack);
void		add_to_bottom(t_stack **stack, t_stack *new);
void		give_stack_position(t_stack *stack, int size);
int		get_stack_size(t_stack *stack);
long    	get_number(char *arg, int argn);
int		arg_checker(int ac, char **av);
int		arg_counter(char *av);
int		validity_checker(char a, char b);
void		free_memory(t_stack **stack);
t_stack	*navigator(t_stack **st_a, t_stack **st_b, int size);
t_stack	*smolfind(t_stack *sss, int size);
void		prevfind(t_stack **sss, t_stack **smol, int size);
void		indexize(t_stack **sss, int adj, int siz);
static void swap(t_stack *stack);
static void rotate(t_stack **stack);
static void reverse_rotate(t_stack **stack);
t_stack	*find_penultimate(t_stack *stack);
void	push(t_stack **st_from, t_stack **st_to);

##	[do_ops.c](do_ops.c)
void		dd(void (*f)(t_stack **, t_stack **), t_stack **fs
void		do_double(void (*f)(t_stack **), t_stack **fst)
void		do_pa(t_stack **stack_a, t_stack **stack_b)
void		do_pb(t_stack **stack_a, t_stack **stack_b)
void		do_sa(t_stack **stack)
void		do_sb(t_stack **stack)
void		do_ra(t_stack **stack)
void		do_rb(t_stack **stack)
void		do_rra(t_stack **stack)
void		do_rrb(t_stack **stack)

##	[algorithm.c](algorithm.c)
int		analyzer(t_stack **stack)
void		sorter(t_stack **stack_a, t_stack **stack_b, int size)
void		dosort_abc(t_stack **stack, t_stack **kcats, int flag)
void		dosort_def(t_stack **stack, t_stack **kcats, int flag)
int		issorted(t_stack **stack_a)

##	[main.c](main.c)
void		push_swap(t_stack **st_a, t_stack **st_b)
t_stack	*stack_maker(int ac, char **av)
t_stack	*new_stack_entry(int value, t_stack *prev)
t_stack	*find_stack_bottom(t_stack *stack)
void		add_to_bottom(t_stack **stack, t_stack *new)
void		give_stack_position(t_stack *stack, int size)
int		get_stack_size(t_stack *stack)
long    	get_number(char *arg, int argn)
int		arg_checker(int ac, char **av)
int		arg_counter(char *av)
int		validity_checker(char a, char b)
void		free_memory(t_stack **stack)

##	[navigator.c](navigator.c)
t_stack	*navigator(t_stack **st_a, t_stack **st_b, int size)
t_stack	*smolfind(t_stack *sss, int size)
void	prevfind(t_stack **sss, t_stack **smol, int size)
void		indexize(t_stack **sss, int adj, int siz)

##	[operations.c](operations.c)
static void swap(t_stack *stack)
static void rotate(t_stack **stack)
static void reverse_rotate(t_stack **stack)
t_stack	*find_penultimate(t_stack *stack)

##	[push.c](push.c)
void	push(t_stack **st_from, t_stack **st_to)

##	[push_swap.c](push_swap.c)


[]()

[]()