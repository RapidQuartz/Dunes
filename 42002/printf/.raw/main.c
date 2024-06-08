/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:30:24 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/01 17:15:25 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* this file is to compile and test the files in the printf project */
/* it is not meant to be included in the submission */

int	main(void)
{
	int		i;
	float	f;
	char	*s;

	i = 0;
	f = 0.0042;
	s = "boots and cats";
	ft_printf("Hello World\n");
// expected: "Hello World"
	printf("Hello World\n");
// expected: "Hello World"
	ft_printf("%d\n", i);
// expected: "0"
	printf("%d\n", i);
// expected: "0"
	ft_printf("% d\n", i);
// expected: " 0"
	printf("% d\n", i);
// expected: " 0"
	ft_printf("%f\n", f);
// expected: "0.004200"
	printf("%f\n", f);
// expected: "0.004200"
	ft_printf("%+f\n", f);
// expected: "+0.004200"
	printf("%+f\n", f);
// expected: "+0.004200"
	ft_printf("%.4f\n", f);
// expected: "0.004200"
	printf("%.4f\n", f);
// expected: "0.004200"
	ft_printf("%s\n", s);
// expected: "boots and cats"
	printf("%s\n", s);
// expected: "boots and cats"
	return (0);
}
