
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
// void	derive_trig(t_pts d, t_pts o, t_img *i)
// void	derive_trig(t_img *i)
// {
// 	i->dx = ft_abs(p->x1 - i->ox);
// 	i->dy = -ft_abs(p->y1 - i->oy);
// 	i->err = i->dx + i->dy;
// 	if (i->ox < p->x1)
// 		i->sx = 1;
// 	else
// 		i->sx = -1;
// 	if (i->oy < p->y1)
// 		i->sy = 1;
// 	else
// 		i->sy = -1;
// }
void	put_pixel(int x, int y, int c, t_mlx *i)
{
	char	*pix;

	if (x < 0 || x >= DEFWID || y < 0 || y >= DEFHEI)
		return ;
	pix = i->adr + (y * i->len + x * (i->bpp / 8));
	*(unsigned int *)pix = c;
}
// void	set_pro(t_pts o, t_pts d, t_pro *p, t_fdf *f)
void	set_pro(t_pts o, t_pts d, t_pro *p)
{
	// p->x0 = (int)rint(o.x) + (f->x_off / 2);
	p->x0 = (int)rint(o.x);
	// p->x1 = (int)rint(d.x) + (f->x_off / 2);
	p->x1 = (int)rint(d.x);
	// p->y0 = (int)rint(o.y) + (f->y_off / 2);
	p->y0 = (int)rint(o.y);
	// p->y1 = (int)rint(d.y) + (f->y_off / 2);
	p->y1 = (int)rint(d.y);
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
void	draw_line(t_pts o, t_pts d, t_fdf *f)
{
	t_pro *p;

	// set_pro(o, d, f->pro, f);
	set_pro(o, d, f->pro);
	p = f->pro;
	while (1)
	{
		put_pixel(p->x0, p->y0, o.c, f->mlx);
		if (p->x0 == p->x1 && p->y0 == p->y1)//SOMETHING FUNNY GOING ON HERE!! DOESNT BREAK SUFFICIENTLY TO PREVENT OVERRUN!!
			break ;
		if (2 * p->err >= p->dy)
		{
			p->err += p->dy;
			p->x0 += p->sx;
		}
		if (2 * p->err <= p->dx)
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
	// while (f->y < f->y_lim - 1)
	while (f->y < f->y_lim)
	{
		f->x = 0;
		// while (f->x < f->x_lim - 1)
		while (f->x < f->x_lim)
		{
			// if (f->x < f->x_lim)
			if (f->x + 1 < f->x_lim)
				draw_line(p[f->y][f->x], p[f->y][f->x + 1], f);
			// if (f->y < f->y_lim)
			if (f->y + 1 < f->y_lim)
				draw_line(p[f->y][f->x], p[f->y + 1][f->x], f);
			f->x++;
		}
		f->y++;
	}
	mlx_hook(m->win, 17, 0, close_handler, f);
	mlx_key_hook(m->win, keychain, f);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	mlx_loop(m->mlx);
}
t_pts	proj_offset(t_pts p, int x, int y, t_fdf *f)
{
	p.x = ((x - y) * (f->cosine) * SCALEX * SCALE + f->x_off / 1.3);
	p.y = ((x + y) * (f->sine * SCALEY * SCALE) - (p.z * SCALEZ * SCALE) + f->y_off / 1.5);
	return (p);
}
	// p.x = ((x - y) * (f->cosine) * (SCALEX * SCALE)
	//  + ((f->x_off * SCALE) / 2));
	// p.y = ((x + y) * (f->sine * (SCALEY * SCALE))
	//  - (p.z * (SCALEZ * SCALE)) + ((f->y_off * SCALE) / 2));
	// p.x = ((x - -y) * (f->cosine));
	// p.y = ((x + -y) * (f->sine) - p.z);
	// p.x = ((x - -y) * (f->cosine) * SCALEX);
	// p.y = ((x + -y) * (f->sine) - p.z * SCALEY);
	// p.x = ((x - -y) * (f->cosine) * SCALEX + f->x_off / 2);
	// p.y = ((x + -y) * (f->sine) - p.z * SCALEZ + f->y_off);
	// p.x = ((x - -y) * (f->cosine) * SCALEX * SCALE + f->x_off / 2);
	// p.x = ((x - y) * (f->cosine) * SCALEX * SCALE + f->x_off / 2);
	// p.y = ((x + y) * (f->sine * SCALEY * SCALE) - p.z * (tan(f->angle) * SCALEZ) + f->y_off);
	// p.x = ((x - -y) * (D_COS) * SCALEX + f->x_off);
	// p.x = ((x - y) * (f->cosine) * SCALEX);//
	// p.x = ((x - y) * (f->cosine) * SCALEX);
	// p.y = ((x + -y) * (D_SIN) - p.z * SCALEY + f->y_off);
	// p.y = ((x + y) * (f->sine) - (p.z * SCALEZ));//
	// p.y = ((x + y) * (f->sine * SCALEY) - (p.z * SCALEZ) + (f->y_off / 2));
	// p.y = ((x + y) * (f->sine) - p.z * SCALEY);
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
	if (f->x_off == 0)
		f->x_off = (DEFWID / 2 - ((f->x_lim - f->y_lim)));
	if (f->y_off == 0)
		f->y_off = (DEFHEI / 2 - ((f->x_lim + f->y_lim)));
	while (s[x])
	{
		len = get_lmn_len(s[x]);
		p[x].c = extract_color(s[x], ft_abs(len));
		p[x].z = get_height(s[x], ft_abs(len));
		p[x] = proj_offset(p[x], x, y, f);
		x++;
	}
	return (p);
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
	free (raw->lines);
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
	fdf->t = 0;
	fdf->co = 0;
	fdf->si = 0;
	fdf->x_off = 0;
	fdf->y_off = 0;
	fdf->scale = 1;//NB
	// fdf->angle = ANGLE * (PI/180.0);
	fdf->angle = ANGLE;//NB
	// fdf->max = NULL;
	fdf->raw = NULL;
	// fdf->map = NULL;
	fdf->dim = NULL;
	fdf->mlx = NULL;
	fdf->img = NULL;
	fdf->win = NULL;
	fdf->pts = NULL;
	fdf->pro = NULL;
	fdf->radians = (fdf->angle * PI) / 180.0;
	// fdf->cosine = SCALEX * cos(fdf->radians);
	fdf->cosine = cos(fdf->radians);
	// fdf->sine = SCALEY * sin(fdf->radians);
	fdf->sine = sin(fdf->radians);
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
