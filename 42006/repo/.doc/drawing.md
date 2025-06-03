#	index

to draw a line, we need to know certain things about the coordinates we wish  
to project from 2D to 3D.  
:  
from the outset we have the following::  
- x  
	-	set to `0` initially
- y  
	-	set to `0` initially
- xmax
	-	number of elements in width/X-axis
- ymax  
	-	number of elements in height/Y-axis
- theta  
	-	angle to use for isometric projection
- zoom  
	-	set to `1` initially  
	{but can be skipped (?)}
- window size  
	-	set to `800 x 600` initially  
	{but can be configured at runtime if modified input handling}
  
finding the projected points means:
- finding 4 points for horizontal lines
- finding 4 points for vertical lines

in other words, a function for each is prudent

`int h[4]`  
`int v[4]`  

`if (fdf->x < fdf->xmax - 1)`  
&emsp;`h = project_horizontal(t_fdf *fdf)`  
`if (fdf->y < fdf->ymax - 1)`  
&emsp;`v = project_vertical(t_fdf *fdf)`  
  
notes:
- the project_ functions should call the drawing function too
- i can save the previous x1/y1 coordinates to save cycles