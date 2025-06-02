
# include "inc/fdf.h"

/*	TODO: 2025.06.02 11:40:41
IT WORKS WITH OTHER MAPS~!!!!!!~!!1!!!!1!!
-	make it center correctly
	-	why isnt it centering?
		-	position is calculated once
		-	jalombar did it twice
			!	try to calc pos/offset twice:
				1.	basic pos
				2.	offset based on pos/zoom
					a.	zoom after offset -> zoom offset
					b.	offset after zoom -> screen based
				3.	updated pos based on offset
-	make colors work
	IT KINDA WORKS WITH COLORRRRRRRR
	-	make it work with gradients of colors?

*/

/* lmeubrin

zooms - calc after screen size comparison

offsets

scale around draw line

*/
/* 	-	make it work with other maps.
-	why isn't it working now?
//(gdb) r test_maps/50-4.fdf 
//Starting program: /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf test_maps/50-4.fdf
//[Thread debugging using libthread_db enabled]
//Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
//^C
//Program received signal SIGINT, Interrupt.
//put_pixel (x=32767, y=-8232, c=0, i=0x7fffffffdf70) at omni.c:47
//47      {

	// so, it goes waaay outta bounds. why?

	// ?	not obeying x-limits?
	// 	!	could set another condition:
	// 		based on `sx/sy`:
	// 			+1	if x0 > x1 -> break
	// 			-1	if x0 < x1 -> break
	// 		++	could make an inbounds function?
	// 			while (inbounds(o, d, var))
					
	// ?	where would it be limited?
 */
int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
int	keychain(int key, void *par)
{
	if (key == 65307 || !par)
		exit(0);
	return (0);
}
int	close_handler(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit (0);
	return (0);
}

void	put_pixel(int x, int y, int c, t_mlx *i)
{
	char	*pix;

	if (x < 0 || x >= DEFWID || y < 0 || y >= DEFHEI)
		return ;
	pix = i->adr + (y * i->len + x * (i->bpp / 8));
	*(unsigned int *)pix = c;
}

// void	set_pro(t_pts o, t_pts d, t_pro *p, int zoom)
// void	set_pro(t_pts o, t_pts d, t_pro *p)
void	set_pro(t_pts o, t_pts d, t_pro *p, t_fdf *f)
{
	// p->x0 = round(o.x + f->x_off);
	// p->x0 = round(((o.x) * f->zoom) + f->x_off);
	p->x0 = round((o.x * f->zoom) + f->x_off);
	// p->x0 = round((o.x * f->zoom) + ((DEFWID / 2) + f->x_off));
	// p->x0 = round((o.x / f->zoom) + ((DEFWID / 2) + f->x_off));
	// p->x1 = round(d.x + f->x_off);
	// p->x1 = round(((d.x) * f->zoom) + f->x_off);
	p->x1 = round((d.x * f->zoom) + f->x_off);
	// p->x1 = round((d.x * f->zoom) + ((DEFWID / 2) + f->x_off));
	// p->x1 = round((d.x / f->zoom) + ((DEFWID / 2) + f->x_off));
	// p->y0 = round(o.y + f->y_off);
	// p->y0 = round(((o.y) * f->zoom) + f->y_off);
	p->y0 = round((o.y * f->zoom) + f->y_off);
	// p->y0 = round((o.y * f->zoom) + ((DEFHEI / 4) + f->y_off));
	// p->y0 = round((o.y / f->zoom) + ((DEFHEI / 4) + f->y_off));
	// p->y1 = round(d.y + f->y_off);
	// p->y1 = round(((d.y) * f->zoom) + f->y_off);
	p->y1 = round((d.y * f->zoom) + f->y_off);
	// p->y1 = round((d.y * f->zoom) + ((DEFHEI / 4) + f->y_off));
	// p->y1 = round((d.y / f->zoom) + ((DEFHEI / 4) + f->y_off));
	p->dx = ft_abs(p->x1 - p->x0);
	p->dy = -ft_abs(p->y1 - p->y0);
	p->err = p->dx + p->dy;
	if (p->x0 < p->x1)
		p->sx = 1;
	else
		p->sx = -1;
	if (p->y0 < p->y1)
		p->sy = 1;
	else
		p->sy = -1;
}
/*	NORMALIZING LOGIC

add the smallest limit to all numbers

*/
/*	NORMALIZER

take halfway

start - center limit == center of img. obj.

f->x_range[0]
x_halfrange = (f->x_range[1] + -(f->x_range[0])) / 2
f->y_range[0]
y_halfrange = (f->y_range[1] + -(f->y_range[0])) / 2
f->x_off = DEFWID / 2 - (f->x_range[2] * f->zoom);
f->y_off = DEFHEI / 2 - (f->y_range[2] * f->zoom);

find middle of f->x_range

find middle of f->y_range
 
*/
// void	normalize_pts(t_pts **p, t_fdf *f)
void	normalize_pts(t_fdf *f)
{
	int	x_half;
	int	y_half;

	x_half = ((f->x_range[1] + -(f->x_range[0])) / 2);
	// x_half = ((f->x_range[1] + -(f->x_range[0])) / 2);
	y_half = ((f->y_range[1] + -(f->y_range[0])) / 2);
	// y_half = ((f->y_range[1] + -(f->y_range[0])) / 2);
	f->x_off = DEFWID / 2 - (x_half);
	f->y_off = DEFHEI / 2 - (y_half);
	// f->x_off = DEFWID / 2 - (x_half * f->zoom);
	// f->y_off = DEFHEI / 2 - (y_half * f->zoom);
/*	f->y = 0;
	while (f->y < f->y_lim)
	{
		f->x = 0;
		while (f->x < f->x_lim)
		{
			p[f->y][f->x].x += f->x_range[0];
			p[f->y][f->x].y += f->y_range[0];
			f->x++;
		}
		f->y++;
	} */
}

