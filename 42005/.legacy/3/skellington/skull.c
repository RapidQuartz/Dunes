/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skull.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:10:56 by akjoerse          #+#    #+#             */
/*   Updated: 2025/01/21 15:23:01 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mind.h"

////
////lungs()
/////diaphragm()
/////trachea()
////
////
////
void	speak(int code)
{
	printf("Hello World\n%d\n", code);//// TODO: move, split, complicate
}


////	TODO:put funcs above not below
int	main(int argc, char **argv)
{
	speak(argc);
	lungs(argv);
	return (0);
}
