
///		MAIN:C:
int		main(int argc, char **argv);
void		push_swap(t_stk *s);
void		exec_turk(t_stk **stk);
void		sort_three(t_stk *sta);
t_stk		*three_ops(t_stk *s, int *b);
///		INIT:C:
long		arg_to_int(char *arg, int argn);
int		*arg_to_arr(int *arr, int *argn, char **argv);
int		*arr_normalizer(int *arr, int siz);
t_stk		*arr_to_stk(int *arr, t_stk *s);
int		*arr_transcriber(int *arr, int *brr, int siz);
///		TURK:C:
void		do_moves(t_stk *s, int *a, int *b, int *c);
int		*realign_stack(int *s);
void		realign_or_not(t_stk *s);
void		preen(t_stk *s);
int		bears_come_home(t_stk *s);
///		PUSH:SWAP:C:
t_stk		*push_a(int *a, int *b, t_stk *c);
t_stk		*push_b(int *a, int *b, t_stk *c);
t_stk		*swap_a(t_stk *s);
t_stk		*swap_b(t_stk *s);
t_stk		*swap_s(t_stk *s);
///		ROTATE:C:
void		rotate_a(t_stk *s, int post);
void		rotate_b(t_stk *s, int post);
void		rotate_s(t_stk *s);
///		REVERSE:C:
void		reverse_a(t_stk *s, int post);
void		reverse_b(t_stk *s, int post);
void		reverse_s(t_stk *s);
///		COST:C:
void		get_cost(t_stk *s, int *a, int *b);
void		set_cost(int smaller, int bigger, t_stk *s, int i);
int		*get_collective_cost(int *a, int *b, int *c, t_stk *s);
///		CHECK:C:
bool		arg_duplicate(int *arr);
int		*arg_check(char *arg, int *argn, int j);
bool		unsorted(t_stk *s);
bool		ifnull(t_stk *s);

///		FIND:C:
int		find_next_bigger(int *s, int n);
int		find_next_smaller(int *s, int n);
void		biggest_bois(t_stk *s, int *guys);
int		goldilox(t_stk *s);
///		UTIL:C:
int		get_abs(int num);//return (abs);
void		ft_put(char *str);
void		ft_put_struct(t_stk *stk);
void		ft_clear_values(t_stk *s);
////		ERROR:C:
void		error_end_arr(int *array);
void		error_end_stk(t_stk **s);
///
echo "#include \"push_swap.h\"" >> main.c ;
echo "#include \"push_swap.h\"" >> init.c ;
echo "#include \"push_swap.h\"" >> turk.c ;
echo "#include \"push_swap.h\"" >> push_swap.c ;
echo "#include \"push_swap.h\"" >> rotate.c ;
echo "#include \"push_swap.h\"" >> reverse.c ;
echo "#include \"push_swap.h\"" >> cost.c ;
echo "#include \"push_swap.h\"" >> check.c ;
echo "#include \"push_swap.h\"" >> find.c ;
echo "#include \"push_swap.h\"" >> util.c ;
echo "#include \"push_swap.h\"" >> error.c

echo "#include \"push_swap.h\"" >>