void	draw_line(t_pts o, t_pts d, t_fdf *f)
{
	t_pro *p;
	int	e2;

	// set_pro(o, d, f->pro, f->zoom);
	set_pro(o, d, f->pro, f);
	p = f->pro;
	while (1)
	{
		put_pixel(p->x0, p->y0, o.c, f->mlx);
		if (p->x0 == p->x1 && p->y0 == p->y1)
			break ;
		e2 = 2 * p->err;
		if (e2 >= p->dy)
		{
			p->err += p->dy;
			p->x0 += p->sx;
		}
		if (e2 <= p->dx)
		{
			p->err += p->dx;
			p->y0 += p->sy;
		}
	}
}
void	init_img(t_fdf *f, t_mlx *m)
{
	t_pts	**p;

	p = f->pts;
	f->pro = malloc(sizeof(t_pro));
	if (!f->pro || f->pro == NULL)
		exit (0);//TODO:integrate into exit function
	m->adr = mlx_get_data_addr(m->img, &m->bpp, &m->len, &m->end);
	normalize_pts(f);
	f->y = 0;
	while (f->y < f->y_lim)
	{
		f->x = 0;
		while (f->x < f->x_lim)
		{
			if (f->x + 1 < f->x_lim)
				draw_line(p[f->y][f->x], p[f->y][f->x + 1], f);
			if (f->y + 1 < f->y_lim)
				draw_line(p[f->y][f->x], p[f->y + 1][f->x], f);
			f->x++;
		}
		f->y++;
	}
}

void	proj_zoom(t_fdf *f)
{
	int	x_zoom;
	int	y_zoom;


	x_zoom = DEFWID / (f->x_range[1] - f->x_range[0]);
	// x_zoom = (DEFWID / (f->x_range[1] - f->x_range[0]));
	y_zoom = DEFHEI / (f->y_range[1] - f->y_range[0]);
	// y_zoom = (DEFHEI / (f->y_range[1] - f->y_range[0]));
	if (x_zoom < y_zoom)
		f->zoom = round(x_zoom * 0.75);
	else
		f->zoom = round(y_zoom * 0.75);
}

