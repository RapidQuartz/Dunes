/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:38:48 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/05 19:41:33 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	provisional header file for new project
#include "push_swap.h"

#ifndef NEW
# define NEW
/*	s_byte structure
typedef	struct s_byte
{
	char			*a;
	char			*b;
	struct s_byte	*next;
} t_byte;
*/

////	FT:PROTO:
//	'forest' introduces the new project to the stack
void		forest(t_stack **stack_a, t_stack **stack_b);
//	''
t_byte	*worldtree(t_byte	*tree, short acorn);
//	''
void		baumschule(t_byte	**tree, short acorn, t_stack **stack);
//	''
t_byte	*imprinting(t_byte	**tree, short acorn, t_stack **stack);
//	
#endif