[main-readme](README.md#main-readme)  
[index](#index)  
# Welcome to the README for FdF
—
##	[cleanup](cleanup.md#index)  
### the project was continued	2025.05.10 10:20:11
##	[2025.05.20](20250520.md#index)
##	[2025.05.12](20250512.md#index)  
##	[2025.05.11](20250511.md#index)  
###	[TODAY'S DEEDS](#checklist)  
###	[THE WAY](#path-to-glory)  
###	[TODOLIST](todo.md#index)  

#### path to glory

##	[today](20250530.md#status)  

###	{loose leaf}
gitta gotta getta gud
make some progress today bud
lines should be made a certain way
angles and termination points
associate map coords with angles

# it matters if im drawing horizontal or vertical::

## `horizontal line`  
	—	`x0` = (map_x - map_y) * (cos THETA)  
	—	`x1` = ((map_x + 1) - map_y) * (cos THETA)  
	—	`y0` = (map_x + map_y) * (sin THETA) - map_z  
	—	`y1` = ((map_x + 1) + map_y) * (sin THETA) - map_z  

## `vertical line`  
	—	`x0` = (map_x - map_y) * (cos THETA)  
	—	`x1` = (map_x - (map_y + 1)) * (cos THETA)  
	—	`y0` = (map_x + map_y) * (sin THETA) - map_z  
	—	`y1` = (map_x + (map_y + 1)) * (sin THETA) - map_z  



### {packed pellet}

`how is a coord transformed into angles and dy/dx values?`

##	!	THETA is usually 30 degrees in isometric projection

	x'iso = (X - Y) * cos THETA
	y'iso = (X + Y) * sin THETA - Z

	THETA	=	30 deg
	cos	~=	0.866
	sin	~=	0.5

	{{subtracting the Z coordinate makes the height apparent}}

##	!	dy/dx in drawing

## `connecting two projected points (x0, y0) and (x1, y1), slope is::`

	(dy/dx) == ((y1 - y0)/(x1 - x0))

	{{determines how steep line becomes}}

## `!	getting x0/x1/y0/y1 is a matter of::`

	map_x — current X coordinate
	map_y — current Y coordinate
	map_z — current Y coordinate
	proj_x — a single point on x-axis
		proj_x = (map_x - map_y) * (cos THETA)
	proj_y — a single point on y-axis
		proj_y = (map_x + map_y) * (sin THETA - map_z)
	
	x0 = proj_x
	y0 = proj_y

	THEN
		while (map_x < width_limit)
			++map_x;
		get_proj(map_x, map_y, map_z, THETA)
			proj_x = (map_x - map_y) * (cos THETA)
			proj_y = (map_x + map_y) * (sin THETA - map_z)

	xy = get_proj(map_x, map_y, map_z, THETA)
	int *get_proj(int *map_x, int *map_y, int *map_z, int THETA)
	{
		int	xy[4];

		xy[0] = (map_x - map_y) * (cos THETA)
		xy[2] = ((map_x + 1) - map_y) * (cos THETA)
		xy[1] = (map_x + map_y) * (sin THETA - map_z)
		xy[3] = ((map_x + 1) + map_y) * (sin THETA - map_z)
		return (xy)
	}
- [ ] 1
	- [ ] 1.1
	- [ ] 1.2
- [ ] 2
	- [ ] subset
	- [ ] subset


#	`!	getting dy/dx::`

	dx = ft_abs(x1 - x0)
	dy = ft_abs(y1 - y0)

	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;

	

##	[Bresenham's algorithm](bresenham.md#bresenham-algorithm)  






















#### checklist
- [ ] x0/x1
	- [ ] x0 = map_x - map_y
	- [ ] subset
- [ ] y0/y1
	- [ ] subset
	- [ ] subset
- [ ] antialiasing
	- [x] breckenham
		- [ ] easier to understand
		- [ ] doesn't use floats
	- [ ] wushaolin
		- [ ] nicer to look at
		- [ ] more complicated
- [ ] rendering
	- [ ] offscreen elements
		- [ ] lines that continue off screen
		- [ ] implied termination points
	- [ ] rotation/offsets
		- [ ] default angles and perspective
		- [ ] storing states

##	map parsing
so far, `get_next_line` performs as expected and reads the map file  
converting to coordinates is not 'difficult' per se, but requires:  
- [x] splitting the lines by ' ' spaces ((or commas{TODO:LATER:}))
- [x] splitting the lines by '\n' newlines (newline = y--)
- [x] `num_lines` count lines
- [x] `num_elements` count elements, essentially spaces?
- [ ] `key_exotic` `val_exotic` split exotics and location to save space?
- [x] ft_atoi split lines to `int **array` by `array[j][i++]`
- [x] next line to `array[j++][i]`
- [ ] repeat until `line` is `NULL` (or whatever gnl returns)
##	TODO:LATER:
- [x] parse color info:
	- [x] store color info in `char **gamma`
		- [ ] store '\0' when no color info (no ',' found after number)
		- [x] store 'hex code' when color info (when number followed by ',')
	- [ ] store x-y-z info in `int`
		- [ ] `z = array[y][x]`
- [ ] tread through array
	- [ ]	EITHER:
		- [ ] iterate `x--` — going backwards from last number
		- [ ] iterate `y++` — going upwards from bottom rung once x == 0
	- [ ] OR:
		- [ ] iterate `x++` — going forwards from first number
		- [ ] iterate `y--` — from highest line to lowest once i reach '\n'


### the project was continued	2025.04.25:13:26:01.
—
## next steps
[map](#map-input)
[prereqs](#prerequisites)
[process](#process)   

##	map-input
- parse map
	- based on 3 coordinates
		-	x	— axis
		-	y	— ordinate
		-	z	— altitude
	- without crashing
		- by validating map before causing harm
		- by making a safe and thorough error-exit function
##	prerequisites
-	input  
	- [ ] other input
	- [ ] validates map
	- [ ] understands [colors](manuals/man1/mlx_pixel_put.1#L57)  
	- [ ] pressing `ESC` closes the program
	- [ ] clicking `x` in the window closes the program
-	thoroughput
	- [ ] MAP TASKS:	A
		- [ ] parses a valid map
			- [ ] map parsing
				- [ ] color
				- [ ] heights
				- [ ] widths
				- [ ] depths
			- [ ] map validation
				- [ ] color
				- [ ] heights
				- [ ] widths
				- [ ] depths

	- [ ] MAP TASKS:	B
		- [ ] color handling
		- [ ] error handling
			- [ ] Invalid input
				- [ ] NULL
				- [ ] disorder
			- [ ] Invalid output
				- [ ] limitations
				- [ ] bugs
			- [ ] Memory handling
	- [ ] RUNNING TASKS
		- [ ] subset
			- [ ] sub-subset
			- [ ] sub-subset
		- [ ] subset
			- [ ] sub-subset
			- [ ] sub-subset
	- [ ] LINKING TASKS
		- [ ] subset
			- [ ] sub-subset
			- [ ] sub-subset
		- [ ] subset
			- [ ] sub-subset
			- [ ] sub-subset

-	output
	- [ ] makes a window

##	process
- [ ] mlx_init
	- [ ] mlx_new_window
		- [ ] sub-subset
		- [ ] sub-subset
	- [ ] mlx_pixel_put
		- [ ] sub-subset
		- [ ] sub-subset
	- [ ] mlx_new_image
		- [ ] sub-subset
		- [ ] sub-subset
	- [ ] mlx_loop
		- [ ] sub-subset
		- [ ] sub-subset
- [ ] void *
	- [ ] subset
	- [ ] subset

### the project was begun	2025.01.13:16:33:42.
—
## things done:
- [ ] [FdF.h](repo/FdF.h)  
	- [ ] struct
	- [ ] enum
- [ ] [Makefile](repo/Makefile)  
	- [ ] correct calling of `make` libft library if necessary
	- [ ] correct calling of `make` mlx library if necessary
## things to do:
- find out [next steps](#next-steps)  
- read up on topics
- read documentation

# TO LEARN:

#	index
[process](#process)  
###	manuals for MiniLibX
[manuals for MiniLibX](manuals/man1/mlx.1)   
[server - client relation](manuals/man1/mlx.1#L24)  
`interface` my software tries to draw something or get input  
`display` the server manages the keyboard mouse and screen  
-	a network connection is necessary:
	- [ ] send drawing orders
		- [ ] from server to client
		- [ ] from client to server
	- [ ] take input from UI
		- [ ] keyboard
		- [ ] mouse

###	creating-windows
[creating-windows](#creating-windows)  
[next steps](#next-steps)  
-	[map-input](#map-input)  
-	[prerequisites](#prerequisites)  

# GLOSSARY:
Fil de Fer - wireframe model

minilibx - the school graphical library
README.md
README.md