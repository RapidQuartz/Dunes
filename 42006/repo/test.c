#include "libft/libft.h"
/* compilation string:
cc -g test.c -Llibft -lft
*/
typedef struct	s_map
{
	int			l_num;
	char			**lines;
	struct s_map	*next;
}	t_map;
void	print(char *str)
{
ft_printf("\n//ft_printf writes and returns number of written characters\n");
ft_printf("ft_printf(str): %s\n",str);
}

t_map	*f_map(char	**lines, int l_num)
{
	t_map	*map;
	t_map	*tmp;
	t_map	*head;
	int	i;
	char	d;

	i = 0;
	d = ' ';
	map = NULL;
	tmp = NULL;
	while (i < l_num)
	{
		map = malloc(sizeof(*map));
		if (i == 0)
		{
			if (!map || map == NULL)
				return (NULL);
			else
				head = map;
		}
		else if (i > 0 && tmp && tmp != NULL && (!map || map == NULL))
		{
			while (tmp != NULL)
			{
				if (tmp->next != NULL)
				{
					map = tmp->next;
					free (tmp);
					tmp = map;
				}
				else if (tmp->next == NULL)
				{
					free (tmp);
					return (NULL);
				}
			}
		}
		if (i < l_num && tmp != NULL)
			tmp->next = map;
		map->lines = ft_split(lines[i], d);
		map->l_num = i++;
		map->next = NULL;
		if (l_num > i)
			tmp = map;
	}
	return (head);
}
//	ft_split test
void	f_split(void)
{
	int	i;
	int	j;
	char	*num;
	char	**nums;
	char	delim;
	t_map	*map;

	map = NULL;
	i = 0;
	j = 0;
	delim = '\n';
	num = ft_strdup("0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0\n0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0\n0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0\n0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0\n0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0\n0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0\n0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0\n0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0\n0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0\n0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0\n0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0\n");
	nums = ft_split(num, delim);
	ft_printf("\n//ft_split returns the string split by AND EXCLUDING delimiters\n{\n");
	while (nums[i] != NULL)
	{
		// ft_printf("<%s>\n", arr[i]);
		ft_printf("<%s>\n", nums[i]);
		i++;
	}
	ft_printf("}\n");
	ft_printf("END OF TEST, NOW COMES THE HARD PART\n");
	map = f_map(nums, i);
	if (!map || map == NULL)
		return ;
	while (map)
	{
		j = 0;
		ft_printf("\n<line:%d<\n", map->l_num);
		while (map->lines[j] != NULL)
			ft_printf("<%s>", map->lines[j++]);
		ft_printf("\n>map->next: %p>\n", map->next);
		if (map->next != NULL)
			map = map->next;
		else
			break ;
	}
	ft_printf("OK DID IT WORK???\n");
}

//	ft_strchr test
void	f_strchr(void)
{
		char	*str;
	char	delim;
	str = ft_strdup("This is the destination.");
	delim = ' ';

	ft_printf("\n//ft_strchr returns the FIRST instance AFTER AND INCLUDING the delimiter\n");
	ft_printf("ft_strchr: <%s>\n", ft_strchr(str, delim));
}

//	ft_strrchr test
void	f_strrchr(void)
{
	char	*str;
	char	delim;

	str = ft_strdup("This is the destination.");
	delim = ' ';
	ft_printf("\n//ft_strrchr returns the LAST instance AFTER AND INCLUDING the delimiter\n");
	ft_printf("ft_strrchr: <%s>\n", ft_strrchr(str, delim));
}

//	ft_atoi test
void	f_atoi(void)
{
	char	*nums;

	nums = ft_strdup("42 314 ");
	ft_printf("\n//ft_atoi returns the numeric value of the first number in a string of numbers\n");
	ft_printf("%d", ft_atoi(nums));
}

//	ft_bzero test
void	f_bzero()
{
	char	*str;
	int	n;

	str = ft_strdup("This is the destination.");
	n = 10;
	ft_printf("\n//ft_bzero returns nothing but nulls out n (10) bytes from string s (\"This is the destination.\")\n");
	ft_printf("BEFORE: <%s>\n", str);
	ft_bzero(str, n);
	ft_printf("AFTER: <%s>\n", str);
}

//	ft_calloc test
void	f_calloc()
{
	int	n;
	int	m;
	char	*arr;
	int	i;
	
	n = 6;
	m = 4;
	i = 0;
	ft_printf("\n//ft_calloc returns a void * pointer to a section of memory with n members of m bytes\n");
	arr = (char *)ft_calloc(n, m);
	while (arr && arr != NULL && arr[i] != '\0')
		ft_printf("%s\n", arr[i++]);
	ft_printf("}\n");
}

