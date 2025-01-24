/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spine.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:18:47 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/21 15:28:17 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mind.h"
// void	choke(void)
// {
// 	printf("a natural response\n");
// }
// void	speak(int code)
// {
// 	printf("Hello World\n%d\n", code);//// TODO: move, split, complicate
// }
void	lungs(char **breath)
{
	int	i;
	
	i = 0;
	if (!(**breath))
		choke();
	else if (**breath)
		speak(0);
	while (breath[i])
	{
		printf("%s",breath[i++]);
	}
	printf("\n%d\n", i);
	speak(i);
}
////	TODO:put funcs above not below
// int	main(int argc, char **argv)
// {
// 	// speak(argc);
// 	lungs(argv);
// 	return (0);
// }