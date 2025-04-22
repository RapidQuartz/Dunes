##	DONE

###	FINISHED

###	UNTESTED
[changed `push_a` and `push_b` to incorporate `realign_stack`](tempo.c)
##	TODO:
###	Add functions to .h:
- [ ] void	do_flag(t_stk *s)
- [ ] void	first_moves(t_stk *s)
- [ ] void	ft_put_steps(int steps)



###	EDGE CASES


- [ ] "00 0000 0002 000200"
- [ ] "12-31" reads as "-1231"

###	HIGH PRIORITY
-	DO NOT SHOW ERROR IF LIST IS SORTED: SHOW NOTHING
- [x] test [tempo.c - changes to push_x functions](tempo.c)
- [ ] ADD 'MULTIPLE ZEROES' CONTINGENCY FUNCTIONS:

-	consider renaming `novelty name` functions such as:
	- [ ] `bears_come_home`
	- [ ] `biggest_bois`
	- [ ] `preen`
	- [ ] `goldilox`
	- [ ] `ft_liberation`
- [ ] remove superfluous/unused fn's
- [ ] review `error_end_arr` & `error_end_stk` fn's
	- [ ] [consider replacing with single `error` fn](#new-error-fn)
-	norminette whole folder
-	evaluation preparations:
	-	find evaluation sheet
		-	how many moves permitted?
	-	test based on evaluation sheet
	-	commit and push
###	MEDIUM PRIORITY

###	LOW PRIORITY
-	add flags:  
	-c *show move count*  
	-v *visualize stacks*  
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
there might be a state, when the benefit of sorting by pushing back halfway, outweighs the benefit of pushing until *A* is empty

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
####	permitted chars

0	-		PERM_NULL = '\0'
1	-		PERM_MIN = '-'
2	-		PERM_PLU = '+'
3	-		PERM_ZERO = '0'
4	-		PERM_ONE = '1'
5	-		PERM_TWO = '2'
6	-		PERM_THREE = '3'
7	-		PERM_FOUR = '4'
8	-		PERM_FIVE = '5'
9	-		PERM_SIX = '6'
10	-		PERM_SEVEN = '7'
11	-		PERM_EIGHT = '8'
12	-		PERM_NINE = '9'
13	-		PERM_SPACE = ' '
14	-		PERM_TAB = '\t'
15	-		PERM_NEW = '\n'

####	permitted flags

0	-		PERM_NULL = '\0'
	//	ends processing
1	-		PERM_MIN = '-'
	//	forbids flag 1/2
2	-		PERM_PLU = '+'
	//	forbids flag 1/2

####	permitted args

3	-		PERM_ZERO = '0'
4	-		PERM_ONE = '1'
5	-		PERM_TWO = '2'
6	-		PERM_THREE = '3'
7	-		PERM_FOUR = '4'
8	-		PERM_FIVE = '5'
9	-		PERM_SIX = '6'
10	-		PERM_SEVEN = '7'
11	-		PERM_EIGHT = '8'
12	-		PERM_NINE = '9'

####	permitted whitespace

13	-		PERM_SPACE = ' '
14	-		PERM_TAB = '\t'
15	-		PERM_NEW = '\n'

####	permitted end
0	-		PERM_NULL = '\0'

####

0     NUL '\0' (null character)   
1     SOH (start of heading)      
2     STX (start of text)         
3     ETX (end of text)           
4     EOT (end of transmission)   
5     ENQ (enquiry)               
6     ACK (acknowledge)           
7     BEL '\a' (bell)             
8     BS  '\b' (backspace)        
9     HT  '\t' (horizontal tab)   
10    LF  '\n' (new line)         
11    VT  '\v' (vertical tab)     
12    FF  '\f' (form feed)        
13    CR  '\r' (carriage ret)     
14    SO  (shift out)             
15    SI  (shift in)              
16    DLE (data link escape)      
17    DC1 (device control 1)      
18    DC2 (device control 2)      
19    DC3 (device control 3)      
20    DC4 (device control 4)      
21    NAK (negative ack.)         
22    SYN (synchronous idle)      
23    ETB (end of trans. blk)     
24    CAN (cancel)                
25    EM  (end of medium)         
26    SUB (substitute)            
27    ESC (escape)                
28    FS  (file separator)        
29    GS  (group separator)       
30    RS  (record separator)      
31    US  (unit separator)        
32    SPACE                       
33    !                           
34    "                           
35    #                           
36    $                           
37    %                           
38    &                           
39    '                           
40    (                           
41    )                           
42    *                           
43    +                           
44    ,                           
45    -                           
46    .                           
47    /                           
48    0                           
49    1                           
50    2                           
51    3                           
52    4                           
53    5                           
54    6                           
55    7                           
56    8                           
57    9                           
58    :                           
59    ;                           
60    <                           
61    =                           
62    >                           
63    ?                           
64    @
65    A
66    B
67    C
68    D
69    E
70    F
71    G
72    H
73    I
74    J
75    K
76    L
77    M
78    N
79    O
80    P
81    Q
82    R
83    S
84    T
85    U
86    V
87    W
88    X
89    Y
90    Z
91    [
92    \  '\\'
93    ]
94    ^
95    _
96    `
97    a
98    b
99    c
100   d
101   e
102   f
103   g
104   h
105   i
106   j
107   k
108   l
109   m
110   n
111   o
112   p
113   q
114   r
115   s
116   t
117   u
118   v
119   w
120   x
121   y
122   z
123   {
124   |
125   }
126   ~
127   DEL