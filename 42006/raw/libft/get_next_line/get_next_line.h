/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:05:52 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/23 19:14:12 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	gnl_strlen(char *first);
char	*gnl_strjoin(char *first, char *second);
char	*get_next_line(int fd);
char	*gnl_fixer(char *buffer);
char	*gnl_buf(char *buffer, int fd, ssize_t *bytes);
char	*gnl_line(char *buffer);
size_t	gnl_strnl(char	*str);
char	*gnl_strcpy(char *first, char *second, char *out, size_t index);
void	*gnl_calloc(size_t nmemb, size_t size);

#endif