//// ////  ////  //////////////////////////////////////////////////////////////
//// FDF:  ////  //////////////////////////////////////////////////////////////
//// ////  ////  //////////////////////////////////////////////////////////////

check arguments
check map
assign fd temporarily
parse map
split by newline
split by space
pass ptr then free
read elements
length before comma
atoi first half
arr[w][x][y] = 
hextoi last half
store zx/zy separately 
store cx/cy separately
arr[w][x][y] = c
arr[w][x][y] = z
convert map to projection
find origin x/y
decide draw x/y
find destination xx/xy
find destination yx/yy
find delta xdx/ydy
find delta ydx/ydy
find slope xsx/xsy
find slope ysx/ysy
create pointer
create window
create image
create address
apply color
draw
loop

//// ////  ////  //////////////////////////////////////////////////////////////
//// STRUCTURE:  //////////////////////////////////////////////////////////////
//// ////  ////  //////////////////////////////////////////////////////////////

//// store all points in a x/y array://////////////////////////////////////////
typedef struct s_pts
{//0x,0y//
	int	x;//fdf.x - fdf.y * cos fdf.t
	int	y;//fdf.x + fdf.y * sin fdf.t - fdf.pts[fdf.y][fdf.x].z
	int	z;//
	int	c;//
}
typedef struct s_pts
{//1x,0y//
	int	x;//fdf.x + 1 - fdf.y * cos fdf.t
	int	y;//fdf.x + 1 + fdf.y * sin fdf.t - fdf.pts[fdf.y][fdf.x + 1].z
	int	z;//
	int	c;//
}
typedef struct s_pts
{//0x,1y//
	int	c;//
	int	z;//
	int	x;//pts[y][x].x = fdf.x - fdf.y + 1 * cos fdf.t
	int	y;//pts[y][x].y = fdf.x + fdf.y + 1 * sin fdf.t - fdf.pts[fdf.y + 1][fdf.x].z
}

if [(*y)][(*x)]
	
	fdf->pts[(*y)][(*x)].c = fdf->pos[(*y)][(*x)].c;
	fdf->pts[(*y)][(*x)].z = fdf->pos[(*y)][(*x)].z;
	fdf->pts[(*y)][(*x)].x = (*x) - (*y) * cos fdf->t;
	fdf->pts[(*y)][(*x)].y = (*x) + (*y) * sin fdf->t - fdf->pts[(*y)][(*x)].z;

void	set_x(t_fdf *fdf, int x, int y)
{
	fdf->pts[y][x].x = fdf->x - fdf->y + 1 * cos fdf.t;

}
void	set_x(t_fdf *fdf, int x, int y)
}
{
typedef struct s_pts
{
	int	zz;//atoi height
	int	zx;
	int	zy;//atoi height
	int	cz;//hextoi color
	int	cx;
	int	cy;//hextoi color
	int	ox;
	int	oy;//find origin 
	int	dx;
	int	dy;//decide draw yes or no
	int	xx;
	int	xy;//find destination
	int	yx;
	int	yy;//find destination
	int	xdx;
	int	xdy;//find delta
	int	ydx;
	int	ydy;//find delta
	int	xsx;
	int	xsy;//find slope
	int	ysx;
	int	ysy;//find slope
}	t_pts;

//// store all chars in a triple array the size of the raw string: ////  //////
typedef struct s_map
{
	char	*str;
	char	*raw;
	char	**lines;
	char	***charts;
}	t_map;

typedef struct s_pos
{
	int	z;
	int	c;
}	t_pos;

<!-- char	***map;

map = malloc(sizeof(raw_string)); -->

//// store pointers in the central fdf structure: ////  ///////////////////////

typedef struct s_fdf
{
	void	*mlx;
	void	*img;
	void	*win;
	t_pts	**map;
	t_pos	**pos;
	t_map *lines;
	int	err;
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	win_x;
	int	win_y;
}	t_fdf;

