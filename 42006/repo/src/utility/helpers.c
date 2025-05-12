# include "../../FdF.h"

////	HEXTOI:
//	if `n` is a number '0'-'9' —> (48 - 57)
//	//	return (n - 48)
//	//	//	—> return (0 - 9)
//	if `n` is a letter 'A'-'F' —> (65 - 70) —>
//	//	return (n - 55)
//	//	//	—> return (10 - 15)
//	if `n` is a letter 'a'-'f' —> (97 - 102) —>
//	//	return (n - 87)
//	//	//	—> return (10 - 15)
int	ft_hextoi(char n)
{
	if (n >= '0' && n <= '9')
		return (n - 48);
	else if (n >= 'A' && n <= 'F')
		return (n - 55);
	else if (n >= 'a' && n <= 'f')
		return (n - 87);
	return (-1);
}