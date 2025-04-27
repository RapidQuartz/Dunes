/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:06:04 by akjoerse          #+#    #+#             */
/*   Updated: 2025/04/23 19:14:12 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	main(void)
{
	int	fd;
	int	i = 0;
	int	e = 0;
	char	*dir;"/home/akjoerse/42/003_get_next_line/.raw/0_pseudo/test.txt";
	char	*line;
	
	if (BUFFER_SIZE <= 0)
		return (-1);
	if (!dir)
		return (-2);
	fd = open(dir, O_RDONLY);
	line = get_next_line(fd);//:ERRORZONE:001:002:003:
	if (line == NULL)
	{
		printf("			::	NULL return\n");
	}
	else if (line != NULL)
	{
		printf("line %d:<%s>\n", i++, line);
	}
	free(line);
	return (0);
}
int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	fd;
	char	*dir;
	char	*line;

	i = 0;
	j = 0;
	if (argc < 2)
		return (1);
	fd = open(dir, O_RDONLY);
	while (argv[i][j] != '\0')
	{
		while (argv[i][j] != '\0')

			j++;
		i++;
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		printf("			::	NULL return\n");
	}
	else if (line != NULL)
	{
		printf("line %d:<%s>\n", i++, line);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = gnl_buf(buffer, fd, &bytes);
	if (!buffer)
		return (NULL);
	line = gnl_line(buffer);
	buffer = gnl_fixer(buffer);
	return (line);
}

char	*gnl_buf(char *buffer, int fd, ssize_t *bytes)
{
	char	*chad;

	chad = gnl_calloc(1, BUFFER_SIZE + 1);
	if (!chad)
		return (NULL);
	*bytes = 1;
	while (!buffer || (gnl_strnl(buffer) == 0 && *bytes != 0))
	{
		*bytes = read(fd, chad, BUFFER_SIZE);
		if (*bytes <= 0 || !*bytes)
			break ;
		chad[*bytes] = '\0';
		buffer = gnl_strjoin(buffer, chad);
		if (!buffer)
			break ;
	}
	free (chad);
	if (*bytes < 0)
	{
		free (buffer);
		return (NULL);
	}
	return (buffer);
}

char	*gnl_line(char *buffer)
{
	char		*t_line;
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	len = gnl_strnl(buffer);
	if (len == 0)
		len = gnl_strlen(buffer);
	t_line = gnl_calloc(1, len + 1);
	if (!t_line)
		return (NULL);
	while (buffer && buffer[i] && i < len)
	{
		t_line[i] = buffer[i];
		i++;
	}
	if (t_line[i] == '\n')
		i++;
	t_line[i] = '\0';
	return (t_line);
}

char	*gnl_fixer(char *buffer)
{
	size_t	i;
	char	*temp;

	i = gnl_strnl(buffer);
	if (!i)
	{
		free (buffer);
		return (NULL);
	}
	temp = gnl_calloc(1, gnl_strlen(buffer) - i + 1);
	if (!temp)
		return (NULL);
	if (!buffer)
	{
		free (temp);
		return (NULL);
	}
	if (buffer)
		temp = gnl_strcpy(NULL, buffer, temp, i);
	free (buffer);
	return (temp);
}
