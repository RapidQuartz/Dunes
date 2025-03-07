#include "../push_swap.h"
//printf("");
int	main(void)
{
	short		num;

	num = 0;
	printf(GRNTXT"debug started\n"DEFTXT);
	while (num != 42)
	{
		printf(GRNTXT"\t\tif a `short num is: %d`\n"DEFTXT, \
		(num));
		printf(YLWTXT"\t\tthen the result of `num / 2` is: %d\n"DEFTXT, \
		(num / 2));
		printf(YLWTXT"\t\tand the result of `num %% 2` is: %d\n"DEFTXT, \
		(num % 2));
		printf(REDTXT"\t\tthe sum of `(num / 2)+(num %% 2)` is: %d\n"DEFTXT, \
		((num / 2) + (num % 2)));
		if (num < 42)
			printf(BLUTXT"\titerating until number is 42\n"DEFTXT);
		else if (num == 42)
			printf(GRNTXT"\n\n\niteration complete\n"DEFTXT);
		num++;
	}
	printf(GRNTXT"end of debug////\n"DEFTXT);
	return (0);
}