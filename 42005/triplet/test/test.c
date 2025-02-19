#include "../push_swap.h"

void	free_memory(t_stack **stack)
{
	//debug("in free memory");
	t_stack	*mem;
	
	if (!stack || !*stack)
		return ;
	printf("stack: %p\n", *stack);
	// printf("stack value: %d\n", (*stack)->value);
	// printf("stack->next: %p\n", (*stack)->next);
	while (*stack)
	{
		//debug("in _fm_ loop");
		mem = (*stack)->next;
		printf("freeing node: %p\n", *stack);
		free(*stack);
		*stack = mem;
	}
	//debug("setting to NULL");
	*stack = NULL;
}

void	error_handling(t_stack **one, t_stack **other)
{
	//debug("in error handling");
	if (one == NULL  || (*one) != NULL)
	{
		//debug("freeing one");
		free_memory(one);
	}
	if (other == NULL  || (*other) != NULL)
	{
		//debug("freeing other");
		free_memory(other);
		other = NULL;
	}
	////DEBUG:REPLACE:WITH:PUTSTR:OR:WRITE:
	// printf("Error\n");
	////DEBUG:REPLACE:WITH:WRITE:
	write (2, "Error\n", 6);
	exit (1);
}

void	check_minmax(long int value, t_stack **stack)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		if (stack || (*stack) != NULL)
			error_handling(stack, NULL);
		else
			error_handling(NULL, NULL);
	}
}

long	get_number(char *arg, int argn)
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

int	arg_checker(char a, char b)
{
	if ((a == ' ') && \
	((b == ' ' || b == '-' || b == '+') || \
	(b >= '0' && b <= '9')) || \
	((a == '-' || a == '+') && (b >= '0' && b <= '9')))
			return (1);
	if (a <= '9' && a >= '0')
	{
		if (b >= '0' && b <= '9')
			return (1);
		if ((b == ' ') || (b == '\0'))
			return (2);
	}
	return (0);
}

int	arg_counter(char *args)
{
	int	index;
	int	argn;
	char	a;
	int	flag;

	argn = 0;
	index = 0;
	while (args[index] != '\0')
	{
		a = args[index];
		index++;
		flag = arg_checker(a, args[index]);
		if (!flag)
			return (0);
		else if (flag == 2)
			argn++;
	}
	return (argn);
}

int		*arg_array(int argc, char **argv, int argn, int *array)
{
	int	index;
	int	argi;
	int	step;
	int	count;
	long	num;

	index = 0;
	step = 1;
	array = malloc(sizeof(int*) * argn);
	if (!array)
		return (0);
	while (step < argc)
	{
		argi = 0;
		count = arg_counter(argv[step]);
		while (argi != count)
		{
			argi++;
			num = get_number(argv[step], argi);
			check_minmax(num, NULL);
			array[index++] = num;
		}
		step++;
	}
	return (array);
}

int	main(void)
{
	int	*array;
	char	*arg[] = {"null", "1 2", "3", "4 5"};
	int	i = 0;
	
	array = arg_array(4, arg, 5, array);
	while (array[i])
	{
		printf("%d\n", array[i]);
		i++;
	}
	return (0);
}