void	get_range(t_pts **p, t_fdf *f)
{
	f->y = 0;
	while (f->y < f->y_lim)
	{
		f->x = 0;
		while (f->x < f->x_lim)
		{
			if (p[f->y][f->x].x < f->x_range[0])
				f->x_range[0] = p[f->y][f->x].x;
			if (p[f->y][f->x].x > f->x_range[1])
				f->x_range[1] = p[f->y][f->x].x;
			if (p[f->y][f->x].y < f->y_range[0])
				f->y_range[0] = p[f->y][f->x].y;
			if (p[f->y][f->x].y > f->y_range[1])
				f->y_range[1] = p[f->y][f->x].y;
			f->x++;
		}
		f->y++;
	}
}
int	get_height(char *num, int end)
{
	int	i;
	char	*height;
	
	i = 0;
	height = malloc(sizeof(char) * end + 1);
	if (!height || height == NULL)
		exit (0);//TODO:integrate into exit function;
	while (i < end)
	{
		height[i] = num[i];
		i++;
	}
	height[i] = '\0';
	i = ft_atoi(height);
	free (height);
	return(i);
}
int	ft_hextoi(char n)
{
	if (n >= '0' && n <= '9')
		return (n - 48);
	else if (n >= 'A' && n <= 'F')
		return (n - 55);
	else if (n >= 'a' && n <= 'f')
		return (n - 87);
	return (-1);
}
int	extract_color(char *col, int j)//TODO::segfault?
{
	int	i;
	int	hex;
	
	i = 2 + j;
	hex = 0;
	if (col[j] != ',')
		return (DEFCOL);
	while (col[i])
	{
		hex *= 16;
		hex += ft_hextoi(col[i]);
		i++;
	}
	return (hex);
}
int	get_lmn_len(char *lmn)//SUPERFLUOUS?
{
	int	i;
	
	i = 0;
	while (lmn[i])
	{
		if (lmn[i] == ',')
			return (-i);
		i++;
	}
	return (i);
}
t_pts	*meta_segments(t_fdf *f, int y)
{
	t_pts	*p;
	char	**s;
	int	len;
	int	x;

	x = 0;
	p = malloc(sizeof(t_pts) * f->x_lim);
	if (!p || p == NULL)
		return (NULL);
	s = f->raw->segments;
	
	while (s[x])
	{
		len = get_lmn_len(s[x]);
		p[x].c = extract_color(s[x], ft_abs(len));
		p[x].z = get_height(s[x], ft_abs(len));
		p[x].x = ((x - y) * (f->cosine));
		p[x].y = (((x + y) * (f->sine)) / 2 - (p[x].z));
		// p[x] = proj_offset(p[x], x, y, f);
		x++;
	}
	return (p);
}
/*	OFFSET LOGIC
we want a buffer from the edge of the screen

int	off;
int	x_off;
int	y_off;
int	buf;
int	x_buf;
int	y_buf;
int	x_start;
int	y_start;

//buffer offset, eg. 2% of picture
void	
x_start = (DEFWID * 0.02);
y_start = (DEFHEI * 0.02);

//	which is higher, x/y//_lim
if (f->x_lim < f->y_lim)//the y is limiting/the x needs a buff
{
	x_buf = y_start * (f->y_lim / f->x_lim);
	y_buf = y_start;
}
if (f->x_lim > f->y_lim)//the x is limiting/the y needs a buff
{
	x_buf = x_start;
	y_buf = x_start * (f->x_lim / f->y_lim);
}
//	end point/limit
x_end = (DEFWID - x_buf);
y_end = (DEFHEI - y_buf);
//	available screen real estate
x_realty = x_end - x_buf;
y_realty = y_end - y_buf;




//	the one that is larger = remains at 2%
int	x_buf;
//	the one that is smaller = becomes 2% times the ratio by which it is smaller
int	y_buf;



if x < y
	extra offset based on y
else
	extra offset based on x




*/
void	get_off(t_fdf *f)
{
	int	off;
	// t_pts p;
	if (f->x_lim > f->y_lim)
		off = (DEFWID / f->x_lim) / 2;
	else
		off = (DEFHEI / f->y_lim) / 2;
	f->x_off = ((DEFWID - off));
	f->y_off = ((DEFHEI - off));

}

