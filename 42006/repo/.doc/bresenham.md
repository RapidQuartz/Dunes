#	[README](README.md#index)  
##	[The Algorithm](#bresenham-algorithm)  

#	Bresenham Algorithm

##	error  
depending on which coordinate is dominant, the error is set differently::
	X-dominant::  
		error = 2 * dy - dx;
	Y-dominant::  
		error = 2 * dx - dy;

##	slope  
the slope is determined by seeing if the error exceeds 0::
	error = ((2 * dy) - dx)
		OR
	error = ((2 * dx) - dy)

THEN

	for each `x++`, add `(2 * dy)` to 'err'

	so we have 8 coords::

		dx —	distance to draw line
		dy —	distance to draw line
		
		sx —	current position being drawn
		sy —	current position being drawn

		x0 —	starting point of the line on the x-axis
		x1 —	ending point of the line on the x-axis

		y0 —	starting point of the line on the y-axis
		y1 —	ending point of the line on the y-axis

	

`err == error`

for `dy = 2; dx = 8; x0 = 0; `::

	err = 2 * dy - dx = 4 - 8 = -4 ()
##  