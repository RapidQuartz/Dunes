# include "FdF.h"

int	main(int a, char **v)
{
debug("program started");
	int	i;
	int	j;
	t_fdf	fdf;
	char	*file;

	i = 0;
	j = 0;
	if (((a < 2 || a > 2) || (a == 2 && !check_file(v, i, j))))
		return (1);//TODO:err_ret
	fdf.fil = v[1];
	fdf.fd = open(file, O_RDONLY);
	init_fdf(&fdf);
	return (0);//TODO:improve return
}

//TODO:MOVE TO OWN FILE
void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx || fdf->mlx == NULL)
		return ;//TODO:free
	fdf->win = mlx_new_window(fdf->mlx, DEFWID, DEFHEI, fdf->fil);
	if (!fdf->win || fdf->win == NULL)
		return ;//TODO:free
	fdf->img->ptr = mlx_new_image(fdf->mlx, DEFWID, DEFHEI);
	if (!fdf->img->ptr || fdf->img->ptr == NULL)
		return ;//TODO:free
	fdf->img->pix = mlx_get_data_addr(fdf->img->ptr, &fdf->img->bit,
							&fdf->img->lin, &fdf->img->end);
	mlx_key_hook(fdf->win, get_keystroke, NULL);
	mlx_hook(fdf->win, 17, 0, get_exit, fdf);
	init_data(fdf);
}

void	init_data(t_fdf *fdf)
{
	double	theta;

	theta = tan(0.5);
	fdf->dim->x_lim = 0;
	fdf->dim->y_lim = 0;
	fdf->dim->w_scr = DEFWID;
	fdf->dim->h_scr = DEFHEI;
	fdf->dim->tot_p = 0;
	fdf->dim->z_max = INT_MIN;
	fdf->dim->z_min = INT_MAX;
	fdf->dim->z_rng = 0;
	fdf->dim->zoom = 1.0;
	fdf->dim->theta = theta;//TODO:check if this always is int
	fdf->map->len = 0;
	fdf->map->map_raw = NULL;
	get_map(fdf);
	get_dimensions(fdf);
}

//TODO:add to header
void	get_map(t_fdf *fdf)
{
	int	fd;
	char	*line;
	char	*raw;

	raw = NULL;
	fd = fdf->fd;
	while (fd != -1)
	{
		line = get_next_line(fd);
		if (line)
			raw = ft_strjoin(raw, line);
	}
	fdf->map->map_raw = raw;
	free (raw);
	close (fd);
}

//TODO:add to header
void	get_dimensions(t_fdf *fdf)
{
	get_mapline(fdf);
	fdf->iso->o_max = fdf->dim->x_lim;
	if (fdf->dim->x_lim < fdf->dim->y_lim)
		fdf->iso->o_max = fdf->dim->y_lim;
}

//TODO:fill this out
//TODO:add to header
int	get_iso(t_fdf *fdf)
{
	if (!fdf)
		return (1);
	return (0);
}

//TODO:add to header
void	get_mapline(t_fdf *fdf)
{
	int	fd;
	char	*str;

	fd = fdf->fd;
	while (fdf->fd == -1)
	{
		fdf->map->map_str = get_next_line(fd);
		str = fdf->map->map_str;
		if (fd == -1)
			break ;
		fdf->map->len = ft_strlen(str);
		fdf->map->map_raw = ft_strjoin(fdf->map->map_raw, str);
		if (!fdf->dim->x_lim)
			get_xlimit(fdf);
		free (fdf->map->map_str);
		fdf->dim->y_lim++;
	}
	if (fd == -1 || !fdf->dim->x_lim || !fdf->dim->y_lim)
		fdf_free(fdf);
}

//TODO:add to header
void	get_xlimit(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (fdf->map->map_str[fdf->map->len - 1] == '\n')
		fdf->map->map_str[fdf->map->len - 1] = 0;
	fdf->map->map_split = ft_split(fdf->map->map_str, ' ');
	while (fdf->map->map_split[fdf->dim->x_lim])
		fdf->dim->x_lim++;
	while (fdf->map->map_split[i])
		free (fdf->map->map_split[i++]);
	free (fdf->map->map_split);//TODO:maybe dont free it or sth lol.
}

//TODO:add to header
void	fdf_free(t_fdf *fdf)
{
	if (!fdf)
		return ;
	else
		exit (0);//TODO:integrate into exit function
}

//TODO:move to own file
int	get_keystroke(int key, void *param)//TODO:add.h
{
	(void)param;//TODO:find out what to do w/this weird thing
	if (key == 65307)
		exit (0);
	return (0);
}

int	get_exit(void *param)//TODO:add.h
{
	(void)param;//TODO:find out what to do w/this weird thing
	exit(0);//TODO:move to exit/leave now function
	return (0);//redundant, no?
}