void	set_points(t_fdf *f, t_pts **p, t_raw *raw)
{
	while (raw->lines[f->y])
	{
		raw->segments = ft_split(raw->lines[f->y], ' ');
		while (f->y == 0 && raw->segments[f->x_lim])
			f->x_lim++;
		p[f->y] = meta_segments(f, f->y);
		free (raw->segments);
		f->y++;
	}
	get_range(p, f);
	// get_off(f);
	free (raw->lines);
	proj_zoom(f);
	// proj_zoom(f, p);
}

void	init_mlx(t_fdf *f)
{
	t_mlx	*m;

	m = malloc(sizeof(t_mlx));
	if (!m || m == NULL)
		exit (0);//TODO:integrate into exit function
	m->win = NULL;
	m->mlx = NULL;
	m->img = NULL;
	m->adr = NULL;
	m->len = 0;
	m->bpp = 0;
	m->err = 0;
	m->end = 0;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, DEFWID, DEFHEI, "Fer De Fil");
	m->img = mlx_new_image(m->mlx, DEFWID, DEFHEI);
	f->mlx = m;
}
void	init_raw(t_fdf *fdf, char *map_file)
{
	t_raw	raw;
	
	fdf->raw = &raw;
	raw.map = open(map_file, O_RDONLY);
	raw.string = get_next_line(raw.map);
	while (raw.map != -1)
	{
		raw.line = get_next_line(raw.map);
		if (raw.line == NULL)
			break;
		raw.string = ft_strjoin(raw.string, raw.line);
	}
	raw.lines = ft_split(raw.string, '\n');
	while (raw.lines[fdf->y_lim])
		fdf->y_lim++;
	fdf->pts = malloc((sizeof(*fdf->pts) * fdf->y_lim));
	if (!fdf->pts || fdf->pts == NULL)
		exit (0);//TODO:integrate into exit function
	set_points(fdf, fdf->pts, &raw);
}
void	init_fdf(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	fdf->x_lim = 0;
	fdf->y_lim = 0;
	fdf->e = 0;
	fdf->b = 0;
	fdf->l = 0;
	fdf->x_off = 0;
	fdf->y_off = 0;
	fdf->scale = 1;//NB
	fdf->raw = NULL;
	fdf->dim = NULL;
	fdf->mlx = NULL;
	fdf->img = NULL;
	fdf->win = NULL;
	fdf->pts = NULL;
	fdf->pro = NULL;
	fdf->radians = (ANGLE * PI) / 180.0;
	fdf->cosine = cos(fdf->radians);
	fdf->sine = sin(fdf->radians);
	fdf->x_range[0] = 0;
	fdf->x_range[1] = 0;
	fdf->y_range[0] = 0;
	fdf->y_range[1] = 0;
}

bool	check_file(char **a)
{
	int i;
	int j;

	/* if filename ENDS with .fdf */
	j = ft_strlen(a[1]);
	i = j - 4;
	if (ft_strnstr(a[1] + i, ".fdf", 4))
		return (true);
	return (false);
}

int	main(int arg, char **param)
{
	t_fdf	fdf;
	// t_img	*img;

	if (arg != 2 || !check_file(param))
		return (1);
	init_fdf(&fdf);
	init_raw(&fdf, param[1]);
	init_mlx(&fdf);
	fdf.x = 0;
	fdf.y = 0;
	init_img(&fdf, fdf.mlx);
	mlx_hook(fdf.mlx->win, 17, 0, close_handler, &fdf);
	mlx_key_hook(fdf.mlx->win, keychain, &fdf);
	mlx_put_image_to_window(fdf.mlx->mlx, fdf.mlx->win, fdf.mlx->img, 0, 0);
	mlx_loop(fdf.mlx->mlx);
	printf(RED"just follow me\n"DEF);
}
