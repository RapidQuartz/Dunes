
# include "inc/fdf.h"


/*	WORK		IN		PROGRESS	*/

////	MEMORY:HANDLING:WITH:LINKED:LISTS:
////	BASIC:STRUCTURE:FOR:GARBAGE:COLLECTOR
/*
typedef struct	s_gb
{
	void		*mem_ptr;
	struct s_gb	*next;
}	t_gb;
t_gb	ft_garbage_collector(void *typ, size_t siz)
{
	if (siz != 0 && typ != NULL)
	// ?? i dont know what to do here.
}
*/
////	BUILDING:THE:LINKED:LIST:
/*
t_gb	ft_garbage_collector(void *typ, size_t siz);
*/
////	FREEING:THE:MEMORY:
/*
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
*/
int	ft_abs(int num)//KO
{
	if (num < 0)
		return (-num);
	return (num);
}
int	keychain(int key, void *par)//KO
{
	if (key == 65307 || !par)
		exit(0);
	return (0);
}
int	close_handler(void *param)//KO
{
	t_fdf	*fdf;

	fdf = param;
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit (0);
	return (0);
}

void	put_pixel(int x, int y, int c, t_mlx *i)//KO
{
	char	*pix;

	if (x < 0 || x >= DEFWID || y < 0 || y >= DEFHEI)
		return ;
	pix = i->adr + (y * i->len + x * (i->bpp / 8));
	*(unsigned int *)pix = c;
}

void	set_pro(t_pts o, t_pts d, t_pro *p, t_fdf *f)//KO
{
	p->x0 = round(((o.x) * f->zoom) + f->x_off);
	p->x1 = round(((d.x) * f->zoom) + f->x_off);
	p->y0 = round(((o.y) * f->zoom) + f->y_off) / 2;
	p->y1 = round(((d.y) * f->zoom) + f->y_off) / 2;
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

void	normalize_pts(t_fdf *f)//KO
{
	f->x_off = (DEFWID - (f->x_rng[1] - f->x_rng[0])) / 2 - f->x_rng[0];

	f->y_off = (DEFHEI - (f->y_rng[1] - f->y_rng[0])) / 2 - f->y_rng[0];

}

void	draw_line(t_pts o, t_pts d, t_fdf *f)//KO
{
	t_pro *p;
	int	e2;

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

void	get_off(t_fdf *f)//KO
{
	int	off;

	if (f->x_lim > f->y_lim)
		off = (DEFWID / f->x_lim) / 2;
	else
		off = (DEFHEI / f->y_lim) / 2;
	f->x_off = ((DEFWID - off));
	f->y_off = ((DEFHEI - off));
}

void	buffer_offset(t_fdf *f)//KO
{
	double	x_buf;
	double	y_buf;

	x_buf = (DEFWID * 0.02);
	y_buf = (DEFHEI * 0.02);
	if (f->x_lim < f->y_lim)
	{
		f->x_off = round(y_buf * (f->y_lim - f->x_lim));
		f->y_off = round(y_buf);
	}
	if (f->x_lim > f->y_lim)
	{
		f->x_off = round(x_buf);
		f->y_off = round(x_buf * (f->x_lim - f->y_lim));
	}
}
void	init_img(t_fdf *f, t_mlx *m)//KO
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

void	proj_zoom(t_fdf *f)//KO
{
	double	x_zoom;
	double	y_zoom;

	x_zoom = (double)DEFWID / (f->x_rng[1] - f->x_rng[0]);
	y_zoom = (double)DEFHEI / (f->y_rng[1] - f->y_rng[0]);
	if (x_zoom < y_zoom)
		f->zoom = round(x_zoom * 0.75);
	else
		f->zoom = round(y_zoom * 0.75);
}

void	get_range(t_pts **p, t_fdf *f)//KO
{
	f->y = 0;
	while (f->y < f->y_lim)
	{
		f->x = 0;
		while (f->x < f->x_lim)
		{
			if (p[f->y][f->x].x < f->x_rng[0])
				f->x_rng[0] = p[f->y][f->x].x;
			if (p[f->y][f->x].x > f->x_rng[1])
				f->x_rng[1] = p[f->y][f->x].x;
			if (p[f->y][f->x].y < f->y_rng[0])
				f->y_rng[0] = p[f->y][f->x].y;
			if (p[f->y][f->x].y > f->y_rng[1])
				f->y_rng[1] = p[f->y][f->x].y;
			if (p[f->y][f->x].z < f->z_range[0])
				f->z_range[0] = p[f->y][f->x].y;
			if (p[f->y][f->x].z > f->z_range[1])
				f->z_range[1] = p[f->y][f->x].y;
			f->x++;
		}
		f->y++;
	}
}

int	get_height(char *num, int end)//KO
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

int	ft_hextoi(char n)//KO
{
	if (n >= '0' && n <= '9')
		return (n - 48);
	else if (n >= 'A' && n <= 'F')
		return (n - 55);
	else if (n >= 'a' && n <= 'f')
		return (n - 87);
	return (-1);
}

int	extract_color(char *col, int j)//TODO::segfault?//KO
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

int	get_lmn_len(char *lmn)//SUPERFLUOUS?//KO
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

t_pts	*meta_segments(t_fdf *f, int y)//KO
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
		p[x].y = (((x + y) * (f->sine)) / 2 - (p[x].z * SCALEZ));
		x++;
	}
	return (p);
}

void	set_points(t_fdf *f, t_pts **p, t_raw *raw)//KO
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
	free (raw->lines);
	proj_zoom(f);
}

void	init_mlx(t_fdf *f)//KO
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

void	init_raw(t_fdf *fdf, char *map_file)//KO
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

void	init_fdf(t_fdf *fdf)//KO
{
	fdf->x = 0;
	fdf->y = 0;
	fdf->x_lim = 0;
	fdf->y_lim = 0;
	fdf->x_off = 0;
	fdf->y_off = 0;
	fdf->raw = NULL;
	fdf->dim = NULL;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->pts = NULL;
	fdf->pro = NULL;
	fdf->radians = (ANGLE * PI) / 180.0;
	fdf->cosine = cos(fdf->radians);
	fdf->sine = sin(fdf->radians);
	fdf->x_rng[0] = 0;
	fdf->x_rng[1] = 0;
	fdf->y_rng[0] = 0;
	fdf->y_rng[1] = 0;
	fdf->z_range[0] = 0;
	fdf->z_range[1] = 0;
}

bool	check_file(char **a)//KO
{
	int i;
	int j;

	j = ft_strlen(a[1]);
	i = j - 4;
	if (ft_strnstr(a[1] + i, ".fdf", 4))
		return (true);
	return (false);
}

int	main(int arg, char **param)//KO
{
	t_fdf	fdf;

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
