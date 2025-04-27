/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:33:06 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/27 15:02:14 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
// # include "get_next_line/get_next_line.h"
// # include "ft_printf/ft_printf.h"

// libft functions
int		ft_toupper(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_tolower(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
// // ft_printf functions
// int		ft_printf(const char *format, ...);
// int		ft_ptfcha(char c);
// int		ft_ptfstr(const char *format);
// int		ft_vex(const char format, va_list ap);
// int		ft_ptfhex(unsigned long long int num, const char format);
// int		ft_ptfhex_len(unsigned long long int num);
// void	ft_ptfhex_put(unsigned long long int num, const char format);
// int		ft_ptfptr(unsigned long long ptr);
// int		ft_ptfint(int num);
// int		ft_ptfint_put(int num);
// int		ft_ptfuin_put(unsigned int num);
// int		ft_ptfnumlen(unsigned int num);
// char	*ft_uitoa(unsigned int num);

#endif
