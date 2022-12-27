#include "../includes/cub3d.h" 

/*
    North (W): 0° = 360° or 0
    South (N): 270°
    East (E): 180°
    West (S): 90°
 */

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

int	main(int argc, char *argv[])
{
	t_data data;

	check_error_argument(argc, argv);
	if (init_all(&data, argv[1]))
		clean_all(&data, 1);
	print_wall(&data);
	draw_player(&data);
	mlx_key_hook(data.mlx_win, take_keycode, &data);
	mlx_hook(data.mlx_win, 17, 0L,close_window, &data);
	mlx_loop(data.mlx_ptr);
	clean_all(&data, 0);
	return (0);
}
