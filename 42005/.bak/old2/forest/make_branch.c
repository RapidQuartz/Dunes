/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_branch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:07:52 by akjoerse          #+#    #+#             */
/*   Updated: 2025/03/07 15:20:51 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//pa
t_byte	*perform_a(t_byte *branch, t_byte *shoot, char ops)
{
	int	i;

	i = 5;
	/*
	if `b_size` is 1 (a[3] + b[3] == 1)
		then B becomes empty, meaning a[3] = 0
	if `b_size` is >1 (a[3] + b[3] > 1)
		then B loses 1 member
			if a[3] > b[3] an odd number is stored
				then, a[3] -= 1 but b[3] stays
			else if a[3] == b[3] an even number is stored
				then, a[3] stays but b[3] += 1
		and A gains one member
			if a[2] > b[2] an odd number is stored
				then, a[2] stays but b[2] += 1
			else if a[2] == b[2] an even number is stored
				then, a[2] += 1 but b[2] stays
	if a[1] = 252
		then a[1] = 253 
	if a[1] = 253
		if `b_size` > 1
			then a[1] stays
		else if `b_size` == 1
			then a[1] = 251
	 */
	if (branch->a[3])
	while (branch->a[i] != 0)
		i++;
	//push_a requires all A-stack values move +1
	//start by copying first number after delimiter
	//replace that number with delimiter
	//move all *a values (copy, paste at i+1, i--, repeat until delimiter)
	
	return (branch);
}

//pb
t_byte	*perform_b(t_byte *branch, t_byte *shoot, char ops)
{
	//push_b requires all B-stack values move +1
	//start by copying 0-0 delimiter (or count/delim with 252 or similar)
	//remember index
	//decrement `a_count` -1
	//then move all values +1
	//then copy buffer from end of a to start of b
	/*
	if a[1] = 251 (`a_size` is 1 (a[2] + b[2] == 1)
		then
			a[1] = 252
			a[2] = 0
	if a[1] = 253 (`a_size` is >1 (a[2] + b[2] > 1))
		then
			a[1] == 253
	then
		A loses 1 member
	[1]		if a[2] > b[2] an odd number is stored
				then, a[2] -= 1 but b remains the same
	[2]		else if a[2] == b[2] an even number is stored
				then, a[2] stays the same but b[2] -= 1
	then
		traverse the *a until 0 is found
			x = i-1
		traverse the *b until 0 is found
			copy b[i-1] to b[i] and set b[i+1] to 0
			keep decrementing i--, copy b[i-1] to b[i]
		when i == 5
			b[5] = a[x] 
	{1}		a[x] = 0
	{2}		a[x] =
	 */
	branch->a[1] = 253;
	return (branch);
}

//
t_byte	*perform_c(t_byte *branch, t_byte *shoot, char ops)
{
	return (branch);
}

//
t_byte	*perform_d(t_byte *branch, t_byte *shoot, char ops)
{
	return (branch);
}

//
t_byte	*perform_e(t_byte *branch, t_byte *shoot, char ops)
{
	return (branch);
}

//
t_byte	*perform_f(t_byte *branch, t_byte *shoot, char ops)
{
	return (branch);
}

//
t_byte	*perform_g(t_byte *branch, t_byte *shoot, char ops)
{
	return (branch);
}

//
t_byte	*perform_h(t_byte *branch, t_byte *shoot, char ops)
{
	return (branch);
}

//
t_byte	*perform_i(t_byte *branch, t_byte *shoot, char ops)
{
	return (branch);
}

//
t_byte	*perform_j(t_byte *branch, t_byte *shoot, char ops)
{
	return (branch);
}

//
t_byte	*perform_k(t_byte *branch, t_byte *shoot, char ops)
{
	return (branch);
}

/* pa	--		{ii{mm}[aa+1]/{cc}[bb#1]{pp}[aa#1]/{mm}[bb-1]/{uu}[aa+1]{uu}[bb-1]ee}
pb	--		{ii{mm}[bb+1]/{cc}[aa#1]{pp}[bb#1]/{mm}[aa-1]/{uu}[aa-1]/{uu}[bb-1]ee}/
sa	--		{ii/{cc}[aa#2]/{cc}[aa#1]/{pp}[aa#1]/{pp}[aa#2]//ee}
sb	--		{ii/{cc}[bb#2]/{cc}[bb#1]/{pp}[bb#1]/{pp}[bb#2]/ee}
ss	--		{ii/{sa}/{sb}/ee}
ra	--		{ii/{cc}[aa#1]/{mm}[aa-1]/{pp}[aa#L]/ee}
rb	--		{ii/{cc}[bb#1]/{mm}[bb-1]/{pp}[bb#L]/ee}
rr	--		{ii/{ra}/{rb}/ee}
rra	--		{ii/{cc}[aa#L]/{mm}[aa+1]/{pp}[aa#1]/ee}
rrb	--		{ii/{cc}[bb#L]/{mm}[bb+1]/{pp}[bb#1]/ee}
rrr	--		{ii/{rra}/{rrb}/ee} */