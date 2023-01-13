#include "../includes/cub3d.h" 

/*
void	init_wall(void **texture, void **mlx_ptr)
{
	int	width;
	int	height;
	void 	*path;
	path = mlx_xpm_file_to_image(*mlx_ptr, (char *)*texture, &width, &height);
	free(*texture);
	*texture = path;
}

void	print_wall(t_data *d)
{
	if (d->elem->NO)
		init_wall(&d->elem->NO, &d->mlx_ptr);
	if (d->elem->SO)
		init_wall(&d->elem->SO, &d->mlx_ptr);
	if (d->elem->EA)
		init_wall(&d->elem->EA, &d->mlx_ptr);
	if (d->elem->WE)
		init_wall(&d->elem->WE, &d->mlx_ptr);
	d->y = 0;
	while (d->map[d->y])
	{
		d->x = -1;
		while (d->map[d->y][++d->x])
		{
			if (d->map[d->y][d->x] == '1')
			{
				mlx_put_image_to_window(d->mlx_ptr,\
			d->mlx_win, d->elem->NO, d->x * 32, d->y * 32);
			}
		}
		d->y++;
	}
}
*/
void	init_window(t_data *data)
{
    data->mlx = mlx_init();
    if (data->mlx == NULL)
        free(data->mlx);
    data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, WIN_TITLE);
    if (data->win == NULL)
        free(data->mlx);
    data->img.img = mlx_new_image(data->mlx, WIN_W, WIN_H);
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
                                   &data->img.line_len, &data->img.endian);
}

int	main(int argc, char *argv[])
{
	t_data data;
    data.resX = 2560;
    data.resY = 1442;

	check_error_argument(argc, argv);
    data.mlx = mlx_init();
    init_window(&data);
    //textures_init(data.paths);
    if(!data.mlx)
        return 1;
	/*if (init_texture(&data))
		clean_all(&data, 1);*/
    castRay(&data);
	//mlx_key_hook(data.win, take_keycode, &data);
	//mlx_hook(data.win, 17, 0L,close_window, &data);
	//mlx_loop(data.mlx);
	//clean_all(&data, 0);
	return (0);
}