// //	ft_isalnum test
void	f_isalnum(void)
{
	char	c;
	char	v;

	c = 'A';
	v = '0';
	ft_printf("\n//ft_isalnum returns char c IF it is alphanumeric\n");
	ft_printf("(valid): %c\n", ft_isalnum(c));
	ft_printf("(invalid): %c\n", ft_isalnum(v));
}

// //	ft_isalpha test
void	f_isalpha(void)
{
	char	c;
	char	v;

	c = 'A';
	v = '0';
	ft_printf("\n//ft_isalpha returns char c IF it is alphabetic\n");
	ft_printf("(valid): %c\n", ft_isalpha(c));
	ft_printf("(invalid): %c\n", ft_isalnum(v));
}

// //	ft_isascii test
void	f_isascii(void)
{
	char	c;
	char	v;

	c = 'A';
	v = '\n';
	ft_printf("\n//ft_isascii returns char c IF it is ascii\n");
	ft_printf("(valid): %c\n", ft_isascii(c));
	ft_printf("(invalid): %c\n", ft_isalnum(v));
}

// //	ft_isdigit test
void	f_isdigit(void)
{
	char	c;
	char	v;

	c = '0';
	v = 'A';
	ft_printf("\n//ft_isdigit returns char c IF it is digit\n");
	ft_printf("(valid): %c\n", ft_isdigit(c));
	ft_printf("(invalid): %c\n", ft_isalnum(v));
}

// //	ft_isprint test
void	f_isprint(void)
{
	char	c;
	char	v;

	c = '\t';
	v = 13;
	ft_printf("\n//ft_isprint returns char c IF it is printable\n");
	ft_printf("(valid): %c\n", ft_isprint(c));
	ft_printf("(invalid): %c\n", ft_isalnum(v));
}

// //	ft_itoa test
void	f_itoa(void)
{
	int	num;

	num = ft_atoi("42 314 ");
	ft_printf("\n//ft_itoa returns a char * made of the number provided\n");
	ft_printf("%s\n", ft_itoa(num));
}

// //	ft_memchr test
void	f_memchr(void)
{
	char		*str;
	char		c;
	size_t	n;

	str = ft_strdup("This is the destination.");
	c = 'd';
	n = 15;
	ft_printf("\n//ft_memchr returns a char * pointer, advancing a maximum of n (%u) bytes, to the first occurrence of a character c (%c) in a string s (%s)\n", n, c, str);
	ft_printf("%s\n", (char *)ft_memchr(str, c, n));
}

// //	ft_memcmp test
void	f_memcmp(void)
{
	char	*s1;
	char	*s2;
	int	n;

	s1 = "a special surprise for the children\n";
	s2 = "a special suprise for the children\n";
	n = 21;
	ft_printf("\n//ft_memcmp returns an int depending on input strings s1 and s2, while traversing n bytes. If they are identical, it returns 0. If they are dissimilar, it returns the value of s1[i] - s2[i]\n");
	ft_printf("%d\n", ft_memcmp(s1, s2, n));
}

// //	ft_memcpy test
void	f_memcpy(void)
{
	char		*dest;
	char		*src;
	size_t	n;

	dest = ft_strdup("this is the destination");
	src = ft_strdup("this is the source");
	n = ft_strlen(dest);
	ft_printf("\n//ft_memcpy returns a void * pointer to a copy of string *src so long as it is not identical to string *dest, up to n bytes\n");
	ft_printf("%s\n", ft_memcpy(dest, src, n));
}

// //	ft_memmove test
void	f_memmove(void)
{
	char		*dest;
	char		*src;
	size_t	n;

	dest = ft_strdup("this is the destination");
	src = ft_strdup("this is the source");
	n = ft_strlen(dest);
	ft_printf("\n//ft_memmove returns a void * pointer which, depending on the size of input strings *dest (%s) and *src (%s) , either copies forwards up to n (%u) bytes (when dest is smaller than src) or backwards from n bytes (when src is smaller than dest)\n", dest, src, n);
	ft_printf("%s\n", ft_memmove(dest, src, n));
}

// //	ft_memset test
void	f_memset(void)
{
	char		*src;
	char		c;
	size_t	n;

	src = ft_strdup("this is the source");
	c = 'x';
	n = ft_strlen(src) - 6;
	ft_printf("\n//ft_memset returns a void * pointer to a string s (\"this is the source\"), which is filled up to n (strlen - 6) bytes with a character c (\"x\")\n");
	ft_printf("%s\n", ft_memset(src, c, n));
}

// //	ft_putchar_fd test
void	f_putchar_fd(void)
{
	char	c;
	int	fd;

	c = 'N';
	fd = 1;
	ft_printf("\n//ft_putchar_fd returns nothing, but uses write to print character c (\"N\") to file descriptor fd (\"1\")\n<");
	ft_putchar_fd(c, fd);
	ft_printf(">\n");
}

