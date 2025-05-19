get_next_line

requires a function to call it, that should look something like this:

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