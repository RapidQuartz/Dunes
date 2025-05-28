
# include "inc/fdf.h"

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
void	derive_trig(t_pts o, t_pts d, t_img *i)
{
	i->dx = ft_abs(d.x - o.x);
	i->dy = -ft_abs(d.y - o.y);
	i->err = i->dx + i->dy;
	if (o.x < d.x)
		i->sx = 1;
	else
		i->sx = -1;
	if (o.y < d.y)
		i->sy = 1;
	else
		i->sy = -1;
}
void	put_pixel(int x, int y, int c, t_img *i)
{
	char	*pix;

	if (x < 0 || x >= DEFWID || y < 0 || y >= DEFHEI)
		return ;
	pix = i->addr + (y * i->len + x * (i->bpp / 8));
	*(unsigned int *)pix = c;
}
void	draw_line(t_pts o, t_pts d, t_img *i)
{
	derive_trig(o, d, i);
	while (1)
	{
		put_pixel(o.x, o.y, o.c, i);
		if (o.x == d.x && o.y == d.y)
			break ;
		if (2 * i->err >= i->dy)
		{
			i->err += i->dy;
			o.x += i->sx;
		}
		if (2 * i->err <= i->dx)
		{
			i->err += i->dx;
			o.y += i->sy;
		}
	}
}
void	init_img(t_fdf *f, t_img *i, t_pts **p)
{
	i->addr = mlx_get_data_addr(i->img, &i->bpp, &i->len, &i->endian);
	while (f->y < f->y_lim)
	{
		f->x = 0;
		while (f->x < f->x_lim)
		{
			if (f->x + 1 < f->x_lim)
				draw_line(p[f->y][f->x + 1], p[f->y][f->x], i);
			if (f->y + 1 < f->y_lim)
				draw_line(p[f->y + 1][f->x], p[f->y][f->x], i);
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
	return(ft_atoi(height));
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
int	extract_color(char *col, int j)
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
int	get_lmn_len(char *lmn)
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
t_pts	proj_offset(t_pts p, int x, int y, t_fdf *f)
{
	float	fx;
	float	fy;
	float	fz;

	fx = x * SCALEX;
	fy = y * SCALEY;
	fz = p.z * SCALEZ;
	p.x = ((fx - -fy) * (cos (f->angle)) + f->x_off);
	p.y = ((fx + -fy) * (sin (f->angle)) - fz + f->y_off);
	return (p);
}
t_pts	*meta_segments(t_fdf *f, int y)
{
	t_pts	*p;
	char	**s;
	int	len;
	int	x;

	x = 0;
	f->x_off = (DEFWID - ((f->x_lim - f->y_lim) * cos(f->angle) * SCALE)) / 2;
	f->y_off = (DEFHEI - ((f->x_lim + f->y_lim) * sin(f->angle) * SCALE)) / 2;
	p = malloc(sizeof(t_pts) * f->x_lim);
	if (!p || p == NULL)
		return (NULL);
	s = f->raw->segments;
	while (s[x])
	{
		len = get_lmn_len(s[x]);
		p[x].c = extract_color(s[x], ft_abs(len));
		p[x].z = get_height(s[x], ft_abs(len));
		p[x] = proj_offset(p[x], x, y, f);
		// p[x] = proj_offset(p[x], x, (f->y_lim - 1 - y), f);
		x++;
	}
	return (p);
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
	while (raw.lines[fdf->y])
	{
		raw.segments = ft_split(raw.lines[fdf->y], ' ');
		while (raw.segments[fdf->x_lim] && fdf->y == 0)
			fdf->x_lim++;
		fdf->pts[fdf->y] = meta_segments(fdf, fdf->y);
		free (raw.segments);
		fdf->y++;
	}
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
	fdf->t = 0;
	fdf->co = 0;
	fdf->si = 0;
	// fdf->x_off = DEFWID / 2;
	// fdf->y_off = DEFHEI / 2;
	fdf->scale = 1;
	fdf->angle = ANGLE;
	fdf->max = NULL;
	fdf->raw = NULL;
	fdf->map = NULL;
	fdf->dim = NULL;
	fdf->mlx = NULL;
	fdf->img = NULL;
	fdf->win = NULL;
	fdf->pts = NULL;
	fdf->pro = NULL;
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
	t_img	*img;

	if (arg != 2 || !check_file(param))
		return (1);
	init_fdf(&fdf);
	init_raw(&fdf, param[1]);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, DEFWID, DEFHEI, "Fer De Fil");
	img = malloc(sizeof(t_img));
	img->img = mlx_new_image(fdf.mlx, DEFWID, DEFHEI);
	fdf.img = img;
	fdf.x = 0;
	fdf.y = 0;
	init_img(&fdf, fdf.img, fdf.pts);
	mlx_hook(fdf.win, 17, 0, close_handler, &fdf);
	mlx_key_hook(fdf.win, keychain, &fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img->img, 0, 0);
	mlx_loop(fdf.mlx);
	printf(RED"just follow me\n"DEF);
}