// //	ft_putendl_fd test
void	f_putendl_fd(void)
{
	char		*src;
	int		fd;

	src = ft_strdup("this is the source");
	fd = 1;
	ft_printf("\n//ft_putendl_fd returns nothing, but uses write to print string s (\"%s\") to file descriptor int fd (%d)\n", src, fd);
	ft_putendl_fd(src, fd);
}

//	ft_putnbr_fd test
void	f_putnbr_fd(void)
{
	int		n;
	int		fd;

	n = 1024;
	fd = 1;
	ft_printf("\n//ft_putnbr_fd returns nothing, but puts a number int n (%d) to file descriptor int fd (%d)\n", n, fd);
	ft_putnbr_fd(n, fd);
}

//	ft_putstr_fd test
void	f_putstr_fd(void)
{
	char		*src;
	int		fd;

	src = ft_strdup("this is the source");
	fd = 1;
	ft_printf("\n//ft_putstr_fd returns nothing, but uses write to print string s (\"%s\") to file descriptor int fd (%d)\n", src, fd);
	ft_putstr_fd(src, fd);
}

//	ft_strdup test
void	f_strdup(void)
{
	char		*src;

	src = ft_strdup("this is the source");
	ft_printf("\n//ft_strdup returns a pointer to a copy of string char *s\n");
	ft_printf("%s", ft_strdup(src));
}

//	ft_striteri test
void	f_striteri(void)
{
	char	*src;

	src = ft_strdup("duplication on duplication");
	ft_printf("\n//ft_striteri returns nothing, but applies a function (*f)(unsigned int, char*) to a string char *str (%s)\n", src);
	ft_printf("ERROR THIS DOES NOT WORK GET GOOD SCRUB!!\n");
	// ft_striteri(src, (char *)ft_strjoin(src, src));
	// while (src != NULL && *src != NULL)
	// 	ft_printf("<%s>\n", src++);
}

//	ft_strjoin test
void	f_strjoin(void)
{
	char	*src;
	src = ft_strdup("duplication on ");
	ft_printf("\n//ft_strjoin returns a pointer to a joining of two strings char *s1 and char *s2\n");
	ft_printf("%s\n", ft_strjoin(src, src));
}

//	ft_strlcat test
void	f_strlcat(void)
{
	char		*src;
	char		*dst;
	size_t	size;
	
	src = ft_strdup("toast for a change");
	dst = ft_strdup("duplication on ");
	size = ft_strlen(dst) + 6;
	ft_printf("\n//ft_strlcat returns a concatenated string made from char *src added to the end of char *dst, provided the current size of dst is smaller than t_size size + 1.\n");
	ft_strlcat(dst, src, size);
	ft_printf("<%s>\n", dst);
}

//	ft_strlcpy test
void	f_strlcpy(void)
{
	char		*src;
	char		*dst;
	size_t	size;
	
	src = ft_strdup("toast for a change");
	dst = ft_strdup("duplication on ");
	size = ft_strlen(dst) + 6;
	ft_printf("\n//ft_strlcpy returns ft_strlen(src) after copying the contents of src (\"%s\") up to size (%u) bytes, to the string dst (\"%s\"), and null terminates the string it changes.\n", src, size, dst);
	ft_strlcpy(dst, src, size);
	ft_printf("dst: %s\nsrc: %s\n", dst, src);
}

//	ft_strlen test
void	f_strlen(void)
{
	char		*src;

	src = ft_strdup("toast for a change\0\0\0\0");
	ft_printf("\n//ft_strlen returns size_t which reflects the length of a string str (\"%s\")(until the string is '0' (22), not just null terminated (18))\n");
	ft_printf("%u\n", ft_strlen(src));
}

//	ft_strmapi test
void	f_strmapi(void)
{
	char	*src;

	src = ft_strdup("duplication on duplication");
	ft_printf("\n//ft_strmapi returns a string char * that has been put through a function (f*)(unsigned int, char)\n");
	ft_printf("ERROR THIS DOES NOT WORK GET GOOD SCRUB!!\n");
	// ft_printf("%s\n", src);
	// ft_strmapi(src, ft_memset(src, ' ', 20));
	// ft_printf("%s\n", src);
}

//	ft_strncmp test
void	f_strncmp(void)
{

	char	*s1;
	char	*s2;
	int	n;

	s1 = "a special surprise for the children\n";
	s2 = "a special suprise for the children\n";
	n = 21;
	ft_printf("\n//ft_strncmp returns an int depending on input strings s1 and s2, while traversing n bytes. If they are identical, it returns 0. If they are dissimilar, it returns the value of s1[i] - s2[i]\n{{{I DONT KNOW THE DIFFERENCE BETWEEN MEMCMP AND STRNCMP}}}");
	ft_printf("%d\n", ft_strncmp(s1, s2, n));
}

