####	2025-04-16 10:26:32

#####	UNTESTED
[changed `push_a` and `push_b` to incorporate `realign_stack`](tempo.c)

#####	TODO:

######	HIGH PRIORITY
-	DO NOT SHOW ERROR IF LIST IS SORTED: SHOW NOTHING
-	test [tempo.c - changes to push_x functions](tempo.c)
-	ADD 'MULTIPLE ZEROES' CONTINGENCY FUNCTIONS:
	-	eg: "00 0000 0002 000200"
	-	(find out which should be treated as valid)
-	consider renaming `novelty name` functions such as:
	-	`bears_come_home`
	-	`biggest_bois`
	-	`preen`
	-	`goldilox`
	-	`ft_liberation`
-	remove superfluous/unused fn's
-	review `error_end_arr` & `error_end_stk` fn's
	-	consider replacing with single `error` fn
		-	[description of new error fn](#new-error-fn)
-	norminette whole folder
-	evaluation preparations:
	-	find evaluation sheet
		-	how many moves permitted?
	-	test based on evaluation sheet
	-	commit and push
######	MEDIUM PRIORITY

######	LOW PRIORITY
-	add algo-improvements if too many moves:
	-	consider adding [similar algorithm for `push back to A` as `push out to B`](#push-back-same-way)
	-	consider [`pushing back to A` before `3 members remaining` threshold](#premature-pushback)

###	new error fn

	should do the following:
		-	take parameters:
			-	stack
			-	arrays
		-	`free` variables
			-	check to avoid dbl free
		-	output `"Error\n"`
		-	stop the program (legally)

###	push back same way
there might be a benefit to considering the `state of stack A` vis-a-vis the `state of stack B` more carefully when pushing back  
for example: if the `bottom of stack B` matches `bottom of stack A` or similar, more than it matches then pushing back  

###	premature pushback
there might be a state, when the benefit of sorting by halfw

##	DEPRECATED

###	AND CHANGED

	t_stk	*push_a(int *a, int *b, t_stk *c);

	t_stk	*push_a(int *a, int *b, t_stk *c)
	{
		int	i;
		int	s;
		int	m;
		int	n;

		i = 0;
		a[0]++;
		s = a[0];
		m = b[1];
		while (i++ < s)
		{
			n = a[i];
			a[i] = m;
			m = n;
		}
		b = realign_stack(b);
		write (1, "pa\n", 3);
		return (c);
	}

	t_stk	*push_b(int *a, int *b, t_stk *c);

	t_stk	*push_b(int *a, int *b, t_stk *c)
	{
		int	i;
		int	s;
		int	m;
		int	n;

		i = 0;
		b[0]++;
		s = b[0];
		m = a[1];
		while (i++ < s)
		{
			n = b[i];
			b[i] = m;
			m = n;
		}
		a = realign_stack(a);
		write (1, "pb\n", 3);
		return (c);
	}

###	AND REMOVED

####	realign_stack

	int		*realign_stack(int *s);  

	int	*realign_stack(int *s)
	{
		int	i;
		int	m;
		int	n;

		if (s[0] > 0)
		{
			i = s[0];
			m = s[i];
			s[i] = 0;
			while (i-- != 1)
			{
				n = s[i];
				s[i] = m;
				m = n;
			}
		}
		else
			s[1] = 0;
		s[0]--;
		return (s);
	}

####	ft_put_ops

	void	ft_put_ops(t_stk *s)
	
	void	ft_put_ops(t_stk *s)
	{
		int	i;

		i = 0;
		put_num(s->ops[0]);
		while (i++ < s->ops[0])
			ft_scrbl(s, i);
		printf("MOVES:\n%d\n", s->ops[0]);
		printf("MOVES:\n%d\n", s->steps);
	}

####	ft_put_struct

	void	ft_put_struct(t_stk *stk);
	
	void	ft_put_struct(t_stk *stk)
	{
		int	i;

		i = 1;
		while (i <= stk->a[0] || i <= stk->b[0])
		{
			printf("a: ");
			if (stk->a[0] == 0 || stk->a[0] < i)
				printf("-\t");
			else if (i <= stk->a[0])
				printf("%d\t", stk->a[i]);
			printf("b: ");
			if (stk->b[0] == 0 || stk->b[0] < i)
				printf("-");
			else if (i <= stk->b[0])
				printf("%d", stk->b[i]);
			printf("\n");
			i++;
		}
		printf("\n");
	}


####	ft_scrbl

	void	ft_scrbl(t_stk *s, int i);

	void	ft_scrbl(t_stk *s, int i)
	{	
		if (s->ops[i] == 1)
			ft_put("pa");
		if (s->ops[i] == 2)
			ft_put("pb");
		if (s->ops[i] == 3)
			ft_put("sa");
		if (s->ops[i] == 4)
			ft_put("sb");
		if (s->ops[i] == 5)
			ft_put("ss");
		if (s->ops[i] == 6)
			ft_put("ra");
		if (s->ops[i] == 7)
			ft_put("rb");
		if (s->ops[i] == 8)
			ft_put("rr");
		if (s->ops[i] == 9)
			ft_put("rra");
		if (s->ops[i] == 10)
			ft_put("rrb");
		if (s->ops[i] == 11)
			ft_put("rrr");
	}

####	put_num

	void	put_num(int num);
	void	put_num(int num)
	{
		int	mem;
		int	len;
		char	*digit;

		if (num == 0)
			return ;
		mem = num;
		len = 0;
		while (mem /= 10)
			len++;
		digit = (char *)malloc(len + 1);
		mem = num;
		digit = ft_itoa(num, digit, 0);
		// digit = ft_rev_str(digit, len);
		while (len)
			write (1, &digit[len--], 1);
	}

####	ft_keep_op

	void	ft_keep_op(char *op, t_stk *s);

	void	ft_keep_op(char *op, t_stk *s)
	{
		int	i;

		i = ++s->ops[0];
		if (op[0] == 'p' && op[1] == 'a')//pa
			s->ops[i] = 1;
		else if (op[0] == 'p' && op[1] == 'b')//pb
			s->ops[i] = 2;
		else if (op[0] == 's' && op[1] == 'a')//sa
			s->ops[i] = 3;
		else if (op[0] == 's' && op[1] == 'b')//sb
			s->ops[i] = 4;
		else if (op[0] == 's' && op[1] == 's')//ss
			s->ops[i] = 5;
		else if (op[0] == 'r' && op[1] == 'a')//ra
			s->ops[i] = 6;
		else if (op[0] == 'r' && op[1] == 'b')//rb
			s->ops[i] = 7;
		else if (op[0] == 'r' && op[1] == 'r' && op[2] == '\0')//rr
			s->ops[i] = 8;
		else if (op[2] == 'a' && op[3] == '\0')//rra
			s->ops[i] = 9;
		else if (op[2] == 'b' && op[3] == '\0')//rrb
			s->ops[i] = 10;
		else if (op[2] == 'r' && op[3] == '\0')//rrr
			s->ops[i] = 11;
	}

####	ft_itoa

	char *ft_itoa(int num, char *str, int i);

	char *ft_itoa(int num, char *str, int i)
	{
		int	digit;

		if (num == 0)
			return (str);
		digit = num % 10;
		str[i++] = digit + '0';
		return (ft_itoa(num / 10, str, i));
	}

####
####