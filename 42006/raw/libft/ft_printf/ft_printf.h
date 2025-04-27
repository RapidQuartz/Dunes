/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:06:17 by akjoerse          #+#    #+#             */
/*   Updated: 2024/08/31 16:07:15 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_ptfcha(char c);
int		ft_ptfstr(const char *format);
int		ft_vex(const char format, va_list ap);
int		ft_ptfhex(unsigned long long int num, const char format);
int		ft_ptfhex_len(unsigned long long int num);
void	ft_ptfhex_put(unsigned long long int num, const char format);
int		ft_ptfptr(unsigned long long ptr);
int		ft_ptfint(int num);
int		ft_ptfint_put(int num);
int		ft_ptfuin_put(unsigned int num);
int		ft_ptfnumlen(unsigned int num);
char	*ft_uitoa(unsigned int num);

#endif