//	ft_strnstr test
void	f_strnstr(void)
{
	char		*needle;
	char		*haystack;
	size_t	n;
	needle = ft_strdup("needle");
	haystack = ft_strdup("it's basically how to find a needle in a haystack, right?");
	n = ft_strlen(haystack) - 8;
	ft_printf("\n//ft_strnstr returns a char * pointer to the first instance of a string char *needle (%s) found in a string char *haystack (%s) while traversing a maximum of n (%d) bytes\n", needle, haystack, n);
	ft_printf("%s\n", ft_strnstr(haystack, needle, n));
}

//	ft_strtrim test
void	f_strtrim(void)
{
	char *str;
	char *set;

	str = ft_strdup("this string has 29 characters");
	set = ft_strdup("0123456789");
	ft_printf("\n//ft_strtrim returns... lets find out. it goes through string char *s1 (%s) to find out if it is made up of cahracters from string char *set (%s) \n", str, set);
	ft_printf("%s\n", ft_strtrim(str, set));
}

//	ft_substr test
void	f_substr(void)
{
	char 			*str;
	unsigned int	start;
	size_t		len;

	start = 22;
	len = 7;
	str = ft_strdup("this is a string, and it should find itself.");
	ft_printf("\n//ft_substr returns a null-terminated string from input string char *s (%s), starting at position start (%u), while string length of s (%u) is greater than the starting position, until len (%u) characters have been copied\n", str, start, ft_strlen(str), len);
	ft_printf("%s\n", ft_substr(str, start, len));
}

//	ft_tolower test
void	f_tolower(void)
{
	char 			*str;

	str = ft_strdup("THIS string COULD use a little ADJUSTMENT!!");
	ft_printf("\n//ft_tolower returns the string converted to lower case\n");
	ft_printf("ERROR SCRUB FIGURE IT OUT, IT RETURNS ONLY INTS NOOB");
	// ft_printf("BEFORE: %s\nAFTER:%s\n", str, ft_tolower(str));
}

//	ft_toupper test
void	f_toupper(void)
{
	char 			*str;

	str = ft_strdup("and this string COULD use some MOTIVATION!!");
	ft_printf("\n//ft_toupper returns the string converted to upper case\n");
	ft_printf("ERROR SCRUB FIGURE IT OUT, IT RETURNS ONLY INTS NOOB");
	// ft_printf("BEFORE: %s\nAFTER:%s\n", str, ft_toupper(str));
}

//	THIS IS A TEST MAIN TO EXPERIMENT WITH LIBFT FUNCTIONS
int	main(void)
{
	ft_printf("%s", "\n\n//\n//	THIS IS A TEST MAIN TO EXPERIMENT WITH LIBFT FUNCTIONS\n");
	int	n;
	int	m;

	n = 4;
	m = 6;
	// f_atoi();
	// f_bzero();
	// f_calloc();
	// f_isalnum();
	// f_isalpha();
	// f_isascii();
	// f_isdigit();
	// f_isprint();
	// f_itoa();
	// f_memchr();
	// f_memcmp();
	// f_memcpy();
	// f_memmove();
	// f_memset();
	// f_putchar_fd();
	// f_putendl_fd();
	// f_putnbr_fd();
	// f_putstr_fd();
	f_split();
	// f_strchr();
	// f_strdup();
	// f_striteri();
	// f_strjoin();
	// f_strlcat();
	// f_strlcpy();
	// f_strlen();
	// f_strmapi();
	// f_strncmp();
	// f_strnstr();
	// f_strrchr();
	// f_strtrim();
	// f_substr();
	// f_tolower();
	// f_toupper();
	return (0);
}

/*
ft_atoi
ft_bzero
ft_calloc
ft_isalnum
ft_isalpha
ft_isascii
ft_isdigit
ft_isprint
ft_itoa
ft_memchr
ft_memcmp
ft_memcpy
ft_memmove
ft_memset
ft_putchar_fd
ft_putendl_fd
ft_putnbr_fd
ft_putstr_fd
ft_strdup
ft_striteri
ft_strjoin
ft_strlcat
ft_strlcpy
ft_strlen
ft_strmapi
ft_strncmp
ft_strnstr
ft_strtrim
ft_substr
ft_tolower
ft_toupper
*/
/*
f_atoi
f_bzero
f_calloc
f_isalnum
f_isalpha
f_isascii
f_isdigit
f_isprint
f_itoa
f_memchr
f_memcmp
f_memcpy
f_memmove
f_memset
f_putchar_fd
f_putendl_fd
f_putnbr_fd
f_putstr_fd
f_split
f_strchr
f_strdup
f_striteri
f_strjoin
f_strlcat
f_strlcpy
f_strlen
f_strmapi
f_strncmp
f_strnstr
f_strrchr
f_strtrim
f_substr
f_tolower
f_toupper
*/