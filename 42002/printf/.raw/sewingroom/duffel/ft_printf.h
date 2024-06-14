/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:56:21 by akjoerse          #+#    #+#             */
/*   Updated: 2024/06/11 19:11:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// #include "libft.h" //cc//change to correct directory
# include "LIB/libft.h"
// # include <string.h>
# include <stdarg.h>

//cc// define functions
/* fts
ft_printf()
ft_vex(const char *format, va_list ap)
ft_ptfcha()
ft_ptfstr()
ft_ptfhex()
ft_ptfhex_len(format, va_arg(ap, unsigned int));
*/
int		ft_vex(const char *format, va_list ap);
int		ft_ptfcha(char c); //va_arg(ap, int)
int 	ft_ptfhex(const char *format, unsigned int num); //va_arg(ap, unsigned int)
int		ft_ptfint(const char *format, int num); //va_arg(ap, int)
int		ft_ptfptr(unsigned long long int ptr); //va_arg(ap, unsigned long long)
int		ft_ptfstr(const char *format); //va_arg(ap, char *)
int		ft_ptfuin(unsigned int num); //va_arg(ap, unsigned int)
int	ft_printf(const char *format, ...);

#endif