##	[README](README.md#index)  
#	index

#	pad::

###	notes::

####	LEARN ABOUT::
how do i cast a type to a function that allocates memory?
i want to make sure that it knows to take an `(int)`
or be able to cast a `(t_str)` structure for that matter.
(maybe it is inconsequential, and it is sufficient to get a void pointer with the number of bits needed, meaning i use a
`size_t siz = sizeof(type) * sizeof(data);`  
and then just send
	int		*arr;
	int		mem;
	size_t	siz;
	
	siz = sizeof((int) * mem);
	arr = (int *)ft_gbco(siz))
in order to allocate sufficient memory for an int, and then casting the `void *` pointer to an `int *` when i receive it.

i think that could work tbh!

##	strat:

###	todo:
OK	copy functions to own files  
[KO	fix memory](#develop-memory-handling-function)  
[makefile housecleaning](#change-makefile-to-download-mlx-repo)  
[improvements](#fine-tune-or-alter-algo)  
	[ideas for zoom/offset changes](#rambles)  
[judgment](#submit)  
[return on investment](#profit)  
#####	change makefile to download mlx repo
	(or just ignore and let evaluator do it in spe)
#####	fine tune or alter algo
	(really just cosmetic tbh, i mean, most maps are smallish and the big ones do draw right, just a bit small i guess. could be easy)
#####	submit
	evaluations must go well or i must have time to redo (min. 24 hours)
#####	????
	???
		??
			?
#####	profit
	and eternal glory
		where my forefathers
			rejoice in heaven
				and the beyond

####	rambles
-	—	alternatively, i could:
*	have two factors::
	*	zoom
	— tries to fill the screen up
	*	offset
	— tries to keep a portion free

*	find max width and height of img
	*	range of x/y min/max
	*	percentage of real estate
	*	fixed or ratio offset
*	find how much to zoom to fill
	*	how many pixels for img?
*	check fixed/relative offset is OK

  
##	inc::  
  
  
###	in src dir  
  
# include "../inc/fdf.h"  
  
###	in root dir  
  
# include "inc/fdf.h"  
  
#	func names  
  
##	all  
  
###	sorted  
  
###	fdf.c  
int	main(int arg, char **param)  
bool	check_file(char **a)  
<!-- ERROR HANDLING -->  
  
###	src/helpers.c  
int	ft_abs(int num)  
int	ft_hextoi(char n);  
int	get_lmn_len(char *lmn);  
<!-- MEMORY HANDLING -->  
  
###	src/parse.c  
int	extract_color(char *col, int j);  
int	get_height(char *num, int end);  
t_pts	*meta_segments(t_fdf *f, int y);  
void	get_range(t_pts **p, t_fdf *f);  
void	set_points(t_fdf *f, t_pts **p, t_raw *raw);  
  
  
###	src/project.c  
void	proj_zoom(t_fdf *f);  
void	set_pro(t_pts o, t_pts d, t_pro *p, t_fdf *f);  
void	normalize_pts(t_fdf *f);  
void	buffer_offset(t_fdf *f);  
void	get_off(t_fdf *f);  
  
  
###	src/draw.c  
void	put_pixel(int x, int y, int c, t_mlx *i);  
void	draw_line(t_pts o, t_pts d, t_fdf *f);  
int	keychain(int key, void *par);  
int	close_handler(void *param);  
  
  
###	src/init.c  
void	init_img(t_fdf *f, t_mlx *m);  
void	init_mlx(t_fdf *f);  
void	init_raw(t_fdf *fdf, char *map_file);  
void	init_fdf(t_fdf *fdf);  
  
  
  
##	sanitize  
  
void	normalize_pts(t_fdf *f)  
  
##	check  
  
void	get_off(t_fdf *f)  
  
  
#	file names  
  
  
  
fdf.c  
  
src/helpers.c  
src/parse.c  
src/project.c  
src/draw.c  
src/init.c  
  
  
#	fix memory  

##	simple
###	note where valgrind flinches
[first dump](valdump.md#20250603-1307)
[clear text]()
###	individual free-calls

##	intermediate
###	walk through and note mallocs 
###	exit-free function

##	complicated
###	restructure libft
####	develop memory handling function
	
	<!--		garbage collector::
	in simple terms, a garbage collector is
	a function that does three things:
	1.	allocate memory on demand
	2.	save memory ptrs in linked list
	3.	free all ptrs at end of execution

	———————————————————————————————————————

	in practice it is not too difficult to
	develop such a function-plex. there are
	two main strategies:
	1.	modify functions in libft to use
	a homebrew function similar to this:
	`t_gb	*ft_gbgco(void *typ, size_t siz)`
	returning a structure pointer to:
	`typedef struct	s_gb
	{
		void		*mem_ptr;
		struct s_gb	*next;
	}	t_gb;`
	
	—

	then, once execution is finished, this
	or similar function will engage:
////	BUILDING:THE:LINKED:LIST:
t_gb	ft_garbage_collector(void *typ, size_t siz);
////	FREEING:THE:MEMORY:
int	ft_binday(t_gb *bin)
{
	t_gb	*mem;

	while (bin)
	{
		mem = bin;
		if (mem->mem_ptr)
		{
			free (mem->mem_ptr);
			mem->mem_ptr = NULL;
		}
		if (bin && bin->next != NULL)
		{
			bin = bin->next;
			mem->next = NULL;
			free (mem);
			mem = NULL
		}
		else if (bin->next == NULL)
		{
			free (bin);
			bin = NULL;
		}
	}
	return (0);			
}
	which will `return (0);` if freeing all
	memory has been successful, and another
	code if another state has been reached

							-->

