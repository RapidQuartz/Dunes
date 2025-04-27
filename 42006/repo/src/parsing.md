[index](#index)  
#	links and references
[converting args](#converting-args)  
[parsing-maps [to the top]](#parsing-maps)  
[root-readme [above it all]](../../README.md#main-readme)  


##	input
[ft_split](../libft/src/ft_split.c)  

	char	**ft_split(char const *s, char c);

char *
	char **dotsplit;
	char c;

	c = '.';
	dotsplit = ft_split(filename, char '.')
	{

	}



##	converting args
ft_strjoin can join various argv strings together into one
[ft_strjoin](../libft/src/ft_strjoin.c)  

example expected input:  

`$>./fdf 42.fdf`  

	map name is stored as
	
`char *nom;`
	
	map is parsed line by line with:
`char *get_next_line(int fd)`

	map is loaded line by line while noting stats:
-	are all arguments similar? how wide is character span/range?
-	range if arguments numeric
-	[is_numeric](#is_numeric)  
	-	height only


			t_chart *	ft_isometry(char **args, t_data **map)
			{
				t_chart	**chart;
				t_data	*lore;
				int		line;
	
				map = NULL;
				lore = NULL;
				line = 0;
				map_scan(args, map)
				init_chart(args, chart, lore);
				while (chart[line] != '\0')
			}

-	is_exotic
	-	color and hex values and such

`struct->int *x_wide;`  
`struct->int *y_long;`  
`struct->int *z_deep;`  

`struct s_map`

	typedef struct	s_map
	{
		int	*x_wide;
		int	*y_long;
		int	*z_deep;
	}	t_map;

		map = get_values(strlen(line), line);
		chart->next = map;

`struct s_chart`

	typedef struct	s_chart
	{
		struct	s_chart	**head;
		struct	s_map		*prev;
		struct	s_map		*next;
	}	t_chart;

		map = get_values(strlen(line), line);
		chart->next = map;

`$>./fdf`  

	no response  
	do not allocate memory

`$>./fdf broken.fdf virus.fdf`

	no response  
	exit program
	free memory if not null

##	is_numeric


#	parsing maps

[index](#index)  
##	index
[input](#input)  
#	map input
- [ ] arguments
	- [ ] argc — `char **c`
	- [ ] argv — `char **c`
		- [ ] map file
- [ ] conversions
	- [ ] argv to struct
	- [ ] enum of valids? 
- function defs
	- data = init_fdf(a, c);//-->//verify_args(int a, char **c);
		- t_data *init_fdf(int a, char **c);//
			- verify_args(int a, char **c);
				- {int/bool}	validate_arg(char *c)
					- {int/bool}	arg_islegal(char c)
						- bool	arg_is_coord(char c)
						- bool	arg_is_info(char c)
						- bool	arg_is_color(char c)
			data->map = convert_args(data->array, data->args);//convert_args(int *array, char *args);
		- 
	if (data != NULL)
	if (map != NULL)
		parse_map(data->map, data->kompass);//parse_map(t_map **map, t_struct **kompass);
#	data process
- function calls
	;
	:	init_fdf(a, c)
- variable defs
	- t_data *data:{int *array; char *args; t_map **map; t_struct **kompass;}
	
